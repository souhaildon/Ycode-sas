#include <stdio.h>
#include <stdlib.h>


void echange(int *a, int *b){
int tmp=*a;
*a=*b;
*b=tmp;
}

void Triselection(int tab[],int taille){
    for(int i=0;i<taille-1;i++){
        int min=i;
        for(int j=i+1;j<taille;j++){
            if(tab[j]<tab[min]){
                min=j;

            }
        }
         echange(&tab[min],&tab[i]);

    }
}


void affichage(int tab[],int taille){
    for(int i=0;i<taille;i++){
        printf("[%d ]",tab[i]);
    }
    printf("\n");
}

int main()
{
    int taille=10;
    int tab[]={ 12, 2, 3, 5, 4, 9, 7, 8, 10,11 };
    printf("tableau initial : \n");
    affichage(tab,taille);
    Triselection(tab,taille);
    printf("tableau tri en ordre:\n");
    affichage(tab,taille);


    return 0;
}
