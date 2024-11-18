#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure Étudiant
typedef struct Etudiant {
    int m; // matricule
    char n[50]; // nom
    char p[50]; // prénom
    char s[10]; // sexe
    int a; // âge
    float n1, n2, n3; // notes
    struct Etudiant *suiv; // pointeur vers l'étudiant suivant
} Etudiant;

// Fonction pour ajouter un étudiant à la liste
void ajouter_etudiant(Etudiant **liste, int m, char *n, char *p, char *s, int a, float n1, float n2, float n3) {
    Etudiant *nouveau = malloc(sizeof(Etudiant));
    nouveau->m = m;
    strcpy(nouveau->n, n);
    strcpy(nouveau->p, p);
    strcpy(nouveau->s, s);
    nouveau->a = a;
    nouveau->n1 = n1;
    nouveau->n2 = n2;
    nouveau->n3 = n3;
    nouveau->suiv = *liste;
    *liste = nouveau;
}

// Fonction pour mettre à jour un étudiant
void mettre_a_jour_etudiant(Etudiant *liste, int m, float n1, float n2, float n3) {
    Etudiant *actuel = liste;
    while (actuel != NULL) {
        if (actuel->m == m) {
            actuel->n1 = n1;
            actuel->n2 = n2;
            actuel->n3 = n3;
            return;
        }
        actuel = actuel->suiv;
    }
}

// Fonction pour supprimer un étudiant
void supprimer_etudiant(Etudiant **liste, int m) {
    Etudiant *actuel = *liste;
    Etudiant *prec = NULL;
    while (actuel != NULL) {
        if (actuel->m == m) {
            if (prec == NULL) {
                *liste = actuel->suiv;
            } else {
                prec->suiv = actuel->suiv;
            }
            free(actuel);
            return;
        }
        prec = actuel;
        actuel = actuel->suiv;
    }
}

// Fonction pour afficher la liste des étudiants
void afficher_etudiants(Etudiant *liste) {
    Etudiant *actuel = liste;
    while (actuel != NULL) {
        printf("Matricule : %d\n", actuel->m);
        printf("Nom : %s\n", actuel->n);
        printf("Prénom : %s\n", actuel->p);
        printf("Sexe : %s\n", actuel->s);
        printf("Âge : %d\n", actuel->a);
        printf("Note 1 : %.2f\n", actuel->n1);
        printf("Note 2 : %.2f\n", actuel->n2);
        printf("Note 3 : %.2f\n", actuel->n3);
        printf("\n");
        actuel = actuel->suiv;
    }
}

int main() {
    Etudiant *liste = NULL;
    int choix;
    do {
        printf("Menu :\n");
        printf("1 - Ajouter un étudiant\n");
        printf("2 - Mettre à jour un étudiant\n");
        printf("3 - Supprimer un étudiant\n");
        printf("4 - Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                // Ajouter un étudiant
                break;
            case 2:
                // Mettre à jour un étudiant
                break;
            case 3:
                // Supprimer un étudiant
                break;
            case 4:
                // Quitter
                break;
            default:
                printf("Choix invalide !\n");
        }
    } while (choix != 4);
    return 0;
}
