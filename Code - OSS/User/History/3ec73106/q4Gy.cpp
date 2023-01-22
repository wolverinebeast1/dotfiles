/*
Ruslan Avksentyev
DNI/NIE: Y3695173F
Practica 3

*/

//constante para practica 2 ejercicio 1
#define tiempo_10_segundos 10
//constantes para practica 2 ejercicio 3
#define pos_final 75
#define N 200

//Librerias
#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <math.h>

#include <time.h>

//#include <unistd.h> //solo para linux/mac os

//Funciones para los menus

int styler(void) { //Dibuja los iguales 

  for (int i = 0; i <= 40; i++) {

    printf("=");

  }
  printf("\n");

  return 0;
}

int cabecera_practica(int numero) { // cabecera de la practica
  styler();
  printf("\t\tPractica %d\n", numero);
  styler();
  return 0;

}

int cabecera_ejercicio(int num1, int num2) { //cabecera de los ejercicios acompañada con su práctica correspondiente
  styler();
  printf("       \tPractica %d ejercicio %d\n", num1, num2);
  styler();

  return 0;
}

int menuprin() { //menu principal
  int numero;
  do {
    styler();
    printf("\t      Menu Principal\n");
    styler();
    printf("\n1- Practica 1\n");
    printf("2- Practica 2\n");
    printf("3- Salir\n");
    printf("Opcion: ");
    scanf("%d", & numero);
    getchar();
  }
  while (numero < 1 || numero > 3);
  return numero;

}

int menupr1() { //menu de la practica 1
  int numero;
  do {
    cabecera_practica(1);
    printf("\n1- Ejercicio 1\n");
    printf("2- Ejercicio 2\n");
    printf("3- Ejercicio 3\n");
    printf("4-Volver al menu anterior\n");
    printf("Opcion: ");
    scanf("%d", & numero);

  }
  while (numero < 1 || numero > 4);

  return numero;

}

int menupr2() { //menu de la practica 2
  int numero;
  do {
    cabecera_practica(2);
    printf("\n1- Ejercicio 1\n");
    printf("2- Ejercicio 2\n");
    printf("3- Ejercicio 3\n");
    printf("4-Volver al menu anterior\n");
    printf("Opcion: ");
    scanf("%d", & numero);

  }
  while (numero < 1 || numero > 4);

  return numero;

}

//Funciones para practica 1 ejercicio 1
void cabecera_ejercicio_1_practica_1() {
  printf("Practica 1 FP. Ejercicio 1\n ");
  //número de práctica y del ejercicio
  printf("---------------------------\n");
  return;
}
//Recoger datos del ejericicio 1 de la practica 1
void recoger_datos(int & long_1, int & long_2, int & long_3) {

  printf("Longitud del primer lado:\n ");
  scanf("%d", & long_1);

  printf("Longitud del segundo lado:\n ");
  scanf("%d", & long_2);

  printf("Longitud del tercer lado:\n ");
  scanf("%d", & long_3);

  return;

}
//Funciones para practica 1 ejercicio 2
void cabecera_ejercicio2_practica1() {
  printf("Practica 1 de FP1. Ejercicio 2\n");
  printf("---------------------------------\n");

  return;
}

//Recoger datos del ejercicio 2 de la practica 1
void solicitar_datos_pr2_ejer2(float & nota_practica1, float & nota_practica2, float & nota_practica3, float & nota_practica4, float & nota_examen_parcial, float & nota_examen_final) {

  printf("Calificacion practica 1: \n");
  scanf("%f", & nota_practica1);

  printf("Calificacion practica 2: \n");
  scanf("%f", & nota_practica2);

  printf("Calificacion practica 3: \n");
  scanf("%f", & nota_practica3);

  printf("Calificacion practica 4: \n");
  scanf("%f", & nota_practica4);

  printf("Calificacion examen parcial\n");
  scanf("%f", & nota_examen_parcial);

  printf("Calificacion examen final\n");
  scanf("%f", & nota_examen_final);

}

//Funciones para practica 1 ejercicio 3

void cabecera_pr1_ejer3() {
  printf("Practica 1 de FP1. Ejercicio 3\n");
  printf("-------------------------------\n");

  return;
}

