#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define max_livre 500
//#define max_titre 500
//#define max_auteur 500

int main() {

    int max_livre=500;
    int max_titre=500;
    int max_auteur=500;

    char titre[max_livre][max_titre];
    char auteur[max_livre][max_auteur];
    float prix[max_livre];
    int quantite[max_livre];
    int compteur = 0;
    int choix;

    while (1) {
        printf("\t -- Menu--\n");
        printf("1. Ajouter un livre au stock.\n");
        printf("2. Afficher tous les livres disponibles.\n");
        printf("3. Rechercher un livre par son titre.\n");
        printf("4. Mettre a jour la quantite d'un livre.\n");
        printf("5. Supprimer un livre du stock.\n");
        printf("6. Afficher le nombre total de livres en stock.\n");
        printf("7. Quitter.\n");
        printf("Faites votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                if (compteur >= max_livre) {
                    printf("Le stock est plein !!\n");
                } else {
                    printf("Veuillez entrer le titre du livre: ");
                    scanf(" %[^\n]",titre[compteur]);
                    printf("Veuillez entrer l'auteur: ");
                    scanf(" %[^\n]",auteur[compteur]);
                    printf("Veuillez entrer le prix du livre: ");
                    scanf("%f", &prix[compteur]);
                    printf("Veuillez entrer la quantite du stock: ");
                    scanf("%d", &quantite[compteur]);
                    compteur++;
                }
                break;

            case 2:
                if (compteur == 0) {
                    printf("Pas de document !!\n");
                } else {
                    printf("Liste des livres disponibles:\n");
                    for (int i = 0; i < compteur; i++) {
                        printf("Titre: %s, Auteur: %s, Prix: %.2f DH, Quantite: %d\n",
                               titre[i], auteur[i], prix[i], quantite[i]);
                    }
                }
                break;

            case 3: {
                char title[max_titre];
                printf("Entrez le titre du livre que vous souhaitez: ");
                scanf(" %[^\n]", title);
                int trouver = 0;
                for (int i = 0; i < compteur; i++) {
                    if (strcmp(title, titre[i]) == 0) {
                        printf("Livre trouve:\nTitre: %s, Auteur: %s, Prix: %.2f DH, Quantite: %d\n",
                               titre[i], auteur[i], prix[i], quantite[i]);
                        trouver = 1;
                        break;
                    }
                }
                if (!trouver) {
                    printf("Livre est en rupture de stock\n");
                }
                break;
            }

            case 4: {
                char title[max_titre];
                printf("Entrez le titre du livre a mettre a jour: ");
                scanf(" %[^\n]", title);
                int entrer = 0;
                for (int i = 0; i < compteur; i++) {
                    if (strcmp(title, titre[i]) == 0) {
                        printf("Nouvelle quantite: ");
                        scanf("%d", &quantite[i]);
                        printf("Quantite mise a jour.\n");
                        entrer = 1;
                        break;
                    }
                }
                if (!entrer) {
                    printf("Livre non trouver  !!\n");
                }
                break;
            }

            case 5: {
                char title[max_titre];
                printf("Entrez le titre du livre a supprimer: ");
                scanf(" %[^\n]", title);
                int found = 0;
                for (int i = 0; i < compteur; i++) {
                    if (strcmp(title, titre[i]) == 0) {
                        for (int j = i; j < compteur - 1; j++) {
                            strcpy(titre[j], titre[j + 1]);
                            strcpy(auteur[j], auteur[j + 1]);
                            prix[j] = prix[j + 1];
                            quantite[j] = quantite[j + 1];
                        }
                        compteur--;
                        found = 1;
                        printf("Livre supprime.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Livre non trouve.\n");
                }
                break;
            }

            case 6:
                printf("Nombre total de livres en stock: %d\n", compteur);
                 int total_quantite = 0;
                for (int i = 0; i < compteur; i++) {
                    total_quantite += quantite[i];
                }
                printf("Quantite total de livres en stock: %d\n", total_quantite);
                break;

            case 7:
                printf("Au revoir!\n");
                exit(0);

            default:
                printf("Choix invalide: veuillez reessayer.\n");
        }
    }
    return 0;
}
