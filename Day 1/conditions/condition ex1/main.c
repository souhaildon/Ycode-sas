#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    printf("Veuillez saisir un nombre:");
    scanf("%d",&N);
    if(N%2==1)
    printf("le nombre %d est impair");
    else
    printf("le nombre %d est pair");

    return 0;
}
