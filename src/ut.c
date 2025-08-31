#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <gtk/gtk.h>
#include "ut.h"
#include "utilisateur.h"



int chercherf(int id,char mdp[] , char *historique)
{
	log l;
 int t=0;
  FILE *f = fopen(historique, "r");
  if (f != NULL) {

    while (fscanf(f,"%d %s\n ",&l.ide,l.mdpp) != EOF) {
      if ((l.ide == id)&&strcmp(mdp,l.mdpp)==0) {
        t=1;
      }
    }
  }

  fclose(f);
  return t ;
}
int chercherf1(char id[],char mdp[] , char *historique)
{
	utilisateur u;
 int t=0;
  FILE *f = fopen(historique, "r");
  if (f != NULL) {

    while (fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s\n ",u.Cin,u.nom,u.prenom,&u.dateNaissance.jj,&u.dateNaissance.mm,&u.dateNaissance.yy,u.genre,u.Region,u.num,u.Role,u.login,u.mpd) != EOF) {
      if (strcmp(u.login,id)==0&&strcmp(mdp,u.mpd)==0) {
        t=1;
      }
    }
  }

  fclose(f);
  return t ;
}
