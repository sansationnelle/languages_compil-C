#include <stdio.h>
#include <string.h>
int main(void){
    int age = 19;
    float taille = 1.69f;
    char nom[] = "Chara";
    char al = *nom;
    printf("+-------------------------------+\n| FICHE D'IDENTITE              |\n+-------------------------------+\n");
    printf("| Prenom: %s                 |\n", nom);
    printf("| Age: %d ans                   |\n", age);
    printf("| Taille: %.2f m                |\n", taille);
    printf("| Initiale: %c                   |\n", al);
    printf("+-------------------------------+\n| Code de sortie : 0 (succes)   |\n+-------------------------------+\n");
    return 1;
}