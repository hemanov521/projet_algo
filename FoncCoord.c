/**************************
***     COORDONNEES     ***
***************************/
#include "FoncCoord.h"



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
        /*fscanf(Fichier,"%[^;]%*c", Personne->Nom); // je lis un char * (donc un string) jusqu'au premier ; ou \n
        fscanf(Fichier,"%[^;]%*c", Personne->Prenom);// je lis un char * (donc un string) jusqu'au premier ; ou \n
        fscanf(Fichier,"%[^;]%*c", Personne->Email);// je lis un char * (donc un string) jusqu'au premier ; ou \n
        fscanf(Fichier,"%f\n", &Personne->Importance);// je lis un float et \n
        */
        ChargerCoordonnees(Personne, Fichier);
        AfficherCoordonnees(Personne);
    }
    printf("\n\n\n");
    return 1;
}

int ChargerCoordonnees(COORDONNEES *Personne, FILE *Fichier)
//int ChargerCoordonnees(char *Fichier)
{
    if (Fichier == NULL) 
	{ 
		fprintf(stderr, "\nERREUR : l'acces au fichier n'a pas fonctionnee !\n"); 
		exit (1); 
	} 
    fscanf(Fichier,"%[^;]%*c", Personne->Nom); // je lis un char * (donc un string) jusqu'au premier ; ou \n
    fscanf(Fichier,"%[^;]%*c", Personne->Prenom);// je lis un char * (donc un string) jusqu'au premier ; ou \n
    fscanf(Fichier,"%[^;]%*c", Personne->Email);// je lis un char * (donc un string) jusqu'au premier ; ou \n
    fscanf(Fichier,"%f\n", &Personne->Importance);// je lis un float et \n
    return 1;
}

int RechercheCoordonnees(COORDONNEES *Personne, FILE *Fichier, int choix)
{
    if (Fichier == NULL) 
	{ 
		fprintf(stderr, "\nERREUR : l'acces au fichier n'a pas fonctionnee !\n"); 
		exit (1); 
	}
    else
    {
        COORDONNEES *buffer;
        fseek(Fichier,0,SEEK_SET);
        printf("\nNous recherchons :\n");
        int trouve=0;
        AfficherCoordonnees(Personne);
        while(!feof(Fichier))
        {
            ChargerCoordonnees(buffer, Fichier);//on récupère 1 contact
            switch(choix)
            {
                case 1:if (strstr(buffer->Nom, Personne->Nom)!=NULL) trouve=1;break;
                case 2:if (strstr(buffer->Prenom, Personne->Prenom)!=NULL) trouve=1;break;
                case 3:if (strstr(buffer->Email, Personne->Email)!=NULL) trouve=1;break;
            }
            if (trouve==1) // si trouvé Nom, ou Prénom, ou Email
            {
                printf("\nNous avons trouve : \n");
                AfficherCoordonnees(buffer);
                //on renvoie les coordonnées...
                memcpy(Personne, buffer, sizeof(COORDONNEES)); // je renvoie 
                return 1;
            }
        }
        printf("\nNous n'avons pas trouve...\n");//si j'ai balayé tout le fichier sans faire le return
    }
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
//printf("Là !!!\n");


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
printf("Là !!!\n");

      i++;
printf("Là !!!\n");
      fscanf(Fichier,"%[^\n]\n",ligne);
printf("Là !!!\n");
      if(strstr(ligne,MotCle)!=NULL)
      {
printf("Là !!!\n");
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

