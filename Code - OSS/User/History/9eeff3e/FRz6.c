#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>

#include <termios.h> //SOLO PARA LINUX / MAC OS

#include <unistd.h> //SOLO PARA LINUX / MAC OS

#include <fcntl.h> 
//#define filas 20
//#define columnas 70

int filas, columnas;
//Simulation of getch function (SOLO PARA MAC OS Y LINUX)




int preguntar_filas() {

  printf("Dame un valor de N [1-20]: ");
  scanf("%d", & filas);
  if (filas <= 0 || filas > 20) {
    while (filas <= 0 || filas > 20) {
      printf("Error:Introduzca valores entre [1-20]: ");
      scanf("%d", & filas);

    }

  }

  return filas;
}

//Preguntamos las columnas
int preguntar_columnas() {

  printf("Dame un valor de M [1-78]: ");
  scanf("%d", & columnas);
  if (columnas <= 0 || columnas > 20) {
    while (columnas <= 0 || columnas > 78) {
      printf("Error: Introduzca valores entre [1-78]: ");
      scanf("%d", & columnas);

    }

  }

  return columnas;
}




//FUncion que genera la matriz mapa
void inicio( char mapa[filas][columnas]){


    for (int i=0;i<filas;i++){

        for(int j=0;j<columnas;j++){

            mapa[i][j]=' ';

        }
    }






    return ;
}





//Funcionas que calculan los % de objetos y zombis
int zombispawn(){
    int aux=filas*columnas;
    int zombis=aux*5/100;
    return zombis;
}
int minaspawn(){
    int aux=filas*columnas;
    int minas=aux*10/100;
    return minas;
}
int tpspawn(){
    int aux=filas*columnas;
    int tp=aux*1/100;
    return tp;
}



void iniciozombis(int zombis, char mapa[filas][columnas]){
    int contador =0;
    int rand1;
    int rand2;
    contador=zombis;

    while (contador>0) {
        rand1=rand()%filas;
        rand2=rand()%columnas;

        if (mapa[rand1][rand2]!='z'&& mapa[rand1][rand2]!='S'){

        mapa[rand1][rand2]='z';
        contador=contador-1;
         }
    }
    return;
}


void iniciominas(int minas, char mapa[filas][columnas]){
    int contador =0;
    int rand1=0;
    int rand2=0;
    contador=minas;

    while (contador>0) {
        rand1=rand()%filas;
        rand2=rand()%columnas;

        if (mapa[rand1][rand2]!='z'  && mapa[rand1][rand2]!='S' && mapa[rand1][rand2]!='*' ){

            mapa[rand1][rand2]='*';
            contador=contador-1;
        }
    }
    return;
}


void iniciotp(int tp, char mapa[filas][columnas]){
    int contador =0;
    int rand1=0;
    int rand2=0;
    contador=tp;

    while (contador>0) {
        rand1=rand()%filas;
        rand2=rand()%columnas;

        if (mapa[rand1][rand2]!='z'  && mapa[rand1][rand2]!='S' && mapa[rand1][rand2]!='*' && mapa[rand1][rand2]!='@' ){

            mapa[rand1][rand2]='@';
            contador=contador-1;
        }
    }



    return;
}







void pantalla(char mapa[filas][columnas], int posX, int posY){
    for (int i=0;i<=filas;i++){

        for(int j=0;j<=columnas;j++){

            if (i==posX && j==posY){
                printf("S");

            }else if(i==0||j==0||i==filas||j==columnas){

                printf("x");

            }else{
                if (mapa[i][j]=='M'){
                    mapa [i][j]='z';
                }

                printf("%c",mapa[i][j]);
            }

        }

        printf("\n");
    }
    return ;
}




void cursores(char mapa[filas][columnas], int* posX, int* posY){

    char tecla = getch();

    mapa[*posX][*posY] = ' ';

    if (tecla == -32 || tecla == 0) {
        tecla = getch();
    }

    switch (tecla) {
    case 72:
    case '8':
    case 'A':
        if (*posX > 1) {
            (*posX)--;
        }

        // Instrucciones asociadas a arriba
        break;
    case 80:
    case '2':
    case 'B':
        if (*posX <= filas - 2) {
            (*posX)++;
        }
        // Instrucciones asociadas a abajo
        break;
    case 75:
    case '4':
    case 'D':
        if (*posY > 1) {
            (*posY)--;
        }

        // Instrucciones asociadas a izquierda
        break;
    case 77:
    case '6':
    case 'C':
        if (*posY <= columnas-2) {
            (*posY)++;
        }


        // Instrucciones asociadas a derecha
        break;

    }



    return;
}


void teletrtansporte(int posX, int posY, char mapa[filas][columnas]){

    if (mapa[posX][posY]=='@'){
        do {
            posX=rand()%filas;
            posY=rand()%columnas;


        }
        while(mapa[posX][posY]=='z'||mapa[posX][posY]=='*'||mapa[posX][posY]=='@');
    }
    return;
}

int perder( int posX, int posY, char mapa[filas][columnas] ){

    int vida=1;

    if (mapa[posX][posY]=='z'||mapa[posX][posY]=='*'){

        printf("\nBuen intento, pero te has convertido en comida para zombis JAJAJAJAJA\n\n");

        vida=0;

    }
    return vida;
}

