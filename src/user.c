#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <gtk/gtk.h>
#include "user.h"
#include <time.h>
#include "gestionEts.h"
#include "don1.h"




// ajout un rdv 
int ajouter_rdv(rdv r, char *fichieerdv) {
  FILE *f = fopen(fichieerdv, "a");
  if (f != NULL) 
{
    fprintf(f,"%d %s %d %d %d %s\n",r.id,r.ETS,r.date.j,r.date.m,r.date.a,r.cr);

    fclose(f);
    printf("fermer le fichier");
return 1;
  }
else {return 0;}
}
//****************************************************************

 
int chercher_rdv(int id , char *historique)
{ rdv r;
 int t=0;
  FILE *f = fopen(historique, "r");
  if (f != NULL) {

    while (fscanf(f,"%d %s %d %d %d %s\n ",&r.id,r.ETS,&r.date.j,&r.date.m,&r.date.a,r.cr ) != EOF) {
      if (r.id == id) {
        t=1;
      }
    }
  }

  fclose(f);
  if(t==0)
  r.id = -1;

  return t ;
}
// Modifier un rdv


int modifier_rdv(rdv rd,rdv r2, const char *fichieerdv) {
    rdv r;
    int tr = 0;
    FILE *f = fopen(fichieerdv, "r");
    FILE *f2 = fopen("temp.txt", "w");

    if (f == NULL || f2 == NULL) {
        perror("Error opening file");
        return tr;
    }

    while (fscanf(f, "%d %s %d %d %d %s\n", &r.id, r.ETS, &r.date.j, &r.date.m, &r.date.a, r.cr) != EOF) {
        if (strcmp(r.ETS, r2.ETS) == 0 && r.date.j == r2.date.j && r.date.m == r2.date.m && r.date.a == r2.date.a && strcmp(r.cr, r2.cr) == 0) {
            fprintf(f2, "%d %s %d %d %d %s\n", rd.id, rd.ETS, rd.date.j, rd.date.m, rd.date.a, rd.cr);
            tr = 1;
        } else {
            fprintf(f2, "%d %s %d %d %d %s\n", r.id, r.ETS, r.date.j, r.date.m, r.date.a, r.cr);
        }
    }

    fclose(f);
    fclose(f2);

    // Remove the original file and rename the temporary file
    remove(fichieerdv);
    rename("temp.txt", fichieerdv);

    return tr;
}


// Supprimer un RDV
/*int supprimer_rdv(char ets,int j,int m,int a,char cr, char *historique) {
  rdv rd;
  int tr = 0;
  FILE *f = fopen(historique, "r");
  FILE *f2 = fopen("RDV.txt", "w");
  if (f == NULL || f2 == NULL)
    return tr;
  else {
    while (fscanf(f, "%d %s %d %d %d %s\n", &rd.id, rd.ETS, &rd.date.j, &rd.date.m, &rd.date.a, rd.cr) != EOF) {
      if ((rd.ETS != ets)&&(rd.date.j!=j)&&(rd.date.m!=m)&&(rd.date.a!=a)&&(rd.cr!=cr)) {
        fprintf(f2, "%d %s %d %d %d %s\n", rd.id, rd.ETS, rd.date.j, rd.date.m, rd.date.a, rd.cr);
      } else {
        tr = 1;
      }
    }
    // Close both files
    fclose(f);
    fclose(f2);
    // Remove and rename files
    remove(historique);
    rename("RDV.txt", historique);
  }
  return tr;
}*/
/*void historique(char nomFichier[], char CIN[])
 { 
  FILE *fichierLecture;
    FILE *fichierSauvegarde;

    don r;
    int a ;
    a=atoi(CIN);
    // Ouverture du fichier en mode lecture
    fichierLecture = fopen(nomFichier, "r");
    // Ouverture du fichier de sauvegarde en mode écriture
    fichierSauvegarde = fopen("historique_donneur.txt", "w");

    // Vérification si le fichier est ouvert avec succès
    if (fichierLecture != NULL&&fichierSauvegarde!=NULL) {
    // Lecture du fichier et sauvegarde des dons du donneur dans un autre fichier
     while (fscanf(fichierLecture, "%d %s %s %s %d\n",&r.id,r.id_donneur,r.id_ets,r.type_sanguin,&r.quantite_ml) != EOF){
        if (r.id== a) {
           fprintf(fichierSauvegarde, "%d %s %s %s %d\n ",r.id,r.id_donneur,r.id_ets,r.type_sanguin,r.quantite_ml);
           
        }
    }}

    // Fermeture des fichiers
    fclose(fichierLecture);
    fclose(fichierSauvegarde);
     if (fichierLecture == NULL&&fichierSauvegarde==NULL)
        {
            exit(EXIT_FAILURE);
}

    printf("L'historique des dons a été sauvegardé dans 'historique_donneur.txt'\n");*/
    

