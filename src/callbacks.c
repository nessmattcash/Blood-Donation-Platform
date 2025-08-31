#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "string.h"
#include "user.h"

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ut.h"
#include"utilisateur.h"
#include "ficheDonneur.h"
#include "don1.h"
#include "gestionEts.h"
char fichierrayen[] = "rayen.txt";
char fichierlog[] = "log.txt";
#include <time.h>
#define NUM_COLUMNS 4

rdv r;
rdv r1 ;
rdv r2;
char fichierrdv[] = "fichierrdv.txt";
char fichierets[] = "fichierets.txt";
int id;
int sure=0;
int x=0;
char dates[20];
char dates2[20];
GtkListStore *liststore;
int choix=0;
int y=0;
int crn ;
int aziz;
int g ;
int g1;
int fume1 ;
int tatou1 ;
int fume2 ;
int tatou2 ;
char filename[]="ficheDonneur.txt";


void
on_button_login_clicked                (GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget *input0;
    GtkWidget *input1;
     GtkWidget *logn ;
    GtkWidget *suiv;
    GtkWidget *err;
    int num,n,n1;


    // Retrieve GTK widgets
    input0 = lookup_widget(objet_graphique, "entry_log_log"); 
   input1 = lookup_widget(objet_graphique, "entry_log_mp");
    const char *text0 ;
    text0= gtk_entry_get_text(GTK_ENTRY(input0));
    num=atoi(text0); 
    id=num;
     const char *text1 ;
    text1= gtk_entry_get_text(GTK_ENTRY(input1));
    n= chercherf(num,text1 ,fichierlog);
     n1= chercherf1(text0,text1 ,fichierrayen);
     if(n==1)
     {
        logn = lookup_widget(objet_graphique, "login");
    gtk_widget_hide(logn);
    suiv = create_gestion();
    gtk_widget_show(suiv);
     }
     else if (n1==1)
     {
         logn = lookup_widget(objet_graphique, "login");
    gtk_widget_hide(logn);
    suiv = create_gestion();
    gtk_widget_show(suiv);
     }
     else
     {
        err= lookup_widget(objet_graphique, "label_msg_login");
        gtk_label_set_text(GTK_LABEL(err),"ERROR");
     }
     }
    



void
on_button_utilisateur_clicked          (GtkWidget *objet_graphique, gpointer user_data){
   GtkWidget *dach ;
    GtkWidget *acc;
    dach = lookup_widget(objet_graphique, "login");
    gtk_widget_hide(dach);
    acc = create_Uaffiche();
    gtk_widget_show(acc);

}


void
on_button_ets_clicked                  (GtkWidget *objet_graphique, gpointer user_data)
{GtkWidget *dach ;
    GtkWidget *acc;
    dach = lookup_widget(objet_graphique, "login");
    gtk_widget_hide(dach);
    acc = create_NL_Afficher_ETS();
    gtk_widget_show(acc);

}


void
on_button_don_clicked                  (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *dach ;
    GtkWidget *acc;
    dach = lookup_widget(objet_graphique, "login");
    gtk_widget_hide(dach);
    acc = create_acceuil_don_rania();
    gtk_widget_show(acc);
}


void
on_button_fichedonneur_clicked         (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *dach ;
    GtkWidget *acc;
    dach = lookup_widget(objet_graphique, "login");
    gtk_widget_hide(dach);
    acc = create_FDaffiche();
    gtk_widget_show(acc);
}


void
on_button_rdv_clicked                  (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *dach ;
    GtkWidget *acc;
    dach = lookup_widget(objet_graphique, "login");
    gtk_widget_hide(dach);
    acc = create_window1_ac();
    gtk_widget_show(acc);
}


void
on_button_poche_clicked                (GtkWidget *objet_graphique, gpointer user_data)
{

}
void
on_button_retour_aziz_clicked          (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *dach ;
    GtkWidget *acc;
    dach = lookup_widget(objet_graphique, "window1_ac");
    gtk_widget_hide(dach);
    acc = create_login();
    gtk_widget_show(acc);
}


void on_button_rdv_aziz_clicked(GtkWidget *objet_graphique, gpointer user_data) {
    int aux=chercher_rdv2(id,fichierrdv) ;
    printf("Value of aux: %d\n", aux);
    if (aux>0)
    {
    GtkWidget *treeview3;
    GtkWidget *aff ;
    GtkWidget *acc;
    acc = lookup_widget(objet_graphique, "window1_ac");
    gtk_widget_hide(acc);
    aff = create_window4_aff();
    gtk_widget_show(aff);

    treeview3 = lookup_widget(aff, "treeview3");
    create_treeview(id,treeview3);
}
    else if (aux==0)
    {

       GtkWidget *aff2 ;
    GtkWidget *acc;
    acc = lookup_widget(objet_graphique, "window1_ac");
    gtk_widget_hide(acc);
    aff2 = create_window6_aff2();
    gtk_widget_show(aff2); 
    }}
void
on_but_aj_1_aziz_clicked               (GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget *aj2 ;
    GtkWidget *acc;
    acc = lookup_widget(objet_graphique, "window1_ac");
    gtk_widget_hide(acc);
    aj2 = create_window2_cord();
    gtk_widget_show(aj2);
}
void
on_button_suiv_1_aziz_clicked          (GtkWidget *objet_graphique, gpointer user_data)
 {GtkWidget *input0;
    GtkWidget *input1;
     GtkWidget *sui ;
    GtkWidget *tem;
    GtkWidget *err;
    int num;

    // Retrieve GTK widgets
    input0 = lookup_widget(objet_graphique, "entryazizid"); 
     input1 = lookup_widget(objet_graphique, "comboboxentry1aziz");
    // Extract text from GTK widgets
    const char *text0 ;
    text0= gtk_entry_get_text(GTK_ENTRY(input0));
    num=atoi(text0); 
    const char *text1;
    GtkEntry *entry = GTK_ENTRY(gtk_bin_get_child(GTK_BIN(input1)));
    if (GTK_IS_ENTRY(entry)) {
        text1 = gtk_entry_get_text(entry);
    } else {
        g_warning("Invalid cast from 'GtkComboBoxEntry' to 'GtkEntry'");
        // Handle the error accordingly
        return;
    }
    strcpy(r.ETS,text1);
    r.id=num; 
    if (strlen(text0)==8){
      if(strcmp(text0, "") != 0 && strcmp(text1, "") != 0)
    {
    sui = lookup_widget(objet_graphique, "window2_cord");
    gtk_widget_hide(sui);
    tem= create_window3_tem();
    gtk_widget_show(tem);}}
     else if (strlen(text0)!=8)
    {
        err= lookup_widget(objet_graphique, "label52");
        gtk_label_set_text(GTK_LABEL(err),"ERROR");
        
    }

    

   
}


void
on_button_ann_aziz_1_clicked           (GtkWidget *objet_graphique, gpointer user_data)
{
 GtkWidget *ann ;
    GtkWidget *acc;
    ann = lookup_widget(objet_graphique, "window2_cord");
    gtk_widget_hide(ann);
    acc= create_window1_ac();
    gtk_widget_show(acc);
}



void
on_annul_2_aziz_clicked                (GtkWidget *objet_graphique, gpointer user_data)
{
 GtkWidget *ann ;
    GtkWidget *acc;
    ann = lookup_widget(objet_graphique, "window3_tem");
    gtk_widget_hide(ann);
    acc= create_window1_ac();
    gtk_widget_show(acc);
}


