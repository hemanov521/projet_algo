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
    int choix, choix2, choix3; // déclarations des variables de choix du menu
    choix=-1;
    choix2=-1;
    choix3=-1;
    char *Supp=(char *)calloc(32, sizeof(char));//[320];
    //char *NomRepertoire, NomReponses;
    FILE *fRepertoire, *fReponses;
    /*fReponses= fopen("Config.ini","w+");
    fputs("Repertoire.dat\n",fReponses);
    fputs("Reponses.dat\n",fReponses);
    //fclose(fReponses);
    //fReponses= fopen("Config.ini","r");
    printf("1\n");
    fscanf("%s",&NomReponses);
    printf("Repertoire : %s\nReponses : %s\n", NomRepertoire, NomReponses);
    fscanf("%s",&NomRepertoire);
    fclose(fReponses);
    printf("Repertoire : %s\nReponses : %s\n", NomRepertoire, NomReponses);
    *///
    //COORDONNEES *Pleindepersonnes;
    //Pleindepersonnes=(COORDONNEES *) malloc (100*sizeof(COORDONNEES));
    REPONSE *reponse = (REPONSE *)calloc(1, sizeof(REPONSE));
    COORDONNEES *UnePersonne = (COORDONNEES *)calloc(1, sizeof(COORDONNEES));
    //InitReponse(reponse, 1);
    //AfficherMotCle(reponse);
    //fReponses = fopen("testreponse.dat", "w");
    //SauverMotCle(reponse, fReponses);
    //fclose(fReponses);
    //fReponses = fopen("testreponse.dat", "r");
    //ListeReponse(fReponses);
    //fclose(fReponses);
    //return 1;
    //REPONSE Recup[255];

    fRepertoire = fopen("Repertoire.dat", "a+");
    fReponses = fopen("Reponses.dat", "a+");//was a
    //printf("size COORDONNEES : %ld", sizeof(COORDONNEES));
    //printf("size UnePersonne : %ld", sizeof(UnePersonne));
    //strcpy(UnePersonne->Nom,"");
    //strcpy(UnePersonne->Prenom,"");
    //strcpy(UnePersonne->Email,"");
    //UnePersonne->Importance=0;
    
    char server[]="192.168.43.145"; // déclaration de l'URL du serveur
    //char *server="192.168.0.38";
    //int debug = 1;
    //printf("%ld\n",sizeof(test));
    printf("Bienvenue !\n\n");
    while(choix!=0)
    {

   
        printf("1 - Mode Utilisateur\n2 - Mode Administrateur\n0 - Sortie\n\nChoix : ");
        scanf("%d", &choix);
        getchar();//suppression retour chariot
        //printf("vous avez choisi '%c'\n",choix);
        switch(choix)
        {
            case 1: //utilisateur
                //do
                printf("Case 1 : inactive\n");
                break;
            case 2: //Administrateur
                printf("\t1 - Saisir Coordonnes\n\t2 - Lister Coordonnees\n\t3 - Rechercher coordonnes\n\t4 - Supprimer coordonnee\n\n\t5 - Saisir Mot Cle / reponse\n\t6 - Lister Mot cle / Reponse\n\t7 - Rechercher Mot Cle / Reponse\n\t8 - Supprimer Mot Cle / Reponse\n\n\t9 - Saisie Action Manuelle\n\t0 - Sortie\n\nChoix : ");
                scanf("%d", &choix2);
                getchar();//suppression retour charriot
                printf("vous avez choisi '%d' : ",choix2);
                switch(choix2)
                {
                    case 1: //Saisie Coord
                        printf("Saisie Coordonnees\n");
                        SaisieCoordonnees(fRepertoire);//UnePersonne,
                        break;
                    case 2: //Lister Coord
                        printf("Liste des Coordonnees\n");
                        ListerCoordonnees(fRepertoire);
                        break;
                    case 3: //Rechercher Coord
                        //do
                        //ChargerCoordonnees(Pleindepersonnes, fRepertoire);
                        printf("\nRechercher par : \n1-Nom\n2-Prenom\n3-Email\nChoix : ");
                        scanf("%d",&choix3);
                        switch(choix3)
                        {
                            case 1:{
                                    printf("\nSaisir Nom : ");
                                    scanf("%s", UnePersonne->Nom);
                                    strcpy(UnePersonne->Prenom,"");
                                    strcpy(UnePersonne->Email,"");
                                    break;
                                }
                            case 2:{
                                    printf("\nSaisir Prenom : ");
                                    scanf("%s", UnePersonne->Prenom);
                                    strcpy(UnePersonne->Nom,"");
                                    strcpy(UnePersonne->Email,"");
                                    break;
                                }
                            case 3:{
                                    printf("\nSaisir Email : ");
                                    scanf("%s", UnePersonne->Email);
                                    strcpy(UnePersonne->Prenom,"");
                                    strcpy(UnePersonne->Nom,"");
                                    break;
                                }
                        }
                        UnePersonne->Importance=0;
                        RechercheCoordonnees(UnePersonne, fRepertoire, choix3);
                        break;
                    case 4: //Supprimer Coord
                        //do
                        printf("Suppression des Coordonnees\n\nPersonne a eliminer : ");
                        scanf("%32s", Supp);
                        getchar();
                        SupprimerLigneCoordonnees(Supp, fRepertoire);
                        break;
                    case 5: //Saisie MotCle
                        SaisieMotCle(reponse, fReponses);
                        break;
                    case 6: //Lister MotCle
                        ListeReponse(fReponses);
                        break;
                    case 7: //Rechercher MotCle
                        //do
                        break;
                    case 8: //Supprimer MotCle
                        //do
                        break;
                    case 9:
                        printf("Saisie Action Manuelle :\n Veuillez Saisir l'action a executer (Par ex /RELAY1=ON) :");
                        scanf("%s",reponse->Action);
                        SendCommand(server,reponse->Action,5000, 1);
                        break;
                    case 0:
                        break;
                };
                break;
            case 0: // Sortie
                printf(">>> Sortie\n");
                //do
                break;
            default:
                //do
                break;
                
        };

    } 
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
    SendCommand(server,"/RELAY1=ON",50000, debug);
    SendCommand(server,"/RELAY1=OFF",50000, debug);
    SendCommand(server,"/RELAY2=ON",50000, debug);
    SendCommand(server,"/RELAY2=OFF",50000, debug);
    SendCommand(server,"/RELAY3=ON",50000, debug);
    SendCommand(server,"/RELAY3=OFF",50000, debug);
    SendCommand(server,"/RELAY4=ON",50000, debug);
    SendCommand(server,"/RELAY4=OFF",50000, debug);
    //}*/
    fclose(fRepertoire);
    fclose(fReponses);
    free(UnePersonne);
    free(reponse);
    free(Supp);

    return 1;
}
