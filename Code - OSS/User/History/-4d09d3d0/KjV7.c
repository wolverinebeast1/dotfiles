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
printf("\n\n");

char **string2 = malloc(sizeof(char*) * 2);


char *str = malloc(sizeof(char)* 10); 
char *str2 = malloc(sizeof(char)* 10); 


strcpy(str ,  "Hello");
strcpy(str2 ,  "There");

string2[0] = str;

string2[1] = str2;

printf("%s" , string2[0]);

printf("%s" , string2[1]);
printf("\n");
for(int i = 0; i <= 20 ; i++) {
    for(int j = 0; j <= 20 ; j++){
        if(i == 0 || i == 20) {
            printf("-");

        }
        else if(j == 0 || j == 20) 
        {
            printf("|");

        }
        else if(i == 10 && j == 10) {
            printf("H");

        }
        else{ 
            printf(" ");

        }

}
printf("\n");
    }

    return 0;
}