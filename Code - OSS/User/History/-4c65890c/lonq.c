#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"
#include <unistd.h>
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


for(int i = 0 ; i <= 75 ; i++) {
system("clear");
strcat(c , " ");
printf("%s ------>" , c);

usleep(100000);
}


  //reset();
  return 0;
}