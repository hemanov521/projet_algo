/**************************
***      MESSAGES       ***
***************************/
#include "FoncReponse.h"

int SaisieMotCle(REPONSE *Reponses, FILE *Fichier) //Fonction permettant la saisie des Mots Clés et des réponses associées
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


int SauverMotCle(REPONSE *Reponses, FILE *Fichier)//Fonction permettant la sauvegarde dans un fichier des Mots clés et des réponses
{
    //FILE *sauvegarde;
    //char ListeMots[32*26]="";
    int i;
    //sauvegarde = fopen(Fichier, "a");
 	if (Fichier == NULL) 
	{ 
		printf("\nErreur d'acces au fichier !\n"); 
		exit (1); 
	}
    /*char MotCle[32][26]; //32 mots clés de 26 caractères max
    char Action[255]; // jusqu'a 256 caractères
    char Reponse[255]; // jusqu'a 256 caractères*/
    /*fseek(Fichier,0,SEEK_END);
    for (i=0; i<32; i++)
    {
        fprintf(Fichier," %s;", Reponses->MotCle[i]);
    }
    fprintf(Fichier,"%s;",Reponses->Action);
    fprintf(Fichier,"%s\n",Reponses->Reponse);
    */

    if(fwrite(&Reponses, sizeof(REPONSE),1, Fichier) != 0) 
		printf("Donnees sauvegardees !\n"); 
	else
        printf("\nERREUR : Donnees non sauvegardees !\n"); 

    //fclose(sauvegarde);
    return 0;
}
int ChargerMotCle(REPONSE *Reponses, FILE *Fichier)//Fonction permettant la récupération dans un fichier des Mots clés et des réponses
{
    //printf("Chargement du fichier \n");
    //FILE *sauvegarde;
    //char *buffer, *token;
    //char ListeMots[32*26]="";
    //int i,j;
    //sauvegarde = fopen(Fichier, "r"); /// ouverture pour lecture
 	if (Fichier == NULL) 
	{ 
		printf("\nErreur d'acces au fichier !\n"); 
		exit (1); 
	}
    else {printf("\nFichier ouvert\n");}

    /*char MotCle[32][26]; //32 mots clés de 26 caractères max
    char Action[255]; // jusqu'a 256 caractères
    char Reponse[255]; // jusqu'a 256 caractères*/
    //fseek(sauvegarde,0,SEEK_SET); // Curseur au début du fichier
    //printf("Curseur set");
    if(fread(&Reponses, sizeof(REPONSE),1, Fichier) != 0) 
		printf("Donnees recuperees !\n"); 
	else
        printf("\nERREUR : Donnees non recuperees !\n"); 

/*    j=0;

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
  */
    //fclose(sauvegarde);
    return 0;
}
int Recherche(MESSAGE *Message, REPONSE *ListeReponse, MESSAGE *Reponse)
{
    //char *ret;
    int i;
    for (i=0; i<32; i++) //je cherche chaque mot clé de ListeReponse
        {
            if (strstr(Message->MSG, ListeReponse->MotCle[i])!=NULL) //Si trouvé mot clé dans le Message reçu alors :
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

int ListeReponse(FILE *Fichier)
{
    REPONSE *Reponses;
    Reponses = (REPONSE *) malloc(sizeof(REPONSE));
    fseek(Fichier, 0, SEEK_SET);
    while (!feof(Fichier))
    {
        ChargerMotCle(Reponses, Fichier);
    }
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