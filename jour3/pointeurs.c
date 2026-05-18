#include <stdio.h>

void min_max(int tab[], int n, int *pmin, int *pmax){
    for (int i = 0; i < n; i += 1){
        if (tab[i] > *pmax){
            *pmax = tab[i];
        } else if (tab[i] < *pmin){
            *pmin = tab[i];
        }
    }
}

double moyenne(int tab[], int n){
    double s = 0;
    for (int i = 0; i < n; i += 1){
        s += tab[i];
    }
    return s/n;
}

int main(void){
    int tab[8] = {3,12,14,2,7,20,16,4};
    int min = tab[0];
    int max = tab[0];
    min_max(tab, 8, &min, &max);
    double moy = moyenne(tab, 8);
    printf("Le minimum est %d\nLe maximum est %d\n", min, max);
    printf("La moyenne des notes est %.2f\n", moy);
}