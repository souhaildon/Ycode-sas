#include <stdio.h>
#include <stdlib.h>

int main()
{
   char caractere;
   printf("entrer votre caractere pour le verification:");
   scanf("%c",&caractere);
   switch (caractere){
    case 'a':printf("Voyelle");
    break;
    case 'e':printf("Voyelle");
    break;
    case 'i':printf("Voyelle");
    break;
    case 'o':printf("Voyelle");
    break;
    case 'u':printf("Voyelle");
    break;
    case 'y':printf("Voyelle");
    break;
    default:printf("Non");
    break;
   }


    return 0;
}
