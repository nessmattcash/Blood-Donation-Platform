#ifndef UT_H_INCLUDED
#define UT_H_INCLUDED
#include <gtk/gtk.h>

typedef struct 
{
  int ide;
  char mdpp[60];
  
}log;
int chercherf(int id,char mdp[] , char *historique);
int chercherf1(char id[],char mdp[] , char *historique);
#endif