void
on_term_1_aziz_clicked                 (GtkWidget *objet_graphique, gpointer user_data)
{

    double num1,num2,num3;
    int num4,num5, num6,num,cap,num8;

    GtkWidget *input0;
    GtkWidget *input1;
    GtkWidget *input2;
    GtkWidget *input3;
    GtkWidget *err;
    GtkWidget *err1;
    GtkWidget *err2;

    input0 = lookup_widget(objet_graphique, "spinbutton1aziz");
    input1 = lookup_widget(objet_graphique, "spinbutton2aziz");
    input2 = lookup_widget(objet_graphique, "spinbutton3aziz");
    input3 = lookup_widget(objet_graphique, "comboboxentry2aziz");


// Getting the value from GtkSpinButton
    GtkAdjustment *adjustment1 = gtk_spin_button_get_adjustment(GTK_SPIN_BUTTON(input0));
    num1 = gtk_adjustment_get_value(adjustment1);
    num4=(int)num1;
    // Getting the value from GtkSpinButton
    GtkAdjustment *adjustment2 = gtk_spin_button_get_adjustment(GTK_SPIN_BUTTON(input1));
    num2 = gtk_adjustment_get_value(adjustment2);
    num5=(int)num2;
    // Getting the value from GtkSpinButton
    GtkAdjustment *adjustment3 = gtk_spin_button_get_adjustment(GTK_SPIN_BUTTON(input2));
    num3 = gtk_adjustment_get_value(adjustment3);
    num6=(int)num3;
        // Correct way to get text from GtkComboBoxEntry
    const char *text1;
    GtkEntry *entry = GTK_ENTRY(gtk_bin_get_child(GTK_BIN(input3)));
    if (GTK_IS_ENTRY(entry)) {
        text1 = gtk_entry_get_text(entry);
    } else {
        g_warning("Invalid cast from 'GtkComboBoxEntry' to 'GtkEntry'");
        // Handle the error accordingly
        return;
    }


    r.date.j=num4;
    r.date.m=num5;
    r.date.a=num6;
    strcpy(r.cr,text1);
   

    time_t currentTime;
    time(&currentTime);

    char formattedDate[20]; 
    strftime(formattedDate, sizeof(formattedDate), "%Y-%m-%d", localtime(&currentTime));
    int x=0 ;
    char text0[20];
    char text3[20];
    char text2[20];
    strncpy(text0, formattedDate + 8, 2);
    strncpy(text3, formattedDate + 5, 2);
    strncpy(text2, formattedDate + 0, 4);
    int j = atoi(text0);
    int m = atoi(text3);
    int a = atoi(text2);
    printf("Entered Date: %d-%d-%d\n", r.date.a, r.date.m, r.date.j);
printf("Current Date: %d-%d-%d\n", a, m, j);
               if (r.date.a < a) {
                 printf("Invalid Year\n");
    err = lookup_widget(objet_graphique, "label54");
    gtk_label_set_text(GTK_LABEL(err), "Invalid Date");
} else if (r.date.a == a) {
    if (r.date.m < m) {
         printf("Invalid Month\n");
        err = lookup_widget(objet_graphique, "label54");
        gtk_label_set_text(GTK_LABEL(err), "Invalid Date");
    } else if (r.date.m == m) {
        if (r.date.j <= j) {
             printf("Invalid day\n");
            err = lookup_widget(objet_graphique, "label54");
            gtk_label_set_text(GTK_LABEL(err), "Invalid Date");
        }
    }
}
    else{            
    GtkWidget *ter ;
    GtkWidget *acc;
    int result,res;
    
          

    if(strcmp(text1, "") != 0)
    { if(y==0)
    {result = capacite(fichierets,r.ETS);
    cap=(int)(result/2);
    res = HoraireDispo(fichierrdv,r.ETS ,cap,r.date.j, r.date.m, r.date.a,r.cr);
    crn=res;
    printf("donner moi une resultat %d %d",result,res);
     if(res!=0){
     num=ajouter_rdv(r,fichierrdv);
    ter = lookup_widget(objet_graphique, "window3_tem");
    gtk_widget_hide(ter);
    acc= create_window1_ac();
    gtk_widget_show(acc); 

    }
    else{
        err1 = lookup_widget(objet_graphique, "label55");
            gtk_label_set_text(GTK_LABEL(err1), "FULL");
        }}
    else if (y==1){
        result = capacite(fichierets,r.ETS);
    cap=(int)(result/2);
    res = HoraireDispo(fichierrdv,r.ETS ,cap,r.date.j, r.date.m, r.date.a,r.cr);
    crn=res;
    printf("donner moi une resultat2 %d %d",result,res);
        if(res!=0){
    num8=modifier_rdv(r,r2,fichierrdv);
    ter = lookup_widget(objet_graphique, "window3_tem");
    gtk_widget_hide(ter);
    acc= create_window1_ac();
    gtk_widget_show(acc);
    }
    else{
         err1 = lookup_widget(objet_graphique, "label55");
            gtk_label_set_text(GTK_LABEL(err1), "FULL");
    }

}
      
}}


y=0;
}


void
on_button_supp1_aziz_clicked           (GtkWidget *objet_graphique, gpointer user_data)
{ if (x==1)
{ GtkWidget *sup;
    GtkWidget *sup2;
    sup= lookup_widget(objet_graphique, "window4_aff");
    gtk_widget_hide(sup);
    sup2= create_window5_sup();
    gtk_widget_show(sup2);

}
x=0;
}



void
on_button_modf_aziz_clicked            (GtkWidget *objet_graphique, gpointer user_data)
{
    if (x==1){

  
    char text0[20];        // 1-8-2022
    char text1[20];
    char text2[20];
    if ((dates2[1]=='/')&&(dates2[3]=='/')){


    strncpy(text0, dates2 + 4, 4);
    strncpy(text1, dates2 + 2, 1);
    strncpy(text2, dates2 + 0, 1);
    r2.date.a= atoi(text0);
    r2.date.m = atoi(text1);
     r2.date.j = atoi(text2);}
     else if((dates2[1]=='/')&&(dates2[4]=='/'))
     {

    strncpy(text0, dates2 + 5, 4);
    strncpy(text1, dates2 + 2, 2);
    strncpy(text2, dates2 + 0, 1);
    r2.date.a= atoi(text0);
    r2.date.m = atoi(text1);
     r2.date.j = atoi(text2);
     }
      else if((dates2[2]=='/')&&(dates2[4]=='/'))
     {

    strncpy(text0, dates2 + 5, 4);
    strncpy(text1, dates2 + 3, 1);
    strncpy(text2, dates2 + 0, 2);
    r2.date.a= atoi(text0);
    r2.date.m = atoi(text1);
     r2.date.j = atoi(text2);
     }
      else if((dates2[2]=='/')&&(dates2[5]=='/'))
     {

    strncpy(text0, dates2 + 6, 4);
    strncpy(text1, dates2 + 3, 2);
    strncpy(text2, dates2 + 0, 2);
    r2.date.a= atoi(text0);
    r2.date.m = atoi(text1);
     r2.date.j = atoi(text2);
     }
    y=1; 
    GtkWidget *mod;
    GtkWidget *aj;
    mod= lookup_widget(objet_graphique, "window4_aff");
    gtk_widget_hide(mod);
    aj= create_window2_cord();
    gtk_widget_show(aj);
    g_print("la date %d %d %d\n", r2.date.j, r2.date.m, r2.date.a);
   
}
    x=0;


}


void
on_button_quit_2_aziz_clicked          (GtkWidget *objet_graphique, gpointer user_data)
{rdv r ;
 GtkWidget *quit;
    GtkWidget *acc;
    quit = lookup_widget(objet_graphique, "window4_aff");
    gtk_widget_hide(quit);
    acc= create_window1_ac();
    gtk_widget_show(acc);
}

void
on_button_3_ter_aziz_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget *input0;
    GtkWidget *acc;
    GtkWidget *tem;
    GtkWidget *err;
    int num;
    int n;

    // Assuming id and choix are declared and initialized somewhere in your code
    input0 = lookup_widget(objet_graphique, "entry2aziz");
    const char *text0;
    text0 = gtk_entry_get_text(GTK_ENTRY(input0));
    num = atoi(text0);

    // Assuming r2.ETS, dates2, r2.cr, fichierrdv are declared and initialized
    if (id == num)
    {
        if (choix == 1)
        {
            n = supprimer_rdv2(r2.ETS, dates2, r2.cr, fichierrdv);
            acc = lookup_widget(objet_graphique, "window5_sup");

            if (acc != NULL)
            {
                gtk_widget_hide(acc);
                tem = create_window1_ac();
                gtk_widget_show(tem);
            }
            else
            {
                // Handle the case where the widget is not found
                g_print("Error: Widget 'window5_sup' not found.\n");
            }
        }
    }
    else
    {
        err = lookup_widget(objet_graphique, "label57");
        if (err != NULL)
        {
            gtk_label_set_text(GTK_LABEL(err), "ERROR");
        }
        else
        {
            // Handle the case where the widget is not found
            g_print("Error: Widget 'label57' not found.\n");
        }
    }
}


void
on_button_4_ann_aziz_clicked           (GtkWidget *objet_graphique, gpointer user_data)
{ GtkWidget *ann ;
    GtkWidget *sup;
      
    
    ann = lookup_widget(objet_graphique, "window5_sup");
    gtk_widget_hide(ann);
    sup= create_window1_ac();
    gtk_widget_show(sup);
     

}


void
on_radiobutton4_aziz_clicked           (GtkWidget *objet_graphique, gpointer user_data)
{
choix=1;
}


void
on_radiobutton3_aziz_clicked           (GtkWidget *objet_graphique, gpointer user_data)
{
choix=0;
}


void
on_button_ajout_2_aziz_clicked         (GtkWidget *objet_graphique, gpointer user_data)
{
 GtkWidget *aj ;
    GtkWidget *sup;
    sup= lookup_widget(objet_graphique, "window6_aff2");
    gtk_widget_hide(sup);
    aj= create_window2_cord();
    gtk_widget_show(aj);

}


void
on_button_quit_4_aziz_clicked          (GtkWidget *objet_graphique, gpointer user_data)
{GtkWidget *acc ;
    GtkWidget *sup;
    sup= lookup_widget(objet_graphique, "window6_aff2");
    gtk_widget_hide(sup);
    acc= create_window1_ac();
    gtk_widget_show(acc);

}


void
on_button_quit_hist_aziz_clicked       (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *quit ;
    GtkWidget *acc;
    quit= lookup_widget(objet_graphique, "window_hist");
    gtk_widget_hide(quit);
    acc= create_window1_ac();
    gtk_widget_show(acc);
}


void
on_button_aj_2_aziz_clicked            (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *aj ;
    GtkWidget *histo;
    histo= lookup_widget(objet_graphique, "window_hist");
    gtk_widget_hide(histo);
    aj= create_window2_cord();
    gtk_widget_show(aj);
}
void on_button_supp_2_aziz_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
    int n;
    GtkWidget *treeview2;
    
    treeview2 = lookup_widget(objet_graphique, "treeview2");
    
    clear_treeview(treeview2);
    //n = supprimer_rdv2("r1.ETS", "dates", "r1.cr", fichierrdv);
    n = supprimer_rdv2(r1.ETS, dates, r1.cr, fichierrdv);
    printf("%d", n);

    create_treeview3(id, treeview2);
}



void
on_buttonhistoaziz_clicked              (GtkWidget *objet_graphique, gpointer user_data)
                            
{
    GtkWidget *treeview2;
    GtkWidget *aff ;
    GtkWidget *acc;
    acc = lookup_widget(objet_graphique, "window1_ac");
    gtk_widget_hide(acc);
    aff = create_window_hist();
    gtk_widget_show(aff);

    treeview2 = lookup_widget(aff, "treeview2");
    create_treeview3( id,treeview2);
    
}


