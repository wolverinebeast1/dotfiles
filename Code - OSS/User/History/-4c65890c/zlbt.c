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

void Green() {


printf("\033[1;32m");
}

void Yellow() {

printf("\033[1;33m");

}



void reset () {
  printf("\033[0m");
}


int main () {
//srand(time(NULL));
char c[100] = "";
char c2[100] = "";
char c3[100] = "";
char c4[100] = "";
for(int i = 0 ; strlen(c) <= 75 || strlen(c2) <= 75 || strlen(c3) <= 75 || strlen(c4) <= 75; i++) {

strcat(c , " ");
strcat(c2 , " ");
strcat(c3 , " ");
strcat(c4 , " ");
system("clear");
red();
printf("%s :)))\n" , c);
Blue();
printf("%s <==\xe2\x99\xa5==>\n" , c2);
Green();
printf("%s <==\xe2\x99\xa5==>\n" , c3);
Yellow();
printf("%s <==\xf0\x9f\x90\xa7==>\n" , c4);
usleep(100000);
}


  //reset();
  return 0;
}