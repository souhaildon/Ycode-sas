#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //Progrqmme qui transforme le Km en Yards



    int Km , Yards;

    printf("veuillez entrer la distance en kilometre:");
    scanf("%d",&Km);
    Yards= Km*1093.61;
    printf(" la distance en yards est :%.2d",Yards);

    return 0;

}
