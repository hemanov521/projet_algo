#include <stdio.h> //Standard Input/Output
#include <stdlib.h> //Standard Library
#include <string.h> //String library


typedef struct
{
    char Nom[32];
    char Prenom[32];
    char Email[320]; //i.a.w. wikipedia local-part@domain with local-part up to 64 bytes and domain up to 255 bytes
    float Importance; //importance du client en %, floatant entre 0 et 1. précision 2 chiffres
}COORDONNEES; // Coordonnées d'une personne / d'un client

typedef struct
{
    char MotCle[32][26]; //32 mots clés de 26 caractères max
    char Reponse[255]; // jusqu'a 256 caractères
}REPONSE; // Réponse et mots clés associés

typedef struct
{
    char *EM[320]; // Emetteur du message
    char *OBJ[77]; //Objet du Message : Longueur Max Gmail/Yahoo
    char *MSG[255]; //Texte du message
}MESSAGE;

int SaisieCoordonnees(COORDONNEES *Personne, char *Fichier); //Fonction permettant la saisie des Coordonnées d'une personne
int AfficherCoordonnees(COORDONNEES *Personne); //Fonction permettant l'affichage des Coordonnées d'une personne
int SauverCoordonnees(COORDONNEES *Personne, char *Fichier); //Fonction permettant la sauvegarde dans un fichier des Coordonnées
int ListerCoordonnees(char *Fichier); //Fonction affichant l'ensemble des coordonnées contenues dans un fichier
//int ChargerCoordonnees(COORDONNEES *Personne, char *Fichier); //Fonction permettant la récupération dans un fichier des Coordonnées
int RechercheCoordonnees(COORDONNEES *Personne);//Fonction permettant la recherche des Coordonnées d'une personne

int SaisieMotCle(REPONSE *Reponses, char *Fichier); //Fonction permettant la saisie des Mots Clés et des réponses associées
int AfficherMotCle(REPONSE *Reponses); //Fonction permettant l'affichage des Mots Clés et des réponses associées
//int SauverMotCle(REPONSE *Reponses, char *Fichier);//Fonction permettant la sauvegarde dans un fichier des Mots clés et des réponses
int SupprimerMotCle(REPONSE *Reponse, char *Fichier); //Fonction permettant la suppression de Mots clés et de la réponse assocée
//int ChargerMotCle(char *Fichier);//Fonction permettant la récupération dans un fichier des Mots clés et des réponses
int RechercheMotCle(REPONSE *MotCleCherche, char *Fichier);//Fonction permettant la recherche de Mots clés et de la réponse assocée

int SaisieMessage(MESSAGE *MessageRecu);
int GenererReponse(MESSAGE *MessageRecu, MESSAGE *MessageReponse);
int AfficherReponse(MESSAGE *MessageReponse);

int main(void)
{
    COORDONNEES *test[1];
    printf("%ld\n",sizeof(test));
    printf("Bienvenue !\n");
    SaisieCoordonnees(test, "Rep.dat");
    ListerCoordonnees("Rep.dat");
    //AfficherCoordonnees(test);
    //SauverCoordonnees(test, "repertoire.txt");
    //ChargerCoordonnees("repertoire.txt");

    return 1;
}

int SaisieCoordonnees(COORDONNEES *Personne, char *Fichier)
{
    int res;
    float importance=-1;
    printf("\nSaisir Nom : ");
    res=scanf("%s", Personne->Nom);
    printf("\nSaisir Prenom : ");
    res=scanf("%32s", Personne->Prenom);
    printf("\nSaisir Email : ");
    res=scanf("%320s", Personne->Email);
    while(importance<0 || importance>100) {
        printf("\nSaisir Importance du Client (en pourcentage) : ");
        res=scanf("%f", &importance);}
    Personne->Importance = importance/100;
    SauverCoordonnees(Personne, Fichier);
    return res;
}

int SauverCoordonnees(COORDONNEES *Personne, char *Fichier)
{
    FILE *sauvegarde;
    sauvegarde = fopen(Fichier, "a");
 	if (sauvegarde == NULL) 
	{ 
		printf("\nErreur d'ouverture du fichier : %s !\n", Fichier); 
		exit (1); 
	}


	/*if(fwrite(&Personne, sizeof(Personne),1, sauvegarde) != 0) 
		printf("Donnees sauvegardees !\n"); 
	else
        printf("\nERREUR : Donnees non sauvegardees !\n"); */

    fprintf(sauvegarde,"\n%s;%s;%s;%f",Personne->Nom, Personne->Prenom, Personne->Email, Personne->Importance);
    fclose(sauvegarde);
    return 1;
}

int AfficherCoordonnees(COORDONNEES *Personne)
{
    printf("\nNom : %s\nPrenom : %s\nEmail : %s\nImportance : %.0f%%\n", Personne->Nom, Personne->Prenom, Personne->Email, 100*Personne->Importance);
    return 1;
}

int ListerCoordonnees(char *Fichier)
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
        token=strtok(Ligne, ";");

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