// Fonction pour obtenir la capacité d'une ETS à partir d'un fichier
int capacite(char nomFichier[], char ETS1[]) {
    int tr = 0;
    ets e;
    FILE *f = fopen(nomFichier, "r");

    if (f == NULL) {
        // Handle the case where the file cannot be opened
        return tr;
    }

    while (fscanf(f, "%d %s %s %d %s %d\n", &e.id, e.nom, e.adresse, &e.capacite, e.region, &e.telephone) != EOF) {
        if (strcmp(e.region, ETS1) == 0) {
            tr = e.capacite;
            fclose(f); // Close the file after finding the match
            return tr;
        }
    }

    fclose(f); // Close the file if the loop completes without finding a match

    // If the loop completes without finding a match, handle that case
    printf("ERREUR: ETS not found\n");
    return tr;
}


int HoraireDispo(char nomFichier[], char ETS[], int capacite, int jour, int mois, int annee, char horaire[]) {
    FILE *fichier;
      rdv rdv;
    int nombreRDVs = 0;

    fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier RDV");
        exit(1);
    }

    while (fscanf(fichier, "%d %s %d %d %d %s\n",
                  &rdv.id,  rdv.ETS, 
                  &rdv.date.j, &rdv.date.m, &rdv.date.a,
                  rdv.cr) != EOF) {
        if (strcmp(rdv.ETS, ETS) == 0 &&
            rdv.date.j == jour &&
            rdv.date.m == mois &&
            rdv.date.a == annee &&
            strcmp(rdv.cr,horaire) == 0) 
          {  nombreRDVs++;}
        
    }

    fclose(fichier);

    if (nombreRDVs < capacite) {
        return capacite - nombreRDVs;
    } else {
        return 0;
    }
}
   
int chercher_rdv2(int id, char *fichieerdv) {
    rdv r;
    time_t currentTime;
    time(&currentTime);

    char formattedDate[20]; 
    strftime(formattedDate, sizeof(formattedDate), "%Y-%m-%d", localtime(&currentTime));
    int x=0 ;
    char text0[20];
    char text1[20];
    char text2[20];
    strncpy(text0, formattedDate + 8, 2);
    strncpy(text1, formattedDate + 5, 2);
    strncpy(text2, formattedDate + 0, 4);
    int j = atoi(text0);
    int m = atoi(text1);
    int a = atoi(text2);
    FILE *f = fopen(fichieerdv, "r");
    if (f != NULL) {
        while (fscanf(f, "%d %s %d %d %d %s\n ", &r.id, r.ETS, &r.date.j, &r.date.m, &r.date.a, r.cr) != EOF) {
            if (r.id == id) {
                if (r.date.a > a) {
                    x = x + 1;
                }else if (r.date.a == a) {
                    if (r.date.m > m) {
                        x = x + 1;
                   }else if (r.date.m == m) {
                        if (r.date.j >= j) {
                            x = x + 1;
                        }
                    }
                }
            }
        }
    }

    fclose(f);

    return x;
}
GtkCellRenderer *create_text_renderer() {
    return gtk_cell_renderer_text_new();
}

