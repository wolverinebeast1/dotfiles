#include <stdio.h>
#include <stdlib.h>


int main() {

    int *V = malloc(sizeof(int) * 20);

    V[100000000] = 12;
    return 0;
}