void solicitar_datos_pr1_ejer3(int & numero1, int & numero2, char & simbolo) {

  printf("Introduzca una operacion [num1][+,-,*,/ o %%][num2]: ");
  scanf("%d %c %d", & numero1, & simbolo, & numero2);

  return;
}

void dividir_entre_0(char signo, int num) {

  if ((signo == '/' || signo == '%') && num == 0) { //bloque "if" que filtra las divisiones entre 0

    printf("Error: El divisor no puede ser cero.\n");

  }

}

//Funciones para practica 2 ejercicio 1
void limitador_de_tiempo(float retraso_en_segundos) {
  int centinela = 0;
  int x1, y1, x2, y2;
  x2 = 0; //variable final (fila)
  y2 = 0; //variable final (columna)
  time_t tiempo_inic; //tiempo inicio
  time_t ahora; //tiempo ahora
  float tiempo_transcurido; //tiempo transcurido
  float setTime = retraso_en_segundos; //seteamos el tiempo

  time( & tiempo_inic); //inicializamos el tiempo 
  while (tiempo_transcurido < setTime) { //bucle que solo se ejecutara 10 segundos

    ahora = time(NULL);
    tiempo_transcurido = difftime(ahora, tiempo_inic);
    x1 = rand() % 23 + 1; //posicion aleatoria (fila)
    x2 = x1; //Posicion final al principio es posicion inicial(1 asterisco) //Ff = Fi
    y1 = rand() % 79 + 1; //posicion aleatoria (columna)
    y2 = y1;

    centinela = 1; //centinela
    do {

      for (int i = 0; i < 24; i++) { //filas 
        for (int j = 0; j < 80; j++) { //columnas
          if (i == 0 || i == 23 || j == 0 || j == 79) { //borde decorativo
            printf("o");

          } else {

            if (x2 >= i && y2 >= j && x1 <= i && y1 <= j) { //condicion para mover el rectangulo

              printf("*");

            } else {
              printf(" "); //espacio
            }

          }
        }
        printf("\n"); //salto de linea

      }

      switch (rand() % 4 + 1) {
      case 1:
        y2++; //agrandamos 
        break;
      case 2:
        y1--; //disminuimos
        break;
      case 3:
        x1--; //disminuimos
        break;
      case 4:
        x2++; //agrandamos
        break;

      }

      if (x2 == 23 || y2 == 79 || x2 == 0 || y2 == 0 || x1 == 23 || y1 == 79 || x1 == 0 || y1 == 0) { //Si el rectangulo llega al borde , cambiamos el valor del centinela y saldremos del bucle do while

        centinela = 2;
      }
      _sleep(100); //animacion mas suave
      system("cls"); //borramos pantalla

    }
    while (centinela == 1);

  }
}

//Funciones para practica 2 ejercicio 2
void generar_letras(int fil, int col, char letters[100]) {
  for (int i = 1; i <= fil; i++) {
    for (int j = 1; j <= col; j++) {

      letters[i] = 65 + (rand() % 10); //generamos letras aleatorias

    }
  }
}

void imprimir_matriz(int fil, int col, char letters[100]) {
  for (int i = 1; i <= fil; i++) { //imprimimos la matriz de letras

    for (int j = 1; j <= col; j++) {
      printf(" %c", letters[i]);
      printf(" %c", letters[j]);
    }
    printf("\n");
  }

}

//Funciones para practica 2 ejercicio 3

void guiones() { //funcion que imprime guiones
  printf("-------------------------------------------------------------------------------------\n");
}

char imprimir_cohete(char rocket[N], int numero_cohete) { //funcion que imprime cohetes

  printf("%s>----\\\n", rocket);
  printf("%s>  %d  )\n", rocket, numero_cohete);
  printf("%s>----/\n\n", rocket);

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

    printf("%s/|\\\n                                                                            - -\n                                                                            /|\\\n\n", rocket);

  }
  return numero_cohete;
}

