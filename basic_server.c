#include "pipe_networking.h"

void change(char *line){
	for (int i = 0; i<strlen(line); i++){
		if (line[i] == 'h'){
			line[i] = 'H';
		}
	}
}

int main() {

	int parent;
	char line[100];
	int sd = server_socket();
	
	listen (sd, 5);
	//while (1){
		/*if (parent){
			parent = 0;
			continue;
		}
		while (read(from_client, line, 100)){
			if (strcmp(line, "exit1") == 0){
				break;
			}
			change(line);
			write(to_client, line, 100);
		}
		return 0;
	}*/
}