// Funcion que calcula la posicion del zombi respecto del jugador para decidir que movimiento hacer
int posicion(int posX, int posY, char mapa[filas][columnas], int i, int j, int direccion){



    if (i>posX && j<posY){
        direccion=2;
    }
    if (i>posX && j==posY){
        direccion=1;
    }
    if (i>posX && j>posY){
        direccion=0;
    }
    if (i==posX && j>posY){
        direccion=3;
    }
    if (i==posX && j<posY){
        direccion=4;
    }
    if (i<posX && j>posY){
        direccion=5;
    }
    if (i<posX && j==posY){
        direccion=6;
    }
    if (i<posX && j<posY){
        direccion=7;
    }

    return direccion;
}
// Funcion que ejecuta el movimiento
int movimiento(char mapa[filas][columnas], int posX, int posY, int dificultad, int zombis, int vida){
    int aux1=0;
    int aux2=0;
    int direccion=0;





    for (int i=0;i<=filas;i++){

        for(int j=0;j<=columnas;j++){
            direccion=posicion(posX,posY,mapa,i,j,direccion);
            aux1=i;
            aux2=j;
            //Probabailidad de movimiento segun la dificultad
            if (dificultad*10>rand()%99){

                if (mapa[aux1][aux2]=='z'){

                    mapa[aux1][aux2]=' ';


                   //Segun la direccion se ejecuta un movimiento u otro entre los 8 posibles
                    switch (direccion){
                    case 0:
                        if (mapa[aux1-1][aux2-1]=='*'){
                            mapa[aux1-1][aux2-1]=' ';
                            zombis=zombis-1;
                        }else if(mapa[aux1-1][aux2-1]=='S') {
                            vida=0;
                        }else{

                            mapa[aux1-1][aux2-1]='M';
                        }

                            break;
                    case 1:
                                if (mapa[aux1-1][aux2]=='*'){
                                    mapa[aux1-1][aux2]=' ';
                                    zombis=zombis-1;
                                }else if(mapa[aux1-1][aux2]=='S') {
                                    vida=0;
                                }else{
                                    mapa[aux1-1][aux2]='M';
                                }
                                    break;

                            case 2:
                                        if (mapa[aux1-1][aux2+1]=='*'){
                                            mapa[aux1-1][aux2+1]=' ';
                                            zombis=zombis-1;
                                        }else if(mapa[aux1-1][aux2+1]=='S') {
                                            vida=0;
                                        }else{
                                            mapa[aux1-1][aux2+1]='M';
                                        }
                                        break;

                                    case 3:
                                        if(mapa[aux1][aux2-1]=='*'){
                                           mapa[aux1][aux2-1]=' ';
                                           zombis=zombis-1;
                                        }else if(mapa[aux1][aux2-1]=='S') {
                                            vida=0;
                                        }else{
                                            mapa[aux1][aux2-1]='M';
                                        }
                                        break;

                                    case 4:
                                        if (mapa[aux1][aux2+1]=='*'){
                                            mapa[aux1][aux2+1]=' ';
                                            zombis=zombis-1;
                                        }else if(mapa[aux1][aux2+1]=='S') {
                                            vida=0;
                                        }else{
                                            mapa[aux1][aux2+1]='M';
                                        }
                                        break;

                                    case 5:
                                        if (mapa[aux1+1][aux2-1]=='*'){
                                            mapa[aux1+1][aux2-1]=' ';
                                            zombis=zombis-1;
                                        }else if(mapa[aux1+1][aux2-1]=='S') {
                                            vida=0;
                                        }else{
                                            mapa[aux1+1][aux2-1]='M';
                                        }
                                        break;

                                    case 6:
                                        if (mapa[aux1+1][aux2]=='*'){
                                            mapa[aux1+1][aux2]=' ';
                                            zombis=zombis-1;
                                        }else if(mapa[aux1+1][aux2]=='S') {
                                            vida=0;
                                        }else{
                                            mapa[aux1+1][aux2]='M';
                                        }

                                        break;

                                    case 7:
                                        if (mapa[aux1+1][aux2+1]=='*'){
                                            mapa[aux1+1][aux2+1]=' ';
                                            zombis=zombis-1;
                                        }else if(mapa[aux1+1][aux2+1]=='S') {
                                            vida=0;
                                        }else{
                                            mapa[aux1+1][aux2+1]='M';
                                        }
                                        break;




                                }




                        }
                    }
                }
            }


    return vida;
}







int main (void){
    srand (time(NULL));
    int Filas = preguntar_filas(); 
    int Columnas = preguntar_columnas();
    char mapa[Filas][Columnas];
    int zombis=0;
    int dificultad =0;
    int minas=0;
    int tp=0;
    int posX=rand()%filas;
    int posY=rand()%columnas;
    int vida=1;
    int victoria=0;
   


    printf("Introduzca la dificultad del juego:");
    scanf("%d", &dificultad);

    while (dificultad<1||dificultad>10){
        printf("Error, introduzca una dificultad valida\n");
        scanf ("%d",&dificultad);
    }





    //Calculo del numero de objetos y zombis
    minas=minaspawn();

    zombis=zombispawn();

    tp=tpspawn();


    //Generacion de mapa
    inicio(mapa);

    iniciozombis(zombis,mapa);
    iniciominas(minas,mapa);
    iniciotp(tp,mapa);

    while(vida>0 ){
        system("cls");

        pantalla(mapa, posX, posY);

        cursores(mapa,&posX,&posY);

        //funcion de interacciones

        // teletrtansporte(posX,posY,mapa);
        if (mapa[posX][posY]=='@'){
            mapa[posX][posY]=' ';
            do {

                posX=rand()%filas;
                posY=rand()%columnas;


            }
            while(mapa[posX][posY]=='z'||mapa[posX][posY]=='*'||mapa[posX][posY]=='@');
        }
        vida=perder(posX,posY,mapa);

        vida=movimiento(mapa,posX,posY,dificultad, zombis,vida);


        if (zombis<=0){
            victoria=1;
            printf("No esperaba que lo sobrevivieras, enhorabuena superviviente");
        }







    }








    return 0;
}