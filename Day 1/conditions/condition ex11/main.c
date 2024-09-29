#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    char jours[7][10] = {"lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche"};
    srand(time(0));
    int jouraleatoire = rand()%7;
    printf("Jour aleatoire : %s\n", jours[jouraleatoire-1]);
    return 0;
}