void
on_checkbutton1aziz_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if( gtk_toggle_button_get_active(togglebutton) && sure==0)
{

sure=1;
}else{sure=0;}
}


void
on_shearch_clicked                     (GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget *input0;
    GtkWidget *treeview2;
    input0 = lookup_widget(objet_graphique, "entry1");

    const char *text0 ;
    text0= gtk_entry_get_text(GTK_ENTRY(input0));






    // Retrieve GTK widgets
     
    treeview2 = lookup_widget(objet_graphique, "treeview2");


    clear_treeview(treeview2);
    create_treeview4(id,treeview2,text0);


}



void on_treeview2_row_activated(GtkTreeView *treeview, GtkTreePath *path, GtkTreeViewColumn *column, gpointer user_data) {
    GtkTreeIter iter;
    gint id;
    gchar *ETS;
    gchar *date;
    gchar *temps;

    enum {
        COLUMN_ID,
        COLUMN_ETS,
        COLUMN_DATE,
        COLUMN_TEMPS,
    };

    GtkTreeModel *model = gtk_tree_view_get_model(treeview);

    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(GTK_LIST_STORE(model), &iter,
                           COLUMN_ID, &id,
                           COLUMN_ETS, &ETS,
                           COLUMN_DATE, &date,
                           COLUMN_TEMPS, &temps,
                           -1);

        // Do something with the retrieved data...

        
        r1.id = id;
    g_strlcpy(r1.ETS, ETS, sizeof(r1.ETS));
    g_strlcpy(dates, date, sizeof(r1.date));
    g_strlcpy(r1.cr, temps, sizeof(r1.cr));
    printf("%s %s %s\n", r1.ETS, r1.cr,dates);
    // Free allocated strings
        g_free(ETS);
        g_free(date);
        g_free(temps);
}
    
}





        



void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
    GtkTreeIter iter;
    gint id;
    gchar *ETS;
    gchar *date;
    gchar *temps;

    enum {
        COLUMN_ID,
        COLUMN_ETS,
        COLUMN_DATE,
        COLUMN_TEMPS,
    };

    GtkTreeModel *model = gtk_tree_view_get_model(treeview);

    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(GTK_LIST_STORE(model), &iter,
                           COLUMN_ID, &id,
                           COLUMN_ETS, &ETS,
                           COLUMN_DATE, &date,
                           COLUMN_TEMPS, &temps,
                           -1);

        // Do something with the retrieved data...

        
        r2.id = id;
    g_strlcpy(r2.ETS, ETS, sizeof(r2.ETS));
    g_strlcpy(dates2, date, sizeof(r2.date));
    g_strlcpy(r2.cr, temps, sizeof(r2.cr));
    printf("%s %s %s\n", r2.ETS, r2.cr,dates2);
    // Free allocated strings
        g_free(ETS);
        g_free(date);
        g_free(temps);
        x=1;
}
}


void
on_buttoncr_clicked                    (GtkWidget *objet_graphique, gpointer user_data)
{   GtkWidget *err1;
    err1 = lookup_widget(objet_graphique, "label58");

    // Check if the label exists
    if (err1 == NULL) {
        g_print("Error: label58 not found!\n");
        return;
    }

    char *text = g_strdup_printf("%d", crn);
    gtk_label_set_text(GTK_LABEL(err1), text);

    // Free the allocated string
    g_free(text);
}
void
on_treeviewU_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_Udeconnexcion_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}

void
on_UgenreFemmeAjout_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{g=2;} 
}


void
on_UgenreHommeAjout_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{g=1;} 
}

void
on_UgenreHommeModifier_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{g1=1;} 
}


void
on_UgenreFemmeModifier_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{g1=2;} 
}

void
on_UajoutWidget_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Uajoute,*Uaffiche;
     Uaffiche = lookup_widget(button,"Uaffiche");
   gtk_widget_destroy(Uaffiche);
     Uajoute = lookup_widget(button,"Uajoute");
     Uajoute = create_Uajoute();
     gtk_widget_show(Uajoute);
}


void
on_UmodifierWidget_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Umodife,*Uaffiche;
     Uaffiche = lookup_widget(button,"Uaffiche");
   gtk_widget_destroy(Uaffiche);
     Umodife = lookup_widget(button,"Umodife");
     Umodife = create_Umodife();
     gtk_widget_show(Umodife);
}


void
on_UsupprimerWidget_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *Usupprime,*Uaffiche;
     Uaffiche = lookup_widget(button,"Uaffiche");
   gtk_widget_destroy(Uaffiche);
     Usupprime = lookup_widget(button,"Usupprime");
     Usupprime = create_Usupprime();
     gtk_widget_show(Usupprime);
}


void
on_Uactualiser_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *Uaffiche,*w1,*treeview;
      w1=lookup_widget(button,"Uaffiche");
      Uaffiche=create_Uaffiche();
       gtk_widget_show(Uaffiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(Uaffiche,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateur(treeview, "rayen.txt");
}


void
on_UstatistiqueWidget_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Ustatistique,*Uaffiche;
     Uaffiche = lookup_widget(button,"Uaffiche");
   gtk_widget_destroy(Uaffiche);
     Ustatistique = lookup_widget(button,"Ustatistique");
     Ustatistique = create_Ustatistique();
     gtk_widget_show(Ustatistique);
}


void
on_UannulerAjoutButton_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *Uajoute,*Uaffiche;
     Uajoute = lookup_widget(button,"Uajoute");
   gtk_widget_destroy(Uajoute);
     Uaffiche = lookup_widget(button,"Uaffiche");
     Uaffiche = create_Uaffiche();
     gtk_widget_show(Uaffiche);
}

//bouton ajouter

void
on_UajoutButton_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *cin,*nom,*prenom,*jj,*mm,*yy,*region,*num,*role,*login,*mdp,*Uajoute,*label,*pInfo,*Uaffiche,*w1,*treeview;
   int b = 1;
   utilisateur u;

   Uajoute = lookup_widget(button,"Uajoute");
           Uajoute = create_Uajoute();

  cin = lookup_widget(button,"UcinEntryAjout");
  nom =lookup_widget(button,"UnomEntryAjout");
  prenom = lookup_widget(button,"UprenomEntryAjout");
  jj = lookup_widget(button,"UjjSpinAjout");
  mm = lookup_widget(button,"UmmSpinAjout");
  yy = lookup_widget(button,"UyySpinAjout");
  region = lookup_widget(button,"UregionComboAjout");
  num = lookup_widget(button,"UnumEntryAjout");
  role = lookup_widget(button,"UroleComboAjout");
  login = lookup_widget(button,"UloginEntryAjout");
  mdp = lookup_widget(button,"UmdpEntryAjout");
  label = lookup_widget(button,"UcontroleSaisiAjout");    

  strcpy(u.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
  strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
  u.dateNaissance.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        u.dateNaissance.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        u.dateNaissance.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
  strcpy(u.Region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));
  strcpy(u.num,gtk_entry_get_text(GTK_ENTRY(num)));
   strcpy(u.Role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
   strcpy(u.login,gtk_entry_get_text(GTK_ENTRY(login)));
   strcpy(u.mpd,gtk_entry_get_text(GTK_ENTRY(mdp)));

    if(g == 1){
     strcpy(u.genre,"Homme");
  }else{
       strcpy(u.genre,"Femme");

    }

     if(strcmp(u.Cin,"")==0 ){
      
           b=0;
             }
       if(strcmp(u.nom,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.prenom,"")==0 ){
      
           b=0;
             }
      if(strcmp(u.Region,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.num,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.Role,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.login,"")==0 ){
      
           b=0;
             }
          if(strcmp(u.mpd,"")==0 ){
      
           b=0;
             }
          
                 if(b == 1){
       int t =  ajouterUtilisateur("rayen.txt",u);
       if(t == 1){
//++++++++++++++
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Ajout Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
                  gtk_entry_set_text(GTK_ENTRY(cin),"");
                  gtk_entry_set_text(GTK_ENTRY(nom),"");
                  gtk_entry_set_text(GTK_ENTRY(prenom),"");
                  gtk_entry_set_text(GTK_ENTRY(num),"");
                  gtk_entry_set_text(GTK_ENTRY(login),"");
                  gtk_entry_set_text(GTK_ENTRY(mdp),"");
                  
                gtk_widget_destroy(Uajoute);
              Uaffiche = lookup_widget(button,"Uaffiche");
             Uaffiche = create_Uaffiche();
             gtk_widget_show(Uaffiche);
                 w1=lookup_widget(button,"Uaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(Uaffiche,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateur(treeview, "rayen.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }

   
}

//afficher mot passe 

void
on_UafficherMdpAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    GtkWidget *pass,*buttoncheck;
       pass = lookup_widget(togglebutton, "UmdpEntryAjout");
     buttoncheck = lookup_widget(togglebutton,"UafficherMdpAjout");
   
    if( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(buttoncheck))){
       gtk_entry_set_visibility(pass,TRUE);
   }else{
       gtk_entry_set_visibility(pass,FALSE);
   }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++



void
on_UsupprimerButton_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *cin,*Usupprime,*label,*pInfo,*Uaffiche,*w1,*treeview;
      int b = 1;
    char cin1[50];
   Usupprime = lookup_widget(button,"Usupprime");
           Usupprime = create_Usupprime();
  cin = lookup_widget(button,"UidEntrySupprimer");
 
  label = lookup_widget(button,"UcontroleSaisiSupprimer");    

  strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(cin)));
 
  

     if(strcmp(cin1,"")==0 ){
      
           b=0;
             }
      
          
                 if(b == 1){
       int t =  supprimerUtilisateur("rayen.txt",cin1);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Supprimer  Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
                  gtk_entry_set_text(GTK_ENTRY(cin),"");
                  
                  
                gtk_widget_destroy(Usupprime);
              Uaffiche = lookup_widget(button,"Uaffiche");
             Uaffiche = create_Uaffiche();
             gtk_widget_show(Uaffiche);
                 w1=lookup_widget(button,"Uaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(Uaffiche,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateur(treeview, "rayen.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }
}


