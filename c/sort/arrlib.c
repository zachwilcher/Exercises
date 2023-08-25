#include "arrlib.h"

void printarr(int len, int** arrptr) {
	
	int* arr = *arrptr;
	for(int i = 0; i < len - 1; i++) {
		printf("%d, ", arr[i]);
	}
	printf("%d\n", arr[len - 1]);

}


void randarr(int len, int** arrptr) {
	

	for(int i = 0; i < len; i++) {
		int newpos = rand() % len;
		swap(*arrptr + i, *arrptr + newpos);
	}
	


}


void zeroarr(int len, int** arrptr) {
	//sets every value in arr to 0
	
	int* arr = *arrptr;
	for(int i = 0; i < len; i++) {
		arr[i] = 0;
	}
}


void swap(int* num0, int* num) {

	int temp = *num0;
	*num0 = *num;
	*num = temp;
}


