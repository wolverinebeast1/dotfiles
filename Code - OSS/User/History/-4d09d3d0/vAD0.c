#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {

char *string = malloc(sizeof(char) * 10);


strcpy(string , "Hellowww");

for(int i = 0 ; i < 10 ; i++) {

printf("%c\n" , *string[i]);


}



    return 0;
}