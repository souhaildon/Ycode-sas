#include <stdio.h>
#include <stdlib.h>




int myfunction(int a,int b){
if (a>b){
   return(a);
    }
    return(b);
}

int main()
{
    int a=4, b=9;
    printf("le maximum est : %d",myfunction(4,9));
    return 0;
}
