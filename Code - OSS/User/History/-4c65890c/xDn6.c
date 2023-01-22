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
srand(time(NULL));
char c[100] = "";


for(int i = 0 ; strlen(c) <= 75 ; i++) {

strcat(c , " ");
system("clear");
printf("%s ------>\n" , c);

usleep(10000);
}


  //reset();
  return 0;
}