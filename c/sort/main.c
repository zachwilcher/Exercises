
#include "arrlib.h"
#include <time.h>

int main(int argc, char** argv) {

	srand(time(NULL));

	int len = 10;

	int* arr = (int*) malloc(sizeof(int) * len);
	
	for(int i = 0; i < len; i++) {
		arr[i] = i;
	}

	randarr(len, &arr);

	printarr(len, &arr);

}