void
on_UannulerSupprimerButton_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *Usupprime,*Uaffiche;
     Usupprime = lookup_widget(button,"Usupprime");
   gtk_widget_destroy(Usupprime);
     Uaffiche = lookup_widget(button,"Uaffiche");
     Uaffiche = create_Uaffiche();
     gtk_widget_show(Uaffiche);
}




//retour statistique 

void
on_UannulerStatistiqueButton_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Ustatistique,*Uaffiche;
     Ustatistique = lookup_widget(button,"Ustatistique");
   gtk_widget_destroy(Ustatistique);
     Uaffiche = lookup_widget(button,"Uaffiche");
     Uaffiche = create_Uaffiche();
     gtk_widget_show(Uaffiche);
}

//bouton modifier 

void
on_UModifierButton_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *cin,*nom,*prenom,*jj,*mm,*yy,*region,*num,*role,*login,*mdp,*Umodife,*label,*pInfo,*Uaffiche,*w1,*treeview;
   int b = 1;
   utilisateur u;

   Umodife = lookup_widget(button,"Umodife");
           Umodife = create_Umodife();

  cin = lookup_widget(button,"UcinEntryModifier");
  nom =lookup_widget(button,"UnomEntryModifier");
  prenom = lookup_widget(button,"UprenomEntryModifier");
  jj = lookup_widget(button,"UjjSpinModifier");
  mm = lookup_widget(button,"UmmSpinModifier");
  yy = lookup_widget(button,"UyySpinModifier");
  region = lookup_widget(button,"UregionComboModifier");
  num = lookup_widget(button,"UnumEntryModifier");
  role = lookup_widget(button,"UroleComboModifier");
  login = lookup_widget(button,"UloginEntryModifier");
  mdp = lookup_widget(button,"UmdpEntryModifier");
  label = lookup_widget(button,"UcontroleSaisiModifier");    

  strcpy(u.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
  strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
  u.dateNaissance.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        u.dateNaissance.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        u.dateNaissance.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
  strcpy(u.Region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));
  strcpy(u.num,gtk_entry_get_text(GTK_ENTRY(num)));
   strcpy(u.Role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
   strcpy(u.login,gtk_entry_get_text(GTK_ENTRY(login)));
   strcpy(u.mpd,gtk_entry_get_text(GTK_ENTRY(mdp)));

    if(g1 == 1){
     strcpy(u.genre,"Homme");
  }else{
       strcpy(u.genre,"Femme");

    }

     if(strcmp(u.Cin,"")==0 ){
      
           b=0;
             }
       if(strcmp(u.nom,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.prenom,"")==0 ){
      
           b=0;
             }
      if(strcmp(u.Region,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.num,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.Role,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.login,"")==0 ){
      
           b=0;
             }
          if(strcmp(u.mpd,"")==0 ){
      
           b=0;
             }
          
                 if(b == 1){
       int t =  modifierUtilisateur("rayen.txt",u.Cin,u);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Modifier Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
                  gtk_entry_set_text(GTK_ENTRY(cin),"");
                  gtk_entry_set_text(GTK_ENTRY(nom),"");
                  gtk_entry_set_text(GTK_ENTRY(prenom),"");
                  gtk_entry_set_text(GTK_ENTRY(num),"");
                  gtk_entry_set_text(GTK_ENTRY(login),"");
                  gtk_entry_set_text(GTK_ENTRY(mdp),"");
                  
                gtk_widget_destroy(Umodife);
              Uaffiche = lookup_widget(button,"Uaffiche");
             Uaffiche = create_Uaffiche();
             gtk_widget_show(Uaffiche);
                 w1=lookup_widget(button,"Uaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(Uaffiche,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateur(treeview, "rayen.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed modifier  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }

}

//modifier vers afficher

void
on_UannulerModifierButton_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *Umodife,*Uaffiche;
     Umodife = lookup_widget(button,"Umodife");
   gtk_widget_destroy(Umodife);
     Uaffiche = lookup_widget(button,"Uaffiche");
     Uaffiche = create_Uaffiche();
     gtk_widget_show(Uaffiche);
}

// affichage mot de passe modifier ++++++++++++++++++++++++++++++

void
on_UafficherMdpModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
     GtkWidget *pass,*buttoncheck;
       pass = lookup_widget(togglebutton, "UmdpEntryModifier");
     buttoncheck = lookup_widget(togglebutton,"UafficherMdpModifier");
   
    if( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(buttoncheck))){
       gtk_entry_set_visibility(pass,TRUE);
   }else{
       gtk_entry_set_visibility(pass,FALSE);
   }
}



//bouton chercher modifier 

void
on_UbuttonRechercherIDModifier_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *cin,*nom,*prenom,*jj,*mm,*yy,*region,*num,*role,*login,*mdp,*Umodife,*label,*pInfo,*Uaffiche,*w1,*treeview;
   int b = 1;
   utilisateur u;
   char cin1[50];
   Umodife = lookup_widget(button,"Umodife");
           Umodife = create_Umodife();
  cin = lookup_widget(button,"UcinEntryModifier");
  nom =lookup_widget(button,"UnomEntryModifier");
  prenom = lookup_widget(button,"UprenomEntryModifier");

  region = lookup_widget(button,"UregionComboModifier");
  num = lookup_widget(button,"UnumEntryModifier");
  role = lookup_widget(button,"UroleComboModifier");
  login = lookup_widget(button,"UloginEntryModifier");
  mdp = lookup_widget(button,"UmdpEntryModifier");
  label = lookup_widget(button,"UcontroleSaisiModifier");    

  strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(cin)));
 



     if(strcmp(cin1,"")==0 ){
      
           b=0;
             }

         if(b == 1){

     u =  chercherUtilisateurByCin("rayen.txt", cin1);
       if(strcmp(u.Cin,"-1")==0){

pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"ets n'est pas trouver ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 gtk_entry_set_text(GTK_ENTRY(cin),"");
               break;}

          }else{
                 
                 
              gtk_entry_set_text(GTK_ENTRY(cin),u.Cin);
                  gtk_entry_set_text(GTK_ENTRY(nom),u.nom);
                  gtk_entry_set_text(GTK_ENTRY(prenom),u.prenom);
                  gtk_entry_set_text(GTK_ENTRY(num),u.num);
                  gtk_entry_set_text(GTK_ENTRY(login),u.login);
                  gtk_entry_set_text(GTK_ENTRY(mdp),u.mpd);
                 
                 // gtk_combo_box_set_active_iter(region, p.region);
          }



     }else if (b == 0){

         gtk_label_set_text(GTK_LABEL(label),"verifier votre Cin   ❌️");

       }
      
}
void
on_Ubutton_AfficherByRole_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *role,*pInfo,*Uaffiche,*w1,*treeview;
       int b = 1;
    char role1[50];
    Uaffiche = lookup_widget(button,"Uaffiche");
     Uaffiche = create_Uaffiche();
    role = lookup_widget(button,"Ucombobox_filtre");
     strcpy(role1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
      if(strcmp(role1,"")==0 ){
      
       pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"case est vide  ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
     }else{

         
      w1=lookup_widget(button,"Uaffiche");
      Uaffiche=create_Uaffiche();
       gtk_widget_show(Uaffiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(Uaffiche,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateurByRole(treeview, "rayen.txt",role1);
}

}


void
on_UsearchButton_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *cin,*pInfo,*Uaffiche,*w1,*treeview;
       int b = 1;
    char cin1[50];
    Uaffiche = lookup_widget(button,"Uaffiche");
     Uaffiche = create_Uaffiche();
    cin = lookup_widget(button,"UsearchEntry");
     strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(cin)));
      if(strcmp(cin1,"")==0 ){
      
       pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"case est vide  ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
     }else{

         
      w1=lookup_widget(button,"Uaffiche");
      Uaffiche=create_Uaffiche();
       gtk_widget_show(Uaffiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(Uaffiche,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateurByCin(treeview, "rayen.txt",cin1);
}
}
void
on_afficher_don_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview;
        GtkWidget *window1;
        window1=lookup_widget(objet_graphique,"acceuil_don_rania");
        treeview=lookup_widget(objet_graphique,"treeview1");
        
        afficher_don(treeview);
}


void
on_deco_clicked                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_go_to_ajout_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"acceuil_don_rania");
gtk_widget_hide(window1);
window2 =create_ajoute_don();
gtk_widget_show (window2);

}


void
on_go_to_modif_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"acceuil_don_rania");
gtk_widget_hide(window1);
window2 =create_modifer_don();
gtk_widget_show (window2);
}


void
on_recherche_modif_gr_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   char id_don[100];
   char id_donneur[100];
   char id_ets[100];
   char type_sanguin[100];
   char quantite[100];
   char date_don[100];
   int x;
   GtkWidget *input;
   GtkWidget *output;
   input=lookup_widget(objet_graphique,"entry6_md_gr");
   strcpy(id_don,gtk_entry_get_text(GTK_ENTRY(input)));
   x=verifier_don(id_don);
   output=lookup_widget(objet_graphique,"label24_md_gr");
 if ((strlen(id_don)==0))
{
       gtk_label_set_text(GTK_LABEL(output),"veuilez remplir la case");
}
else 
{
if (x == 1) // Membre trouvé
{
    gtk_label_set_text(GTK_LABEL(output), "membre existant");
}
else // Membre non trouvé
{
    gtk_label_set_text(GTK_LABEL(output), "membre non existant");
}

}
}



