#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>

#include <termios.h> //SOLO PARA LINUX / MAC OS

#include <unistd.h> //SOLO PARA LINUX / MAC OS

#include <fcntl.h>  //SOLO PARA LINUX / MAC OS
 //#include <conio.h> //SOLO PARA WINDOWS 

#define Zombi 'Z'
#define mina '*'
#define espacio ' '
#define tp '@'
#define player 'S'

//Variables globales
int N, M, nivel;

//Preguntamos las filas
int preguntar_filas() {

  printf("Dame un valor de N [1-20]: ");
  scanf("%d", & N);
  if (N <= 0 || N > 20) {
    while (N <= 0 || N > 20) {
      printf("Error:Introduzca valores entre [1-20]: ");
      scanf("%d", & N);

    }

  }

  return N;
}

//Preguntamos las columnas
int preguntar_columnas() {

  printf("Dame un valor de M [1-78]: ");
  scanf("%d", & M);
  if (M <= 0 || M > 20) {
    while (M <= 0 || M > 78) {
      printf("Error: Introduzca valores entre [1-78]: ");
      scanf("%d", & M);

    }

  }

  return M;
}

//Preguntamos el nivel
int preguntar_nivel() {

  printf("Dame un valor del nivel [1-10]: ");
  scanf("%d", & M);
  if (M <= 0 || M > 20) {
    while (nivel <= 0 || nivel > 10) {
      printf("Error: Introduzca valores entre [1-10]: ");
      scanf("%d", & nivel);

    }

  }

  return nivel;
}

//Simulation of getch function (SOLO PARA MAC OS Y LINUX)
int getch(void) {
  struct termios oldt, newt;
  int ch;
  tcgetattr(STDIN_FILENO, & oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, & newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, & oldt);
  return ch;
}

//Inicializamos la matriz
void Init(char matrix[N][M]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      matrix[i][j] = espacio;
  }

  return;
}

//Funcion que rellenarera minas
int rellenar_minas(char matrix[N][M], int cantidad_minas) {
  int ran, dom, cont = 0;
  int n = N - 2;
  int m = M - 2;

  //rellenareramos aleatoriamente minas
  while (cont < cantidad_minas) {
    ran = (rand() % n) + 1;
    dom = (rand() % m) + 1;

    if (matrix[ran][dom] != tp && matrix[ran][dom] != player && matrix[ran][dom] != Zombi) {

      matrix[ran][dom] = mina;
      cont++;
    }
  }
  return cantidad_minas;
}

//Funcion que rellenarera zombis
int rellenar_zombis(char matrix[N][M], int cantidad_zombis) {
  int ran, dom, cont = 0;
  int n = N - 2;
  int m = M - 2;

  //rellenareramos aleatoriamente zombis
  while (cont < cantidad_zombis) {
    ran = (rand() % n) + 1;
    dom = (rand() % m) + 1;

    if (matrix[ran][dom] != tp && matrix[ran][dom] != player && matrix[ran][dom] != mina) {
      matrix[ran][dom] = Zombi;
      cont++;
    }
  }
  return cantidad_zombis;
}

//Funcion que rellenarera teletrasportadores
int rellenar_teleport(char matrix[N][M], int cantidad_tp) {
  int ran, dom, cont = 0;
  int n = N - 2;
  int m = M - 2;
  //rellenareramos aleatoriamente telentrasportadores
  while (cont < cantidad_tp) {
    ran = (rand() % n) + 1;
    dom = (rand() % m) + 1;

    if (matrix[ran][dom] != Zombi && matrix[ran][dom] != player && matrix[ran][dom] != mina) {
      matrix[ran][dom] = tp;
      cont++;
    }
  }
  return cantidad_tp;
}

//Imprimimos matriz
void imprimir(char matrix[N][M], int pos_x, int pos_y) {
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      //posicion del jugador
      if (i == pos_x && j == pos_y) {
        printf("%c", player);

      }
      //borde decorativo
      else if (i == 0 || j == 0 || i == N || j == M) {
        printf("x");
      }
      //matrix inicializada
      else {
        printf("%c", matrix[i][j]);

      }

    }

    printf("\n");

  }

  return;
}

//Cursores
void Mov(char tablero[N][M], int * pj_x, int * pj_y) {

  char tecla = getch();

  tablero[ * pj_x][ * pj_y] = espacio;

  if (tecla == -32 || tecla == 0) {
    tecla = getch();
  }

  switch (tecla) {
  case 72:
  case '8':
  case 'A':
    if ( * pj_x > 1) {
      ( * pj_x) --;
    }

    // Instrucciones asociadas a arriba
    break;
  case 80:
  case '2':
  case 'B':
    if ( * pj_x <= N - 2) {
      ( * pj_x) ++;
    }
    // Instrucciones asociadas a abajo
    break;
  case 75:
  case '4':
  case 'D':
    if ( * pj_y > 1) {
      ( * pj_y) --;
    }

    // Instrucciones asociadas a izquierda
    break;
  case 77:
  case '6':
  case 'C':
    if ( * pj_y <= M - 2) {
      ( * pj_y) ++;
    }

    // Instrucciones asociadas a derecha
    break;

  }

  return;
}

