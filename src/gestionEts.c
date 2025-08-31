#include<stdio.h>
#include<string.h>
#include "gestionEts.h"

enum{EID,
     ENOM,
     EADRESSE,
     ECAPACITE,
     EREGION,
     ETELEPHONE,
     COLUMNS
      };
void afficherEtsByRegion(GtkWidget *liste, char *filename,char *region){
   GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char id[50],capacite[50],telephone[50];
    store = NULL;
   ets e;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", ENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("adresse", renderer, "text", EADRESSE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("capacité", renderer, "text", ECAPACITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("region", renderer, "text", EREGION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("telephone", renderer, "text", ETELEPHONE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        // La liste contient 7 colonnes de type chaine de caractères
    }
    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


     


              f = fopen(filename, "r");

    if (f == NULL)
    {
        return;
    }
    else
    {
       
        while (fscanf(f,"%d %s %s %d %s %d\n",&e.id,e.nom,e.adresse,&e.capacite,e.region,&e.telephone)!=EOF)
        {     if(strcmp(e.region,region)==0){

         sprintf(id,"%d",e.id);
         sprintf(capacite,"%d",e.capacite);
         sprintf(telephone,"%d",e.telephone);
        
        





            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, EID, id, ENOM, e.nom, EADRESSE, e.adresse, ECAPACITE, capacite, EREGION, e.region, ETELEPHONE, telephone ,-1);}
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }















}
afficherTrier(GtkWidget *liste, char *filename){


        GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char id[50],capacite[50],telephone[50];
    store = NULL;
   ets e;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", ENOM, NULL);

        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("adresse", renderer, "text", EADRESSE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("capacité", renderer, "text", ECAPACITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("region", renderer, "text", EREGION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("telephone", renderer, "text", ETELEPHONE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        // La liste contient 7 colonnes de type chaine de caractères
    }
    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
                 f = fopen(filename, "r");

           ets e4[100];
    int  countETS =listeEts(filename,e4);
       // Trier les ETS par capacités (tri à bulles pour cet exemple)
    for (int i = 0; i < countETS - 1; i++) {
        for (int j = 0; j < countETS - i - 1; j++) {
            if (e4[j].capacite < e4[j + 1].capacite) {
                ets temp = e4[j];
                e4[j] = e4[j + 1];
                e4[j + 1] = temp;
            }
        }
    }


    
         for (int i = 0; i < countETS; i++) {
       
    

  
       
      

         sprintf(id,"%d",e4[i].id);
   
         sprintf(capacite,"%d",e4[i].capacite);
         sprintf(telephone,"%d",e4[i].telephone);
        
        





            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, EID, id, ENOM, e4[i].nom, EADRESSE, e4[i].adresse, ECAPACITE, capacite, EREGION, e4[i].region, ETELEPHONE, telephone ,-1);
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    










}
void vider_Ets(GtkWidget *liste){

         GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char id[50],capacite[50],telephone[50];
    store = NULL;
   ets e;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", ENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("adresse", renderer, "text", EADRESSE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("capacité", renderer, "text", ECAPACITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("region", renderer, "text", EREGION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("telephone", renderer, "text", ETELEPHONE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        // La liste contient 7 colonnes de type chaine de caractères
    }
    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);






}

void afficherEts(GtkWidget *liste, char *filename){
      GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char id[50],capacite[50],telephone[50];
    store = NULL;
   ets e;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", ENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("adresse", renderer, "text", EADRESSE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("capacité", renderer, "text", ECAPACITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("region", renderer, "text", EREGION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("telephone", renderer, "text", ETELEPHONE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        // La liste contient 7 colonnes de type chaine de caractères
    }
    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


     


              f = fopen(filename, "r");

    if (f == NULL)
    {
        return;
    }
    else
    {
       
        while (fscanf(f,"%d %s %s %d %s %d\n",&e.id,e.nom,e.adresse,&e.capacite,e.region,&e.telephone)!=EOF)
        {

         sprintf(id,"%d",e.id);
         sprintf(capacite,"%d",e.capacite);
         sprintf(telephone,"%d",e.telephone);
        
        





            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, EID, id, ENOM, e.nom, EADRESSE, e.adresse, ECAPACITE, capacite, EREGION, e.region, ETELEPHONE, telephone ,-1);
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }













}
void Menu(){
   char filename[50] = "nermine.txt";
   int w;
   int id;
 ets e,e1;
 ets e4[100];
 char region[50];
 int choix;
    while(1)
    {
      beg:
        printf("\n*******************************************************\n");
        printf("*   Menu :                                            *\n");
        printf("* 1. Ajouter un Ets                                   *\n");
        printf("* 2. Modifier un Ets                                   *\n");
        printf("* 3. Supprimer un Ets                                *\n");
        printf("* 4. Afficher Liste des Ets                           *\n");
        printf("* 5. EtsParRegion                                     *\n");
        printf("* 6. afficher ETS Tries Par Capacites                 *\n");
        printf("* Choisissez une option :                             *\n");
        printf("******************************************************* \n");

        scanf("%d", &choix);
        if(choix<1 || choix >6)
        {

            printf("\n try again ..........");
        }
        else
        {
            switch (choix)
            {
            case 1:

                printf("\n donner votre id : \n");
                scanf("%d",&e.id);
                printf("\n donner votre nom : \n");
                scanf("%s",e.nom);
                printf("\n donner votre adresse : \n");
                scanf("%s",e.adresse);
                printf("\n donner votre capacité : \n");
                scanf("%d",&e.capacite);
                printf("\n donner votre region: \n");
                scanf("%s",e.region);
                printf("\n donner votre telephone: \n");
                scanf("%d",&e.telephone);

                int x = ajouterEts(filename,e);
                x==1?printf("\n ajout avec succe \n"):printf("\n failed add \n");
                break;
            case 2:
                printf("\n donner moi id de ets que vous allez cherchez \n ");
                scanf("%d",&id);
                fflush(stdin);
                e1 = chercherEts(filename,id);


                if(e1.id!=-1)
                {
                    fflush(stdin);
                    printf(" \n");
                    fflush(stdin);
                    printf("============================\n");
                    printf("=  id est :     %d         =\n",e1.id);
                    printf("=  le nom est :   %s       =\n",e1.nom);
                    printf("=  adresse est :     %s    =\n",e1.adresse);
                    printf("=  le capacite est :    %d  =\n",e1.capacite);
                    printf("=  la region est :  %s      =\n",e1.region);
                    printf("=  la telephone est :  %d   =\n",e1.telephone);
                    printf("============================ \n");

                    printf("\n donner votre id: \n");
                    scanf("%d",&e1.id);
                    fflush(stdin);
                    printf("\n donner votre nom : \n");
                    scanf("%s",e1.nom);
                    fflush(stdin);

                    printf("\n donner votre adresse : \n");
                    scanf("%s",e1.adresse);
                    fflush(stdin);
                    printf("\n donner votre capacité : \n");
                    scanf("%d",&e1.capacite);
                    fflush(stdin);
                    printf("\n donner votre region: \n");
                    scanf("%s",e1.region);
                    fflush(stdin);
                    printf("\n donner votre telephone : \n");
                    scanf("%d",&e1.telephone);
                    int y = modifierEts(filename,id,e1);
                    if(y == 1)
                    {
                        printf("\n ets modifier avec succ�� \n");
                    }
                    else
                    {
                        printf("\n modification echou�  \n");
                    }

                    break;
                }
                else if(e1.id == -1)
                {
                    break;
                }
            case 3:
                printf("\n donner moi le id de ets que vous allez supprimer \n ");
                scanf("%d",&id);
                int z= supprimerEts(filename,id);
                if(z==1)
                {
                    printf("\n ets supprimer avec succ�� \n");
                }
                else
                {
                    printf("\n suppression a  echou�  \n");
                }

                break;
            case 4:

                 w =listeEts(filename,e4);
                if(w==0)
                {
                    printf("il n y a pas utilisateur ");
                }
                else
                {
                    for(int i = 0; i<w; i++)
                    {

                        printf("============================\n");
                        printf("=  le id  est :     %d     =\n",e4[i].id);
                        printf("=  le nom est :   %s       =\n",e4[i].nom);
                        printf("=  le adresse est :     %s =\n",e4[i].adresse);
                        printf("=  le capacité est :    %d =\n",e4[i].capacite);
                        printf("=  la region est :  %s     =\n",e4[i].region);
                        printf("=  la telephone est :  %d  =\n",e4[i].telephone);
                        printf("============================ \n");
                    }
                }
                break;
                case 5:
                printf("\n donner moi le region de ets que vous allez afficher \n ");
                scanf("%s",region);
                int k =EtsParRegion(filename,region,e4);
                if(k==0)
                {
                    printf("il n y a pas ce region ");
                }
                else
                {     printf("nombre de ets de cette region est %d",k);
                    for(int i = 0; i<k; i++)
                    {

                        printf("============================\n");
                        printf("=  le id  est :     %d     =\n",e4[i].id);
                        printf("=  le nom est :   %s       =\n",e4[i].nom);
                        printf("=  le adresse est :     %s =\n",e4[i].adresse);
                        printf("=  le capacité est :    %d =\n",e4[i].capacite);
                        printf("=  la region est :  %s     =\n",e4[i].region);
                        printf("=  la telephone est :  %d  =\n",e4[i].telephone);
                        printf("============================ \n");
                    }
                }
                break;
            case 6:
                afficherETSTriesParCapacites(filename);

                break;

            default:
                printf("Option invalide. Veuillez choisir une option valide.\n");
            }
            printf("\nvous voulez faire une autre instruction ou quittez programme [oui/non] \n");
            char reponse[3];
            scanf("%s",reponse);
            if(strcmp(reponse,"non")==0)
            {
                printf("programme termin� ");
                break;
            }
            else
            {
                goto beg;

            }

        }

    }















}
int ajouterEts(char *filename, ets e ){

  FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %d %s %d\n",e.id,e.nom,e.adresse,e.capacite,e.region,e.telephone);
        fclose(f);
        return 1;
    }
    else return 0;

}

