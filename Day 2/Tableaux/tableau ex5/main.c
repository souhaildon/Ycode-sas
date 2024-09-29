#include <stdio.h>
#include <stdlib.h>

int main()
{
     int nb_element;
    printf("veuillez entrer le nombre d\'element:",nb_element);
    scanf("%d",&nb_element);

    int elm_tableau[nb_element];
    for(int i=0;i<nb_element;i++){
        printf("entrer element :");
        scanf("%d",&elm_tableau[i]);
    }
    int plus_petit=elm_tableau[0];
    for(int i=0;i<nb_element;i++){

        if(plus_petit>elm_tableau[i]){
            plus_petit=elm_tableau[i];
        }
    }

printf("le plus petit nombre est :%d",plus_petit);

    return 0;
}
