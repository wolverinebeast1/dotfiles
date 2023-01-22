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


void 
int main () {
//srand(time(NULL));
char c[100] = "";
char c2[100] = "";


for(int i = 0 ; strlen(c) <= 75 || strlen(c2) <= 75 ; i++) {

strcat(c , " ");
strcat(c2 , " ");
system("clear");
red();
printf("%s :)))\n" , c);
Blue();
printf("%s <==\xe2\x99\xa5\n==>" , c2);

usleep(30000);
}


  //reset();
  return 0;
}