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
    //int i;
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

    if(fwrite(Reponses, sizeof(REPONSE),1, Fichier) != 0) 
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
    int i;//,j;
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
    //fseek(Fichier,0,SEEK_SET); // Curseur au début du fichier
    i=fread(Reponses, sizeof(REPONSE),1, Fichier);
    printf("%d\n", i);
    /*if(fread(&Reponses, sizeof(REPONSE),1, Fichier) != 0) 
		printf("Donnees recuperees !\n"); 
	else
        printf("\nERREUR : Donnees non recuperees !\n"); 
*/
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
   //const char * word; //variable contenant 1 seul mot
   int i=0;
   char re[77]="RE: "; //variable contenant l'OBJET de la réponse
   Reponse = (MESSAGE *) malloc( sizeof(MESSAGE) ); //allocation de mémoire pour la réponse
/*    word = strtok(Message->MSG, " ,.-"); //découpage du message en mots
    while(word != NULL)
    {
            if (strcmp(word,ListeReponse->MotCle)==0) //Comparation mot a mot // trouvé mot clé
*/  printf("\nRecherche du mot cle '%s'\n", Message->MSG);
    strcpy(Reponse->OBJ,"");
    for(i=0; i<=32; i++)
    {   
            if (strstr(Message->MSG,ListeReponse->MotCle[i]) != NULL) // Trouvé mot clé
            {
                printf("Mot cle identifie : %s \n",ListeReponse->MotCle[i]);
                strcpy(Reponse->EM,Message->EM); // Je répond a l'emmeteur
                strcpy(Reponse->OBJ, strcat(re,Message->OBJ)); // j'ajoute "RE:" à l'objet
                strcpy(Reponse->MSG, ListeReponse->Reponse); // J'envoie la réponse "qui va bien"
                break; // je sors de la boucle
            }
    }
//            word = strtok(NULL, " ,.-");
//        }
   /*printf("Reponse transmise : \n");
   printf("Destinataire : %s\n", Reponse->EM);
   printf("Objet : %s\n", Reponse->OBJ);
   printf("Message : %s\n", Reponse->MSG);*/
   return 0;
}

