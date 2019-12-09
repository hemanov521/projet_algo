#ifndef SENDTCP_H
#define SENDTCP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int SendCommand(char *host, char *url, int pause, int debug);

#endif