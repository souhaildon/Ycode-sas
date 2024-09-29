#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c ;
    printf("veuillez entre l\'alphabet:");
    scanf("%c",&c);
    if(c>=65 && c<=90){
        printf("la lettre est majuscule:");}
        else{
            printf("Non");
        }

    return 0;
}
