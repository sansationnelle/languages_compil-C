#include <stdio.h>
int main(void){
    int a = 17, b= 5;
    printf("add: %d\nminus: %d\ntimes: %d\ndivide: %d (entier), %2f (floattant)\nmodulo %d\n", a + b, a - b, a*b, a/b, (float)a/(float)b, a%b);
}