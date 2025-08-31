#include <gtk/gtk.h>


void
on_button_login_clicked               (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_utilisateur_clicked          (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_ets_clicked                 (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_don_clicked                  (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_fichedonneur_clicked        (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_rdv_clicked                  (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_poche_clicked               (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_retour_aziz_clicked          (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_histo_aziz_clicked           (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_rdv_aziz_clicked             (GtkWidget *objet_graphique, gpointer user_data);

void
on_but_aj_1_aziz_clicked               (GtkWidget *objet_graphique, gpointer user_data);

void
on_radiobutton1_aziz_clicked           (GtkWidget *objet_graphique, gpointer user_data);

void
on_radiobutton2_aziz_clicked           (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_conf_aziz_clicked            (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_suiv_1_aziz_clicked          (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_ann_aziz_1_clicked           (GtkWidget *objet_graphique, gpointer user_data);

void
on_annul_2_aziz_clicked                (GtkWidget *objet_graphique, gpointer user_data);

void
on_term_1_aziz_clicked                 (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_supp1_aziz_clicked           (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_modf_aziz_clicked            (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_quit_2_aziz_clicked          (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_3_ter_aziz_clicked           (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_4_ann_aziz_clicked           (GtkWidget *objet_graphique, gpointer user_data);

void
on_radiobutton4_aziz_clicked           (GtkWidget *objet_graphique, gpointer user_data);

void
on_radiobutton3_aziz_clicked           (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_ajout_2_aziz_clicked         (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_quit_4_aziz_clicked          (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_quit_hist_aziz_clicked       (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_aj_2_aziz_clicked            (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_supp_2_aziz_clicked          (GtkWidget *objet_graphique, gpointer user_data);

void
on_buttonhistoaziz_clicked             (GtkWidget *objet_graphique, gpointer user_data) ;

void
on_checkbutton1aziz_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_shearch_clicked                     (GtkWidget *objet_graphique, gpointer user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttoncr_clicked                    (GtkWidget *objet_graphique, gpointer user_data);

void
on_treeviewU_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Ubutton_AfficherByRole_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_UsearchButton_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_Udeconnexcion_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_UajoutWidget_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_UmodifierWidget_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_UsupprimerWidget_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_Uactualiser_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_UstatistiqueWidget_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_UannulerAjoutButton_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_UajoutButton_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_UafficherMdpAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UgenreFemmeAjout_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UgenreHommeAjout_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UsupprimerButton_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_UannulerSupprimerButton_clicked     (GtkButton       *button,
                                        gpointer         user_data);


void
on_UannulerStatistiqueButton_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_UModifierButton_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_UannulerModifierButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_UafficherMdpModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UgenreHommeModifier_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UgenreFemmeModifier_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UbuttonRechercherIDModifier_clicked (GtkButton       *button,
                                        gpointer         user_data);
void
on_afficher_don_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_deco_clicked                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_go_to_ajout_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_go_to_modif_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_recherche_modif_gr_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_modifier_don_gr_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_go_to_aff_md_gr_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_recherche_supp_don_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_sup_don_gr_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_go_to_aff_sup_gr_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_go_to_supprim_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_go_to_acceuil_ajout_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ajoute_don_gr_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_go_to_quantit___sang_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_sang_plus_rare_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_afficche_quantit___clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_go_to_aff_gr_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
void
on_treeviewFD_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_FDsearchButton_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDdeconnexcion_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDajoutWidget_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDmodifierWidget_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDsupprimerWidget_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDactualiser_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDstatistiqueWidget_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDnonFumeAjout_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FDouiFumeAjout_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FDouiTatouAjout_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FDnonTatouAjout_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FDannulerAjoutButton_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDajoutButton_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDmodifierButton_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDannulerModifierButton_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDnonTatouModifier_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FDouiTatouModifier_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FDouiFumeModifier_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FDnonFumeModifier_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FDsearchModifierButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDsupprimerButton_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDannulerSupprimerButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDtreeviewStatistique_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_FDannulerStatistiqueButton_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDrdvMoyenneButtonStatistique_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDstatistiqueButton_clicked         (GtkButton       *button,
                                        gpointer         user_data);
void
on_NL_buttonAjouterETS_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_NL_buttonRetourETS_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAnnulerModification_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonValiderModification_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRechercherIDModifier_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_NL_treeviewETS_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_NL_button_AfficherByRole_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_NL_Button_tree_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualisertrie_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_NL_buttonAjouterWidgetETS_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_NL_buttonModifierWidgetETS_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_NL_buttonSupprimerWidgetETS_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAnnulerSuppression_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonValiderSuppression_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRechercherSuppression_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_NL_buttonConnecter_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_sesouvenir_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_NL_buttonAnnulerSuppression_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_NL_buttonConfirmerSuppression_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);
void
on_FDstatistiqueButton1_clicked        (GtkButton       *button,
                                        gpointer         user_data);
