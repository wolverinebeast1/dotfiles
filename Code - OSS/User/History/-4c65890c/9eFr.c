#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

struct test {

    char a;
    char b;

};

typedef s



int main() {


//using stack


struct test symb = {'(' , '$'};

printf("Variable a: %c || variable b: %c\n\n" , symb.a , symb.b);


//using heap
struct test *letra = malloc(sizeof(struct test));

letra->a = '#';
letra->b = '/';

printf("Variable a: %c || variable b: %c " , letra->a , letra->b);

free(letra);



    return 0;
}