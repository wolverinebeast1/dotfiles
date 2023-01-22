#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define mina 'M'
#define player 'U'
#define espacio ' '
#define N 18


void Init(char matrix[N][N]) {
    

    for(int i = 0 ; i< N ; i++) {
        for(int j = 0 ; j< N ; j++){
    
        matrix[i][j] = espacio;


        }
    }
    return;
}




int calculate_mines() {
cant_mines = (N*N*10)/100;


    return cant_mines;
}

void generate_mines(char matrix[N][N] , int cant_minas, int pos_x , int pos_y) {

int cont = 0;
int x,y;
while(cont < cant_minas) {
ran = rand()%N;
dom = rand()%N;

//Filtamos la posicion del usuario para que no aparezca ninguna mina en ese lugar
if(matrix[ran][dom] != matrix[pos_x][pos_y]) {
matrix[ran][dom] = mina;
cont++;
    }
}


    return;
}



//Mensaje
void useless_message() {
    printf("Escape del campo de minas\n");




    return;
}


//Imprimimos mapa
void print_map(char matrix[N][N], int pos_x , int pos_y) {

    for(int i = 0 ; i< N ; i++) {
        for(int j = 0 ; j<= N ; j++){
            if(i == pos_x && j == pos_y) {

        printf("%c" , player);
        int direction = rand()%3 - 1;
            }

            else if(j == 0 || j == N ) {
                printf("*");
            }

            else {
                printf("%c" , matrix[i][j]);

            }

             }
            printf("\n");
                }

    return;
}


//Movimiento del usuario
void user_move(char matrix[N][N] , int p_x , int p_y) {

//3 posibles movimientos (arriba , izquierda , derecha)
int direccion = rand()%2;


switch(direccion) {
case 0:


break;


case 1:

break;


case 2:


break;




}



    return;
}



//funcion que mata al usuario :)
int looser(char matrix[N][N] , int p_x, int p_y) {
    int loose = 0;
    int minas = calculate_mines();
//Si pisamos una mina , volvemos a la posicion inicial y volvemos a gastar el tiempo digo intentar llegar arriba
if(matrix[p_x][p_y] == mina){
    matrix[p_x][p_y] == 'X';
        loose++;
        p_x =  N-1;
        p_y =  N/2;
        generate_mines(game, minas);
        }



return loose;
}




int main() {

//variables
char game[N][N];
int mines = calculate_mines();
int pos_x = N-1;
int pos_y = N/2;
int loose;
int cont = 0;

//Inicializamos matriz y la rellenamos de minas
Init(game);
generate_mines(game,mines);


//Bucle de juego
do{
printf("Iteracion %d Intento %d" , cont , loose);
useless_message();
system("clear");
print_map(game, pos_x , pos_y);
loose = looser(game, pos_x , pos_y);
cont++;
}

while(pos_y != 0);

printf("\nSe encunetra solucion en %d iteraciones y %d intentos" , cont , loose);

  return 0;
}