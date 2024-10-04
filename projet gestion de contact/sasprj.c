#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Reservation {
    int id;
    char nom[20];
    char prenom[20];
    char telephone[11];
    int age;
    char statut[10];
    char date[11];
};

struct Reservation rdv_tab[500];
int cpt = 0;
int id = 1;

const char* rdv_statut[] = {"valide", "reporte", "annule", "traite"};
const int nombre_statuts = sizeof(rdv_statut) / sizeof(rdv_statut[0]);

int ver_date(const char *date) {
    int an, mois, jour;
    if (sscanf(date, "%d-%d-%d", &an, &mois, &jour) != 3) return 0;
    if (mois < 1 || mois > 12) return 0;
    if (jour < 1 || jour > 31) return 0;

    if (mois == 2) {
        if (jour > 28) return 0; // Ne prend pas en compte les années bissextiles
    } else if (mois == 4 || mois == 6 || mois == 9 || mois == 11) {
        if (jour > 30) return 0;
    }
    return 1;
}

int ver_n() {
    int var;
    while (1) {
        if (scanf("%d", &var) != 1 || var < 0) {
            printf("Entrée invalide. Veuillez entrer un nombre positif : ");
            while (getchar() != '\n');
        } else {
            while (getchar() != '\n');
            return var;
        }
    }
}

int valide_Tele(const char* phone) {
    if (strlen(phone) != 10) return 0;
    for (int i = 0; i < 10; i++) {
        if (!isdigit(phone[i])) return 0;
    }
    return 1;
}

int ver_Phone(const char* phone) {
    for (int i = 0; i < cpt; i++) {
        if (strcmp(rdv_tab[i].telephone, phone) == 0) {
            return 0; // Numéro de téléphone déjà utilisé
        }
    }
    return 1; // Numéro de téléphone unique
}

void ajouter_reserv(char nom[20], char prenom[20], char telephone[11], int age, char statut[10], char date[11]) {
    if (!ver_Phone(telephone)) {
        printf("Le numero de telephone %s est deja utilise.\n", telephone);
        return; // Sortir en cas de numéro déjà existant
    }

    if (cpt < 500) {
        rdv_tab[cpt].id = id++;

        strcpy(rdv_tab[cpt].nom, nom);
        strcpy(rdv_tab[cpt].prenom, prenom);
        strcpy(rdv_tab[cpt].telephone, telephone);
        rdv_tab[cpt].age = age;
        strcpy(rdv_tab[cpt].statut, statut);
        strcpy(rdv_tab[cpt].date, date);
        cpt++;
    } else {
        printf("La liste de reservation est pleine!\n");
    }
}

void afficher_rdv_tab() {
    if (cpt == 0) {
        printf("Pas de reservation pour ce moment.\n");
        return;
    }
    printf("+----+----------------+----------------+---------------+-----+------------+------------+\n");
    printf("| ID |       Nom      |     Prénom     |   Téléphone   | Âge |   Statut   |   Date     |\n");
    printf("+----+----------------+----------------+---------------+-----+------------+------------+\n");
    for (int i = 0; i < cpt; i++) {
        printf("| %2d | %-14s | %-14s | %-13s | %3d | %-10s | %s |\n",
               rdv_tab[i].id, rdv_tab[i].nom, rdv_tab[i].prenom,
               rdv_tab[i].telephone, rdv_tab[i].age, rdv_tab[i].statut,
               rdv_tab[i].date);
    }
    printf("+----+----------------+----------------+---------------+-----+------------+------------+\n");
}

void rechercher_par_ref(int id, struct Reservation* reserve) {
    for (int i = 0; i < cpt; i++) {
        if (rdv_tab[i].id == id) {
            *reserve = rdv_tab[i];
            return; // Réservation trouvée
        }
    }
    reserve->id = -1; // Indique que la réservation n'a pas été trouvée
}

void modifier_reservation(int id) {
    struct Reservation rendvous;
    rechercher_par_ref(id, &rendvous);
    if (rendvous.id != -1) {
        printf("Modifier la réservation (ID: %d)\n", rendvous.id);
        printf("Nouveau nom (actuel: %s): ", rendvous.nom);
        scanf(" %[^\n]s", rendvous.nom);

        printf("Nouveau prénom (actuel: %s): ", rendvous.prenom);
        scanf(" %[^\n]s", rendvous.prenom);

        char new_phone[15];
        do {
            printf("Nouveau telephone (actuel: %s): ", rendvous.telephone);
            scanf(" %[^\n]s", new_phone);
        } while (!valide_Tele(new_phone));
        strcpy(rendvous.telephone, new_phone);

        printf("Nouvel âge (actuel: %d): ", rendvous.age);
        rendvous.age = ver_n();

        printf("Choisissez un statut:\n");
        for (int i = 0; i < nombre_statuts; i++) {
            printf("%d. %s\n", i + 1, rdv_statut[i]);
        }
        int choix_statut;
        do {
            printf("Entrez le numéro du statut choisi: ");
            choix_statut = ver_n();
        } while (choix_statut < 1 || choix_statut > nombre_statuts);
        strcpy(rendvous.statut, rdv_statut[choix_statut - 1]);

        printf("Nouvelle date (actuel: %s): ", rendvous.date);
        char new_date[11];
        while (1) {
            scanf(" %10s", new_date);
            if (ver_date(new_date)) {
                strcpy(rendvous.date, new_date);
                break;
            } else {
                printf("Date invalide. Veuillez entrer une date valide (YYYY-MM-DD): ");
            }
        }

        // Mettre à jour la réservation dans le tableau
        for (int i = 0; i < cpt; i++) {
            if (rdv_tab[i].id == id) {
                rdv_tab[i] = rendvous;
                break;
            }
        }
    } else {
        printf("Réservation non trouvée.\n");
    }
}

