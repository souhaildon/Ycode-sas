#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    int i;
    printf("veuillez entrer les valeurs du tableau:",n);
    scanf("%d",&n);
    int T[n];
    for(i=0;i<n;i++){
        printf("T[%d]:",i);
        scanf("%d",&T[i]);
    }
int multi=1;
    for(i=0;i<n;i++){
    multi=multi*T[i];
}
printf("la multiplication des valeurs du tableau sont:%.2d",multi);
    return 0;
}
