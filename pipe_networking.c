#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client
  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.
  returns the file descriptor for the upstream pipe.
  =========================*/
int server_socket() {
	struct addrinfo *hints, *results;
	hints = calloc(1, sizeof(struct addrinfo));
	hints->ai_family = AF_INET;     // don't care IPv4 or IPv6
	hints->ai_socktype = SOCK_STREAM; // TCP stream sockets
	hints->ai_flags = AI_PASSIVE;     // fill in my IP for me

	getaddrinfo(NULL, "9001", hints, &results);
	int sd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
	bind(sd, results->ai_addr, results->ai_addrlen);
	listen (sd, 10);
	free(hints);
	freeaddrinfo(results);
	return sd;
}

int server_connect(int sd) {
  int client_socket;
  socklen_t sock_size;
  struct sockaddr_storage client_address;
  sock_size = sizeof(client_address);
  client_socket = accept(sd, (struct sockaddr *) &client_address, &sock_size);

  return client_socket;
}

/*=========================
  client_handshake
  args: int * to_server
  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.
  returns the file descriptor for the downstream pipe.
  =========================*/
int client_socket() {
	struct addrinfo *hints, *results;
	hints = calloc(1, sizeof(struct addrinfo));
	hints->ai_family = AF_INET;     // don't care IPv4 or IPv6
	hints->ai_socktype = SOCK_STREAM; // TCP stream sockets

	getaddrinfo("127.0.0.1", "9001", hints, &results);
	int sd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
	connect(sd, results->ai_addr, results->ai_addrlen);
	free(hints);
	freeaddrinfo(results);
	return sd;
}
