#include <stdio.h>

int main(void){
    int first, second;
    printf("Entrez 2 entiers\nOperande 1 : ");
    scanf("%d", &first);
    printf("\nOperande 2: ");
    scanf("%d", &second);
    printf("add: %d\nminus: %d\ntimes: %d\ndivide: %d\nmodulo %d", first + second, first - second, first*second, first/second, first%second);
    return 0;
}