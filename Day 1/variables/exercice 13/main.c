#include <stdio.h>
#include <stdlib.h>

int main()
{
    int decimal;
    int n;
    int binNums[99];
    printf("veuillez entrer le numero : ");
    scanf("\n");
    scanf("%d",&n);
    decimal = n;
    int i = 0;
    while (n > 0) {
        binNums[i] = n % 2;
        n = n / 2;
        i++;
    }
    printf("\nvaleur Binaire :\n");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binNums[j]);
        }
    printf("\nValeur hexadecimal :\n%X",decimal);
    return 0;
}
