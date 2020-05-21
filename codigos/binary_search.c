#include <stdio.h>
#include <stdlib.h>

int len(int *pointer){
	int size = (sizeof pointer) / (sizeof pointer[0]);
	//return size; 
	return 5;
}


int binary_search(int number, int *ptr, int min, int max){
	int media = (max+min)/2;
	int response = -1;
	if (ptr[media]==number){
		printf("The number is at the position %d of the array\n", media);
		return media;
	} else if (ptr[media]<number) {
		min = media + 1;
	} else if (ptr[media]>number) {
		max = media - 1;
	} 
	if (min >= 0 && min <= (len(ptr)-1) && max >= 0 && max <= (len(ptr)-1)) {
		response = binary_search(number, ptr, min, max);
	}

	return response;
}

int linear_search(int number, int *ptr){
	for (int i=0; i<6; i++){
		if (ptr[i]==number){
			printf("The number is in the position %d\n", i);
			return i;
		}
	}
	return 0;
}

int main(){
	int pointer[5];
	for (int i=0; i<5; i++){
		*(pointer + i) = i+1;
	}
	for (int i=0; i<5; i++){
		printf("%d", pointer[i]);
	}
	printf("\n");
	//int min = 1, n=5;
	printf("%d\n", sizeof pointer);
	printf("%d\n", sizeof pointer[0]);
	printf("%d\n", len(pointer));
	int res = binary_search(6, pointer, 0, len(pointer)-1);
	linear_search(6, pointer);

	return 0;
}

