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
int N, M , nivel;



//Preguntamos las filas
int preguntar_filas() {

  printf("Dame un valor de N [1-20]: ");
  scanf("%d" , &N);
  if( N <= 0 || N >20 ) {
    while( N<= 0 || N >20 ) {
      printf("Error:Introduzca valores entre [1-20]: ");
      scanf("%d" , &N);

    }


  }
  


  return N;
}



//Preguntamos las columnas
int preguntar_columnas() {
  
  printf("Dame un valor de M [1-78]: ");
  scanf("%d" , &M);
    if( M <= 0 || M >20 ) {
    while( M <= 0 || M > 78) {
      printf("Error: Introduzca valores entre [1-78]: ");
      scanf("%d" , &M);

    }


  }
  

  return M;
}



//Preguntamos el nivel
int preguntar_nivel() {
  
  printf("Dame un valor del nivel [1-10]: ");
  scanf("%d" , &M);
    if( M <= 0 || M >20 ) {
    while( nivel <= 0 || nivel > 10) {
      printf("Error: Introduzca valores entre [1-10]: ");
      scanf("%d" , &nivel);

    }


  }
  

  return nivel;
}







//Simulation of getch function (SOLO PARA MAC OS Y LINUX)
int getch(void){
 struct termios oldt, newt;
 int ch;
 tcgetattr( STDIN_FILENO, &oldt );
 newt = oldt;
 newt.c_lflag &= ~( ICANON | ECHO );
 tcsetattr( STDIN_FILENO, TCSANOW, &newt );
 ch = getchar();
 tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
 return ch;
 }


//Inicializamos la matriz
void Init(char matrix[N][M]) {
for(int i = 0 ; i < N ; i++ ) {
    for(int j = 0 ; j < M ; j++ ) 
        matrix[i][j] = espacio;
}

return;
}

//Funcion que rellenarera minas
int rellenar_minas(char matrix[N][M] , int cantidad_minas ){
   int ran, dom, cont = 0;
   int n = N-2;
   int m = M-2;
   
    //rellenareramos aleatoriamente minas
    while (cont < cantidad_minas) {
        ran = (rand()%n)+1;
        dom = (rand()%m)+1;

         if(matrix[ran][dom] != tp && matrix[ran][dom] != player && matrix[ran][dom] != Zombi) {
          
            matrix[ran][dom] = mina;
            cont++;
         }
    }
    return cantidad_minas;
}

//Funcion que rellenarera zombis
int rellenar_zombis(char matrix[N][M] , int cantidad_zombis ){
   int ran, dom, cont = 0;
   int n = N-2;
   int m = M-2;
    
    //rellenareramos aleatoriamente zombis
    while (cont < cantidad_zombis) {
        ran = (rand()%n)+1;
        dom = (rand()%m)+1;

         if(matrix[ran][dom] != tp && matrix[ran][dom] != player && matrix[ran][dom] != mina) { 
            matrix[ran][dom] = Zombi;
            cont++;
         }
    }
    return cantidad_zombis;
}

//Funcion que rellenarera teletrasportadores
int rellenar_teleport(char matrix[N][M] , int cantidad_tp ){
   int ran, dom, cont = 0;
   int n = N-2;
   int m = M-2;
    //rellenareramos aleatoriamente telentrasportadores
    while (cont < cantidad_tp) {
        ran = (rand()%n)+1;
        dom = (rand()%m)+1;

        if(matrix[ran][dom] != Zombi && matrix[ran][dom] != player && matrix[ran][dom] != mina) {
            matrix[ran][dom] = tp;
            cont++;
        }
    }
    return cantidad_tp;
}