void supprimer_reservation(int id) {
    for (int i = 0; i < cpt; i++) {
        if (rdv_tab[i].id == id) {
            for (int j = i; j < cpt - 1; j++) {
                rdv_tab[j] = rdv_tab[j + 1];
            }
            cpt--;
            printf("Réservation supprimée avec succès.\n");
            return;
        }
    }
    printf("Réservation non trouvée.\n");
}

void afficher_statistiques(int choix) {
    int total_age = 0;
    int age_cpt[3] = {0}; // 0-18, 19-35, 36+
    int statut_cpt[nombre_statuts];
    memset(statut_cpt, 0, sizeof(statut_cpt));

    for (int i = 0; i < cpt; i++) {
        total_age += rdv_tab[i].age;
        if (rdv_tab[i].age <= 18) age_cpt[0]++;
        else if (rdv_tab[i].age <= 35) age_cpt[1]++;
        else age_cpt[2]++;

        for (int j = 0; j < nombre_statuts; j++) {
            if (strcmp(rdv_tab[i].statut, rdv_statut[j]) == 0) {
                statut_cpt[j]++;
            }
        }
    }

    switch (choix) {
        case 1:
            printf("Moyenne d'âge: %.2f\n", (cpt > 0 ? (float)total_age / cpt : 0));
            break;
        case 2:
            printf("Nombre de patients par tranche d'âge:\n");
            printf("0-18 ans: %d\n", age_cpt[0]);
            printf("19-35 ans: %d\n", age_cpt[1]);
            printf("36 ans et plus: %d\n", age_cpt[2]);
            break;
        case 3:
            printf("Nombre total de réservations par statut:\n");
            for (int j = 0; j < nombre_statuts; j++) {
                printf("%s: %d\n", rdv_statut[j], statut_cpt[j]);
            }
            break;
        default:
            printf("Choix invalide.\n");
    }
}

void insertion_defaut() {
    ajouter_reserv("lasfar", "Souhail", "0708878867", 24, "valide", "2024-10-01");
    ajouter_reserv("Abdi", "AB", "0612345678", 30, "annule", "2024-10-02");
    ajouter_reserv("Hamdi", "Salma", "0623456789", 40, "traitee", "2024-10-03");
    ajouter_reserv("Elbarry", "Anouar", "0667890123", 50, "reportee", "2024-10-04");
    ajouter_reserv("Labit", "Ayoub", "0734567890", 15, "valide", "2024-10-05");
    ajouter_reserv("Allala", "Belal", "0611223344", 20, "annulee", "2024-10-06");
    ajouter_reserv("Maizou", "Nabil", "0611443322", 22, "traitee", "2024-10-07");
    ajouter_reserv("Pianiste", "Amine", "0712113344", 35, "reportee", "2024-10-08");
    ajouter_reserv("Hamidden", "Moad", "0612340987", 28, "valide", "2024-10-09");
    ajouter_reserv("Brahimi", "Hassan", "0680907060", 33, "annulee", "2024-10-10");
}

void afficher_details_reservation(int id) {
    struct Reservation reserve;
    rechercher_par_ref(id, &reserve);
    if (reserve.id != -1) {
        printf("+----+----------------+----------------+---------------+-----+------------+------------+\n");
        printf("| ID |       Nom      |     Prénom     |   Téléphone   | Âge |   Statut   |   Date     |\n");
        printf("+----+----------------+----------------+---------------+-----+------------+------------+\n");
        printf("| %2d | %-14s | %-14s | %-13s | %3d | %-10s | %s |\n",
               reserve.id, reserve.nom, reserve.prenom,
               reserve.telephone, reserve.age, reserve.statut,
               reserve.date);
        printf("+----+----------------+----------------+---------------+-----+------------+------------+\n");
    } else {
        printf("Réservation introuvable.\n");
    }
}

void tri_reservation_par_nom(int ordre) {
    for (int i = 0; i < cpt - 1; i++) {
        for (int j = 0; j < cpt - i - 1; j++) {
            int comparison = strcmp(rdv_tab[j].nom, rdv_tab[j + 1].nom);
            if ((ordre == 1 && comparison > 0) || (ordre == 2 && comparison < 0)) {
                struct Reservation temp = rdv_tab[j];
                rdv_tab[j] = rdv_tab[j + 1];
                rdv_tab[j + 1] = temp;
            }
        }
    }
}