//ejercicio 1 practica 1
int ejer1p1() {
  printf("\n");
  cabecera_ejercicio(1, 1);
  int l1, l2, l3; //variables necesarias
  cabecera_ejercicio_1_practica_1();
  //Pedimos los datos al usuario
  recoger_datos(l1, l2, l3);

  if (l1 > (l2 + l3) || l2 > (l1 + l3) || l3 > (l2 + l1) || l1 <= 0 || l2 <= 0 || l3 <= 0) { //filtramos la entrada de los datos

    printf("Error: las longitudes no se corresponden con un triangulo valido\n ");

  } else { //si la entrada de los datos es correcta , se ejecuta este bloque else

    if (l1 == l2 && l2 == l3 && l1 == l3) { //condicion para el triangulo equilatero
      printf("El triangulo es equilatero\n");

    } else if (l1 == l2 || l1 == l3 || l2 == l3) { //condicion para el triangulo iscoceles

      printf("El triangulo es iscoceles\n");

    } else { //condicion para el triangulo escaleno

      printf("El triangulo es escaleno\n");
    }

  }

  printf("\n");
  return 0;
}

//ejercicio 2 practica 1
int ejer2p1() {
  cabecera_ejercicio(2, 1);
  float nota_pr1, nota_pr2, nota_pr3, nota_pr4, nota_ex_parcial, nota_ex_final; //variables de las notas
  float media_practicas, media_teoria, media_final; // variables de las medias de cada bloque
  cabecera_ejercicio2_practica1();
  //Solicitamos los datos al usuario
  solicitar_datos_pr2_ejer2(nota_pr1, nota_pr2, nota_pr3, nota_pr4, nota_ex_parcial, nota_ex_final);
  //Filtramos las entradas , si el usuario teclea alguna de las notas menores que 0 o mayores que 10
  if ((nota_pr1 > 10 || nota_pr1 < 0) || (nota_pr2 > 10 || nota_pr2 < 0) || (nota_pr3 > 10 || nota_pr3 < 0) || (nota_pr4 > 10 || nota_pr4 < 0) || (nota_ex_parcial > 10 || nota_pr1 < 0) || (nota_ex_final > 10 || nota_ex_final < 0)) {
    printf("Error: Las notas no pueden ser superiores a 10 o menores que 0\n");

  }

  //Si los datos son correctos , el programa calculara las medias en este bloque else
  else {
    //Ecuaciones que calculan la media de cada bloque
    media_teoria = 0.333333 * nota_ex_parcial + 0.66666666 * nota_ex_final;
    media_practicas = (nota_pr1 + nota_pr2 + nota_pr3 + nota_pr4) / 4;

    if (media_teoria < 4 && media_practicas >= 4) { //nota de teoria menor que 4

      printf("La nota de teoria es inferior a 4. No se puede hacer media\n");
      printf("Calificaciones finales:\n");
      printf("Teoria: %0.2f  ", media_teoria);
      printf("Practicas: %0.2f  ", media_practicas);
      media_final = media_teoria;
      printf("Final %0.2f\n", media_final);
      printf("SUSPENSO\n");

    } else if (media_practicas < 4 && media_teoria >= 4) { //nota de practicas menor que 4 
      printf("La nota de practicas es inferior a 4. No se puede hacer media\n");
      printf("Calificaciones finales:\n");
      printf("Teoria: %0.2f  ", media_teoria);
      printf("Practicas: %0.2f  ", media_practicas);
      media_final = media_practicas;
      printf("Final %0.2f\n", media_final);
      printf("SUSPENSO\n");

    } else if (media_teoria < 4 && media_practicas < 4) { //ambos bloques tanto de teoria como de practicas son menores que 4
      printf("Tanto la media de teoria como la media de practicas son inferiores a 4. No se puede hacer la media\n");
      printf("Calificaciones finales:\n");
      printf("Teoria: %0.2f  ", media_teoria);
      printf("Practicas: %0.2f  ", media_practicas);
      if (media_teoria > media_practicas) { //condicion que comprueba la mayor de las dos notas. Nos quedamos con la minima
        media_final = media_practicas;
        printf("Final %0.2f\n", media_final);
        printf("SUSPENSO\n");
      } else { //nos quedamos con la media de teoria si se cumple que la media de practicas es mayor
        media_final = media_teoria;
        printf("Final %0.2f\n", media_final);
        printf("SUSPENSO\n");
      }

    } else { //Bloque else que se encarga de decir la calificacion final si las medias se satisfacen(media_teoria >= 4 && media_practicas >= 4)

      media_final = media_teoria * 0.6 + media_practicas * 0.4;

      printf("Calificaciones finales:\n");
      printf("Teoria: %0.2f  ", media_teoria);
      printf("Practicas: %0.2f  ", media_practicas);
      printf("Final: %0.2f ", media_final);
      printf("\n");
      if (media_final >= 5 && media_final < 7) {
        printf("APROBADO\n");
      } else if (media_final >= 7 && media_final < 9) {
        printf("NOTABLE\n");
      } else if (media_final >= 9 && media_final <= 10) {
        printf("Sobresaliente");
      } else {
        printf("SUSPENSO\n");

      }

    }

  }

  return 0;
}

