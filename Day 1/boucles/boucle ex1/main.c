#include <stdio.h>
#include <stdlib.h>

int main()
{
   int N,i;
   printf("veuillez entrer un nombre:");
   scanf("%d",&N);
   while(N<0 || N>10){
        printf("veuillez entrer un nombre:");
        scanf("%d",N);
        i=0;
        }
        while(i<=10){
            printf("%d * %d=%d\n",N,i,N*i);
            i++;




   }
    return 0;
}
