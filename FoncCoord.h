#ifndef COORD_H
#define COORD_H
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
//#include "declaration.h" // declarations du projet

//typedef int ssize_t;

typedef struct
{
    char Nom[32];
    char Prenom[32];
    char Email[320]; //i.a.w. wikipedia local-part@domain with local-part up to 64 bytes and domain up to 255 bytes
    float Importance; //importance du client en %, floatant entre 0 et 1. précision 2 chiffres
}COORDONNEES; // Coordonnées d'une personne / d'un client




int SaisieCoordonnees( FILE *Fichier); //Fonction permettant la saisie des Coordonnées d'une personne COORDONNEES *Personne,
int AfficherCoordonnees(COORDONNEES *Personne); //Fonction permettant l'affichage des Coordonnées d'une personne
int SauverCoordonnees(COORDONNEES *Personne, FILE *Fichier); //Fonction permettant la sauvegarde dans un fichier des Coordonnées
int ListerCoordonnees(FILE *Fichier); //Fonction affichant l'ensemble des coordonnées contenues dans un fichier
int ChargerCoordonnees(COORDONNEES *Personne, FILE *Fichier); //Fonction permettant la récupération dans un fichier des Coordonnées
//int RechercheCoordonnees(COORDONNEES *Personne, FILE *Fichier);//Fonction permettant la recherche des Coordonnées d'une personne
int RechercheCoordonnees(COORDONNEES *Personne, FILE *Fichier, int choix);
void SupprimerLigneCoordonnees(char *MotCle, FILE *Fichier); //Fonction permettant de supprimer les coordonnées a partir d'un mot 

int InitCOORDONNEES(COORDONNEES *C); //fonction qui initialise les champs vides

char *GetFilename(FILE *Fichier); //Fonction qui retourne l'adresse du fichier à partir de son pointeur

ssize_t readlink(proclnk, filename, MAXSIZE);//fonction système permettant de récupérer l'adresse d'un fichier depuis son pointeur

#endif