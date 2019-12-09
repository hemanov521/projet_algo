#include <stdio.h> //Standard Input/Output
#include <stdlib.h> //Standard Library
#include <string.h> //String library
#include "declaration.h" // declarations du projet

/**************************
***     COORDONNEES     ***
***************************/


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


/**************************
***      MESSAGES       ***
***************************/

int SaisieMotCle(REPONSE *Reponses, char *Fichier) //Fonction permettant la saisie des Mots Clés et des réponses associées
{
    int MotCle,fin;
    char MotCle1[26];//, Reponse1[255];
    for(MotCle=0;MotCle<32;MotCle++) {
        printf("\nSaisir Mot cle n°%i (vide = sortie) : ",MotCle+1);
        //scanf("%[^\n]", Reponses->MotCle[MotCle]); //scanf("%[^\n]s",name);
        fgets(MotCle1,sizeof(Reponses->MotCle[MotCle]),stdin);
        MotCle1[strcspn(MotCle1, "\r\n")] = 0;
        strcpy(Reponses->MotCle[MotCle],MotCle1);
        printf("'%s'",Reponses->MotCle[MotCle]);
        if (strcmp(Reponses->MotCle[MotCle],"")==0) 
            {
             for (fin=MotCle;fin<32;fin++) strcpy(Reponses->MotCle[fin],"");
             printf("Fin de saisie\n");
             break;
            }
    }
    printf("\nSaisir Action : ");
    scanf(" %[^\n]s", Reponses->Action);
    printf("\nSaisir Reponse : ");
    //scanf("%[^\n]", &Reponse1);
    //scanf("%s", Reponses->Reponse); ///-----------------------------------S'arrete au premier espace !!!!!
    scanf(" %[^\n]s", Reponses->Reponse); ///-----------------------------------Semble Fonctionner. Attention il ne faut pas supprimer l'espace avant %
    //fgets(Reponse1,255,stdin);// NOT WORKING
    //fgets(Reponses->Reponse,sizeof(Reponses->Reponse),stdin); ///---------NOT WORKING !!!!!
    //Reponse1[strcspn(Reponse1, "\r\n")] = 0;
    //strcpy(Reponses->Reponse,Reponse1);
    printf("Reponse :%s\n",Reponses->Reponse);
    SauverMotCle(Reponses, Fichier);
    return 0;
}


