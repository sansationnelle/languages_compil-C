#include <stdio.h>
#include <stdlib.h>

int tab(void){
    int n;
    printf("taille du tab\n");
    scanf("%d", &n);
    int *list = (int *) malloc (n * sizeof(int));
    int total = 0;
    if (list == NULL) {
        printf("Echec d'allocation\n");
        return 1;
    }
    int val;
    for (int i = 0; i < n; i+= 1){
        printf("choissisez la valeur %d\n", i+1);
        scanf("%d", &val);
        list[i] = val;
        total += val;
    }
    int len = 0;
    for (int i = 0; i < n; i+= 1){
        printf("Valeur %d: %d\n", i+1, list[i]);
        len += 1;
    }
    printf("total des valeurs: %d\n", total);
    printf("moyenne des valeurs: %d\n", total/len);
    free(list);
    list = NULL;
    return 0;
}

int main(void){
    tab();
}