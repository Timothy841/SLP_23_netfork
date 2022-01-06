#include "pipe_networking.h"

int main() {

	int sd = client_socket();

	printf("Changes 'h' to 'H'\n");
	printf("Type \"exit1\" or \"^C\" to exit client program.\n");
	while (1){
		char *line = calloc(100,1);
		printf("Input: ");
		fgets(line, 100, stdin);
		sscanf(line, "%s\n", line);
		if (strcmp(line, "exit1") == 0){
			exit(0);
		}
		write(sd, line, strlen(line));
		read(sd, line, 100);
		printf("Output: %s\n", line);
		free(line);
	}
}
