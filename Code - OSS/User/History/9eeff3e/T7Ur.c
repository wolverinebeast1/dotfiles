#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 100

#define M 20

#define pos_final 75



void guiones() { //funcion que imprime guiones
  printf("-------------------------------------------------------------------------------------\n");
}



char imprimir_cohete(char rocket[N], int numero_cohete) { //funcion que imprime cohetes
printf("%s>=0%d=>\n" , rocket , numero_cohete);
  
  return numero_cohete;
}

void concatenar_cohetes(char rocket[N]) { //funcion que concatena cohetes con espacios
  if (strlen(rocket) <= pos_final) {
    //strcat() instruccion que concatena cadenas
    strcat(rocket, " ");
  }

  return;
}


int comprobacion(char rocket[N], int numero_cohete) { //funcion que comprueba si el cohete llego al final
  if (strlen(rocket) <= pos_final) {

    imprimir_cohete(rocket, numero_cohete);

  } else { //En el caso que el cohete llega al final , imprimiremos por pantalla la animacion destruida

    printf("%s ¡PUM!\n", rocket);

  }
  return numero_cohete;

}









int main() {

srand(time(NULL)); //inicializa la semilla aleatoria en funcion del tiempo
  //Variables usadas
  


  char cohete[N] = "", cohete2[N] = "", cohete3[N] = "", cohete4[N] = "", cohete5[N] = "", cohete6[N] = "";
  //Bucle for principal , se ejecutara las veces necesarias hasta que todos los cohetes lleguen al final

  for (int i = 0; (strlen(cohete) <= pos_final || strlen(cohete2) <= pos_final || strlen(cohete3) <= pos_final || strlen(cohete4) <= pos_final || strlen(cohete5) <= pos_final || strlen(cohete6) <= pos_final) ; i++) {

    //Borramos pantalla con cada iteracion
    //system("cls");
    //system("COLOR A");
    
    system("clear"); //Solo para Linux/Mac OS

    printf("Iteracion %d\n", i);
    guiones();

    switch (rand() % M) {
    case 1:
      //cohete 1
      concatenar_cohetes(cohete);
      break;
    case 2:
      //cohete 2
      concatenar_cohetes(cohete2);
      break;
    case 3:
      //cohete 3
      concatenar_cohetes(cohete3);
    case 4:
      //cohete 4
      concatenar_cohetes(cohete4);
      break;
    case 5:
      //cohete 5
      concatenar_cohetes(cohete5);
      break;
    case 6:
      //cohete 6
      concatenar_cohetes(cohete6);
      break;
    case 7:
      //cohete 6
      concatenar_cohetes(cohete7);
      break;
    case 8:
      //cohete 6
      concatenar_cohetes(cohete8);
      break;
    case 9:
      //cohete 6
      concatenar_cohetes(cohete9);
      break;
    case 10:
      //cohete 6
      concatenar_cohetes(cohete10);
      break;
    case 11:
      //cohete 6
      concatenar_cohetes(cohete11);
      break;
    case 12:
      //cohete 6
      concatenar_cohetes(cohete12);
      break;
    case 13:
      //cohete 6
      concatenar_cohetes(cohete13);
      break;
    case 14:
      //cohete 6
      concatenar_cohetes(cohete14);
      break;  
    case 15:
      //cohete 6
      concatenar_cohetes(cohete15);
      break;
    case 16:
      //cohete 6
      concatenar_cohetes(cohete16);
      break;
    case 17:
      //cohete 6
      concatenar_cohetes(cohete17);
      break;    
    case 18:
      //cohete 6
      concatenar_cohetes(cohete18);
      break;
    case 19:
      //cohete 6
      concatenar_cohetes(cohete19);
      break;
    }
    //Cohete 1

    comprobacion(cohete, 1);
    //Cohete 2
    comprobacion(cohete2, 2);
    //Cohete 3
    comprobacion(cohete3, 3);
    //Cohete 4  
    comprobacion(cohete4, 4);
    //Cohete 5
    comprobacion(cohete5, 5);
    //Cohete 6
    comprobacion(cohete6, 6);

    comprobacion(cohete7, 7);

    comprobacion(cohete8, 8);

    comprobacion(cohete9, 9);

    comprobacion(cohete10, 10);

    comprobacion(cohete11, 11);

    comprobacion(cohete12, 12);

    comprobacion(cohete13, 13);

    comprobacion(cohete14, 14);

    comprobacion(cohete15, 15);
    
    comprobacion(cohete16, 16);

    comprobacion(cohete17, 17);

    comprobacion(cohete18, 18);

    comprobacion(cohete19, 19);

    guiones();

    // hacemos la animacion mas lenta
    usleep(10000);
  }





    return 0;
}