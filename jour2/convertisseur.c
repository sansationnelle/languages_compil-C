#include <stdio.h>

int main(void){
    int option;
    double yetanother;
    printf("1 : Kilometres → Miles\n2 : Kilogrammes → Livres (pounds)\n3 : Degres Celsius → Fahrenheit\n4: Quitter\n");
    scanf("%d", &option);
    if (option == 1){
        printf("inserez vos kilometre(s): ");
        scanf("%lf", &yetanother);
        printf("%lf kilomêtre(s) vaut %.2f mile(s)\n", yetanother, yetanother*0.6214f);
    } else if (option == 2){
        printf("inserez vos kilogramme(s): ");
        scanf("%lf", &yetanother);
        printf("%lf kilogramme(s) vaut %.2f livre(s)\n", yetanother, yetanother*2.20462f);
    } else if (option == 3){
        printf("inserez vos °C: ");
        scanf("%lf", &yetanother);
        printf("%lf°C vaut %.2f°F\n", yetanother, (yetanother * 9/5) + 32);
    } else if (option == 4){
        printf("Au revoir !\n");
        return 0;
    } else {
        printf("Mauvaise option inséré\n");
        return 1;
    }
    return 0;
}