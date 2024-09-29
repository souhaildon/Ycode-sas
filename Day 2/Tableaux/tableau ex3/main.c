#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Entrez le nombre d\'elements du tableau: ");
    scanf("%d", &n);

    int tableau[n];
    int somme=0;
    for(int i=0;i<n;i++){
        printf("veuillez entrer les elements:",i+1);
        scanf("%d",&tableau[i]);

    }
    for(int i=0;i<n;i++){
        somme+=tableau[i];
    }
printf("la somme est : %d",somme);


    return 0;
}
