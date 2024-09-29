#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nbr;
    float f , i;
    printf("veuillez entrer un nombre:");
    scanf("%d",&nbr);
    if (nbr<0){
    printf("veuillez entrer un nombre positif.");
    }
    else if (nbr==0){
        printf("le factorielle est = 1");}
    else
        f=1;
    for(i=1;i<=nbr;i++)
        f=f*i;
    printf("le factorielle %d est:%.2f",nbr,f);

    return 0;
}
