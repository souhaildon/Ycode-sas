#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ,i;
    i=1;
    printf("veuillez entrer le nombre:");
    scanf("%d",&n);

    while (n > 0) {
        printf("%d,",i);
        i=i+2;
        n = n - 1;


    }


    return 0;
}
