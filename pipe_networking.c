#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client
  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.
  returns the file descriptor for the upstream pipe.
  =========================*/
int server_socket() {
	int status;
	struct addrinfo *hints, *servinfo;
	hints = calloc(1, sizeof(struct addrinfo));
	hints->ai_family = AF_UNSPEC;     // don't care IPv4 or IPv6
	hints->ai_socktype = SOCK_STREAM; // TCP stream sockets
	hints->ai_flags = AI_PASSIVE;     // fill in my IP for me

	if ((status = getaddrinfo(NULL, "9001", hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
		exit(1);
	}
	int sd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
	bind(sd, servinfo->ai_addr, servinfo->ai_addrlen);
	return sd;
}


/*=========================
  client_handshake
  args: int * to_server
  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.
  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
	int from_server;
	return from_server;
}
