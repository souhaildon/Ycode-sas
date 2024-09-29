#include <stdio.h>
#include <stdlib.h>


int factorialle(int n){
int fact=1 ;
for(int i=1;i<=n;i++){
    fact=fact*i;}
    printf("la factorielle de %d est %d",n,fact);
    return (fact);

}


int main()
{
    factorialle(6);

    return 0;
}
