#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>

#include <unistd.h>

//#include <conio.h>

//Programa sin modularizar (de momento)
#define pos_final 75

//Decoracion :)
void guiones() {
  printf("\n");
  for (int i = 0; i < pos_final + 7; i++) {

    printf("-");
  }
  printf("\n");

  return;
}

//Preguntamos por el numero de cohetes y filtramos entrada
int preguntar() {
  int n;
  printf("Cuantos cohetes quieres? ");
  scanf("%d", & n);

  //Filtramos entrada
  if (n <= 0 || n > 20) {

    while (n <= 0 || n > 20) {
      printf("Error: Introduzca la cantidad correcta(1-20): ");
      scanf("%d", & n);
    }

  }

  return n;
}


int cuantos_faltan(int V[] , int num_cohetes) {





  return num_cohetes;
}

int main() {

  srand(time(NULL));
  
  //numero de cohetes
  int N = preguntar();

  //Linea de codigo decorativa pero no obligatoria (pones color a los cohetes:D) , SOLO PARA LINUX / MAC OS
  //system("setterm --half-bright on --foreground yellow");
  system("clear");
  //system("cls");

  //Vector
  int V[20];
  int random = 0;
  //Inicializamos todos los elementos del vector
  for (int i = 0; i < N; i++) {
    V[i] = 0;
  }

  //Bucle principal
  for (int i = 0; i < 2000; i++) {
    system("clear");
    //system("cls");
    printf("Iteracion: %d", i);
    guiones();
    //Elegimos un cohete aleatorio y lo avanzamos 
    random = rand() % N;
    if (V[random] <= pos_final) {
      V[random]++;
    }

    //Bucle que imprime tantos cohetes como indico el usuario
    for (int j = 0; j < N; j++) {
      //Bucle que imprime espacios
      for (int k = 0; k < V[j]; k++) {
        printf(" ");
      }

      //Imrpimir cohetes
      if (j < 10 && V[j] <= pos_final) {
        printf(">=0%d=>\n", j);

      } else if (j >= 10 && V[j] <= pos_final) {
        printf(">=%d=>\n", j);

      } else {

        printf("¡PUM!\n");

      }

    }
    //_sleep(250);
    usleep(10000);
  }

  return 0;

}