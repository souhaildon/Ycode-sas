#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Progrqmme qui transforme la temperature du Celsius en Kelvin

    float C ,K;
    printf("veuillez entrer la temperature en Celsius:");
    scanf("%f",&C);
    K = C + 273.15;
    printf("la temperature en kelvin est :%.2f",K);


    return 0;
}
