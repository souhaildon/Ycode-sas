#include <stdio.h>
#include <stdlib.h>
#include<math.h>


int main()
{
        int a , b,c,d;

        printf("veuillez entrer la valeur de a:");
        scanf("%d",&a);
        printf("veuillez entrer la valeur de b:");
        scanf("%d",&b);
        c=a+b;
        d=c*3;
        if(a!= b){
 printf("la somme est: %.2d",c);
        }
        else{
printf("\nla somme est:%.2d",d);
        }
        return 0;
}
