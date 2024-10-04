#include <stdio.h>
#include <stdlib.h>



void triRapide(int tab,int bas , int haut){

    if(bas<haut){
        int pi=partition(tab,bas,haut);
        triRapide(tab,bas,pi-1);
        triRapide(tab,pi+1,haut);
    }
}

void echange(int *a, int *b){
int tmp=*a;
*a=*b;
*b=tmp;
}
int partition(int tab[],int bas, int haut){
    int pvt=tab[haut];
    int i=(bas - 1);
    for(int j=bas;j<haut;j++){
        if(tab[j] <= pvt){
            i++;
            echange(&tab[i],&tab[j]);
        }
    }
    echange(&tab[i+1],&tab[haut]);
    return (i+1);

}
void affichage(int tab[],int taille){
for(int i=0;i<taille;i++){
    printf(" [%d ]",tab[i]);
}
    printf("\n");
}




int main()
{
  int taille=10 ;
  int tab[]={10, 12, 9, 7, 8, 3, 1, 5,4,2};
  printf("tableau initial : \n");
  affichage(tab,taille);
  triRapide(tab,0,taille-1);
  printf("tableau tri dans l\'ordre :\n");
  affichage(tab,taille);
    return 0;
}
