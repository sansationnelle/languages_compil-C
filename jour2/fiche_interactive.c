#include <stdio.h>

int main(void){
    char prenom[21];
    int age;
    float note;
    printf("donnez vos info pour le gouvernement\nPrenom: ");
    scanf("%20s", prenom);
    printf("age: ");
    scanf("%d", &age);
    printf("notes: ");
    scanf("%f", &note);
    printf("--------\nprenom: %s\nAge: %d\nnotes: %.2f\n--------", prenom, age, note);
    return 0;
}