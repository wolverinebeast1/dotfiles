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
#define N 20
#define M 70
#define usuario_muerto 'X'
//Variables globales
//int N, M, nivel;

//Preguntamos las filas
/*int preguntar_filas() {

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
}*/

//Preguntamos el nivel al usuario y devolvemos el valor
int preguntar_nivel() {

  int level;
  printf("Introduzca la dificultad del juego[1-10]: ");
  scanf("%d", & level);

  while (level < 1 || level > 10) {
    printf("Error, introduzca una dificultad valida[1-10]:");
    scanf("%d", & level);
  }

  return level;
}

//Simulacion de la funcion getch (SOLO PARA MAC OS Y LINUX)
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

//Funciones que calculan el porcentaje de los zombis , minas y los portales

int cantidad_zombis() {
  int cant_zombis = (N * M) * 5 / 100;
  return cant_zombis;
}
int cantidad_minas() {
  int cant_minas = (N * M) * 10 / 100;
  return cant_minas;
}
int cantidad_tps() {

  int cant_tp = (N * M) * 1 / 100;
  return cant_tp;
}

//Funcion que rellena minas
void rellenar_minas(char matrix[N][M], int cantidad_minas) {
  int ran, dom, cont = 0;
  //Filtramos los numeros aleatorios
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
  return;
}

//Funcion que rellenarera zombis
void rellenar_zombis(char matrix[N][M], int cantidad_zombis) {
  int ran, dom, cont = 0;
  //Filtramos los numeros aleatorios
  int n = N - 2;
  int m = M - 2;

  //rellenareramos aleatoriamente zombis
  while (cont < cantidad_zombis) {
    ran = (rand() % n) + +2;
    dom = (rand() % m) + 2;
    //filtro
    if (matrix[ran][dom] != tp && matrix[ran][dom] != player && matrix[ran][dom] != mina) {
      matrix[ran][dom] = Zombi;
      cont++;
    }
  }
  return;
}

//Funcion que rellenarera teletrasportadores
int rellenar_teleport(char matrix[N][M], int cantidad_tp) {
  int ran, dom, cont = 0;
  //filtramos los numeros aleatorios
  int n = N - 2;
  int m = M - 2;
  //rellenareramos aleatoriamente telentrasportadores
  while (cont < cantidad_tp) {
    ran = (rand() % n) + 1;
    dom = (rand() % m) + 1;
    //filtro
    if (matrix[ran][dom] != Zombi && matrix[ran][dom] != player && matrix[ran][dom] != mina) {
      matrix[ran][dom] = tp;
      cont++;
    }
  }
  return cantidad_tp;
}

