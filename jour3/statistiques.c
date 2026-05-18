#include <stdio.h>

int somme(int tab[]){
    int s = 0;
    int size = sizeof(&tab);
    for (int i = 0; i < size; i += 1){
        s += tab[i];
    }
    return s;
}

int moyenne(int tab[]){
    int s = 0;
    int size = sizeof(&tab);
    for (int i = 0; i < size; i += 1){
        s += tab[i];
    }
    return s/size;
}

int minimum(int tab[]){
    int min = tab[0];
    int rank = 0;
    int size = sizeof(&tab);
    for (int i = 1; i < size; i += 1){
        if (tab[i] < tab[rank]){
            min = tab[i];
            rank = i;
        }
    }
    return min;
}

int maximum(int tab[]){
    int max = tab[0];
    int rank = 0;
    int size = sizeof(&tab);
    for (int i = 1; i < size; i += 1){
        if (tab[i] > tab[rank]){
            max = tab[i];
            rank = i;
        }
    }
    return max;
}

int main(void){
    int tab[8] = {1,12,14,10,7,20,16,4};
    printf("la moyenne des notes est %d\n", moyenne(tab));
    printf("la sommes des notes est %d\n", somme(tab));
    printf("la note minimal est %d\n", minimum(tab));
    printf("la note max est %d\n", maximum(tab));
}