void
on_modifier_don_gr_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   don d; 
       
        
   GtkWidget *input1, *input2,*input3,*input4,*input5,*combobox;
        GtkWidget *output1;
   input1=lookup_widget(objet_graphique,"entry6_md_gr");
   input2=lookup_widget(objet_graphique,"entry7_md_gr");
   input3=lookup_widget(objet_graphique,"entry8_md_gr");
   input4=lookup_widget(objet_graphique,"entry9_md_gr");
        input5=lookup_widget(objet_graphique,"entry10_md_gr");
   combobox=lookup_widget(objet_graphique,"combobox2_md_gr");
   output1=lookup_widget(objet_graphique,"label23_md_gr");
   



   strcpy(d.id_don,gtk_entry_get_text(GTK_ENTRY(input1)));
   strcpy(d.id_donneur,gtk_entry_get_text(GTK_ENTRY(input2)));
   strcpy(d.id_ets,gtk_entry_get_text(GTK_ENTRY(input3)));
   strcpy(d.quantite,gtk_entry_get_text(GTK_ENTRY(input4)));
        strcpy(d.date_don,gtk_entry_get_text(GTK_ENTRY(input5)));
   strcpy(d.type_sanguin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
   
   modifier_don (d);
    


       if ((strlen(d.id_don)==0)||(strlen(d.id_donneur)==0)||(strlen(d.id_ets)==0)||(strlen(d.date_don)==0) )
        
{
   
       gtk_label_set_text(GTK_LABEL(output1),"veuilez remplir toutes les cases");
}
else
{
     
     
     gtk_label_set_text(GTK_LABEL(output1),"modifié avec succés");
}
}


void
on_go_to_aff_md_gr_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"modifer_don");
gtk_widget_hide(window1);
window2 =create_acceuil_don_rania();
gtk_widget_show (window2);
}


void
on_recherche_supp_don_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   char id_don[100];
   char id_donneur[100];
   char id_ets[100];
   char type_sanguin[100];
   char quantite[100];
   char date_don[100];
   int x;
   GtkWidget *input;
   GtkWidget *output;
   input=lookup_widget(objet_graphique,"recherche_sup_don");
   strcpy(id_don,gtk_entry_get_text(GTK_ENTRY(input)));
   x=verifier_don(id_don);
   output=lookup_widget(objet_graphique,"label28_vr_gr_sup");
 if ((strlen(id_don)==0))
{
       gtk_label_set_text(GTK_LABEL(output),"veuilez remplir la case");
}
else 
{
if (x == 1) // Membre trouvé
{
    gtk_label_set_text(GTK_LABEL(output), "membre existant");
}
else // Membre non trouvé
{
    gtk_label_set_text(GTK_LABEL(output), "membre non existant");
}

}
}


void
on_sup_don_gr_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *output;
don d;
char ref[20];
input=lookup_widget(objet_graphique,"recherche_sup_don");
output=lookup_widget(objet_graphique,"label31gr");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input)));
if(strcmp(ref,d.id_don)==0)
gtk_label_set_text(GTK_LABEL(output),"don n'existe pas");
else
{
supprimer_don(ref);
gtk_label_set_text(GTK_LABEL(output),"suppression avec succée");
}
}


void
on_go_to_aff_sup_gr_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"supprim_don");
gtk_widget_hide(window1);
window2 =create_acceuil_don_rania();
gtk_widget_show (window2);
}


void
on_go_to_supprim_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"acceuil_don_rania");
gtk_widget_hide(window1);
window2 =create_supprim_don();
gtk_widget_show (window2);

}


void
on_go_to_acceuil_ajout_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"ajoute_don");
gtk_widget_hide(window1);
window2 =create_acceuil_don_rania();
gtk_widget_show (window2);

}


void
on_ajoute_don_gr_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   int a;
   don d;
   GtkWidget *input1, *input2,*input3,*input4,*input5,*combobox;
        GtkWidget *output1;
   input1=lookup_widget(objet_graphique,"entry1_aj_gr");
   input2=lookup_widget(objet_graphique,"entry2_aj_rg");
   input3=lookup_widget(objet_graphique,"entry3_aj_gr");
   input4=lookup_widget(objet_graphique,"entry4_aj_gr");
        input5=lookup_widget(objet_graphique,"entry5_date_ajout_gr");
   combobox=lookup_widget(objet_graphique,"combobox1_aj_gr");
   output1=lookup_widget(objet_graphique,"label16_verif_aj_gr");
   



   strcpy(d.id_don,gtk_entry_get_text(GTK_ENTRY(input1)));
   strcpy(d.id_donneur,gtk_entry_get_text(GTK_ENTRY(input2)));
   strcpy(d.id_ets,gtk_entry_get_text(GTK_ENTRY(input3)));
   strcpy(d.quantite,gtk_entry_get_text(GTK_ENTRY(input4)));
        strcpy(d.date_don,gtk_entry_get_text(GTK_ENTRY(input5)));
   strcpy(d.type_sanguin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));

       if ((strlen(d.id_don)==0)||(strlen(d.id_donneur)==0)||(strlen(d.id_ets)==0)||(strlen(d.date_don)==0) )
{

       gtk_label_set_text(GTK_LABEL(output1),"veuilez remplir toutes les cases");
}
else
{
if (verifier_don(d.id_don)==1)
gtk_label_set_text(GTK_LABEL(output1),"don est existe ");
else
{
        ajouter_don(d);
        
        
        gtk_label_set_text(GTK_LABEL(output1),"ajout avec succés");
       
   
}
}
}


void
on_go_to_quantit___sang_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"acceuil_don_rania");
gtk_widget_hide(window1);
window2 =create_quantite_sang();
gtk_widget_show (window2);
}


void on_sang_plus_rare_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
    char types_sanguin[8][100] = {"AB+", "AB-", "A+", "A-", "B+", "B-", "O+", "O-"};
    char resultats[8][100];
    int quantites[8];

    // Appelez la fonction pour trouver les quantités par type de sang
    trouver_quantite_par_type(resultats, quantites);

    // Trouvez le type de sang le moins fréquent
    int index_sang_plus_rare = 0;
    for (int i = 1; i < 8; i++)
    {
        if (quantites[i] < quantites[index_sang_plus_rare])
        {
            index_sang_plus_rare = i;
        }
    }

    // Obtenez le label correspondant
    GtkWidget *label_sang_plus_rare = lookup_widget(objet_graphique, "label33_sang_rare");

    // Ajoutez une vérification pour le label
    if (label_sang_plus_rare == NULL)
    {
        g_print("Erreur : Le label pour le sang le plus rare est NULL.\n");
        return;
    }

    // Mettez à jour le label avec le type de sang le moins fréquent et sa quantité
    char texte[100];
    sprintf(texte, "%s : %d", types_sanguin[index_sang_plus_rare], quantites[index_sang_plus_rare]);
    gtk_label_set_text(GTK_LABEL(label_sang_plus_rare), texte);
}



void
on_afficche_quantit___clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
    char types_sanguin[8][100] = {"AB+", "AB-", "A+", "A-", "B+", "B-", "O+", "O-"};
    char resultats[8][100];
    int quantites[8];

    // Appelez la fonction pour trouver les quantités par type de sang
    trouver_quantite_par_type(resultats, quantites);

    // Obtenez les labels correspondantes
    GtkWidget *labels[8];
    labels[0] = lookup_widget(objet_graphique, "label43");
    labels[1] = lookup_widget(objet_graphique, "label44");
    labels[2] = lookup_widget(objet_graphique, "label45");
    labels[3] = lookup_widget(objet_graphique, "label46");
    labels[4] = lookup_widget(objet_graphique, "label47");
    labels[5] = lookup_widget(objet_graphique, "label48");
    labels[6] = lookup_widget(objet_graphique, "label49");
    labels[7] = lookup_widget(objet_graphique, "label50");

    // Ajoutez des vérifications pour chaque label
    for (int i = 0; i < 8; i++)
    {
        if (labels[i] == NULL)
        {
            g_print("Erreur : Le label %s est NULL.\n", types_sanguin[i]);
            return;
        }
    }

    // Mettez à jour les labels avec les quantités correspondantes
    for (int i = 0; i < 8; i++)
    {
        char texte[100];
        sprintf(texte, " %d",  quantites[i]);
        gtk_label_set_text(GTK_LABEL(labels[i]), texte);
    }
}
void
on_go_to_aff_gr_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"quantite_sang");
gtk_widget_hide(window1);
window2 =create_acceuil_don_rania();
gtk_widget_show (window2);
}
void
on_treeviewFD_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_FDsearchButton_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *id ,*FDaffiche,*label,*pInfo,*w1,*treeview;
    
           int b = 1;
         char id1[50];
         FDaffiche  = lookup_widget(button,"FDaffiche");
           FDaffiche = create_FDaffiche();
        id = lookup_widget(button,"FDsearchEntry"); 
        
        strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
          if(strcmp(id1,"")==0 ){
      
            pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"case est vide  ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
             }else{
                w1=lookup_widget(button,"FDaffiche");
      FDaffiche=create_FDaffiche();
       gtk_widget_show(FDaffiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(FDaffiche,"treeviewFD");
       viderDonneur(treeview);
       rechercherDonneur(treeview,filename,id1);

           }
          
}


