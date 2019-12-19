/**************************
***     COORDONNEES     ***
***************************/
#include "FoncCoord.h"
#include <unistd.h>



int SaisieCoordonnees(FILE *Fichier)
{
    int res;
    COORDONNEES *Personne;
    Personne = (COORDONNEES *) malloc( sizeof(COORDONNEES) );
    float importance=-1; //initialisation de l'importance à -1 tant que non-renseignee
    printf("\nSaisir Nom : ");
    res=scanf("%s", Personne->Nom); //Saisie du Nom
    printf("\nSaisir Prenom : ");
    res=scanf("%32s", Personne->Prenom); // Saisie du prénom
    printf("\nSaisir Email : ");
    res=scanf("%320s", Personne->Email); // Saisie Email
    while(importance<0 || importance>100) {
        printf("\nSaisir Importance du Client (en pourcentage) : "); // Saisie de l'importance en %
        res=scanf("%f", &importance);}
    Personne->Importance = importance/100; // Conversion du pourcentage pour enregistrement entre 0 et 1
    SauverCoordonnees(Personne, Fichier); // Sauvegarde données dans Fichier
    return res;
}


int SauverCoordonnees(COORDONNEES *Personne, FILE *Fichier)
{
  	if (Fichier == NULL) 
	{ 
		printf("\nErreur d'acces au fichier !\n"); 
		exit (1); 
	}
    fprintf(Fichier,"%s;%s;%s;%f\n",Personne->Nom, Personne->Prenom, Personne->Email, Personne->Importance); //ecriture des données
     return 1;
}

int AfficherCoordonnees(COORDONNEES *Personne) // Fonction d'affichage des coordonnées
{
    printf("\nNom : %s\nPrenom : %s\nEmail : %s\nImportance : %.0f%%\n", Personne->Nom, Personne->Prenom, Personne->Email, 100*Personne->Importance);
    return 1;
}

int ListerCoordonnees(FILE *Fichier) // Fonction d'affichage de l'ensemble du répertoire
{
    COORDONNEES *Personne;
    Personne = (COORDONNEES *) malloc( sizeof(COORDONNEES) );
    //char *test[640];
    //int offset=0;
    if (Fichier == NULL) 
	{ 
		fprintf(stderr, "\nERREUR : l'acces au fichier n'a pas fonctionne !\n"); 
		exit (1); 
	} 
    fseek(Fichier,0,SEEK_SET);
    while(!feof(Fichier))
    {
        fscanf(Fichier,"%[^;]%*c", Personne->Nom); // je lis un char * (donc un string) jusqu'au premier ; ou \n
        fscanf(Fichier,"%[^;]%*c", Personne->Prenom);// je lis un char * (donc un string) jusqu'au premier ; ou \n
        fscanf(Fichier,"%[^;]%*c", Personne->Email);// je lis un char * (donc un string) jusqu'au premier ; ou \n
        fscanf(Fichier,"%f\n", &Personne->Importance);// je lis un float et \n
        AfficherCoordonnees(Personne);
    }
    return 1;
}

int ChargerCoordonnees(COORDONNEES *Personne, FILE *Fichier)
//int ChargerCoordonnees(char *Fichier)
{
    //FILE *sauvegarde;
    //COORDONNEES *UnePersonne;
    //char *Ligne[32+32+320+3+3+1];
    //sauvegarde = fopen(Fichier, "r");
    if (Fichier == NULL) 
	{ 
		fprintf(stderr, "\nERREUR : l'acces au fichier n'a pas fonctionnee !\n"); 
		exit (1); 
	} 

    //fseek(sauvegarde,0,SEEK_SET);
    //fread(&UnePersonne, sizeof(COORDONNEES),1,sauvegarde);
    fscanf(Fichier,"%s;%s;%s;%f",Personne->Nom, Personne->Prenom, Personne->Email, &(Personne->Importance));
    //printf("\nNom : %s\nPrenom : %s\nEmail : %s\nImportance : %.0f%%\n", UnePersonne->Nom, UnePersonne->Prenom, UnePersonne->Email, 100*UnePersonne->Importance);
    AfficherCoordonnees(Personne);
    /*while (fread(&UnePersonne, sizeof(COORDONNEES),1,sauvegarde)!=0)
    {
        //Personne=UnePersonne;
        //AfficherCoordonnees(UnePersonne);
    }*/

    return 1;
}

int InitCOORDONNEES(COORDONNEES *C)
{
    strcpy(C->Nom,"");
    strcpy(C->Prenom,"");
    strcpy(C->Email,"");
    C->Importance=0;
    return 1;
}

void SupprimerLigneCoordonnees(char *MotCle, FILE *Fichier)
{
    char *ligne=  (char*) malloc( sizeof(char) );
    char *buffer =  (char*) malloc( sizeof(char) );
    buffer="";
    FILE *copie;    
    int MAXSIZE = 0xFFF;
    char proclnk[0xFFF];
    char filename[0xFFF];
    int fno;
    ssize_t r;
    int i=0;

    if (Fichier != NULL)
    {
        fno = fileno(Fichier); // Récupération adresse mémoire du fichier
        sprintf(proclnk, "/proc/self/fd/%d", fno);
        r = readlink(proclnk, filename, MAXSIZE); //Récupération adresse absolue dans filename
        if (r < 0)
        {
            printf("failed to readlink\n");
            exit(1);
        }
        filename[r] = '\0';
        //printf("Fichier -> fno -> filename: %p -> %d -> %s\n", Fichier, fno, filename);
    }

/*copie = fopen("Tampon", "a+");

if(copie==NULL)
  {
    printf("fopen error\n");
    return;
  }
  fseek(copie, 0, SEEK_SET);
  printf("fprintf : %d\n",fprintf(copie, "DEBUT DU FICHIER\n"));
  */while(!feof(Fichier))
  {
      i++;
      fscanf(Fichier,"%[^\n]\n",ligne);
      if(strstr(ligne,MotCle)!=NULL)
      {
        //printf("Mot cle '%s' detecte dans la ligne numero %i\n",MotCle,i);
        printf("Voulez vous supprimer la ligne suivante : \n%s\n\nSi oui tapez 1, sinon tapez 2 : ", ligne);
        scanf("%d", &fno);
        getchar();//suppression retour charriot
        if (fno!=1) 
        {   printf("taille ligne : %ld\n",strlen(ligne));
            //buffer = (char *) realloc(buffer, strlen(ligne)*sizeof(char));
            //fputs(ligne, copie);
            strcat(buffer, ligne);
            printf("recopie : %s", ligne);
        }
      }
      else{
      //fprintf(copie,"%s\n",ligne);
      //fputs(ligne, copie);
        //buffer = (char *) realloc(buffer, sizeof(ligne));
        strcat(buffer, ligne);
      }

  }
  printf("Buffer : \n %s", buffer);
  fclose(Fichier);
  printf("Là 2 ?\n");
  copie = fopen("Tampon", "a+");
    if(copie==NULL)
  {
    printf("fopen error\n");
    return;
  }
  else
  {
  fseek(copie, 0, SEEK_SET);
  fputs(buffer, copie);
  fclose(copie);

  }
  printf("Là 3 ?\n");
  remove(filename);
  rename("Tampon",filename);
  free(ligne);
  free(buffer);
  free(copie);
}