GtkTreeViewColumn *create_column(const gchar *title, GtkCellRenderer *renderer, gint column_id) {
    GtkTreeViewColumn *column = gtk_tree_view_column_new_with_attributes(title, renderer, "text", column_id, NULL);
    return column;
}
enum {
    COLUMN_ID,
    COLUMN_ETS,
    COLUMN_DATE,
    COLUMN_TEMPS,
    
};
void create_treeview(int id,GtkWidget *treeview) {
    rdv r ;
    char fichierrdv[20]="fichierrdv.txt";
    // Create a ListStore with columns for ID, Type, Quantity, Sick, Date, and IDS
    GtkListStore *liststore = gtk_list_store_new(4, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    GtkTreeIter iter;

    time_t currentTime;
    time(&currentTime);

    char formattedDate[20]; 
    strftime(formattedDate, sizeof(formattedDate), "%Y-%m-%d", localtime(&currentTime));
    int x=0 ;
    char text0[20];
    char text1[20];
    char text2[20];
    strncpy(text0, formattedDate + 8, 2);
    strncpy(text1, formattedDate + 5, 2);
    strncpy(text2, formattedDate + 0, 4);
    int j = atoi(text0);
    int m = atoi(text1);
    int a = atoi(text2);

    // Read data from the text file
    FILE *file = fopen(fichierrdv, "r");
    if (file != NULL) {
        

        while (fscanf(file, "%d %s %d %d %d %s\n", &r.id, r.ETS, &r.date.j,&r.date.m , &r.date.a, r.cr)==6 ) {
            char dateS[20];
             if (r.id == id) {
                if (r.date.a > a) {
                    sprintf(dateS, "%d/%d/%d", r.date.j,r.date.m, r.date.a);
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                COLUMN_ID,r.id,
                COLUMN_ETS,r.ETS,
                COLUMN_DATE,dateS,
                 COLUMN_TEMPS,r.cr,
                -1);
                }else if (r.date.a == a) {
                    if (r.date.m > m) {
                        sprintf(dateS, "%d/%d/%d", r.date.j,r.date.m, r.date.a);
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                COLUMN_ID,r.id,
                COLUMN_ETS,r.ETS,
                COLUMN_DATE,dateS,
                 COLUMN_TEMPS,r.cr,
                -1);
                   }else if (r.date.m == m) {
                        if (r.date.j >= j) {
                            sprintf(dateS, "%d/%d/%d", r.date.j,r.date.m, r.date.a);
                            gtk_list_store_append(liststore, &iter);
                            gtk_list_store_set(liststore, &iter,
                            COLUMN_ID,r.id,
                            COLUMN_ETS,r.ETS,
                            COLUMN_DATE,dateS,
                            COLUMN_TEMPS,r.cr,
                            -1);
                        }
                    }
                }
            }
            
        }

        fclose(file);
    } else {
        g_printerr("Error: Failed to open file.\n");
        return;
    }
// Set the model to the ListStore
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(liststore));

    // Create columns with CellRenderers
    GtkCellRenderer *renderer_id = create_text_renderer();
    GtkTreeViewColumn *column_id = create_column("ID", renderer_id, COLUMN_ID);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_id);

    GtkCellRenderer *renderer_ETS = create_text_renderer();
    GtkTreeViewColumn *column_ETS = create_column("ETS", renderer_ETS, COLUMN_ETS);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_ETS);

    GtkCellRenderer *renderer_dates = create_text_renderer();
    GtkTreeViewColumn *column_dates = create_column("date", renderer_dates, COLUMN_DATE);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_dates);

    GtkCellRenderer *renderer_TEMPS = create_text_renderer();
    GtkTreeViewColumn *column_TEMPS = create_column("temps", renderer_TEMPS, COLUMN_TEMPS);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_TEMPS);

}

void create_treeview2(GtkWidget *treeview) {
    rdv r ;
    char fichierrdv[20]="fichierrdv.txt";
    // Create a ListStore with columns for ID, Type, Quantity, Sick, Date, and IDS
    GtkListStore *liststore = gtk_list_store_new(4, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    GtkTreeIter iter;

    // Read data from the text file
    FILE *file = fopen(fichierrdv, "r");
    if (file != NULL) {
        

        while (fscanf(file, "%d %s %d %d %d %s\n", &r.id, r.ETS, &r.date.j,&r.date.m , &r.date.a, r.cr)==6 ) {
            char dateS[20];
            sprintf(dateS, "%d/%d/%d", r.date.j,r.date.m, r.date.a);
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                COLUMN_ID,r.id,
                COLUMN_ETS,r.ETS,
                COLUMN_DATE,dateS,
                 COLUMN_TEMPS,r.cr,
                -1);
        }

        fclose(file);
    } else {
        g_printerr("Error: Failed to open file.\n");
        return;
    }
// Set the model to the ListStore
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(liststore));

    // Create columns with CellRenderers
    GtkCellRenderer *renderer_id = create_text_renderer();
    GtkTreeViewColumn *column_id = create_column("ID", renderer_id, COLUMN_ID);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_id);

    GtkCellRenderer *renderer_ETS = create_text_renderer();
    GtkTreeViewColumn *column_ETS = create_column("ETS", renderer_ETS, COLUMN_ETS);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_ETS);

    GtkCellRenderer *renderer_dates = create_text_renderer();
    GtkTreeViewColumn *column_dates = create_column("date", renderer_dates, COLUMN_DATE);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_dates);

    GtkCellRenderer *renderer_TEMPS = create_text_renderer();
    GtkTreeViewColumn *column_TEMPS = create_column("temps", renderer_TEMPS, COLUMN_TEMPS);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_TEMPS);

}