void
on_FDdeconnexcion_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_FDajoutWidget_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
       GtkWidget *FDajoute,*FDaffiche;
     FDaffiche = lookup_widget(button,"FDaffiche");
  
     FDajoute = lookup_widget(button,"FDajoute");
     FDajoute = create_FDajoute();
     gtk_widget_show(FDajoute);
       gtk_widget_destroy(FDaffiche);
}


void
on_FDmodifierWidget_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
      GtkWidget *FDmodife,*FDaffiche;
     FDaffiche = lookup_widget(button,"FDaffiche");
  
     FDmodife = lookup_widget(button,"FDmodife");
     FDmodife = create_FDmodife();
     gtk_widget_show(FDmodife);
      gtk_widget_destroy(FDaffiche);
}


void
on_FDsupprimerWidget_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{   GtkWidget *FDsupprime,*FDaffiche;
     FDaffiche = lookup_widget(button,"FDaffiche");
  
     FDsupprime = lookup_widget(button,"FDsupprime");
     FDsupprime = create_FDsupprime();
     gtk_widget_show(FDsupprime);
      gtk_widget_destroy(FDaffiche);

}


void
on_FDactualiser_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *FDaffiche,*w1,*treeview;
      w1=lookup_widget(button,"FDaffiche");
      FDaffiche=create_FDaffiche();
       gtk_widget_show(FDaffiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(FDaffiche,"treeviewFD");
       viderDonneur(treeview);
       afficherDonneur(treeview, filename);
}


void
on_FDstatistiqueWidget_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *FDstatistique,*FDaffiche;
     FDaffiche = lookup_widget(button,"FDaffiche");
  
     FDstatistique = lookup_widget(button,"FDstatistique");
     FDstatistique = create_FDstatistique();
     gtk_widget_show(FDstatistique);
       gtk_widget_destroy(FDaffiche);
}


void
on_FDnonFumeAjout_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{fume1=2;} 
}


void
on_FDouiFumeAjout_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{fume1=1;} 
}


void
on_FDouiTatouAjout_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if (gtk_toggle_button_get_active(togglebutton))
 {tatou1=1;} 
}


void
on_FDnonTatouAjout_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))
 {tatou1=2;} 
}


void
on_FDannulerAjoutButton_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
       GtkWidget *FDajoute,*FDaffiche;
     FDajoute = lookup_widget(button,"FDajoute");
   
     FDaffiche = lookup_widget(button,"FDaffiche");
     FDaffiche = create_FDaffiche();
     gtk_widget_show(FDaffiche);
     gtk_widget_destroy(FDajoute);
}


void
on_FDajoutButton_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
       GtkWidget *id ,*cin,*etab,*jj,*mm,*yy,*heure,*type,*FDajoute,*label,*pInfo,*FDaffiche,*w1,*treeview;

         int b = 1;
         Donneur d;
          FDajoute = lookup_widget(button,"FDajoute");
           FDajoute = create_FDajoute();
        id = lookup_widget(button,"FDidEntryAjout"); 
        cin = lookup_widget(button,"FDcinEntryAjout");
         etab= lookup_widget(button,"FDetabComboAjout");
        jj =  lookup_widget(button,"FDjjSpinAjout");
        mm =  lookup_widget(button,"FDmmSpinAjout");
        yy =   lookup_widget(button,"FDyySpinAjout");
        heure = lookup_widget(button,"FDheureEntryAjout");
        type =  lookup_widget(button,"FDtypeComboAjout");
        label = lookup_widget(button,"FDcontroleSaisiAjout");
        strcpy(d.id,gtk_entry_get_text(GTK_ENTRY(id)));
        strcpy(d.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
        strcpy(d.etab,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etab)));
        d.dateRdv.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        d.dateRdv.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        d.dateRdv.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
        strcpy(d.heure,gtk_entry_get_text(GTK_ENTRY(heure)));
        strcpy(d.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
        if(fume1 == 1){
          strcpy(d.fume,"oui");
         }else{
         strcpy(d.fume,"non");
         }
          if(tatou1 == 1){
          strcpy(d.tatouage,"oui");
         }else {
         strcpy(d.tatouage,"non");
         }
            if(strcmp(d.id,"")==0 ){
      
           b=0;
             }
              if(strcmp(d.Cin,"")==0 ){
      
           b=0;
             }
              if(strcmp(d.etab,"")==0 ){
      
           b=0;
             }

             if(strcmp(d.heure,"")==0 ){
      
           b=0;
             }
             if(strcmp(d.type,"")==0 ){
      
           b=0;
             }




                 if(b == 1){
       int t =  ajouterDonneur(filename,d);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Ajout Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                  gtk_entry_set_text(GTK_ENTRY(cin),"");
                  gtk_entry_set_text(GTK_ENTRY(heure),"");
                  
                
              FDaffiche = lookup_widget(button,"FDaffiche");
             FDaffiche = create_FDaffiche();
             gtk_widget_show(FDaffiche);
                gtk_widget_destroy(FDajoute);
                 w1=lookup_widget(button,"FDaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(FDaffiche,"treeviewFD");
       viderDonneur(treeview);
       afficherDonneur(treeview, filename);
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }


       
}





void
on_FDannulerModifierButton_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *FDmodife,*FDaffiche;
     FDmodife = lookup_widget(button,"FDmodife");
  
     FDaffiche = lookup_widget(button,"FDaffiche");
     FDaffiche = create_FDaffiche();
     gtk_widget_show(FDaffiche);
       gtk_widget_destroy(FDmodife);
}


void
on_FDnonTatouModifier_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
 {tatou2=2;} 
}


void
on_FDouiTatouModifier_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
 {tatou2=1;} 
}


void
on_FDouiFumeModifier_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{fume2=1;} 
}


void
on_FDnonFumeModifier_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{fume2=2;} 
}

void
on_FDmodifierButton_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *id ,*cin,*etab,*jj,*mm,*yy,*heure,*type,*FDmodife,*label,*pInfo,*FDaffiche,*w1,*treeview;

         int b = 1;
         Donneur d;
          FDmodife = lookup_widget(button,"FDmodife");
           FDmodife = create_FDmodife();
        id = lookup_widget(button,"FDidEntryModifier"); 
        cin = lookup_widget(button,"FDcinEntryModifier");
         etab= lookup_widget(button,"FDetabComboModifier");
        jj =  lookup_widget(button,"FDjjSpinModifier");
        mm =  lookup_widget(button,"FDmmSpinAjout");
        yy =   lookup_widget(button,"FDmmSpinModifier");
        heure = lookup_widget(button,"FDheureEntryModifier");
        type =  lookup_widget(button,"FDtypeComboModifier");
        label = lookup_widget(button,"FDcontroleSaisiModifier");
        strcpy(d.id,gtk_entry_get_text(GTK_ENTRY(id)));
        strcpy(d.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
        strcpy(d.etab,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etab)));
        d.dateRdv.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        d.dateRdv.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        d.dateRdv.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
        strcpy(d.heure,gtk_entry_get_text(GTK_ENTRY(heure)));
        strcpy(d.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
        if(fume2 == 1){
          strcpy(d.fume,"oui");
         }else{
         strcpy(d.fume,"non");
         }
          if(tatou2 == 1){
          strcpy(d.tatouage,"oui");
         }else{
         strcpy(d.tatouage,"non");
         }
            if(strcmp(d.id,"")==0 ){
      
           b=0;
             }
              if(strcmp(d.Cin,"")==0 ){
      
           b=0;
             }
              if(strcmp(d.etab,"")==0 ){
      
           b=0;
             }

             if(strcmp(d.heure,"")==0 ){
      
           b=0;
             }
             if(strcmp(d.type,"")==0 ){
      
           b=0;
             }




                 if(b == 1){
       int t =  modifierDonneur(filename,d.id,d);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Modifier Avec succée ");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                  gtk_entry_set_text(GTK_ENTRY(cin),"");
                  gtk_entry_set_text(GTK_ENTRY(heure),"");
                  
               
              FDaffiche = lookup_widget(button,"FDaffiche");
             FDaffiche = create_FDaffiche();
             gtk_widget_show(FDaffiche);
              gtk_widget_destroy(FDmodife);
                 w1=lookup_widget(button,"FDaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(FDaffiche,"treeviewFD");
       viderDonneur(treeview);
       afficherDonneur(treeview, filename);
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed modifier  ");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ");
     }
}

void
on_FDsearchModifierButton_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *id ,*cin,*etab,*jj,*mm,*yy,*heure,*type,*FDmodife,*label,*pInfo,*FDaffiche,*w1,*treeview;

         int b = 1;
         char id1[50]; 
          FDmodife = lookup_widget(button,"FDmodife");
           FDmodife = create_FDmodife();
        id = lookup_widget(button,"FDidEntryModifier"); 
        cin = lookup_widget(button,"FDcinEntryModifier");
         etab= lookup_widget(button,"FDetabComboModifier");
        jj =  lookup_widget(button,"FDjjSpinModifier");
        mm =  lookup_widget(button,"FDmmSpinAjout");
        yy =   lookup_widget(button,"FDmmSpinModifier");
        heure = lookup_widget(button,"FDheureEntryModifier");
        type =  lookup_widget(button,"FDtypeComboModifier");
        label = lookup_widget(button,"FDcontroleSaisiModifier");
        strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
      
     
            if(strcmp(id1,"")==0 ){
      
           b=0;
             }
             if(b == 1){
                Donneur p =  chercherDonneur(filename, id1);
       if(strcmp(p.id,"-1")==0){

pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"ets n'est pas trouver ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 gtk_entry_set_text(GTK_ENTRY(id),"");
               break;}

          }else{
                 
                 
               gtk_entry_set_text(GTK_ENTRY(id),p.id);
                  gtk_entry_set_text(GTK_ENTRY(cin),p.Cin);
                  gtk_entry_set_text(GTK_ENTRY(heure),p.heure);
               //  gtk_combo_box_append_text (GTK_COMBO_BOX (type), _(p.type));
                 
                 // gtk_combo_box_set_active_iter(region, p.region);
          }



     }else if (b == 0){

         gtk_label_set_text(GTK_LABEL(label),"verifier votre id   ❌️");

       }
}


