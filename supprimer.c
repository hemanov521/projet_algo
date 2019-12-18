#include <stdio.h>
#include <stdlib.h> //Standard Library
#include <string.h>
//Supprime une ligne  d'un fichier qui contient un mot clé défini 


void supprimer(char * MotCle)
{
FILE *rep;
rep = fopen("Repertoire.dat", "r+");
char *ligne;
ligne =  (char*) malloc( sizeof(char) );
FILE *repcopie;
repcopie = fopen("Repertoire_copie.dat", "w");
int i=0;
if(rep==NULL)
  {
    perror("fpopen");
    return;
  }
  while(!feof(rep))
  {
      i++;
      fscanf(rep,"%[^\n]\n",ligne);
      printf("%s\n",ligne);
      if(strstr(ligne,MotCle)!=NULL)
      {
    printf("Mot cle detecte dans la ligne numero %i\n",i);
      }
      else{
      //printf("Ligne copiee\n");
      fprintf(repcopie,"%s\n",ligne);
      }

  }
  fclose(rep);
  fclose(repcopie);
  remove("Repertoire.dat");
  rename("Repertoire_copie.dat","Repertoire.dat");
}

int main()
{
char motcle[32]="LAGO";
supprimer(motcle);
}
