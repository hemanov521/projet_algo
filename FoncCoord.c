/**************************
***     COORDONNEES     ***
***************************/
#include "FoncCoord.h"

int SaisieCoordonnees(COORDONNEES *Personne, char *Fichier)
{
    int res;
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

int SauverCoordonnees(COORDONNEES *Personne, char *Fichier)
{
    FILE *sauvegarde;
    sauvegarde = fopen(Fichier, "a"); // Ouverture du fichier pour ajout
 	if (sauvegarde == NULL) 
	{ 
		printf("\nErreur d'ouverture du fichier : %s !\n", Fichier); 
		exit (1); 
	}

	/*if(fwrite(&Personne, sizeof(Personne),1, sauvegarde) != 0) 
		printf("Donnees sauvegardees !\n"); 
	else
        printf("\nERREUR : Donnees non sauvegardees !\n"); */

    fprintf(sauvegarde,"\n%s;%s;%s;%f",Personne->Nom, Personne->Prenom, Personne->Email, Personne->Importance); //ecriture des données
    fclose(sauvegarde); //fermeture fichier
    return 1;
}

int AfficherCoordonnees(COORDONNEES *Personne) // Fonction d'affichage des coordonnées
{
    printf("\nNom : %s\nPrenom : %s\nEmail : %s\nImportance : %.0f%%\n", Personne->Nom, Personne->Prenom, Personne->Email, 100*Personne->Importance);
    return 1;
}

int ListerCoordonnees(char *Fichier) // Fonction d'affichage de l'ensemble du répertoire
{
    FILE *sauvegarde;
    //COORDONNEES *UnePersonne;
    char Ligne[32+32+320+3+3+1];
    char * token;
    sauvegarde = fopen(Fichier, "r");
    if (sauvegarde == NULL) 
	{ 
		fprintf(stderr, "\nERREUR : l'ouverture de %s n'a pas fonctionnee !\n", Fichier); 
		exit (1); 
	} 

    fseek(sauvegarde,0,SEEK_SET);
    
    while(fgets(Ligne, sizeof(Ligne), sauvegarde) != NULL)
    {
        //printf("%s\n",Ligne);
        token=strtok(Ligne, ";"); // Découpage des infos à chaque ;

        while(token != NULL)
        {
            printf("%s\n",token);
            token = strtok(NULL, ";");
        }
    }
    return 1;
}

//int ChargerCoordonnees(COORDONNEES *Personne, char *Fichier)
int ChargerCoordonnees(char *Fichier)
{
    FILE *sauvegarde;
    COORDONNEES *UnePersonne;
    sauvegarde = fopen(Fichier, "r");
    if (sauvegarde == NULL) 
	{ 
		fprintf(stderr, "\nERREUR : l'ouverture de %s n'a pas fonctionnee !\n", Fichier); 
		exit (1); 
	} 

    fseek(sauvegarde,0,SEEK_SET);
    fread(&UnePersonne, sizeof(COORDONNEES),1,sauvegarde);
    
    printf("\nNom : %s\nPrenom : %s\nEmail : %s\nImportance : %.0f%%\n", UnePersonne->Nom, UnePersonne->Prenom, UnePersonne->Email, 100*UnePersonne->Importance);
    //AfficherCoordonnees(UnePersonne);
    while (fread(&UnePersonne, sizeof(COORDONNEES),1,sauvegarde)!=0)
    {
        //Personne=UnePersonne;
        //AfficherCoordonnees(UnePersonne);
    }
    return 1;
}