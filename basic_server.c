#include "pipe_networking.h"

void change(char *line){
	for (int i = 0; i<strlen(line); i++){
		if (line[i] == 'h'){
			line[i] = 'H';
		}
	}
}

int main() {

	int sd = server_socket();
	printf("Created socket, listening\n");

	while(1){
		int client_socket = server_connect(sd);
		printf("Received connection\n");
		int parent = fork();
		if (parent == 0){//child. parent goes back to accept new client.
			while (1){
				char *line = calloc(100,1);
				read(client_socket, line, 100);
				if (strcmp(line, "exit1") == 0){
					break;
				}
				change(line);
				write(client_socket, line, 100);
				free(line);
			}
			return 0;
		}
		else{
			close(client_socket);
		}
	}
}
