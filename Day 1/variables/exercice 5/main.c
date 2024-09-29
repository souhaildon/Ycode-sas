#include <stdio.h>
#include <stdlib.h>

int main()
{
    int C;
    printf("veuillez entrer la temperature en Celsius :");
    scanf("%d",&C);
    if(C<0)
        printf("l'eau est: solide");
    else if(C<100)
        printf("l'eau est : liquide");
    else
        printf("l'eau est : gaz");

    return 0;
}