//Imprimimos matriz
void imprimir(char matrix[N][M], int pos_x, int pos_y, int resul) {
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
      //matriz 
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

//teletransportador
void teletransportar(char matrix[N][M], int * pos_x, int * pos_y) {
  int n = N - 2;
  int m = M - 2;

  if (matrix[ * pos_x][ * pos_y] == tp) {
    matrix[ * pos_x][ * pos_y] = espacio;
    do {
      * pos_x = (rand() % n) + 1;
      * pos_y = (rand() % m) + 1;
    } while (matrix[ * pos_x][ * pos_y] == Zombi || matrix[ * pos_x][ * pos_y] == mina);

  }

  return;
}

//funcion que calcula la posicion del usuario respecto al zombi
int calcular_posicion(int pos_x, int pos_y, int i, int j) {

  int direc = 0;
  //Diagonal inferior izquierda
  if (i > pos_x && j > pos_y) {
    direc = 0;
  }
  //Vertical inferior
  if (i > pos_x && j == pos_y) {
    direc = 1;
  }
  //Diagonal inferior derecha
  if (i > pos_x && j < pos_y) {
    direc = 2;
  }
  //Horizontal izquierda
  if (i == pos_x && j > pos_y) {
    direc = 3;
  }
  //Horizontal derecha
  if (i == pos_x && j < pos_y) {
    direc = 4;
  }
  //Diagonal superior izquierda
  if (i < pos_x && j > pos_y) {
    direc = 5;
  }
  //Vertical superior
  if (i < pos_x && j == pos_y) {
    direc = 6;
  }
  //Diagonal superior derecha
  if (i < pos_x && j < pos_y) {
    direc = 7;
  }

  return direc;
}

//funcion que mueve los zombis
void move_zombies(char matrix[N][M], int pos_x, int pos_y, int nivel) {

  int direc = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      direc = calcular_posicion(pos_x, pos_y, i, j);

      //Probabilidad con la que se mueve un zombi
      if (nivel * 10 > rand() % 99) {

        //Buscamos la posicion del zombi
        if (matrix[i][j] == Zombi) {
          //como movemos el zombi , la posicion en la que estaba sera un espacio
          matrix[i][j] = espacio;

          //tenemos 8 posibles direcciones , 4 diagonales , arriba ,abajo , derecha , izquierda
          switch (direc) {
            //Diagonal inferior izquierda
          case 0:
            if (matrix[i - 1][j - 1] == mina) {
              //si el zombie pisa la mina , muere
              matrix[i - 1][j - 1] = espacio;

            } else {
              //Posicion del zombi si no piso ninguna mina o mato al usuario  
              matrix[i - 1][j - 1] = Zombi;
            }

            break;

            //Vertical inferior
          case 1:
            if (matrix[i - 1][j] == mina) {
              matrix[i - 1][j] = espacio;

            } else {

              matrix[i - 1][j] = Zombi;
            }

            break;

            //Diagonal inferior derecha
          case 2:
            if (matrix[i - 1][j + 1] == mina) {

              matrix[i - 1][j + 1] = espacio;
            } else {

              matrix[i - 1][j + 1] = Zombi;
            }

            break;

            //Horizontal izquierda
          case 3:
            if (matrix[i][j - 1] == mina) {

              matrix[i][j - 1] = espacio;
            } else {

              matrix[i][j - 1] = Zombi;
            }

            break;

            //Horizontal derecha
          case 4:
            if (matrix[i][j + 1] == mina) {

              matrix[i][j + 1] = espacio;
            } else {

              matrix[i][j + 1] = Zombi;
            }

            break;

            //Diagonal superior izquierda
          case 5:
            if (matrix[i + 1][j - 1] == mina) {

              matrix[i + 1][j - 1] = espacio;
            } else {

              matrix[i + 1][j - 1] = Zombi;
            }

            break;

            //Vertical superior
          case 6:
            if (matrix[i + 1][j] == mina) {

              matrix[i + 1][j] = espacio;
            } else {

              matrix[i + 1][j] = Zombi;
            }

            break;

            //Diagonal superior derecha
          case 7:

            if (matrix[i + 1][j + 1] == mina) {

              matrix[i + 1][j + 1] = espacio;
            } else {

              matrix[i + 1][j + 1] = Zombi;
            }

            break;

          }

        }

      }

    }

  }

  return;

}

//Funcion perdedor
int loose(char matrix[N][M], int pos_x, int pos_y) {
  int resultado = 0;
  if (matrix[pos_x][pos_y] == mina || matrix[pos_x][pos_y] == Zombi) {
    matrix[pos_x][pos_y] = espacio;
    printf("\n\nHas perdido:(");
    resultado++;
  }
  return resultado;
}

int main() {
  //Posicion aleatoria con cada ejecución
  srand(time(NULL));
  //Color decorativo
  //system("setterm --foreground yellow");

  char juego[N][M];

  //Cantidades de minas, zombis y telentransportadores
  int minas = cantidad_minas();
  int zombis = 5;//cantidad_zombis();
  int portales = cantidad_tps();
  int nivel;
  //Valores aleatorios acotados
  int randx = N - 2;
  int randy = M - 2;
  //Posicion del usuario
  int pos_x = 10;//(rand() % randx) + 2;
  int pos_y = 35;//(rand() % randy) + 2;

  int contador_zombis = 0;
  int comprobacion;
  system("clear");
  nivel = preguntar_nivel();

  //Inicializamos matriz y la rellenamos
  Init(juego);
  rellenar_minas(juego, minas);
  rellenar_zombis(juego, zombis);
  rellenar_teleport(juego, portales);

  //Juego
  do {
    //system("cls"); //for windows
    system("clear"); // for linux/mac os

    //Imprimimos la matriz
    imprimir(juego, pos_x, pos_y, comprobacion);

    //Movimiento del usuario
    Mov(juego, & pos_x, & pos_y);

    //Contamos los zombis
    for (int i = 0; i < N; i++) {

      for (int j = 0; j < M; j++) {

        if (juego[i][j] == Zombi) {
          contador_zombis++;

        }

      }
    }

    //Telentransportador
    teletransportar(juego, & pos_x, & pos_y);

    //Movimiento de los zombis
    move_zombies(juego, pos_x, pos_y, nivel);

    //Comprobacion si hemos perdido
    comprobacion = loose(juego, pos_x, pos_y);

    if (contador_zombis <= 0) {
      comprobacion = 1;
      printf("Felicidades , has sobrevivido");
    }

    contador_zombis = 0;
  }
  while (comprobacion != 1);

  return 0;
}