#ifndef GESTIONRDV_H_INCLUDED
#define GESTIONRDV_H_INCLUDED
#include <gtk/gtk.h>
typedef struct {
 int jj;
 int mm;
 int yy;


}Date;
typedef struct {
  char  id[50] ;
  char Cin[50];
  char etab[50];
  Date dateRdv;
  char heure[50] ;
  char type[50];
  char fume[50];
  char tatouage[50];


}Donneur;



void afficherDonneur(GtkWidget *liste, char *filename);
void rechercherDonneur(GtkWidget *liste, char *filename,char *id[50]);
void listeRdvTreeView(GtkWidget *liste,char *filename,char *etab,int jj,int mm, int yy);
void viderDonneur(GtkWidget *liste);
int ajouterDonneur(char *, Donneur );
int modifierDonneur( char *, char *, Donneur );
int supprimerDonneur(char *, char* );
Donneur chercherDonneur(char *, char *);
int listeRDV(char *,char *,int , int ,int,Donneur *);
int nbEts(char *);
float moyRDV_ETS(char * , char * , int , int , int );
#endif // GESTIONRDV_H_INCLUDED
