#include <stdio.h>

int minimum(int a, int b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}
int maximum(int a, int b){
    if (a > b){
        return a;
    } else {
        return b;
    }
}
int valeur_absolue(int x){
    if (x >= 0){
        return x;
    } else {
        return x * -1;
    }
}
int est_pair(int x){
    if (x%2 == 0){
        return 1;
    } else {
        return 0;
    }
}

long factorielle(int n){
    //cela semblai plus aisée de le faire en récursif
    if (n == 0){
        return 1;
    } else if (n == 1){
        return 1;
    } else {
        return n * factorielle(n-1);
    }
}
int main(void){
    int a = 4;
    int b = 99;
    printf("Le plus petit est: %d\n", minimum(a,b));
    printf("Le plus grand est: %d\n", maximum(a,b));
    printf("La valeur absolue de %d est: %d\n", -1 ,valeur_absolue(-1));
    printf("Le nombre %d est paire: %s\n", 2, est_pair(2) ? "oui" : "non");
    printf("Le nombre %d est paire: %s\n", 1, est_pair(1) ? "oui" : "non");
    printf("La factorielle de %d est: %ld\n", a, factorielle(a));
    printf("La factorielle de %d est: %ld\n", 12, factorielle(12));
}