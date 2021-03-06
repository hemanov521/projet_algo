#ifndef REPONSE_H
#define REPONSE_H
/*
Directives #define
Définitions de types (typedef)
Prototypes des fonctions


Par ex : 
int C(int P, int Q);
int Fact(int N);
*/
#include <stdio.h> //Standard Input/Output
#include <stdlib.h> //Standard Library
#include <string.h> //String library

typedef struct
{
    char MotCle[32][26]; //32 mots clés de 26 caractères max
    char Action[255]; // jusqu'a 256 caractères
    char Reponse[255]; // jusqu'a 256 caractères
}REPONSE; // Réponse et mots clés associés

typedef struct
{
    char EM[320]; // Emetteur du message
    char OBJ[77]; //Objet du Message : Longueur Max Gmail/Yahoo
    char MSG[255]; //Texte du message
}MESSAGE;

int SaisieMotCle(REPONSE *Reponses, FILE *Fichier); //Fonction permettant la saisie des Mots Clés et des réponses associées
int AfficherMotCle(REPONSE *Reponses); //Fonction permettant l'affichage des Mots Clés et des réponses associées
int SauverMotCle(REPONSE *Reponses, FILE *Fichier);//Fonction permettant la sauvegarde dans un fichier des Mots clés et des réponses
//int SupprimerMotCle(char *MotCle, char *Fichier);//
int SupprimerMotCle(char *MotCle, FILE *Fichier);
//int SupprimerMotCle(REPONSE *Reponse, FILE *Fichier); //Fonction permettant la suppression de Mots clés et de la réponse assocée
int ChargerMotCle(REPONSE *Reponse, FILE *Fichier);//Fonction permettant la récupération dans un fichier des Mots clés et des réponses
int RechercheMotCle(REPONSE *MotCleCherche, FILE *Fichier);//Fonction permettant la recherche de Mots clés et de la réponse assocée
int Recherche(MESSAGE *Message, REPONSE *ListeReponse, MESSAGE *Reponse);
int ListeReponse(FILE *Fichier);
int InitReponse(REPONSE * Rep, int Number);
char *charcat(char *premier, char *deuxieme);
char *int2char(int input);

int SaisieMessage(MESSAGE *MessageRecu);
int GenererReponse(MESSAGE *MessageRecu, MESSAGE *MessageReponse);
int AfficherReponse(MESSAGE *MessageReponse);

int saisirmessage(MESSAGE *monmessage);

#endif