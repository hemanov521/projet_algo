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
    char *EM[320]; // Emetteur du message
    char *OBJ[77]; //Objet du Message : Longueur Max Gmail/Yahoo
    char *MSG[255]; //Texte du message
}MESSAGE;

int SaisieMotCle(REPONSE *Reponses, char *Fichier); //Fonction permettant la saisie des Mots Clés et des réponses associées
int AfficherMotCle(REPONSE *Reponses); //Fonction permettant l'affichage des Mots Clés et des réponses associées
int SauverMotCle(REPONSE *Reponses, char *Fichier);//Fonction permettant la sauvegarde dans un fichier des Mots clés et des réponses
int SupprimerMotCle(REPONSE *Reponse, char *Fichier); //Fonction permettant la suppression de Mots clés et de la réponse assocée
int ChargerMotCle(REPONSE *Reponse, char *Fichier);//Fonction permettant la récupération dans un fichier des Mots clés et des réponses
int RechercheMotCle(REPONSE *MotCleCherche, char *Fichier);//Fonction permettant la recherche de Mots clés et de la réponse assocée

int SaisieMessage(MESSAGE *MessageRecu);
int GenererReponse(MESSAGE *MessageRecu, MESSAGE *MessageReponse);
int AfficherReponse(MESSAGE *MessageReponse);

#endif