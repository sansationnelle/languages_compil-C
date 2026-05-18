#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jouer(int range){
    int r = rand() % range + 1;
    int found = 0;
    int choosen = 0;
    int tour = 1;
    while (found == 0){
        printf("choississez un nombre\n");
        scanf("%d", &choosen);
        printf("choosen number %d\n", choosen);
        if (choosen == r){
            printf("Congratulations, you win, the number was %d,\nYou've found it in %d turns\n", r, tour);
            found = 1;
        } else if (choosen > r){
            printf("Wrong! the number is below yours\n");
            tour += 1;
        } else {
            printf("Wrong! the number is greater than yours\n");
            tour += 1;
        }
        if (tour >= 100){
            printf("échec, vous n'avez pas trouver le nombre %d\n", r);
            found = 1;
        }
    }
    return tour;
}

int main(void){
    srand(time(NULL));
    jouer(1000);
}