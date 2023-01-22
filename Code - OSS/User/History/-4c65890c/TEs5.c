#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

void red () {
  printf("\033[1;31m");
}

void Blue() {

printf("\033[1;34m");


}



void reset () {
  printf("\033[0m");
}

int main () {

char c[100] = "";


  //reset();
  return 0;
}