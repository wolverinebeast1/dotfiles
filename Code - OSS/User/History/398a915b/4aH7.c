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

void generate_mines(char matrix[N][N] , int cant_minas) {

int cont = 0;
int x,y;
while(cont < cant_minas) {
x = rand()%N;
y = rand()%N;

matrix[x][y] = mina;
cont++;

}


    return;
}




void useless_message() {
    printf("Escape del campo de minas\n");




    return;
}



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



void user_move() {



    return;
}




int looser(char matrix[N][N] , int p_x, int p_y) {
    int loose = 0;

if(matrix[p_x][p_y] == mina){
    matrix[p_x][p_y] == 'X';
        loose++;
        p_x =  N-1;
        p_y =  N/2;
        }



return loose;
}




int main() {

char game[N][N];
int mines = 10;
int pos_x = N-1;
int pos_y = N/2;
int loose;
int cont = 0;
Init(game);
generate_mines(game,mines);

do{
printf("Iteracion %d Intento %d" , cont , loose);
useless_message()
system("clear");
print_map(game, pos_x , pos_y);
loose = looser(game, pos_x , pos_y);
cont++;
}

while(pos_y != 0);
  return 0;
}