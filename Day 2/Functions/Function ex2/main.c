#include <stdio.h>
#include <stdlib.h>

void myfunction(int a,int b){
  int produit= a*b;
  printf("le produit %d*%d est : %.2d",a,b,produit);

}

int main()
{
    myfunction(5,8);

    return 0;
}
