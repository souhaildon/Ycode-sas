#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float Xa,Xb,Ya,Yb,Za,Zb;
    float AB;
    printf("veuillez entrer X de a:");
    scanf("%f",&Xa);
    printf("veuillez entrer Y de a:");
    scanf("%f",&Ya);
    printf("veuillez entrer X de b:");
    scanf("%f",&Xb);
    printf("veuillez entrer Y de b:");
    scanf("%f",&Yb);
    printf("veuillez entrer Z de a:");
    scanf("%f",&Za);
    printf("veuillez entrer Z de b:");
    scanf("%f",&Zb);
    AB=sqrt(pow((Xb-Xa),2)+pow((Yb-Ya),2)+pow((Zb-Za),2));
    printf("la distance entre deux points dans un espace 3D est:%.2f",AB);
    return 0;
}