void
on_FDsupprimerButton_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *id ,*FDsupprime,*label,*pInfo,*FDaffiche,*w1,*treeview;
    
           int b = 1;
         char id1[50];
         FDsupprime  = lookup_widget(button,"FDsupprime");
           FDsupprime = create_FDsupprime();
        id = lookup_widget(button,"FDidEntrySupprimer"); 
        label = lookup_widget(button,"FDcontroleSaisiSupprimer");
        strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
          if(strcmp(id1,"")==0 ){
      
           b=0;
             }

         
                 if(b == 1){
       int t =  supprimerDonneur(filename,id1);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Supprimer Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                 
                  
               
              FDaffiche = lookup_widget(button,"FDaffiche");
             FDaffiche = create_FDaffiche();
             gtk_widget_show(FDaffiche);
               gtk_widget_destroy(FDsupprime);
                 w1=lookup_widget(button,"FDaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(FDaffiche,"treeviewFD");
       viderDonneur(treeview);
       afficherDonneur(treeview, filename);
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }
         
}


void
on_FDannulerSupprimerButton_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *FDsupprime,*FDaffiche;
     FDsupprime = lookup_widget(button,"FDsupprime");
 
     FDaffiche = lookup_widget(button,"FDaffiche");
     FDaffiche = create_FDaffiche();
     gtk_widget_show(FDaffiche);
         gtk_widget_destroy(FDsupprime);
}


void
on_FDtreeviewStatistique_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_FDannulerStatistiqueButton_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *FDstatistique,*FDaffiche;
     FDstatistique = lookup_widget(button,"FDstatistique");
  
     FDaffiche = lookup_widget(button,"FDaffiche");
     FDaffiche = create_FDaffiche();
     gtk_widget_show(FDaffiche);
      gtk_widget_destroy(FDstatistique);

}


void
on_FDrdvMoyenneButtonStatistique_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *label,*jj,*mm,*yy,*FDstatistique ;
    FDstatistique = lookup_widget(button,"FDstatistique");
           FDstatistique = create_FDstatistique();
  label = lookup_widget(button,"FDrdvMoyenneLabelStatistique");
   jj =  lookup_widget(button,"jj1");
        mm =  lookup_widget(button,"mm1");
        yy =   lookup_widget(button,"yy1");
    int jj1,mm1,yy1;
     char moyenne1[50];
      jj1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        mm1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
       yy1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
   float moyenne =     moyRDV_ETS("ets.txt",filename, jj1, mm1 ,yy1 );
        sprintf(moyenne1,"%f",moyenne);
     gtk_label_set_text(GTK_LABEL(label),moyenne1);
}


void
on_FDstatistiqueButton_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *id ,*etab,*jj,*mm,*yy,*FDaffiche,*FDstatistique,*label,*pInfo,*w1,*treeview;
     int b =1;
       char etab1[50];
int jj1,mm1,yy1;
         etab= lookup_widget(button,"FDetabComboStatistique");
        jj =  lookup_widget(button,"FDjjSpinStatistique");
        mm =  lookup_widget(button,"FDmmSpinStatistique");
        yy =   lookup_widget(button,"FDyySpinStatistique");
        
        label = lookup_widget(button,"FDcontroleSaisiStatistique");
         FDstatistique = lookup_widget(button,"FDstatistique");
           FDstatistique = create_FDstatistique();
           strcpy(etab1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etab)));
        jj1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        mm1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
       yy1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
    if(jj1>0 &&  jj1<32){

        b =0;

      }
          if(mm1>0 &&  mm1<13){

        b =0;

      }
            if(yy1>1950 &&  yy1<2025){

        b =0;

      } 


      if(strcmp(etab1,"")==0){
         b =0;
      }

    if(b =1){

          FDstatistique = lookup_widget(button,"FDstatistique");
             FDstatistique = create_FDstatistique();
             gtk_widget_show(FDstatistique);
                 w1=lookup_widget(button,"FDstatistique");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(FDstatistique,"FDtreeviewStatistique");
     //  viderDonneur(treeview);
       listeRdvTreeView(treeview, filename,etab1,jj1,mm1,yy1);
    }else{

        gtk_label_set_text(GTK_LABEL(label),"verifier vos donner");
      }
     
}
void
on_NL_buttonAjouterETS_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *id,*nom,*adresse,*capacite,*region,*telephone,*NL_Ajouter_ETS,*label,*pInfo,*NL_Afficher_ETS,*w1,*treeview;
    char varid[50],varcapacite[50],vartelephone[50];
    ets e;
    int b = 1;
    NL_Ajouter_ETS = lookup_widget(button,"NL_Ajouter_ETS");
     NL_Ajouter_ETS = create_NL_Ajouter_ETS();
    id = lookup_widget(button,"NL_entryId");
    nom =  lookup_widget(button,"NL_entrynom");
    adresse =  lookup_widget(button,"NL_entryemail");
    capacite =  lookup_widget(button,"spinbutton21");
    region = lookup_widget(button,"NL_ComboBoxRegion1");
    telephone = lookup_widget(button,"NL_entrytelephone");
    label = lookup_widget(button,"NL_Ajout_Controle_Saisi");
    strcpy(varid,gtk_entry_get_text(GTK_ENTRY(id)));
    e.id = atoi(varid);
    strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
    strcpy(e.adresse,gtk_entry_get_text(GTK_ENTRY(nom)));
    e.capacite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capacite));
     strcpy(e.region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));
    strcpy(vartelephone,gtk_entry_get_text(GTK_ENTRY(telephone)));
    e.telephone = vartelephone;
    if( e.id == 0 ){
       
       b=0;
     }
     if(strcmp(e.nom,"")==0 ){
      
       b=0;
     }
      if(strcmp(e.adresse,"")==0 ){
      
       b=0;
     }
      if(e.capacite==0 ){
      
       b=0;
     }
    if(strcmp(e.region,"")==0 ){
      
       b=0;
     }
    
      if( e.telephone == 0 ){
       
       b=0;
     }
     
     if(b == 1){
       int t =  ajouterEts("nermine.txt",e);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Ajout Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                  gtk_entry_set_text(GTK_ENTRY(nom),"");
                  gtk_entry_set_text(GTK_ENTRY(adresse),"");
                  gtk_entry_set_text(GTK_ENTRY(telephone),"");
                gtk_widget_destroy(NL_Ajouter_ETS);
              NL_Afficher_ETS = lookup_widget(button,"NL_Afficher_ETS");
             NL_Afficher_ETS = create_NL_Afficher_ETS();
             gtk_widget_show(NL_Afficher_ETS);
                 w1=lookup_widget(button,"NL_Afficher_ETS");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(NL_Afficher_ETS,"NL_treeviewETS");
       vider_Ets(treeview);
       afficherEts(treeview, "nermine.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }
     
}


void
on_NL_buttonRetourETS_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *NL_Ajouter_ETS,*NL_Afficher_ETS;
     NL_Ajouter_ETS = lookup_widget(button,"NL_Ajouter_ETS");
   gtk_widget_destroy(NL_Ajouter_ETS);
     NL_Afficher_ETS = lookup_widget(button,"NL_Afficher_ETS");
     NL_Afficher_ETS = create_NL_Afficher_ETS();
     gtk_widget_show(NL_Afficher_ETS);

}


void
on_buttonAnnulerModification_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
      GtkWidget *NL_Modifier_ETS,*NL_Afficher_ETS;
     NL_Modifier_ETS = lookup_widget(button,"NL_Modifier_ETS");
   gtk_widget_destroy(NL_Modifier_ETS);
     NL_Afficher_ETS = lookup_widget(button,"NL_Afficher_ETS");
     NL_Afficher_ETS = create_NL_Afficher_ETS();
     gtk_widget_show(NL_Afficher_ETS);
}


