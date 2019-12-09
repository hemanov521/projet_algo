#include "FunctionTCP.h"
/*int main()
{
    SendCommand("192.168.43.145","/LED1=ON");
    usleep(100);
    SendCommand("192.168.43.145","/LED1=OFF");
    SendCommand("192.168.43.145","/LED2=ON");
    usleep(100);
    SendCommand("192.168.43.145","/LED2=OFF");
    SendCommand("192.168.43.145","/LED3=ON");
    usleep(100);
    SendCommand("192.168.43.145","/LED3=OFF");
    SendCommand("192.168.43.145","/LED4=ON");
    usleep(100);
     SendCommand("192.168.43.145","/LED4=OFF");
    
}*/

int SendCommand(char *host, char *url, int pause, int debug)
{
    /*Define socket variables */
    //char host[1024] = Hostname;//"192.168.43.145";
    //char url[1024] = URL;//"/LED1=ON";
    printf("\nSend command : %s%s",host, url);
    char request[2000];
    struct hostent *server;
    struct sockaddr_in serverAddr;
    short portno = 80;

    if (debug) printf("Trying to get source of %s%s ...\n",host,url);

    /* Create socket */
    int tcpSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(tcpSocket < 0) {
        if (debug) printf("ERROR opening socket\n");
        exit(-1);
    } else {
        if (debug) printf("Socket opened successfully.\n");
    }

    if ((server = gethostbyname(host)) == NULL) {
        if (debug) fprintf(stderr, "gethostbybname(): error");
        exit(-1);
    }

    memcpy(&serverAddr.sin_addr, server -> h_addr_list[0], server -> h_length);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(portno);

    if(connect(tcpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        if (debug) printf("Can't connect\n");
        exit(-1);
    } else {
        if (debug) printf("Connected successfully\n");
    }

    bzero(request, 2000); // Was 2000
    sprintf(request, "Get %s HTTP/1.1\r\n Host: %s\r\n \r\n \r\n", url, host);
    if (debug) printf("\n%s", request);

    if(send(tcpSocket, request, strlen(request), 0) < 0) {
        if (debug) printf("Error with send()");
    } else {
        if (debug) printf("Successfully sent html fetch request");
    }
    //printf("\ntest\n%i\n",tcpSocket);
    usleep(pause); // pause de X ms pour que le NodeMCU ait le temps d'executer avant la prochaine commande
    return 0;
}