void create_treeview3(int id,GtkWidget *treeview) {
    rdv r ;
    char fichierrdv[20]="fichierrdv.txt";
    // Create a ListStore with columns for ID, Type, Quantity, Sick, Date, and IDS
    GtkListStore *liststore = gtk_list_store_new(4, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    GtkTreeIter iter;

    time_t currentTime;
    time(&currentTime);

    char formattedDate[20]; 
    strftime(formattedDate, sizeof(formattedDate), "%Y-%m-%d", localtime(&currentTime));
    int x=0 ;
    char text0[20];
    char text1[20];
    char text2[20];
    strncpy(text0, formattedDate + 8, 2);
    strncpy(text1, formattedDate + 5, 2);
    strncpy(text2, formattedDate + 0, 4);
    int j = atoi(text0);
    int m = atoi(text1);
    int a = atoi(text2);

    // Read data from the text file
    FILE *file = fopen(fichierrdv, "r");
    if (file != NULL) {
        

        while (fscanf(file, "%d %s %d %d %d %s\n", &r.id, r.ETS, &r.date.j,&r.date.m , &r.date.a, r.cr)==6 ) {
            char dateS[20];
             if (r.id == id) {
                if (r.date.a < a) {
                    sprintf(dateS, "%d/%d/%d", r.date.j,r.date.m, r.date.a);
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                COLUMN_ID,r.id,
                COLUMN_ETS,r.ETS,
                COLUMN_DATE,dateS,
                 COLUMN_TEMPS,r.cr,
                -1);
                }else if (r.date.a == a) {
                    if (r.date.m < m) {
                        sprintf(dateS, "%d/%d/%d", r.date.j,r.date.m, r.date.a);
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                COLUMN_ID,r.id,
                COLUMN_ETS,r.ETS,
                COLUMN_DATE,dateS,
                 COLUMN_TEMPS,r.cr,
                -1);
                   }else if (r.date.m == m) {
                        if (r.date.j <= j) {
                            sprintf(dateS, "%d/%d/%d", r.date.j,r.date.m, r.date.a);
                            gtk_list_store_append(liststore, &iter);
                            gtk_list_store_set(liststore, &iter,
                            COLUMN_ID,r.id,
                            COLUMN_ETS,r.ETS,
                            COLUMN_DATE,dateS,
                            COLUMN_TEMPS,r.cr,
                            -1);
                        }
                    }
                }
            }
            
        }

        fclose(file);
    } else {
        g_printerr("Error: Failed to open file.\n");
        return;
    }
// Set the model to the ListStore
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(liststore));

    // Create columns with CellRenderers
    GtkCellRenderer *renderer_id = create_text_renderer();
    GtkTreeViewColumn *column_id = create_column("ID", renderer_id, COLUMN_ID);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_id);

    GtkCellRenderer *renderer_ETS = create_text_renderer();
    GtkTreeViewColumn *column_ETS = create_column("ETS", renderer_ETS, COLUMN_ETS);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_ETS);

    GtkCellRenderer *renderer_dates = create_text_renderer();
    GtkTreeViewColumn *column_dates = create_column("date", renderer_dates, COLUMN_DATE);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_dates);

    GtkCellRenderer *renderer_TEMPS = create_text_renderer();
    GtkTreeViewColumn *column_TEMPS = create_column("temps", renderer_TEMPS, COLUMN_TEMPS);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_TEMPS);

}