//Imprimimos matriz
void imprimir(char matrix[N][M] , int pos_x , int pos_y ) {
for(int i = 0 ; i <= N ; i++ ) {
    for(int j = 0 ; j <= M ; j++ ) {
        //posicion del jugador
        if(i == pos_x && j == pos_y) {
            printf("%c" , player);

        }
        //borde decorativo
        else if(i == 0 || j == 0 || i == N || j == M) { 
            printf("x");
        }
        //matrix inicializada
        else{
            printf("%c" , matrix[i][j]);
            
            
    }

    }

printf("\n");

}

return;
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



//Cursores
void Mov(char tablero[N][M], int *pj_x, int *pj_y){
    
    char tecla = getch();

    tablero[*pj_x][*pj_y] = espacio;

    if (tecla == -32 || tecla == 0) {
        tecla = getch();
    }

    switch (tecla) {
        case 72:
        case '8':
        case 'A':
            if (*pj_x > 1) {
                (*pj_x)--;
            }

            // Instrucciones asociadas a arriba
            break;
        case 80:
        case '2':
        case 'B':
            if (*pj_x <= N - 2) {
                (*pj_x)++;
            }
            // Instrucciones asociadas a abajo
            break;
        case 75:
        case '4':
        case 'D':
            if (*pj_y > 1) {
                (*pj_y)--;
            }
 
            // Instrucciones asociadas a izquierda
            break;
        case 77:
        case '6':
        case 'C':
            if (*pj_y <= M-2) {
                (*pj_y)++;
            }


            // Instrucciones asociadas a derecha
            break;

    }



return;
}






void mov_zombies(char matrix[N][M] , int pos_x , int pos_y) {
  
   for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(matrix[i][j] == Zombi) {
        if(pos_x == i && pos_y < j) {
          matrix[i][j] = ' ';
          matrix[i][j+1] = Zombi;



        }
      else if(pos_x < i && pos_y == j)
          matrix[i][j] = ' ';
          matrix[i+1][j] = Zombi;


      }

      else if(pos_x == i && pos_y < j) {
          matrix[i][j] = ' ';
          matrix[i+1][j] = Zombi;



        }
      else if(pos_y < i && pos_x == j){
          matrix[i][j] = ' ';
          matrix[i][j+1] = Zombi;


      }

        


      }

      }





  return;
}






int main(){
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


//Posicion del usuario
int pos_x = (rand()%n+2)+2;
int pos_y = (rand()%m+2)+2;



int Perdedor;


//Inicializamos matriz y la rellenamos
Init(juego);
//rellenar_minas(juego, cantidad_minas);
rellenar_zombis(juego, cantidad_zombis);
//rellenar_teleport(juego, cantidad_tp);



//Juego
do{ 
//system("cls"); //for windows
system("clear"); // for linux/mac os

//Imprimimos la matriz
imprimir(juego , pos_x , pos_y);

//Movimiento del usuario
Mov(juego, &pos_x , &pos_y);

//Movimiento de los zombis
//mov_zombies(juego , pos_x , pos_y);

//Telentransportador
  if(juego[pos_x][pos_y] == tp) {
   juego[pos_x][pos_y] = espacio;
    int x = (rand()%N)+1;
    int y = (rand()%M)+1;
    pos_x = x;
    pos_y = y;
  


  }

//Si el usuario pisa una mina o se encuentra con un zombi , pierde
Perdedor = loose(juego, pos_x ,pos_y);


}
while(Perdedor != 1);





return 0;
}





/*void move_zombies(char matrix[N][M], int pos_x , int pos_y) {
  int i, j;

  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      if (matrix[i][j] == Zombi) {
        // Choose a random direction
        int direction = rand() % 4;

        // Move zombie in the chosen direction
        switch (direction) {
          case 0: // Up
            if (i > 1) {
              matrix[i][j] = ' ';
              matrix[i-1][j] = Zombi;
            }
            break;
          case 1: // Down
            if (i < N - 2) {
              matrix[i][j] = ' ';
              matrix[i+1][j] = Zombi;
            }
            break;
              case 2: // Left
            if (j > 1) {
              matrix[i][j] = ' ';
              matrix[i][j-1] = Zombi;
            }
            break;
          case 3: // Right
            if (j < M - 2) {
              matrix[i][j] = ' ';
              matrix[i][j+1] = Zombi;
            }
            break;
        }
      }
    }
  }
}*/
