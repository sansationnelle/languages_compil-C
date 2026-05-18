#include <stdio.h>
int main(void){
    int n = 0;
    int times = 0;
    do {
        printf("type your table:\n");
        scanf("%d", &n);
        if (n == 0){
            printf("welp just know that everything is 0 in here\n");
        } else {
            for (int i = 1; i <= 10;i += 1){
                times = n * i;
                printf("table of %d: %d * %d = %d\n", n, n, i, times);
            }
        }
    } while (n != 0);
}