//ejercicio 3 practica 1
int ejer3p1() {
  cabecera_ejercicio(3, 1);
  char symb; //variable de tipo char necesaria
  int num1, num2, result = 0; //variables de tipo entero necesarias
  cabecera_pr1_ejer3();
  solicitar_datos_pr1_ejer3(num1, num2, symb);

  dividir_entre_0(symb, num2); //filtra entrada de divisiones entre 0

  if (symb != '+' && symb != '-' && symb != '*' && symb != '/' && symb != '%') { //bloque if que nos filtra la entrada de las operaciones no contempladas
    printf("Error: Operador no reconocido.\n");

  } else { //bloque else que contiene todas las operaciones dependiendo del operador tecleado por el usuario
    if (symb == '+') { //operador suma
      result = num1 + num2;
      printf("Resultado: %d+%d = %d\n", num1, num2, result);

    } else if (symb == '-') { //operador resta
      result = num1 - num2;
      printf("Resultado: %d-%d = %d\n", num1, num2, result);

    } else if (symb == '*') { //operador multiplicacion
      result = num1 * num2;
      printf("Resultado: %d*%d = %d\n", num1, num2, result);

    } else if (symb == '/') { //operador division
      result = num1 / num2;
      printf("Resultado: %d/%d = %d\n", num1, num2, result);

    } else { // operador divison por modulo ; else if(symb == '%') -> equivalente al else
      result = num1 % num2;
      printf("Resultado: %d %% %d = %d\n", num1, num2, result);

    }
  }

  return 0;
}

//ejercicio 1 practica 2	
int ejer1p2() {
  system("Color B"); //Color decorativo
  cabecera_ejercicio(2, 1);
  limitador_de_tiempo(tiempo_10_segundos);
  system("Color 7");
  return 0;
}






//ejercicio 2 practica 2
int ejer2p2() {
  cabecera_ejercicio(2, 2);
  //Variables usadas
  int filas = 10;
  int columnas = 5;
  int valor = 0;
  int contador_de_letras = 0;
  int puntuacion = 0;
  int puntuacion_total = 0;
  char letras[100];
  char letra[1];

  printf("-------------------------------------------\n");
  printf("Puntuacion: %d puntos  \n", puntuacion); //Puntos antes de empezar el juego
  printf("-------------------------------------------\n");

  //Recorremos la matriz de las letras usando bucles anidados
  generar_letras(filas, columnas, letras);

  imprimir_matriz(filas, columnas, letras);

  for (int i = 1; i <= 10; i++) { //Como tenemos 10 letras recorremos , usamos bucle for para recorrerlas y prengutar al usuario 
    switch (i) { //en funcion de la variable i , entraremos a los casos del switch .
    case 1:
      //Letra A 
      letra[0] = 'A';
      break;
    case 2:
      //Letra B
      letra[0] = 'B';
      break;
    case 3:
      //Letra C
      letra[0] = 'C';
      break;
    case 4:
      //Letra D
      letra[0] = 'D';
      break;
    case 5:
      //Letra E
      letra[0] = 'E';
      break;
    case 6:
      //Letra F
      letra[0] = 'F';
      break;
    case 7:
      //Letra G
      letra[0] = 'G';
      break;
    case 8:
      //Letra H
      letra[0] = 'H';
      break;
    case 9:
      //Letra I
      letra[0] = 'I';
      break;
    case 10:
      //Letra J
      letra[0] = 'J';
      break;
    }
    printf("-------------------------------------------\n");
    printf("Apariciones de la letra %c :", letra[0]);
    scanf("%d", & valor); //numero de letras contado por el usuario
    contador_de_letras = 0; //La variable que cuenta de la matriz
    for (int i = 1; i <= filas; i++) {
      for (int j = 1; j <= columnas; j++) {
        if (letras[i] == letra[0]) {
          contador_de_letras++;
        }
        if (letras[j] == letra[0]) {
          contador_de_letras++;
        }

      }

    }

    printf("La letra %c aparece %d veces. \n", letra[0], contador_de_letras);
    //Ecuacion para la puntuacion obtenida en el momento

    puntuacion = (contador_de_letras - abs(valor - contador_de_letras));

    if (puntuacion < 0) {
      puntuacion = 0;
    }

    //Ecuacion que suma todas las puntuaciones
    puntuacion_total = puntuacion_total + puntuacion;

    //Imprimimos puntuacion
    printf("Te llevas %d puntos. \n", puntuacion);
    printf("-------------------------------------------\n\n");

    //Imprimimos puntuacion total
    printf("Puntacion  : %d \n", puntuacion_total);
    printf("-------------------------------------------\n");

    //Con cada iteracion iremos quitando letras y las sustituiremos por "-" , para ello volveremos a usar bucles anidados
    for (int i = 1; i <= filas; i++) {

      for (int j = 1; j <= columnas; j++) {

        if (letras[i] == letra[0]) { //comprobamos si la letra de la matriz es igual a la letra que le pedimos al usuario
          letras[i] = '-'; //en el caso afirmativo imrpimiremos un guion en vez de la letra pedida por el usuario
        }
        if (letras[j] == letra[0]) {
          letras[j] = '-';
        }
        printf(" %c", letras[i]); //imprime la letra en la coordenada x
        printf(" %c", letras[j]); //imprime la letra en la coordenada y
      }
      printf("\n"); //salto de linea
    }
  }

  printf("Tu puntacion final: %d\n", puntuacion_total); //imprimimos puntuacion total

  return 0;

}