void clear_treeview(GtkWidget *treeview) {

    GtkListStore *liststore;
    liststore = gtk_list_store_new(4, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


    // Remove all columns from the treeview
    GList *columns = gtk_tree_view_get_columns(GTK_TREE_VIEW(treeview));
    for (GList *iter = columns; iter != NULL; iter = g_list_next(iter)) {
        GtkTreeViewColumn *column = GTK_TREE_VIEW_COLUMN(iter->data);
        gtk_tree_view_remove_column(GTK_TREE_VIEW(treeview), column);
    }
    g_list_free(columns);

    // Clear the model
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
    if (model != NULL) {
        g_object_unref(model);
    }

    // Create a new, empty ListStore and set it as the model
    liststore = gtk_list_store_new(NULL);  // 0 columns
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(liststore));
}

    void create_treeview4(int id,GtkWidget *treeview,char in[]) {
    rdv r ;
    char fichierrdv[20]="fichierrdv.txt";
    // Create a ListStore with columns for ID, Type, Quantity, Sick, Date, and IDS
    GtkListStore *liststore = gtk_list_store_new(4, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    GtkTreeIter iter;

    time_t currentTime;
    time(&currentTime);

    char formattedDate[20]; 
    strftime(formattedDate, sizeof(formattedDate), "%Y-%m-%d", localtime(&currentTime));
    int x=0 ;
    char text0[20];
    char text1[20];
    char text2[20];
    char text6[20];
    char text5[20];
    char text4[20];
    strncpy(text0, formattedDate + 8, 2);
    strncpy(text1, formattedDate + 5, 2);
    strncpy(text2, formattedDate + 0, 4);
    int j = atoi(text0);
    int m = atoi(text1);
    int a = atoi(text2);

    strncpy(text4, in + 8, 2);
    strncpy(text5, in + 5, 2);
    strncpy(text6, in + 0, 4);

    int j1 = atoi(text4);
    int m1 = atoi(text5);
    int a1 = atoi(text6);



    // Read data from the text file
    FILE *file = fopen(fichierrdv, "r");
    if (file != NULL) {
        

        while (fscanf(file, "%d %s %d %d %d %s\n", &r.id, r.ETS, &r.date.j,&r.date.m , &r.date.a, r.cr)==6 ) {
            char dateS[20];
             if (r.id == id) {
                
                     if(r.date.a==a1){
                        
                        if(r.date.m==m1){

                   
                
                            if(r.date.j == j1){
                            sprintf(dateS, "%d/%d/%d", r.date.j,r.date.m, r.date.a);
                            gtk_list_store_append(liststore, &iter);
                            gtk_list_store_set(liststore, &iter,
                            COLUMN_ID,r.id,
                            COLUMN_ETS,r.ETS,
                            COLUMN_DATE,dateS,
                            COLUMN_TEMPS,r.cr,
                            -1);
                        }
                    
                
            }
            
        }}}

        fclose(file);
    } else {
        g_printerr("Error: Failed to open file.\n");
        return;
    }
// Set the model to the ListStore
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(liststore));

        GtkCellRenderer *renderer_id = create_text_renderer();
    GtkTreeViewColumn *column_id = create_column("ID", renderer_id, COLUMN_ID);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_id);

    GtkCellRenderer *renderer_ETS = create_text_renderer();
    GtkTreeViewColumn *column_ETS = create_column("ETS", renderer_ETS, COLUMN_ETS);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_ETS);

    GtkCellRenderer *renderer_dates = create_text_renderer();
    GtkTreeViewColumn *column_dates = create_column("date", renderer_dates, COLUMN_DATE);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_dates);

    GtkCellRenderer *renderer_TEMPS = create_text_renderer();
    GtkTreeViewColumn *column_TEMPS = create_column("temps", renderer_TEMPS, COLUMN_TEMPS);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_TEMPS);



}


int supprimer_rdv2(const char *ets, const char *date, const char *cr, const char *historique)
{
    rdv rd;

    // Extract day, month, and year from the date string with spaces
    int j, m, a;
    if (sscanf(date, "%d/%d/%d", &j, &m, &a) != 3)
    {
        // Handle invalid date format
        return 0;
    }

    int tr = 0;
    FILE *f = fopen(historique, "r");
    FILE *f2 = fopen("RDV.txt", "w");
    if (f == NULL || f2 == NULL)
    {
        return tr;
    }
    else
    {
        while (fscanf(f, "%d %s %d %d %d %s\n", &rd.id, rd.ETS, &rd.date.j, &rd.date.m, &rd.date.a, rd.cr) != EOF)
        {
            if (strcmp(rd.ETS, ets) != 0 || rd.date.j != j || rd.date.m != m || rd.date.a != a || strcmp(rd.cr, cr) != 0)
            {
                fprintf(f2, "%d %s %d %d %d %s\n", rd.id, rd.ETS, rd.date.j, rd.date.m, rd.date.a, rd.cr);
            }
            else
            {
                tr = 1;
            }
        }
        // Close both files
        fclose(f);
        fclose(f2);
        // Remove and rename files
        remove(historique);
        rename("RDV.txt", historique);
    }
    return tr;
}

// Example usage