int ListeReponse(FILE *Fichier)
{
    int i=0;//,j = 0;
    //char *buffer=(char *)malloc(sizeof(char)*1500);
    //j=sizeof(REPONSE);
    REPONSE *Reponses = (REPONSE *) malloc(sizeof(REPONSE));
    //printf("\nftell1 : %ld\nSizeof(REPONSE) : %d \nCalcul : %d\n",ftell(Fichier), sizeof(REPONSE), ftell(Fichier)-sizeof(REPONSE)/2);
    //fseek(Fichier, ftell(Fichier), SEEK_SET);
    //fseek(Fichier, 0, SEEK_END);
    //i= fread(Reponses, sizeof(REPONSE),1, Fichier);
    //printf("fread : %d\n",i);    printf("ftell2 : %ld\n",ftell(Fichier));
    //fseek(Fichier, -(sizeof(REPONSE)), SEEK_CUR);
    //printf("ftell3 : %ld\n",ftell(Fichier));
    /*fseek(Fichier, ftell(Fichier)-sizeof(REPONSE), SEEK_CUR);//SEEK_CUR semble ne pas fonctionner
    printf("ftell4 : %ld\n",ftell(Fichier));
    */
    while(!feof(Fichier))
    {
        if (fread(Reponses, sizeof(REPONSE),1, Fichier)) AfficherMotCle(Reponses);
        i++;
    }
    //i= fread(Reponses, sizeof(REPONSE),1, Fichier);
    //i= fread(buffer, 1,1342, Fichier);
    //printf("fread : %d\n",i);
    //AfficherMotCle(Reponses);
    //fread(&Reponses, sizeof(REPONSE),1, Fichier);
    //AfficherMotCle(Reponses);
    //fread(&Reponses, sizeof(REPONSE),1, Fichier);
    //AfficherMotCle(Reponses);

    /*while (!feof(Fichier)&&i<5)
    {
        printf("ftell : %ld\n",ftell(Fichier));
        ChargerMotCle(Reponses, Fichier);
        i++;
    }*/
    return i;
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

int SupprimerMotCle(char *MotCle, FILE *Fichier)//(char * MotCle)
{
    REPONSE *ReponseLigne;
    const char *Tampon = "TamponReponses.dat";
    //FILE *rep;
    FILE *repcopie;
    repcopie = fopen(Tampon, "wb");

    int MAXSIZE = 0xFFF;
    char proclnk[0xFFF];
    char filename[0xFFF];
    int fno;
    ssize_t r;
    int i=0;
    int detecte=0;
    int fichier_modifie=0;
    int j=0;

    if (Fichier != NULL)
    {
        fno = fileno(Fichier); // Récupération adresse mémoire du fichier
        sprintf(proclnk, "/proc/self/fd/%d", fno);
        r = readlink(proclnk, filename, MAXSIZE); //Récupération adresse absolue dans filename
        if (r < 0)
        {
            printf("failed to readlink\n");
            exit(1);
        }
        filename[r] = '\0';
        //printf("Fichier -> fno -> filename: %p -> %d -> %s\n", Fichier, fno, filename);
    }


    //rep = fopen("Reponses.dat", "rb");
    fseek(Fichier, 0, SEEK_SET);
    while(1)
    {
        if(feof(Fichier))
        {
            printf("Mot cle non detecte\n"); 
            break;
        } 
        j++;
        fread(&ReponseLigne,sizeof(REPONSE),1,Fichier);
        //printf("Ligne numero : %i\n",j);
        for (i=0; i<32; i++)
        {
            if(strstr(ReponseLigne->MotCle[i],MotCle)!=NULL)
            {
                printf("Mot cle detecte : %s dans \n",ReponseLigne->MotCle[i]);
                AfficherMotCle(ReponseLigne);
                printf("\n >>> SUPPRESSION\n\n");
                detecte=1;
            }
        //printf("%s\n",ReponseLigne.MotCle[i]);
        }
        if(detecte==0)
        {
            fwrite(&ReponseLigne,sizeof(REPONSE),1,repcopie);
        }
        else
        {
            detecte=0;
        }
    }
    fclose(Fichier);
    fclose(repcopie);
    if(fichier_modifie==1)
    {
        remove(filename);
        rename(Tampon,filename);
    }
    else
    {
        remove(Tampon);
    }
    free(repcopie);
    Fichier=fopen(filename, "a+");
    return 1;
}






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

int InitReponse(REPONSE * Rep, int Number)
{
    int i;

    //char MotCle[32][26]; //32 mots clés de 26 caractères max
    //char Action[255]; // jusqu'a 256 caractères
    //char Reponse[255]; // jusqu'a 256 caractères
    for (i=0;i<32;i++)
    {
        strcpy(Rep->MotCle[i], charcat("MotCle-",int2char(i)));
    }
    strcpy(Rep->Action, "Action");
    strcpy(Rep->Reponse, "Reponse");
    return 1;
}

char *int2char(int input)
{
    char *buffer=(char *)calloc(255, sizeof(char));//=(char *)calloc(1, sizeof(char));
    //itoa(input,buffer,10);
    sprintf(buffer, "%d", input);
    free(buffer);
    return buffer;
}

char *charcat(char *premier, char *deuxieme)
{
    char *resultat = (char *)calloc(1, sizeof(premier)+sizeof(deuxieme));
    strcpy(resultat,premier);
    strcat(resultat, deuxieme);
    return resultat;
}


int saisirmessage(MESSAGE *monmessage)
{
    //MESSAGE monmessage;
    while(1)
    {

        FILE *fptr;
        // opening file in writing mode
        fptr = fopen("log.txt", "a+");
        int size=0;
        char Saisie[255];
        // exiting program 
        if (fptr == NULL) {
            printf("Error!");
            exit(1);
        }

        printf("Emmetteur : ");
        //fscanf (stdin, "%[^\n]s", monmessage->EM);
        //fgets(monmessage->EM, sizeof(monmessage->EM), stdin);
        

        fgets(Saisie,sizeof(Saisie),stdin);
        size=strcspn(Saisie, "\r\n");
        strcpy(monmessage->EM,Saisie);
        fprintf(fptr, "%s\n", monmessage->EM);




        printf("Objet : ");
        //fscanf (stdin, "%[^\n]s", monmessage->OBJ);
        //fgets(monmessage->OBJ, sizeof(monmessage->OBJ), stdin);
        
        
        fgets(Saisie,sizeof(Saisie),stdin);
        size=strcspn(Saisie, "\r\n");
        strcpy(monmessage->OBJ,Saisie);
        fprintf(fptr, "%s\n", monmessage->OBJ);

        
        printf("Message : ");
//        fscanf (stdin, "%[^\n]s", monmessage->MSG);
        //fgets(monmessage->MSG, sizeof(monmessage->MSG), stdin);
 //       fprintf(fptr, "%s\n", monmessage->MSG);
        fgets(Saisie,sizeof(Saisie),stdin);
        size=strcspn(Saisie, "\r\n");
        printf("message : '%s'",saisie);
        strcpy(monmessage->MSG,Saisie);
        fprintf(fptr, "%s\n", monmessage->MSG);
        fclose(fptr);
    return 1;


    }
}