int SauverMotCle(REPONSE *Reponses, char *Fichier)//Fonction permettant la sauvegarde dans un fichier des Mots clés et des réponses
{
    FILE *sauvegarde;
    //char ListeMots[32*26]="";
    int i;
    sauvegarde = fopen(Fichier, "a");
 	if (sauvegarde == NULL) 
	{ 
		printf("\nErreur d'ouverture du fichier : %s !\n", Fichier); 
		exit (1); 
	}
    /*char MotCle[32][26]; //32 mots clés de 26 caractères max
    char Action[255]; // jusqu'a 256 caractères
    char Reponse[255]; // jusqu'a 256 caractères*/
    fseek(sauvegarde,0,SEEK_END);
    for (i=0; i<32; i++)
    {
        fprintf(sauvegarde," %s;", Reponses->MotCle[i]);
    }
    fprintf(sauvegarde,"%s;",Reponses->Action);
    fprintf(sauvegarde,"%s\n",Reponses->Reponse);
    fclose(sauvegarde);
    return 0;
}
int ChargerMotCle(REPONSE *Reponses, char *Fichier)//Fonction permettant la récupération dans un fichier des Mots clés et des réponses
{
    printf("Chargement du fichier : %s\n", Fichier);
    FILE *sauvegarde;
    char *buffer, *token;
    //char ListeMots[32*26]="";
    int i,j;
    sauvegarde = fopen(Fichier, "r"); /// ouverture pour lecture
 	if (sauvegarde == NULL) 
	{ 
		printf("\nErreur d'ouverture du fichier : %s !\n", Fichier); 
		exit (1); 
	}
    else {printf("\nFichier ouvert\n");}

    /*char MotCle[32][26]; //32 mots clés de 26 caractères max
    char Action[255]; // jusqu'a 256 caractères
    char Reponse[255]; // jusqu'a 256 caractères*/
    fseek(sauvegarde,0,SEEK_SET); // Curseur au début du fichier
    //printf("Curseur set");
    j=0;

    do
    {
        fscanf(sauvegarde, " %[^\n]s", buffer); // Lecture d'une ligne et stockage dans buffer
        printf("On est là !\n\n");
        token = strtok(buffer, ";"); // stockage 1er champ dans token
        
        for (i=0; i<32; i++)
        {
            //printf("%s\n",token);
            strcpy(Reponses[j].MotCle[i], token);
            printf("Mot Cle %d : %s\n",i,Reponses[j].MotCle[i]);
            token = strtok(NULL, ";");
        }
        strcpy(Reponses[j].Action,token);
        printf("Action : %s\n", Reponses[j].Action);
        token = strtok(NULL, ";");
        strcpy(Reponses[j].Reponse,token);
        printf("Reponse : %s\n", Reponses[j].Reponse);
    //    strcpy(Reponses->Reponse,strtok(buffer, "\n"));

        //fscanf(sauvegarde," %[^;]26s %[^;]26s %[^;]26s %[^;]26s %[^;]26s %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]255s;%[^\n]255s\n", Reponses->MotCle[0], Reponses->MotCle[1], Reponses->MotCle[2], Reponses->MotCle[3], Reponses->MotCle[4], Reponses->MotCle[5], Reponses->MotCle[6], Reponses->MotCle[7], Reponses->MotCle[8], Reponses->MotCle[9], Reponses->MotCle[10], Reponses->MotCle[11], Reponses->MotCle[12], Reponses->MotCle[13], Reponses->MotCle[14], Reponses->MotCle[15], Reponses->MotCle[16], Reponses->MotCle[17], Reponses->MotCle[18], Reponses->MotCle[19], Reponses->MotCle[20], Reponses->MotCle[21], Reponses->MotCle[22], Reponses->MotCle[23], Reponses->MotCle[24], Reponses->MotCle[25], Reponses->MotCle[26], Reponses->MotCle[27], Reponses->MotCle[28], Reponses->MotCle[29], Reponses->MotCle[30], Reponses->MotCle[31],Reponses->Action,Reponses->Reponse);
        //fscanf(sauvegarde, " %[^\n]s", buffer);

        //printf("%s",buffer);
        //sscanf(buffer," %[^;]26s %[^;]26s %[^;]26s %[^;]26s %[^;]26s %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]26s; %[^;]255s;%[^\n]255s\n", Reponses->MotCle[0], Reponses->MotCle[1], Reponses->MotCle[2], Reponses->MotCle[3], Reponses->MotCle[4], Reponses->MotCle[5], Reponses->MotCle[6], Reponses->MotCle[7], Reponses->MotCle[8], Reponses->MotCle[9], Reponses->MotCle[10], Reponses->MotCle[11], Reponses->MotCle[12], Reponses->MotCle[13], Reponses->MotCle[14], Reponses->MotCle[15], Reponses->MotCle[16], Reponses->MotCle[17], Reponses->MotCle[18], Reponses->MotCle[19], Reponses->MotCle[20], Reponses->MotCle[21], Reponses->MotCle[22], Reponses->MotCle[23], Reponses->MotCle[24], Reponses->MotCle[25], Reponses->MotCle[26], Reponses->MotCle[27], Reponses->MotCle[28], Reponses->MotCle[29], Reponses->MotCle[30], Reponses->MotCle[31],Reponses->Action,Reponses->Reponse);
        

        //sscanf("                Relai 1 ON;                RELAI 1 ON;","%[^\n]26s;%[^\n]26s", Reponses->MotCle[0], Reponses->MotCle[1]);
        printf("Buffer : \n'%s'\n", buffer);
        //fscanf(sauvegarde, " %[^\n]s", buffer);
        //printf("Stream2 : \n%s\n", buffer);
        //AfficherMotCle(Reponses);
    } while(strlen(buffer)>2);
    fclose(sauvegarde);
    return 0;
}
int Recherche(MESSAGE *Message, REPONSE *ListeReponse, MESSAGE *Reponse)
{
    //char *ret;
    int i;
    for (i=0; i<32; i++) //je cherche chaque mot clé de ListeReponse
        {
            if (strstr(Message->MSG, ListeReponse->MotCle[i])!=NULL) //trouvé mot clé
            {
                strcpy(Reponse->EM,Message->EM); // Je répond a l'emmeteur
                strcpy(Reponse->OBJ, strcat("RE:",Message->OBJ)); // j'ajoute "RE:" à l'objet
                strcpy(Reponse->MSG, ListeReponse->Reponse); // J'envoie la réponse "qui va bien"
                break; // je sors de la boucle
            }
        }
   //printf("The substring is: %s\n", ret);
   return 0;
}

int AfficherMotCle(REPONSE *Reponses) //Fonction permettant l'affichage des Mots Clés et des réponses associées
{
    int i;
    printf("\nMots cles :\n");
    for (i=0; i<32; i=i+4) //je cherche chaque mot clé de ListeReponse
        {
            printf("%26s;\t%26s;\t%26s;\t%26s\n",Reponses->MotCle[i],Reponses->MotCle[i+1],Reponses->MotCle[i+2],Reponses->MotCle[i+3]);
        }
    printf("\nAction :\n%s\n\nReponse :\n%s\n",Reponses->Action, Reponses->Reponse);
    return 0;
}
/*int SupprimerMotCle(REPONSE *Reponse, char *Fichier); //Fonction permettant la suppression de Mots clés et de la réponse assocée
*/

/*char * getfield(char *line, int num)
{
    char *tok;
    for (tok = strtok(line, ";");tok && *tok; tok = strtok(NULL, ";\n"))
    {
        if (!--num)
        return tok;
    }
    return NULL;
}*/