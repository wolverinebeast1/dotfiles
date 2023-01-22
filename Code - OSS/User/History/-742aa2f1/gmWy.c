#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <termios.h> //SOLO PARA LINUX / MAC OS
#include <unistd.h> //SOLO PARA LINUX / MAC OS
#include <fcntl.h>  //SOLO PARA LINUX / MAC OS           
//#include <conio.h> //SOLO PARA WINDOWS OS


#define Zombi 'Z'
#define mina '*'
#define espacio ' '
#define tp '@'
#define N 20
#define M 70
#define player 'S'


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

//Funcion que genera minas
int gen_minas(char matrix[N][M] , int cantidad_minas ){
   int ran, dom, cont = 0;
    
    //generamos aleatoriamente minas
    while (cont < cantidad_minas) {
        ran = rand() % N;
        dom = rand() % M;

        
            matrix[ran][dom] = mina;
            cont++;
        
    }
    return cantidad_minas;
}

//Funcion que genera zombis
int gen_zombis(char matrix[N][M] , int cantidad_zombis ){
   int ran, dom, cont = 0;
    
    
    //generamos aleatoriamente zombis
    while (cont < cantidad_zombis) {
        ran = rand() % N;
        dom = rand() % M;

        
            matrix[ran][dom] = Zombi;
            cont++;
        
    }
    return cantidad_zombis;
}

//Funcion que genera teletrasportadores
int gen_teleport(char matrix[N][M] , int cantidad_tp ){
   int ran, dom, cont = 0;
    
    //generamos aleatoriamente telentrasportadores
    while (cont < cantidad_tp) {
        ran = rand() % N;
        dom = rand() % M;

        
            matrix[ran][dom] = tp;
            cont++;
        
    }
    return cantidad_tp;
}









//Imprimimos matriz
void imprimir(char matrix[N][M] ,int pos_x , int pos_y ) {
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
        printf("\nCareful out there xd");
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




void Mov_Zombis(char tablero[N][M], int pos_x, int pos_y) {

if(pos_x == pos_x+1 && pos_y = pos_y+1) {
    tablero[pos_x][pos_y] = zombi;


} 



    return;
}


int main(){
//Posicion aleatoria con cada ejecución
srand(time(NULL));
//Color decorativo
system("setterm --foreground yellow");
//system("COLOR 6"); //color amarillo para windows (:

//matriz de juego
char juego[N][M];
//TEMPORALMENTE , cantidades de minas , zombis y teletraportadores (EN LA ALPHA VERSION ESTAS VARIABLES SERÁN FUNCIONES)
int cantidad_minas = 25;
int cantidad_zombis= 10;
int cantidad_tp = 5;
//Posicion por defecto del usuario
int pos_x = N-10 , pos_y = 1;
int Perdedor;
//Inicializamos matrix
Init(juego);
//Rellenamos la matriz de minas , zombis y teletransportadores
gen_minas(juego, cantidad_minas);
gen_zombis(juego, cantidad_zombis);
gen_teleport(juego, cantidad_tp);
//Entramos en bucle que se ejecutara hasta que el usuario gane o pierda
do{ 
//system("cls"); //for windows
system("clear"); // for linux/mac os
//Imprimimos la matriz
imprimir(juego, pos_x , pos_y);
//Le damos a los cursores las coordenadas del usuario
Mov(juego, &pos_x , &pos_y);
//Si el usuario pisa una mina o se encuentra con un zombi , pierde
Perdedor = loose(juego, pos_x ,pos_y);

//Simulacion del telentransportador(EN LA ALPHA VERSION ESTO ESTARÁ DENTRO EN UNA FUNCION APARTE )
if(juego[pos_x][pos_y] == tp) {
    juego[pos_x][pos_y] = espacio;
    int x = rand()%N-2;
    int y = rand()%M;
    pos_x = x;
    pos_y = y;

}
}
while(Perdedor != 1);





return 0;
}