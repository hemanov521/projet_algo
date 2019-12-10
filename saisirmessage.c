#include "declaration.h"
#include <stdlib.h>
#include <stdio.h>


int main()
{
  MESSAGE monmessage;
  
while(1)
{

      FILE *fptr;
    // opening file in writing mode
    fptr = fopen("log.txt", "a+");
    // exiting program 
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    printf("Emmetteur : ");
    fscanf (stdin, "%s", monmessage.EM);
    fgets(monmessage.EM, sizeof(monmessage.EM), stdin);
    fprintf(fptr, "%s\n", monmessage.EM);

    printf("Objet : ");
    fscanf (stdin, "%s", monmessage.OBJ);
    fgets(monmessage.OBJ, sizeof(monmessage.OBJ), stdin);
    fprintf(fptr, "%s\n", monmessage.OBJ);


    printf("Message : ");
    fscanf (stdin, "%s", monmessage.MSG);
    fgets(monmessage.MSG, sizeof(monmessage.MSG), stdin);
    fprintf(fptr, "%s\n", monmessage.MSG);
    fclose(fptr);

  return 0;

}
}