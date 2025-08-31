#ifndef GESTIONETS_H_INCLUDED
#define GESTIONETS_H_INCLUDED
#include <gtk/gtk.h>
typedef struct{
    int id;
    char nom[50];
    char adresse[50];
    int capacite;
    char region[50];
    int telephone;
}ets;
void Menu();
int ajouterEts(char *, ets );
int modifierEts( char *, int, ets );
int supprimerEts(char *, int );
ets chercherEts(char *, int);
int listeEts(char *,ets *);
int EtsParRegion(char *, char *,ets *);
void afficherETSTriesParCapacites(char *);
void afficherTrier(GtkWidget *liste, char *filename);
void afficherEtsByRegion(GtkWidget *liste, char *filename,char *region);
void afficherEts(GtkWidget *liste, char *filename);
void vider_Ets(GtkWidget *liste);
#endif // GESTIONETS_H_INCLUDED
