#include <stdio.h>
#include <stdlib.h>

int main()
{
    float l ,L,P,S;
    printf("veuillez entrer la largeur:",l);
    scanf("%f",&l);
    printf("veuillez entrer la longueur:",L);
    scanf("%f",&L);
    P=(L+l)*2;
    S=l*L;
    printf("le perimetre est:%.2f",P);
    printf("la surface est:%.2f",S);

    return 0;
}
