#include <stdio.h>
#include <stdlib.h>

int main()
{
   int Moyen;
   printf("veuillez entrer votre moyen:");
   scanf("%d",&Moyen);
   if (Moyen<10)
    printf("vous etes recule");
    else if(Moyen>=10 && Moyen<12)
    printf("votre moyen est: passable");
    else if (Moyen>=12 && Moyen<14)
    printf("votre moyen est: Assez bien");
        else if (Moyen>=14 && Moyen<16)
    printf("votre moyen est: bien");
    else
    printf("votre moyen est: Tres bien ");


    return 0;
}
