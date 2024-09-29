#include <stdio.h>
#include <stdlib.h>

int main()
{
   float N1, N2, N3,M;
   printf("vueillez entrer le nombre 1:");
   scanf("%f",&N1);
    printf("vueillez entrer le nombre 2:");
    scanf("%f",&N2);
     printf("vueillez entrer le nombre 3:");
     scanf("%f",&N3);
     M=(N1*2+N2*3+N3*5)/(2+3+5);
     printf("le moyen est:%.2f",M);

    return 0;
}
