#ifndef PROJET_H
#define PROJET_H
/*
Directives #define
Définitions de types (typedef)
Prototypes des fonctions


Par ex : 
int C(int P, int Q);
int Fact(int N);
*/

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
    char Action[255]; // jusqu'a 256 caractères
    char Reponse[255]; // jusqu'a 256 caractères
}REPONSE; // Réponse et mots clés associés

typedef struct
{
    char *EM[320]; // Emetteur du message
    char *OBJ[77]; //Objet du Message : Longueur Max Gmail/Yahoo
    char *MSG[255]; //Texte du message
}MESSAGE;

int SaisieCoordonnees(COORDONNEES *Personne, char *Fichier); //**//Fonction permettant la saisie des Coordonnées d'une personne
int AfficherCoordonnees(COORDONNEES *Personne); //** //Fonction permettant l'affichage des Coordonnées d'une personne
int SauverCoordonnees(COORDONNEES *Personne, char *Fichier); //** //Fonction permettant la sauvegarde dans un fichier des Coordonnées
int ListerCoordonnees(char *Fichier); //** //Fonction affichant l'ensemble des coordonnées contenues dans un fichier
//int ChargerCoordonnees(COORDONNEES *Personne, char *Fichier); //Fonction permettant la récupération dans un fichier des Coordonnées
-->>  int RechercheCoordonnees(COORDONNEES *Personne);//Fonction permettant la recherche des Coordonnées d'une personne

int SaisieMotCle(REPONSE *Reponses, char *Fichier); //** //Fonction permettant la saisie des Mots Clés et des réponses associées
int AfficherMotCle(REPONSE *Reponses); //** //Fonction permettant l'affichage des Mots Clés et des réponses associées
int SauverMotCle(REPONSE *Reponses, char *Fichier);//** //Fonction permettant la sauvegarde dans un fichier des Mots clés et des réponses
-->> int SupprimerMotCle(REPONSE *Reponse, char *Fichier); //Fonction permettant la suppression de Mots clés et de la réponse assocée
int ChargerMotCle(REPONSE *Reponse, char *Fichier);//** //Fonction permettant la récupération dans un fichier des Mots clés et des réponses
-->> int RechercheMotCle(REPONSE *MotCleCherche, char *Fichier);//Fonction permettant la recherche de Mots clés et de la réponse assocée

--> int SaisieMessage(MESSAGE *MessageRecu);
--> int GenererReponse(MESSAGE *MessageRecu, MESSAGE *MessageReponse);
--> int AfficherReponse(MESSAGE *MessageReponse);

//char* getfield(char* line, int num);
int SendCommand(char *host, char *url, int pause, int debug); //** //Envoi de commandes via TCP GET : host=IP ou ServerAddress and url=Command

#endif