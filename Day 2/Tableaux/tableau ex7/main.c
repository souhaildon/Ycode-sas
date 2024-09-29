#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
     int j,temp;
    printf("veuillez entrer les valeurs du tableau:",n);
    scanf("%d",&n);
    int T[n];
    for(i=0;i<n;i++){

        printf("T[%d]:",i);
        scanf("%d",&T[i]);
    }

    for(i=0;i<n-1;i++){
         for (j = 0; j < n - i - 1; j++) {
            if (T[j] > T[j + 1]) {
                temp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = temp;
            }        }

    }

    printf("Le tableau trie en ordre croissant :\n");
    for (i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
    return 0;
}
