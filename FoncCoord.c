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
    char *test[640];
    int offset=0;
    if (Fichier == NULL) 
	{ 
		fprintf(stderr, "\nERREUR : l'acces au fichier n'a pas fonctionne !\n"); 
		exit (1); 
	} 

    fseek(Fichier,0,SEEK_SET);
    while(!feof(Fichier))
    {
       /* printf("Curseur : %d\n", ftell(Fichier));
        fgets(Personne->Email, 320, Fichier);
        printf("1%s\n",Personne->Email);
        fseek(Fichier,0,SEEK_SET);
        printf("Curseur : %d\n", ftell(Fichier));
        fgets(Personne->Email, 320, Fichier);
        printf("2%s\n",Personne->Email);
        fread(test, 320,2, Fichier );
        printf("3%s\n",test);
         */
        fscanf(Fichier,"%s;%s;%s;%f\n",Personne->Nom, Personne->Prenom, Personne->Email, Personne->Importance);
        AfficherCoordonnees(Personne);
        //offset=sizeof(Personne->Nom)+ sizeof(Personne->Prenom) +sizeof(Personne->Email)+ sizeof(Personne->Importance)+4;
        //fseek(Fichier, offset, SEEK_CUR);
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
    fscanf(Fichier,"%s;%s;%s;%f",Personne->Nom, Personne->Prenom, Personne->Email, Personne->Importance);
    //printf("\nNom : %s\nPrenom : %s\nEmail : %s\nImportance : %.0f%%\n", UnePersonne->Nom, UnePersonne->Prenom, UnePersonne->Email, 100*UnePersonne->Importance);
    //AfficherCoordonnees(UnePersonne);
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