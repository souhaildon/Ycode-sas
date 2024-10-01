#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#define max_contact 100
#define max_nom 100
#define max_phone_number 11
#define max_email 100

typedef struct {
    int id;
    char nom[max_contact];
    char phone[11];
    char email[max_email];
} contact;

contact contacts[max_contact];
int contact_n = 0;



int est_numero_valide(const char *phone) {
    if (strlen(phone) != 10) {
        return 0;
    }

    if (phone[0] != '0' || (phone[1] != '6' && phone[1] != '7')) {
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        if (!isdigit(phone[i])) {
            return 0;
        }
    }

    return 1;
}

void ajouter_contact() {
    if (contact_n >= max_contact) {
        printf("La liste est pleine !\n");
        return;
    }

    contact new_contact;


    printf("Entrer le nom du contact: \n");
    fgets(new_contact.nom, max_contact, stdin);
    new_contact.nom[strcspn(new_contact.nom, "\n")] = 0;

    printf("Entrer l'adresse email du contact: \n");
    fgets(new_contact.email, max_email, stdin);
    new_contact.email[strcspn(new_contact.email, "\n")] = 0;

    char phone[max_phone_number];
    while (1) {
        printf("Entrez un numero de telephone (commence par 06 ou 07) : ");
        fgets(phone,max_phone_number,stdin);
        phone[strcspn(phone, "\n")] = 0;

        if (est_numero_valide(phone)) {
            strncpy(new_contact.phone, phone, max_phone_number);
            printf("Le numero %s est valide.\n", new_contact.phone);
            break; // Exit loop if valid
        } else {
            printf("Le numéro %s n'est pas valide. Reessayez.\n", phone);
        }
    }

    contacts[contact_n++] = new_contact;
    printf("Le contact a bien ete ajoute : \n");
}

void afficher_contact() {
    if (contact_n == 0) {
        printf("Aucun contact a afficher !! \n");
        return;
    }

    printf("La liste des contacts est : \n");
    for (int i = 0; i < contact_n; i++) {

        printf("+---------+--------+---------+----------+\n");
        printf("|   ID    |  Nom   |  Email  | telephone|\n");
        printf("|   %d    |  %s    |  %s     |    %s    |\n ",i+1,
               contacts[i].nom, contacts[i].email, contacts[i].phone);
    }

}
void recherche_contact(){
    char nom[max_contact];
    printf("Entrer le nom de contact a recherecher : \n");
    fgets(nom,max_contact,stdin);
    nom[strcspn(nom,"\n")]=0;

    for(int i=0;i<contact_n;i++){
        if(strcmp(contacts[i].nom,nom)==0){
            printf("contact touver: Nom: %s ,Telephone : %s \n Email:%s \n",
                   contacts[i].nom,contacts[i].phone,contacts[i].email);
                   return;
        }
    }
    printf("contact introuvable !! \n");

}

void modifie_contact(){
    char nom[max_contact];
    printf("Entrer le contact que voulez le modifie:\n");
    fgets(nom,max_contact,stdin);
    nom[strcspn(nom,"\n")]=0;

    for(int i=0;i<contact_n;i++){
        if(strcmp(contacts[i].nom,nom)==0){
            printf("Veuillez entre le nouveau numero: \n");
            fgets(contacts[i].phone,max_phone_number,stdin);
            contacts[i].phone[strcspn(contacts[i].phone,"\n")]==0;

              printf("Veuillez entre le nouveau Email: \n");
            fgets(contacts[i].email,max_email,stdin);
            contacts[i].email[strcspn(contacts[i].email,"\n")]==0;

            printf("-- le contact est modifie .\n");
            return;
        }
        printf(" le contact introuvable !! \n");


    }
}

void sup_contact(){
    char nom[max_contact];
    printf("Entrer le nom de contact que voulez supprimer: \n");
    fgets(nom,max_contact,stdin);
    nom[strcspn(nom,"\n")]=0;

    for(int i=0;i<contact_n;i++){
        if(strcmp(contacts[i].nom,nom)==0){
            for(int j=i;j<contact_n-1;j++){
                contacts[j]=contacts[j+1];
            }
            contact_n--;
            printf("le contact est supprimer.\n");
            return;
        }
    }
    printf("Le contact est intouvable !! \n");
}


int main()
{
   int choix;
   do {
        printf("\t --- Menu: ---\n");

        printf("1. Ajouter un contact\n");
        printf("2. Afficher tous les contacts\n");
        printf("3. Rechercher d\'un contact\n");
        printf("4. Modifier un contact\n");
        printf("5. Supprimer un contact\n");
        printf("6. Quitter\n\n");

    printf("Veuillez entrer votre choix:\n");
    scanf("%d",&choix);
        getchar();

    switch (choix){

        case 1: ajouter_contact();
        break;
        case 2:afficher_contact();
        break;
        case 3:recherche_contact();
        break;
        case 4:modifie_contact();
        break;
        case 5:sup_contact();
        break;
        case 6:printf("Merci! Au revoir\n");
        break;
        default:printf("erreur ! Veuillez entrer un nombre :\n");

    }

   } while (choix!=6);

    return 0;
}
