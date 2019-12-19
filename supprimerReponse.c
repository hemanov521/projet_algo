#include <stdio.h>
#include <stdlib.h> //Standard Library
#include <string.h>
//Supprime une ligne  d'un fichier qui contient un mot clé défini 
typedef struct
{
    char MotCle[32][26]; //32 mots clés de 26 caractères max
    char Action[255]; // jusqu'a 256 caractères
    char Reponse[255]; // jusqu'a 256 caractères
}REPONSE; // Réponse et mots clés associés

void supprimer(char * MotCle)
{
REPONSE ReponseLigne;
FILE *rep;
FILE *repcopie;
repcopie = fopen("Reponses_copie.dat", "wb");
rep = fopen("Reponses.dat", "rb");
int detecte=0;
int fichier_modifie=0;
int i=0;
int j=0;
//fseek(rep, 0, SEEK_SET);
while(1)
{
if(feof(rep))
{
  printf("Mot cle non detecte\n"); 
  break;
} 
j++;
fread(&ReponseLigne,sizeof(REPONSE),1,rep);
printf("Ligne numero : %i\n",j);
for (i=0; i<32; i++)
{
  if(strstr(ReponseLigne.MotCle[i],MotCle)!=NULL)
  {
  printf("Mot cle detecte : %s\n",ReponseLigne.MotCle[i]);
  detecte=1;
  }
  printf("%s\n",ReponseLigne.MotCle[i]);
}
  if(detecte==0)
  {
  fwrite(&ReponseLigne,sizeof(REPONSE),1,repcopie);
  }
  else
  {
    detecte=0;
  }
}
  fclose(rep);
  fclose(repcopie);
  if(fichier_modifie==1)
  {
  remove("Reponses.dat");
  rename("Reponses_copie.dat","Reponses.dat");
  }
  else
  {
  remove("Reponses_copie.dat");
  }
}

int main()
{
char motcle[32]="MotCle30";
supprimer(motcle);
}