int modifierEts( char *filename, int id, ets nouv ){


   int tr=0;
   ets e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %d %s %d\n",&e.id,e.nom,e.adresse,&e.capacite,e.region,&e.telephone)!=EOF)
        {
            if(e.id== id)
            {
                fprintf(f2,"%d %s %s %d %s %d\n",nouv.id,nouv.nom,nouv.adresse,nouv.capacite,nouv.region,nouv.telephone);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %s %d %s %d\n",e.id,e.nom,e.adresse,e.capacite,e.region,e.telephone);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;


}

int supprimerEts(char *filename, int id ){
  int tr=0;
    ets e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %d %s %d\n",&e.id,e.nom,e.adresse,&e.capacite,e.region,&e.telephone)!=EOF)
        {
            if(e.id== id)
                tr=1;
            else
                fprintf(f2,"%d %s %s %d %s %d\n",e.id,e.nom,e.adresse,e.capacite,e.region,e.telephone);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;


}




ets chercherEts(char *filename, int id){

      ets e;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %s %s %d %s %d\n",&e.id,e.nom,e.adresse,&e.capacite,e.region,&e.telephone)!=EOF)
        {
            if(e.id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        e.id=-1;
    return e;


}


void afficherETSTriesParCapacites(char *filename){

     ets e4[100];
    int  countETS =listeEts(filename,e4);
       // Trier les ETS par capacités (tri à bulles pour cet exemple)
    for (int i = 0; i < countETS - 1; i++) {
        for (int j = 0; j < countETS - i - 1; j++) {
            if (e4[j].capacite < e4[j + 1].capacite) {
                ets temp = e4[j];
                e4[j] = e4[j + 1];
                e4[j + 1] = temp;
            }
        }
    }


     printf("Liste des ETS triés par capacités (décroissante) :\n");
         for (int i = 0; i < countETS; i++) {
        printf("Id: %d Nom: %s, Adresse: %s, Capacité: %d, Région: %s Telephone %d\n",e4[i].id,e4[i].nom,e4[i].adresse,e4[i].capacite,e4[i].region,e4[i].telephone);
    }



}


int listeEts(char *filename,ets *resultat){

  ets e;

     int i = 0;
      FILE * f=fopen(filename, "r");
        if(f!=NULL)
    {
        while( fscanf(f,"%d %s %s %d %s %d\n",&e.id,e.nom,e.adresse,&e.capacite,e.region,&e.telephone)!=EOF)
        {

             resultat[i] = e;
               i++;

        }
    }
    fclose(f);
    return i;


}
int EtsParRegion(char *filename, char *region,ets *liste){
       ets e;

     int i = 0;
      FILE * f=fopen(filename, "r");
        if(f!=NULL)
    {
        while( fscanf(f,"%d %s %s %d %s %d\n",&e.id,e.nom,e.adresse,&e.capacite,e.region,&e.telephone)!=EOF)
        {
            if(strcmp(e.region,region)==0){
             liste[i] = e;
               i++;
            }
        }
    }
    fclose(f);
    return i;

}
