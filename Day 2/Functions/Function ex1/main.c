#include <stdio.h>
#include <stdlib.h>


void myfunction(int x,int y){
  int somme= x+y;
  printf("le somme %d+%d est : %.2d",x,y,somme);

}

int main()
{
    myfunction(5,8);

    return 0;
}
