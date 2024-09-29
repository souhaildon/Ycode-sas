#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
int operation;


    do{

    printf("Choisissez une operation:\n");

    printf("-1- Addition:\n");
    printf("-2-Soustraction :\n");
    printf("-3-Multiplication:\n");
    printf("-4-Division:\n");
    printf("-5-Moyenne:\n");
    printf("-6-Valeur absolue:\n");
    printf("-7-Exponentiation:\n");
    printf("-8-Racine carree:\n");
    printf("-0- Quitter le programme:\n");


    printf("Entrez votre choix: ");
    scanf("%d", &operation);

    switch (operation){
        case 1:{
            int n;
                printf("Combien de nombres voulez-vous additionner ? ");
                scanf("%d", &n);
                double somme = 0;
                for (int i = 0; i < n; i++) {
                    double nombre;
                    printf("Entrez le nombre %d: ", i+1);
                    scanf("%lf", &nombre);
                    somme += nombre;
                    }

                printf("La somme est: %.2f\n", somme);
                break;
                    }
        case 2:
             {
                double a, b;
                printf("Entrez deux nombres: ");
                scanf("%lf %lf", &a, &b);
                printf("La différence est: %.2f\n", a - b);
                break;
            }

        case 3:{
            int n;
                printf("Combien de nombres voulez-vous multiplier ? ");
                scanf("%d", &n);
                double nbr = 1;
                for (int i = 0; i < n; i++) {
                    double nombre;
                    printf("Entrez le nombre %d: ", i + 1);
                    scanf("%lf", &nombre);
                    nbr *= nombre;
                }
                printf("Le produit est: %.2f\n", nbr);
                break;
            }


        case 4:
            {
                double a, b;
                printf("Entrez deux nombres: ");
                scanf("%lf %lf", &a, &b);
                if (b != 0) {
                    printf("Le résultat est: %.2f\n", a / b);
                } else {
                    printf("Erreur : Division par zéro.\n");
                }
                break;
            }

        case 5:{
                int n;
                printf("Combien de nombres voulez-vous entrer ? ");
                scanf("%d", &n);
                double somme = 0;
                for (int i = 0; i < n; i++) {
                    double nombre;
                    printf("Entrez le nombre %d: ", i + 1);
                    scanf("%lf", &nombre);
                    somme += nombre;
                }
                printf("La moyenne est: %.2f\n", somme / n);
                break;
            }

        case 6:
            {
                double nombre;
                printf("Entrez un nombre: ");
                scanf("%lf", &nombre);
                printf("La valeur absolue est: %.2f\n", fabs(nombre));
                break;
            }

        case 7:{
            double n;
                int p;
                printf("Entrez la nombre et l\'exposant: ");
                scanf("%lf %d", &n, &p);
                printf("Le résultat est: %.2f\n", pow(n, p));
                break;
        }

        case 8: {
            double nomb;
                printf("Entrez un nombre positif: ");
                scanf("%lf", &nomb);
                if (nomb >= 0) {
                    printf("La racine carrée est: %.2f\n", sqrt(nomb));
                } else {
                    printf("Erreur : Le nombre n\'est pas positif.\n");
                }
                break;
            }
            case 0:{
                exit(1);
            }
        default:
            printf(" choix invalide !!!");
                }
    }
                while(operation !=8);

    return 0;
}

