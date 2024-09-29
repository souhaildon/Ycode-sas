#include <stdio.h>
#include <stdlib.h>

int main()
{
    int annee ,Mois,Jours,Heures,Minutes,Secondes,A;
    printf("veuillez entrer le nombre d\'annee:",annee);
    scanf("%d",&annee);
    A=annee*365;
    Mois=A/30;
    Jours=A;
    Heures=A*24;
    Minutes=Heures*60;
    Secondes=Heures*60*60;
    printf("%dMois,%dJours,%dHeures %dMinutes %dSecondes",Mois,Jours,Heures,Minutes,Secondes);


    return 0;
}