void tri_reservation_par_statut(int ordre) {
    for (int i = 0; i < cpt - 1; i++) {
        for (int j = 0; j < cpt - i - 1; j++) {
            int comparison = strcmp(rdv_tab[j].statut, rdv_tab[j + 1].statut);
            if ((ordre == 1 && comparison > 0) || (ordre == 2 && comparison < 0)) {
                struct Reservation temp = rdv_tab[j];
                rdv_tab[j] = rdv_tab[j + 1];
                rdv_tab[j + 1] = temp;
            }
        }
    }
}

void tri_reservation_par_date(int ordre) {
    for (int i = 0; i < cpt - 1; i++) {
        for (int j = 0; j < cpt - i - 1; j++) {
            int comparison = strcmp(rdv_tab[j].date, rdv_tab[j + 1].date);
            if ((ordre == 1 && comparison > 0) || (ordre == 2 && comparison < 0)) {
                struct Reservation temp = rdv_tab[j];
                rdv_tab[j] = rdv_tab[j + 1];
                rdv_tab[j + 1] = temp;
            }
        }
    }
}

int main() {
    insertion_defaut();

    int choix;
    do {
        printf("\n  =================* Menu *================\n");
        printf("1. Ajouter une reservation\n");
        printf("2. Modifier une reservation\n");
        printf("3. Supprimer une reservation\n");
        printf("4. Afficher les reservations\n");
        printf("5. Consulter les details d'une reservation\n");
        printf("6. Statistiques\n");
        printf("7. Trier les reservations\n");
        printf("8. Quitter\n\n");
        printf("Choisissez une option: ");
        choix = ver_n();

        switch (choix) {
            case 1: {
                char nom[20], prenom[20], telephone[11], statut[10], date[11];
                printf("Nom: "); scanf(" %[^\n]s", nom);
                printf("Prénom: "); scanf(" %[^\n]s", prenom);

                do {
                    printf("Téléphone (10 chiffres): ");
                    scanf(" %[^\n]s", telephone);
                } while (!valide_Tele(telephone));

                printf("Âge: ");
                int age = ver_n();

                printf("Choisissez un statut:\n");
                for (int i = 0; i < nombre_statuts; i++) {
                    printf("%d. %s\n", i + 1, rdv_statut[i]);
                }
                int choix_statut;
                do {
                    printf("Entrez le numéro du statut choisi: ");
                    choix_statut = ver_n();
                } while (choix_statut < 1 || choix_statut > nombre_statuts);
                strcpy(statut, rdv_statut[choix_statut - 1]);

                printf("Date (YYYY-MM-DD): ");
                while (1) {
                    scanf(" %10s", date);
                    if (ver_date(date)) {
                        break;
                    } else {
                        printf("Date invalide. Veuillez entrer une date valide (YYYY-MM-DD): ");
                    }
                }
                ajouter_reserv(nom, prenom, telephone, age, statut, date);
                break;
            }
            case 2: {
                int id;
                printf("Entrer la référence unique (ID): ");
                id = ver_n();
                modifier_reservation(id);
                break;
            }
            case 3: {
                int id;
                printf("Entrer la référence unique (ID) à supprimer: ");
                id = ver_n();
                supprimer_reservation(id);
                break;
            }
            case 4:
                afficher_rdv_tab();
                break;

            case 5: {
                int id;
                printf("Entrer la référence unique (ID) pour consulter les détails: ");
                id = ver_n();
                afficher_details_reservation(id);
                break;
            }

            case 6: {
                printf("Choisissez le type de statistique à afficher:\n");
                printf("1. Moyenne d'âge\n");
                printf("2. Nombre de patients par tranche d'âge\n");
                printf("3. Nombre total de réservations par statut\n");
                int choix_statistique = ver_n();
                afficher_statistiques(choix_statistique);
                break;
            }

            case 7: {
                printf("Choisissez un des tri:\n");
                printf("1. Par nom\n");
                printf("2. Par statut\n");
                printf("3. Par date\n");
                int tri = ver_n();

                printf("Choisissez un ordre de tri:\n");
                printf("1. Ascendant\n");
                printf("2. Descendant\n");
                int ord = ver_n(); // ord: ordre

                switch (tri) {
                    case 1:
                        tri_reservation_par_nom(ord);
                        printf("Réservations triées par nom.\n");
                        break;
                    case 2:
                        tri_reservation_par_statut(ord);
                        printf("Réservations triées par statut.\n");
                        break;
                    case 3:
                        tri_reservation_par_date(ord);
                        printf("Réservations triées par date.\n");
                        break;
                    default:
                        printf("Tri invalide.\n");
                }
                break;
            }

            case 8:
                printf("Merci. Au revoir!\n");
                break;

            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 8);

    return 0;
}

