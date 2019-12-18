#include <stdio.h> //Standard Input/Output library
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
    char MotCle[32];//[26]; //32 mots clés de 26 caractères max
    char Action[255]; // jusqu'a 256 caractères
    char Reponse[255]; // jusqu'a 256 caractères
}REPONSE; // Réponse et mots clés associés

typedef struct
{
    char EM[320]; // Emetteur du message
    char OBJ[77]; //Objet du Message : Longueur Max Gmail/Yahoo
    char MSG[255]; //Texte du message
}MESSAGE;

int Recherche(MESSAGE *Message, REPONSE *ListeReponse, MESSAGE *Reponse)
{
   const char * word;
   char re[77]="RE: ";
   Reponse = (MESSAGE *) malloc( sizeof(MESSAGE) ); 
    word = strtok(Message->MSG, " ,.-");
    while(word != NULL)
    {
            if (strcmp(word,ListeReponse->MotCle)==0) //trouvé mot clé
            {
                printf("Mot cle identifie : %s \n",word);
                strcpy(Reponse->EM,Message->EM); // Je répond a l'emmeteur
                strcpy(Reponse->OBJ, strcat(re,Message->OBJ)); // j'ajoute "RE:" à l'objet
                strcpy(Reponse->MSG, ListeReponse->Reponse); // J'envoie la réponse "qui va bien"
                break; // je sors de la boucle
            }
            word = strtok(NULL, " ,.-");
        }
   /*printf("Reponse transmise : \n");
   printf("Destinataire : %s\n", Reponse->EM);
   printf("Objet : %s\n", Reponse->OBJ);
   printf("Message : %s\n", Reponse->MSG);*/
   return 0;
}

int main()
{
 MESSAGE *MessageRecu;
 MessageRecu = (MESSAGE *) malloc( sizeof(MESSAGE) ); 
    strcpy(MessageRecu->EM,"pierre.lago@yahoo.com");
    strcpy(MessageRecu->OBJ,"Ouvrir volet");
    strcpy(MessageRecu->MSG,"Bonjour, j'aimerais ouvrir le volet");

    REPONSE *ListeRep;
    ListeRep = (REPONSE *) malloc( sizeof(REPONSE) ); 
    strcpy(ListeRep->MotCle,"volet");
    strcpy(ListeRep->Action,"ouvrir volet");
    strcpy(ListeRep->Reponse,"Tres bien, je vais ouvrir le volet de ce pas");

 MESSAGE *MessageRep;
 MessageRep = (MESSAGE *) malloc( sizeof(MESSAGE) ); 
 
Recherche(MessageRecu,ListeRep,MessageRep);
}
