#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

	if(argc != 2) {
		printf("Usage: %s <password>\n", argv[0]);
		exit(1);
	}

	char* pass = argv[1];
	
	int i = 0;
	
	int sum = 0;

	while(pass[i] != '\0') {
		sum += pass[i];
		i++;
	}
	
	if(sum == 'A' * 4) {
		printf("Success!\n");
	} else {
		printf("Fail!\n");
		exit(1);
	}


	exit(0);	
}
