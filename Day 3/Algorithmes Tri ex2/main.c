#include <stdio.h>
#include <stdlib.h>


void triInsertion(int tab[],int taille){

for(int i=1;i<taille;i++){
    int tmp = tab[i];
    int j=i-1;
    while(tmp< tab[j] && j>=0){
        tab[j+1]=tab[j];
        j--;
    }
    tab[j+1]=tmp;
    }
}
void affichage(int tab[],int taille){
    for(int i =0;i<taille;i++){
            printf("[ %d ]",tab[i]);
    }
    printf("\n");
}


int main()
{
  int taille=10;
  int tab[]={10,6,9, 8, 2, 4, 3, 7, 1};
  printf(" Tableau initial est : \n");
  affichage(tab,taille);
  triInsertion(tab,taille);
  printf("tableau trie dans l\'ordre est:\n");
  affichage(tab,taille);


    return 0;
}