int posicion(int posX, int posY, char mapa[N][M], int i, int j, int direccion) {

  if (i > posX && j < posY) {
    direccion = 2;
  }
  if (i > posX && j == posY) {
    direccion = 1;
  }
  if (i > posX && j > posY) {
    direccion = 0;
  }
  if (i == posX && j > posY) {
    direccion = 3;
  }
  if (i == posX && j < posY) {
    direccion = 4;
  }
  if (i < posX && j > posY) {
    direccion = 5;
  }
  if (i < posX && j == posY) {
    direccion = 6;
  }
  if (i < posX && j < posY) {
    direccion = 7;
  }

  return direccion;
}

void move_zombies(char mapa[N][M], int posX, int posY, int dificultad) {
  int aux1 = 0;
  int aux2 = 0;
  int direccion = 0;

  for (int i = 0; i <= N; i++) {

    for (int j = 0; j <= M; j++) {
      direccion = posicion(posX, posY, mapa, i, j, direccion);
      aux1 = i;
      aux2 = j;

      if (dificultad * 10 > rand() % 99) {

        if (mapa[aux1][aux2] == 'z') {

          mapa[aux1][aux2] = ' ';

          switch (direccion) {
          case 0:
            if (mapa[aux1 - 1][aux2 - 1] == '*') {
              mapa[aux1 - 1][aux2 - 1] = ' ';
            } else {
              mapa[aux1 - 1][aux2 - 1] = 'M';
              break;
              case 1:
                if (mapa[aux1 - 1][aux2] == '*') {
                  mapa[aux1 - 1][aux2] = ' ';
                } else {
                  mapa[aux1 - 1][aux2] = 'M';
                  break;

                  case 2:
                    if (mapa[aux1 - 1][aux2 + 1] == '*') {
                      mapa[aux1 - 1][aux2 + 1] = ' ';
                    } else {
                      mapa[aux1 - 1][aux2 + 1] = 'M';
                    }
                  break;

                  case 3:
                    mapa[aux1][aux2 - 1] = 'M';
                  break;

                  case 4:
                    if (mapa[aux1][aux2 + 1] == '*') {
                      mapa[aux1][aux2 + 1] = ' ';
                    } else {
                      mapa[aux1][aux2 + 1] = 'M';
                    }
                  break;

                  case 5:
                    if (mapa[aux1 + 1][aux2 - 1] == '*') {
                      mapa[aux1 + 1][aux2 - 1] = ' ';
                    } else {
                      mapa[aux1 + 1][aux2 - 1] = 'M';
                    }
                  break;

                  case 6:
                    if (mapa[aux1 + 1][aux2] == '*') {
                      mapa[aux1 + 1][aux2] = ' ';
                    } else {
                      mapa[aux1 + 1][aux2] = 'M';
                    }

                  break;

                  case 7:
                    if (mapa[aux1 + 1][aux2 + 1] == '*') {
                      mapa[aux1 + 1][aux2 + 1] = ' ';
                    } else {
                      mapa[aux1 + 1][aux2 + 1] = 'M';
                    }
                  break;

                }

            }
          }
        }
      }
    }
  }
}

//Funcion perdedor
int loose(char matrix[N][M], int pos_x, int pos_y) {
  int resultado = 0;
  if (matrix[pos_x][pos_y] == mina || matrix[pos_x][pos_y] == Zombi) {
    matrix[pos_x][pos_y] = espacio;
    printf("\nSe nota que no jugaste lo suficiente al plants vs zombies XD");
    resultado++;
  }
  return resultado;
}

int winner(char matrix[N][M], int pos_x, int pos_y) {

  int cant_zombis;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      if (matrix[i][j] == Zombi) {

        cant_zombis++;
      }
    }

  }

  return cant_zombis;

}

int main() {
  //Posicion aleatoria con cada ejecución
  srand(time(NULL));
  //Color decorativo
  system("setterm --foreground yellow");

  //Preguntamos las filas y columnas y definimos la matriz
  int n = preguntar_filas();
  int m = preguntar_columnas();
  char juego[n][m];

  //Cantidades de minas, zombis y telentransportadores
  int cantidad_minas = 25;
  int cantidad_zombis = 2;
  int cantidad_tp = 5;

  int randx = n - 2;
  int randy = m - 2;
  //Posicion del usuario
  int pos_x = (rand() % randx) + 2;
  int pos_y = (rand() % randy) + 2;

  int Perdedor;
  int ganador;
  int direc;
  int i,j;
  //Inicializamos matriz y la rellenamos
  Init(juego);
  //rellenar_minas(juego, cantidad_minas);
  rellenar_zombis(juego, cantidad_zombis);
  //rellenar_teleport(juego, cantidad_tp);

  //Juego
  do {
    //system("cls"); //for windows
    system("clear"); // for linux/mac os

    //Imprimimos la matriz
    imprimir(juego, pos_x, pos_y);

    //Movimiento del usuario
    Mov(juego, & pos_x, & pos_y);
    direc = posicion(pos_x , pos_y , juego ,  i ,  j , direc);
    move_zombies(juego);
    //Movimiento de los zombis
    //mov_zombies(juego , pos_x , pos_y);

    //Telentransportador
    if (juego[pos_x][pos_y] == tp) {
      juego[pos_x][pos_y] = espacio;
      int x = (rand() % N) + 1;
      int y = (rand() % M) + 1;
      pos_x = x;
      pos_y = y;

    }

    //funcion que comprueba si hemos perdido
    Perdedor = loose(juego, pos_x, pos_y);
    //ganador = winner(juego , pos_x , pos_y);

  }
  while (Perdedor != 1);

  return 0;
}