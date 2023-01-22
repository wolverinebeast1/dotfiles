#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {

char *string = malloc(sizeof(char) * 10);


strcpy(string , "Hellowww");


//1st way to print the string
for(int i = 0 ; i < 10 ; i++) {

printf("%c" , string[i]);


}


//2nd way to print the string

printf("\n%s" , string);

//free the memory

free(string);

    return 0;
}