void
on_buttonValiderModification_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *id,*nom,*adresse,*capacite,*region,*telephone,*NL_Modifier_ETS,*label,*pInfo,*NL_Afficher_ETS,*w1,*treeview;
    char varid[50],varcapacite[50],vartelephone[50];
    ets e;
    int b = 1;
    NL_Modifier_ETS = lookup_widget(button,"NL_Modifier_ETS");
     NL_Modifier_ETS = create_NL_Modifier_ETS();
    id = lookup_widget(button,"NL_entryID");
    nom =  lookup_widget(button,"NL_modentryNom");
    adresse =  lookup_widget(button,"NL_entrymodemail");
    capacite =  lookup_widget(button,"spinbuttonmodcapacite");
    region = lookup_widget(button,"NL_Modifier_Combo_2");
    telephone = lookup_widget(button,"NL_entrymodtelephone");
    label = lookup_widget(button,"NL_Modifier_Controle_Saisi");
    strcpy(varid,gtk_entry_get_text(GTK_ENTRY(id)));
    e.id = atoi(varid);
    strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
    strcpy(e.adresse,gtk_entry_get_text(GTK_ENTRY(nom)));
    e.capacite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capacite));
     strcpy(e.region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));
    strcpy(vartelephone,gtk_entry_get_text(GTK_ENTRY(telephone)));
    e.telephone = vartelephone;
    if( e.id == 0 ){
       
       b=0;
     }
     if(strcmp(e.nom,"")==0 ){
      
       b=0;
     }
      if(strcmp(e.adresse,"")==0 ){
      
       b=0;
     }
      if(e.capacite==0 ){
      
       b=0;
     }
    if(strcmp(e.region,"")==0 ){
      
       b=0;
     }
    
      if( e.telephone == 0 ){
       
       b=0;
     }
     
     if(b == 1){
       int t =  modifierEts("nermine.txt", e.id,e);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"modifier Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                  gtk_entry_set_text(GTK_ENTRY(nom),"");
                  gtk_entry_set_text(GTK_ENTRY(adresse),"");
                  gtk_entry_set_text(GTK_ENTRY(telephone),"");
          gtk_widget_destroy(NL_Modifier_ETS);
              NL_Afficher_ETS = lookup_widget(button,"NL_Afficher_ETS");
             NL_Afficher_ETS = create_NL_Afficher_ETS();
             gtk_widget_show(NL_Afficher_ETS);
                 w1=lookup_widget(button,"NL_Afficher_ETS");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(NL_Afficher_ETS,"NL_treeviewETS");
       vider_Ets(treeview);
       afficherEts(treeview, "nermine.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }
     
}


void
on_buttonRechercherIDModifier_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *id,*nom,*adresse,*capacite,*region,*telephone,*NL_Modifier_ETS,*label,*pInfo; 
       int b =1;
char varid[50],varcapacite[50],vartelephone[50];
    ets e;

     NL_Modifier_ETS = lookup_widget(button,"NL_Modifier_ETS");
     NL_Modifier_ETS = create_NL_Modifier_ETS();
    id = lookup_widget(button,"NL_entryID");
    nom =  lookup_widget(button,"NL_modentryNom");
    adresse =  lookup_widget(button,"NL_entrymodemail");
    capacite =  lookup_widget(button,"spinbuttonmodcapacite");
    region = lookup_widget(button,"NL_Modifier_Combo_2");
    telephone = lookup_widget(button,"NL_entrymodtelephone");
    label = lookup_widget(button,"NL_Modifier_Controle_Saisi");
    strcpy(varid,gtk_entry_get_text(GTK_ENTRY(id)));
    e.id = atoi(varid); 
    if( e.id == 0 ){
       
       b=0;
     }

    if(b == 1){

     ets p =  chercherEts("nermine.txt", e.id);
       if(p.id == -1){

pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"ets n'est pas trouver ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 gtk_entry_set_text(GTK_ENTRY(id),"");
               break;}

          }else{
                 sprintf(varid,"%d",p.id);
                 sprintf(vartelephone,"%d",p.telephone);
                 
               gtk_entry_set_text(GTK_ENTRY(id),varid);
                  gtk_entry_set_text(GTK_ENTRY(nom),p.nom);
                  gtk_entry_set_text(GTK_ENTRY(adresse),p.adresse);
                  gtk_entry_set_text(GTK_ENTRY(telephone),vartelephone);
                 
                 // gtk_combo_box_set_active_iter(region, p.region);
          }



     }else if (b == 0){

         gtk_label_set_text(GTK_LABEL(label),"verifier votre id   ❌️");

       }
    
}


void
on_NL_treeviewETS_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_NL_button_AfficherByRole_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *region,*pInfo,*NL_Afficher_ETS,*w1,*treeview;
       int b = 1;
    char region1[50];
    NL_Afficher_ETS = lookup_widget(button,"NL_Afficher_ETS");
     NL_Afficher_ETS = create_NL_Afficher_ETS();
    region = lookup_widget(button,"NL_combobox_filtre");
     strcpy(region1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));
      if(strcmp(region1,"")==0 ){
      
       pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"case est vide  ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
     }else{

         
      w1=lookup_widget(button,"NL_Afficher_ETS");
      NL_Afficher_ETS=create_NL_Afficher_ETS();
       gtk_widget_show(NL_Afficher_ETS);
       gtk_widget_hide(w1);
       treeview=lookup_widget(NL_Afficher_ETS,"NL_treeviewETS");
       vider_Ets(treeview);
       afficherEtsByRegion(treeview, "nermine.txt",region1);

   }
      
}


void
on_NL_Button_tree_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *NL_Afficher_ETS,*w1,*treeview;
      w1=lookup_widget(button,"NL_Afficher_ETS");
      NL_Afficher_ETS=create_NL_Afficher_ETS();
       gtk_widget_show(NL_Afficher_ETS);
       gtk_widget_hide(w1);
       treeview=lookup_widget(NL_Afficher_ETS,"NL_treeviewETS");
       vider_Ets(treeview);
       afficherTrier(treeview, "nermine.txt");
}


void
on_actualisertrie_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{  GtkWidget *NL_Afficher_ETS,*w1,*treeview;
      w1=lookup_widget(button,"NL_Afficher_ETS");
      NL_Afficher_ETS=create_NL_Afficher_ETS();
       gtk_widget_show(NL_Afficher_ETS);
       gtk_widget_hide(w1);
       treeview=lookup_widget(NL_Afficher_ETS,"NL_treeviewETS");
       vider_Ets(treeview);
       afficherEts(treeview, "nermine.txt");

}


void
on_NL_buttonAjouterWidgetETS_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{    GtkWidget *NL_Ajouter_ETS,*NL_Afficher_ETS;
     NL_Afficher_ETS = lookup_widget(button,"NL_Afficher_ETS");
   gtk_widget_destroy(NL_Afficher_ETS);
     NL_Ajouter_ETS = lookup_widget(button,"NL_Ajouter_ETS");
     NL_Ajouter_ETS = create_NL_Ajouter_ETS();
     gtk_widget_show(NL_Ajouter_ETS);

}


void
on_NL_buttonModifierWidgetETS_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *NL_Modifier_ETS,*NL_Afficher_ETS;
     NL_Afficher_ETS = lookup_widget(button,"NL_Afficher_ETS");
   gtk_widget_destroy(NL_Afficher_ETS);
     NL_Modifier_ETS = lookup_widget(button,"NL_Modifier_ETS");
     NL_Modifier_ETS = create_NL_Modifier_ETS();
     gtk_widget_show(NL_Modifier_ETS);

}


void
on_NL_buttonSupprimerWidgetETS_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
      GtkWidget *NL_Supprimer_ETS,*NL_Afficher_ETS;
     NL_Afficher_ETS = lookup_widget(button,"NL_Afficher_ETS");
   gtk_widget_destroy(NL_Afficher_ETS);
     NL_Supprimer_ETS = lookup_widget(button,"NL_Supprimer_ETS");
     NL_Supprimer_ETS = create_NL_Supprimer_ETS();
     gtk_widget_show(NL_Supprimer_ETS);
}


void
on_buttonAnnulerSuppression_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *NL_Supprimer_ETS,*NL_Afficher_ETS;
     NL_Supprimer_ETS = lookup_widget(button,"NL_Supprimer_ETS");
   gtk_widget_destroy(NL_Supprimer_ETS);
     NL_Afficher_ETS = lookup_widget(button,"NL_Afficher_ETS");
     NL_Afficher_ETS = create_NL_Afficher_ETS();
     gtk_widget_show(NL_Afficher_ETS);
}


void
on_buttonValiderSuppression_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *id,*NL_Supprimer_ETS,*label,*pInfo,*NL_Afficher_ETS,*w1,*treeview;
 char varid[50];
  int b =1;
   int id1;
  NL_Supprimer_ETS = lookup_widget(button,"NL_Supprimer_ETS");
     NL_Supprimer_ETS = create_NL_Supprimer_ETS();
    id = lookup_widget(button,"NL_entryIdSupprimer");
   label = lookup_widget(button,"NL_Supprimer_Controle_saisi");
    strcpy(varid,gtk_entry_get_text(GTK_ENTRY(id)));
    id1 = atoi(varid);
     if( id1 == 0 ){
       
       b=0;
     }
     if(b == 1){
       int t =  supprimerEts("nermine.txt", id1);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"supprimer Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                 
          gtk_widget_destroy(NL_Supprimer_ETS);
              NL_Afficher_ETS = lookup_widget(button,"NL_Afficher_ETS");
             NL_Afficher_ETS = create_NL_Afficher_ETS();
             gtk_widget_show(NL_Afficher_ETS);
                 w1=lookup_widget(button,"NL_Afficher_ETS");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(NL_Afficher_ETS,"NL_treeviewETS");
       vider_Ets(treeview);
       afficherEts(treeview, "nermine.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }
    
   
}


void
on_buttonRechercherSuppression_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_NL_buttonConnecter_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sesouvenir_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_NL_buttonAnnulerSuppression_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_NL_buttonConfirmerSuppression_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}








void
on_FDstatistiqueButton1_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
{
     GtkWidget *labelHomme,*labelFemme,*Ustatistique;
       char homme[50],femme[50];

       Ustatistique = lookup_widget(button,"Ustatistique");
     Ustatistique = create_Ustatistique();

        labelHomme  = lookup_widget(button,"UpourcentageHommeLabelStatistique");
        labelFemme = lookup_widget(button,"UpourcentageFemmeLabelStatistique");
      
    float nbH ,nbF;
     afficherPourcentageParSexe("rayen.txt",&nbH,&nbF);
    sprintf(homme,"%.2f",nbH);
    sprintf(femme,"%.2f",nbF);

     gtk_label_set_text(GTK_LABEL(labelHomme),homme);
     gtk_label_set_text(GTK_LABEL(labelFemme),femme);
}
}

