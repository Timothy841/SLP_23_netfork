#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#ifndef NETWORKING_H
#define NETWORKING_H
#define WKP "mario"

#define HANDSHAKE_BUFFER_SIZE 10
#define BUFFER_SIZE 1000

int server_socket();
int client_handshake(int *to_server);

#endif
