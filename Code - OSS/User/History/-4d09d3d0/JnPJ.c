#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {

char *string = malloc(sizeof(char) * 10);


strcpy(string , "Hellowww");

printf("First way(using a for loop to print char by char): ");
//1st way to print the string
for(int i = 0 ; i < 10 ; i++) {

printf("%c" , string[i]);


}


//2nd way to print the string

printf("\nSecond way(using %%s format): %s" , string);

//free the memory

free(string);


//Multidimensional strings


char **string of strings = malloc(sizeof(char*) * 2);


    return 0;
}