#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N ,i;
    long long somme=0;
    printf("veuillez entrer le nombre:");
    scanf("%d",&N);
    if(N<0){
    printf ("\n veuillez entrer un nombre positif:");
    }
    else{
        for(i=1;i<=N;i++){
        somme +=i;}
        printf("la somme de %d est : %llu",N,somme);

    }
    return 0;
}
