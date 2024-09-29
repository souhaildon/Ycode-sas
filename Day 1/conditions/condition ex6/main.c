#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a;
    printf(" veuillez entrer le nombre:");
    scanf("%f",&a);
    if (a<0){
        printf("le nombre est negatif:");
    }
    else if (a>0){
        printf("le nombre est positive:");
    }
        else{
            printf("le nombre est null:");
            printf("\nle nombre est egal a zero :");
        }

    return 0;
}
