/**************************
***     COORDONNEES     ***
***************************/
#include "FoncCoord.h"



int SaisieCoordonnees( FILE *Fichier)
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

/*
int SaisieCoordonnees(FILE *Fichier)
{
    //int res;
    printf("ici ?");
    char *chaine = (char *) malloc(32);
    char *mail = (char *) malloc(320);
    COORDONNEES *Personne;
    printf("ici ?");
    float importance=0;
    printf("ici ?");
    //InitCOORDONNEES(Personne);
     //initialisation de l'importance à -1 tant que non-renseignee
    printf("ici ?");
    printf("\nici ?");
    printf("\nSaisir Nom : ");
    fgets(chaine, 32, stdin);
    strcpy(Personne->Nom, chaine);
    //scanf("%32s", PersonneLocal.Nom); //Saisie du Nom
    //fgets(Personne->Nom, sizeof(Personne->Nom), stdin);
    printf("\nSaisir Prenom : ");
//    scanf("%32s", Personne->Prenom); // Saisie du prénom
    fgets(chaine, 32, stdin);
    strcpy(Personne->Prenom,chaine);
    printf("\nSaisir Email : ");
//    scanf("%320s", Personne->Email); // Saisie Email
    fgets(chaine, 320, stdin);
    strcpy(Personne->Prenom,chaine);
    while(importance<0 || importance>100) {
        printf("\nSaisir Importance du Client (en pourcentage) : "); // Saisie de l'importance en %
        scanf("%f", &importance);}
    Personne->Importance = importance/100; // Conversion du pourcentage pour enregistrement entre 0 et 1

    SauverCoordonnees(Personne, Fichier); // Sauvegarde données dans Fichier
    return 0;
}*/

int SauverCoordonnees(COORDONNEES *Personne, FILE *Fichier)
{
    //FILE *sauvegarde;
    //sauvegarde = fopen(Fichier, "a"); // Ouverture du fichier pour ajout
 	if (Fichier == NULL) 
	{ 
		printf("\nErreur d'acces au fichier !\n"); 
		exit (1); 
	}

/*	if(fwrite(&Personne, sizeof(Personne),1, sauvegarde) != 0) 
		printf("Donnees sauvegardees !\n"); 
	else
        printf("\nERREUR : Donnees non sauvegardees !\n"); 
*/
    fprintf(Fichier,"%s;%s;%s;%f\n",Personne->Nom, Personne->Prenom, Personne->Email, Personne->Importance); //ecriture des données
    //fclose(sauvegarde); //fermeture fichier
    return 1;
}

int AfficherCoordonnees(COORDONNEES *Personne) // Fonction d'affichage des coordonnées
{
    printf("\nNom : %s\nPrenom : %s\nEmail : %s\nImportance : %.0f%%\n", Personne->Nom, Personne->Prenom, Personne->Email, 100*Personne->Importance);
    return 1;
}

int ListerCoordonnees(FILE *Fichier) // Fonction d'affichage de l'ensemble du répertoire
{
    //FILE *sauvegarde;
    COORDONNEES *Personne;
    //char Ligne[32+32+320+3+3+1];
    //char * token;
    //sauvegarde = fopen(Fichier, "r");

    if (Fichier == NULL) 
	{ 
		fprintf(stderr, "\nERREUR : l'acces au fichier n'a pas fonctionne !\n"); 
		exit (1); 
	} 

    fseek(Fichier,0,SEEK_SET);
    while(!feof(Fichier))
    {
        fscanf(Fichier,"\n%s;%s;%s;%f",Personne->Nom, Personne->Prenom, Personne->Email, Personne->Importance);
        AfficherCoordonnees(Personne);
    }
    /*while(fgets(Ligne, sizeof(Ligne), Fichier) != NULL)
    {
        //printf("%s\n",Ligne);
        token=strtok(Ligne, ";"); // Découpage des infos à chaque ;

        while(token != NULL)
        {
            printf("%s\n",token);
            token = strtok(NULL, ";");
        }
    }*/
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