#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

void red () {
  printf("\033[1;31m");
}

void Blue() {

 printf("\033[0;34m");


}



void reset () {
  printf("\033[0m");
}

int main () {
  red();
  printf("Hello ");
  Blue();
  printf("world\n");
  reset();
  return 0;
}