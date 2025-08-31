#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <gtk/gtk.h>
typedef struct 
{int j;
int m;
int a;}
date ;
typedef struct
{int id ;
char ETS[20] ;
date date ;
char cr[20];
}
rdv;



//...............................................................................
//.................................................................................

int ajouter_rdv(rdv r, char *fichieerdv);
int supprimer_rdv2(const char *ets, const char *date, const char *cr, const char *historique);
int modifier_rdv(rdv rd,rdv r2, const char *fichieerdv);
int supprimer_rdv(char ets,int j,int m,int a,char cr, char *historique);
int chercher_rdv(int id , char *historique);
void historique(char nomFichier[], char CIN[]);
int capacite(char nomFichier[], char ETS[]);
int HoraireDispo(char nomFichier[], char ETS[], int capacite, int jour, int mois, int annee, char horaire[]) ;
int chercher_rdv2(int id , char *historique);
GtkCellRenderer *create_text_renderer();
GtkTreeViewColumn *create_column(const gchar *title, GtkCellRenderer *renderer, gint column_id) ;
void create_treeview(int id,GtkWidget *treeview);
void create_treeview2(GtkWidget *treeview);
void create_treeview3(int id,GtkWidget *treeview);
void clear_treeview(GtkWidget *treeview); 
void create_treeview4(int id,GtkWidget *treeview,char in[]);

#endif
