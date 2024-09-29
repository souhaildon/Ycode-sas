#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c ,M;
    printf("veuillez entrer la valeur de a:");
    scanf("%f",&a);
    printf("veuillez entrer la valeur de b:");
    scanf("%f",&b);
    printf("veuillez entrer la valeur de c:");
    scanf("%f",&c);
    M=cbrt(a*b*c);
    printf("Moyenne géométrique est:%.2f",M);
    return 0;
}
