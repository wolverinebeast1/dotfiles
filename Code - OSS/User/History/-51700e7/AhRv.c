#include <stdio.h>
#include <stdlib.h>


int main() {

    int *array = malloc(sizeof(int) * 20);
    for(int i = 0 ; i < 20 ; i++) {


        array[i] = i+1;

    }

    for(int i = 0 ; i < 20 ; i++) {


      printf("%d\n" , array[i]);

    }

    free(array);
    return 0;
}