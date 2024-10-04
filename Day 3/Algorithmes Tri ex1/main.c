#include <stdio.h>
#include <stdlib.h>


void tribulle(int tab[],int taille){
    for(int i=0;i<taille-1;i++)
        for(int j=0;j<taille-i-1;j++)
    if(tab[j]>tab[j+1]){
        echange(&tab[j],&tab[j+1]);
    }

}
void echange(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
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
    int tab[]={2,1,4,6,23 ,12 ,10, 7 ,3 ,19};
    printf("tableau initial :\n");
    affichage(tab,taille);
    tribulle(tab,taille);
    printf("tableau trie dans l\'ordre est: \n");
    affichage(tab,taille);

    return 0;
}
