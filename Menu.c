#include <stdio.h> //Standard Input/Output library
#include <stdlib.h> //Standard Library
#include <string.h> //String library

#include "FoncCoord.h" //fonctions de gestion des coordonnées
#include "FoncReponse.h" //fonctions de gestion des réponses
#include "FunctionTCP.h" // Fonctions d'appel TCP / URL

/*long ftell(FILE *fic) Retourne la position du curseur dans le fichier
int fseek(FILE *fic, offset, SEEK_SET) Potisionne le curseur au début du fichier décalé de offset octets
fseek(fic, 4, SEEK_SET) positionne le curseur 
SEEK_END
SEEK_CUR


En fichiers textes :
    - int fputc(int car, FILE *fic) // car = 'A' = code ASCII de la lettre, retourne EOF
    - char *fputs()
    - fprintf(FILE *fic, "String", param_Optionnels)
    - int fgetc(FILE *fic) // c=fgetc(fic) renvoie 1 caractère
    - int fgets(const char* chaine, int nombreDeCaractereALire, FILE *fic) // lit jusqu'a \0 (et pas \n)

En fichiers binaires :
    - fwrite(void *p, int taille, int nombre, FILE *fic) // taille en octets (avec sizeof(type))

*/
int main(void)
{
    //COORDONNEES *test[1];
    int choix, choix2; // déclarations des variables de choix du menu
    REPONSE reponse[1];
    //REPONSE Recup[255];
    COORDONNEES *UnePersonne;
    FILE *Repertoire, *Reponses;
    Repertoire = fopen("Repertoire.dat", "a");
    Reponses = fopen("Reponses.dat", "a");
    //printf("size COORDONNEES : %ld", sizeof(COORDONNEES));
    //printf("size UnePersonne : %ld", sizeof(UnePersonne));
    //strcpy(UnePersonne->Nom,"");
    //strcpy(UnePersonne->Prenom,"");
    //strcpy(UnePersonne->Email,"");
    //UnePersonne->Importance=0;
    
    //char server[]="192.168.43.145"; // déclaration de l'URL du serveur
    //char *server="192.168.0.38";
    //int debug = 1;
    //printf("%ld\n",sizeof(test));
    printf("Bienvenue !\n\n");
        printf("1 - Mode Utilisateur\n2 - Mode Administrateur\n0 - Sortie\n\nChoix : ");
        scanf("%d", &choix);
        //printf("vous avez choisi '%c'\n",choix);
        switch(choix)
        {
            case 1: //utilisateur
                //do
                printf("Case 1");
                break;
            case 2: //Administrateur
                printf("\t1 - Saisir Coordonnes\n\t2 - Lister Coordonnees\n\t3 - Rechercher coordonnes\n\t4 - Supprimer coordonnee\n\n\t5 - Saisir Mot Cle / reponse\n\t6 - Lister Mot cle / Reponse\n\t7 - Rechercher Mot Cle / Reponse\n\t8 - Supprimer Mot Cle / Reponse\n\t0 - Sortie\n\nChoix : ");
                scanf("%d", &choix2);
                printf("vous avez choisi '%d' : ",choix2);
                switch(choix2)
                {
                    case 1: //Saisie Coord
                        printf("Saisie Coordonnes\n");
                        SaisieCoordonnees(Repertoire);//UnePersonne,
                        break;
                    case 2: //Lister Coord
                        ListerCoordonnees(Repertoire);
                        break;
                    case 3: //Rechercher Coord
                        //do
                        break;
                    case 4: //Supprimer Coord
                        //do
                        break;
                    case 5: //Saisie MotCle
                        SaisieMotCle(reponse, Reponses);
                        break;
                    case 6: //Lister MotCle
                        //do
                        break;
                    case 7: //Rechercher MotCle
                        //do
                        break;
                    case 8: //Supprimer MotCle
                        //do
                        break;
                    case 0:
                        break;
                };
                break;
            case 0: // Sortie
                printf("case 0");
                //do
                break;
            /*default:
                //do
                break;
                */
        };

    
    //AfficherCoordonnees(test);
    //SauverCoordonnees(test, "repertoire.txt");
    //ChargerCoordonnees("repertoire.txt");
    //printf("\nSaisir Mot cle : ");
    //scanf("%s", &test[0]->Nom);
    //printf("\n'%s' ",test[0]->Nom);

    //
    //ChargerMotCle(Recup, "Reponses.dat");
    //printf("Chargement termine");
    /*while (1)
    {
    SendCommand(server,"/RELAY1=ON",5000, debug);
    SendCommand(server,"/RELAY1=OFF",5000, debug);
    SendCommand(server,"/RELAY2=ON",5000, debug);
    SendCommand(server,"/RELAY2=OFF",5000, debug);
    SendCommand(server,"/RELAY3=ON",5000, debug);
    SendCommand(server,"/RELAY3=OFF",5000, debug);
    SendCommand(server,"/RELAY4=ON",5000, debug);
    SendCommand(server,"/RELAY4=OFF",5000, debug);
    }*/
    fclose(Repertoire);
    fclose(Reponses);
    return 1;
}
