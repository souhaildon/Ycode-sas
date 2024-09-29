#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    float r , V ;
    const Pi=3.14;
    printf("veuillez entrer la valeur du rayon:");
    scanf("%f",&r);
    V=(4/3)*Pi*pow((r),3);
    printf("le volume du sphere est:%.2f",V);



    return 0;
}
