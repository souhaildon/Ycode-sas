#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    float a,b,c,x,x1,x2,delta;

    printf("veuillez entrer a , b , c: ",a,b,c);
    scanf("%f %f %f",&a,&b,&c);
    delta= pow((b),2)-(4*a*c);
    if (delta<0){
        printf(" l'equation na pas de solution:");}
    else if(delta==0){
        x=(-b)/2*a;
        printf("la solution est:%.2f",x);
    }
        else{
            x1=(-b-sqrt(delta))/(2*a);
            x2=(-b+sqrt(delta))/(2*a);
            printf("la solution est x1= %.2f",x1);
            printf("\nla solution est x2= %.2f",x2);
        }





    return 0;
}
