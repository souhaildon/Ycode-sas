#include <stdio.h>
#include <stdlib.h>

int main()
{
int n,N1,N2,N3,N4;
printf("donner un nombre de quatre chiffres:");
scanf("%d",&n);
    N1=n%10;
    N2=(n/10)%10;
    N3=(n/100)%10;
    N4=n/1000;

    printf("l'inverse est:");
    printf("%d",N1);
    printf("%d",N2);
    printf("%d",N3);
    printf("%d",N4);

    return 0;
}

