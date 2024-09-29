#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ms ,kmh;

    printf("veuillez entrer la vitesse en km/h:");
    scanf("%d",&kmh);
    ms=kmh*0.27778;
    printf("la vitesse en m/s est: %d",ms);



    return 0;
}