//ejercicio 3 practica 2
int ejer3p2() {

  cabecera_ejercicio(2, 3);

  system("color E");
  srand(time(NULL)); //inicializa la semilla aleatoria en funcion del tiempo
  //Variables usadas
  char cohete[N] = "", cohete2[N] = "", cohete3[N] = "", cohete4[N] = "", cohete5[N] = "", cohete6[N] = "";
  //Bucle for principal , se ejecutara las veces necesarias hasta que todos los cohetes lleguen al final

  for (int i = 0; (strlen(cohete) <= pos_final || strlen(cohete2) <= pos_final || strlen(cohete3) <= pos_final || strlen(cohete4) <= pos_final || strlen(cohete5) <= pos_final || strlen(cohete6) <= pos_final); i++) {

    //Borramos pantalla con cada iteracion
    system("cls");
    //system("COLOR A");
    //system("clear"); //Solo para Linux/Mac OS

    printf("Iteracion %d\n", i);
    guiones();

    switch (rand() % 6 + 1) {
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
    }
    //Cohete 1
    comprobacion(cohete, 1);
    //Cohete2
    comprobacion(cohete2, 2);
    //Cohete3
    comprobacion(cohete3, 3);
    //Cohete 4  
    comprobacion(cohete4, 4);
    //Cohete 5
    comprobacion(cohete5, 5);
    //Cohete 6
    comprobacion(cohete6, 6);

    guiones();

    // hacemos la animacion mas lenta
    _sleep(10);

    //usleep(10000); //Solo para linux y Mac OS

  } //Fin del bucle for
  system("color 7");

  return 0;
}

int main(void) { //funcion main compuesta de bucles que ejecutan los menus hasta que le usuario no teclee un numero 3(del menu principal) , que es la opcion salir
  int numero = menuprin();
  while ((numero) != 3) {
    int numero2 = 0;
    switch (numero) {
    case 1:
      while (numero2 != 4) {
        switch (numero2 = menupr1()) {
        case 1:
          ejer1p1();
          break;
        case 2:
          ejer2p1();
          break;
        case 3:
          ejer3p1();
          break;
        case 4:
          numero = menuprin();
          break;
        }
      }
      case 2:
        while (numero2 != 4) {
          switch (numero2 = menupr2()) {
          case 1:
            ejer1p2();
            break;
          case 2:
            ejer2p2();
            break;
          case 3:
            ejer3p2();
            break;
          case 4:
            numero = menuprin();
            break;
          }
        }
    }
  }
  if (numero == 3) {
    system("Color 2");
    system("cls");
    styler();
    printf("\t     FIN DEL PROGRAMA\n");
    styler();
  }
  return 0;
}