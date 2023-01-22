#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {

char *string = malloc(sizeof(char) * 10);


strcpy(string , "Hello");

printf("%s" , string);




    return 0;
}