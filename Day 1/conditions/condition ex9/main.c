#include <stdio.h>
#include <stdlib.h>

int main()
{
    int caractere;
    printf("veuillez entrer votre caractere:");
    scanf("%c",&caractere);
    if (caractere>=65 && caractere<=90){
        printf(" s\'agit d\'un alphabet majuscule:");}
    else if (caractere>=97 && caractere<=122){
        printf("s\'agit d\'alphabet miniscule");}
    else
        printf("Non");

    return 0;
}
