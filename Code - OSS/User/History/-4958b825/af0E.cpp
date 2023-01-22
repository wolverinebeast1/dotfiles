#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>

#include <termios.h> //SOLO PARA LINUX / MAC OS

#include <unistd.h> //SOLO PARA LINUX / MAC OS

#include <fcntl.h> //SOLO PARA LINUX / MAC OS
#define filas 20
#define columnas 70





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







void pantalla(char mapa[filas][columnas], int posX, int posY, int final){
    for (int i=0;i<=filas;i++){

        for(int j=0;j<=columnas;j++){

            if (i==posX && j==posY){
                if (final==0){
                    printf("X");
                }else{
                printf("S");
                }

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
    if (final==0){
        mapa[posX][posY]='X';
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

int perder( int posX, int posY, char mapa[filas][columnas], int final){



    if (mapa[posX][posY]=='z'||mapa[posX][posY]=='*'){



        final=0;

    }
    return final;
}

// Funcion que calcula la posicion del zombi respecto del jugador para decidir que movimiento hacer
int posicion(int posX, int posY, int i, int j, int direccion){



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
int movimiento(char mapa[filas][columnas], int posX, int posY, int dificultad,  int vida){
    int aux1=0;
    int aux2=0;
    int direccion=0;


    for (int i=0;i<=filas;i++){

        for(int j=0;j<=columnas;j++){
            direccion=posicion(posX,posY,i,j,direccion);
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
                        }else if(aux1-1==posX && aux2-1==posY) {
                            vida=0;
                        }else{

                            mapa[aux1-1][aux2-1]='M';
                        }

                        break;
                    case 1:
                        if (mapa[aux1-1][aux2]=='*'){
                            mapa[aux1-1][aux2]=' ';
                        }else if(mapa[aux1-1][aux2]=='S') {
                            vida=0;
                        }else{
                            mapa[aux1-1][aux2]='M';
                        }
                        break;

                    case 2:
                        if (mapa[aux1-1][aux2+1]=='*'){
                            mapa[aux1-1][aux2+1]=' ';
                        }else if(aux1-1==posX && aux2+1==posY) {
                            vida=0;
                        }else{
                            mapa[aux1-1][aux2+1]='M';
                        }
                        break;

                    case 3:
                        if(mapa[aux1][aux2-1]=='*'){
                            mapa[aux1][aux2-1]=' ';
                        }else if(aux1==posX && aux2-1==posY) {
                            vida=0;
                        }else{
                            mapa[aux1][aux2-1]='M';
                        }
                        break;

                    case 4:
                        if (mapa[aux1][aux2+1]=='*'){
                            mapa[aux1][aux2+1]=' ';
                        }else if(aux1==posX && aux2+1==posY) {
                            vida=0;
                        }else{
                            mapa[aux1][aux2+1]='M';
                        }
                        break;

                    case 5:
                        if (mapa[aux1+1][aux2-1]=='*'){
                            mapa[aux1+1][aux2-1]=' ';
                        }else if(aux1+1==posX && aux2-1==posY) {
                            vida=0;
                        }else{
                            mapa[aux1+1][aux2-1]='M';
                        }
                        break;

                    case 6:
                        if (mapa[aux1+1][aux2]=='*'){
                            mapa[aux1+1][aux2]=' ';
                        }else if(aux1+1==posX && aux2==posY) {
                            vida=0;
                        }else{
                            mapa[aux1+1][aux2]='M';
                        }

                        break;

                    case 7:
                        if (mapa[aux1+1][aux2+1]=='*'){
                            mapa[aux1+1][aux2+1]=' ';
                        }else if(aux1+1==posX && aux2+1==posY) {
                            vida=0;
                            mapa[aux1+1][aux2+1]='M';
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

int contador(char mapa[filas][columnas], int contadorZ){
    for (int i=0;i<filas;i++){

        for(int j=0;j<columnas;j++){

            if (mapa[i][j]=='z'){
                contadorZ=contadorZ+1;

            }

        }
    }

    return contadorZ;
}







int main (void){
     srand (time(NULL));
    //int filas=0;
    // int columnas =0;
    int zombis=0;
    int dificultad =0;
    int minas=0;
    int tp=0;
    int posX=rand()%filas;
    int posY=rand()%columnas;
    int final=1;
    int contadorZ=0;




    //Entrada de datos con filtro


    /* printf("Introduzca las dimensiones del mapa filasXcoumnas\n");
    scanf ("%d",&filas);
    scanf ("%d",&columnas);

    while (filas<1 || filas>20||columnas<1||columnas>78){
        printf("Error, introduzca datos validos\n");
        scanf ("%d",&filas);
        scanf ("%d",&columnas);
    }*/


    printf("Introduzca la dificultad del juego:");
    scanf("%d", &dificultad);

    while (dificultad<1||dificultad>10){
        printf("Error, introduzca una dificultad valida\n");
        scanf ("%d",&dificultad);
    }




    char mapa[filas][columnas];

    //Calculo del numero de objetos y zombis
    //minas=minaspawn();

    zombis=3;

    //tp=tpspawn();


    //Generacion de mapa
    inicio(mapa);

    iniciozombis(zombis,mapa);
    iniciominas(minas,mapa);
    iniciotp(tp,mapa);

    while(final==1){
        system("clear");

        pantalla(mapa, posX, posY, final);

        cursores(mapa,&posX,&posY);
        for (int i=0;i<filas;i++){

            for(int j=0;j<columnas;j++){

                if (mapa[i][j]=='z'|| mapa[i][j]=='M'){
                    contadorZ=contadorZ+1;

                }


            }
        }

        //Funciones encargadas de las interacciones entre objertos del mapa

        // teletrtansporte(posX,posY,mapa);
        if (mapa[posX][posY]=='@'){
            mapa[posX][posY]=' ';

            do {

                posX=rand()%filas;
                posY=rand()%columnas;


            } while(mapa[posX][posY]=='z'||mapa[posX][posY]=='*'||mapa[posX][posY]=='@');
        }


        final=perder(posX,posY,mapa, final);

        final=movimiento(mapa,posX,posY,dificultad,final);
       // contadorZ=contador(mapa,zombis);



        if (contadorZ<=0){
            final=2;

        }
        contadorZ=0;









    }
     system("clear");

     pantalla(mapa,posX,posY, final);


    if (final==0){
         printf("\nBuen intento, pero te has convertido en comida para zombis JAJAJAJAJA\n\n");

}else{
        printf("\nIncreible, has sobrevivido al apocalipsis\n");
    }









    return 0;
}