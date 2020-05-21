#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int low, int mid, int high){
	int i, j, k, c[50];
	i=low;
	j=mid+1;
	k=low;
	while ((i<=mid)&&(j<=high)){
		if (array[i]<array[j]){
			c[k]=array[i];
			k++;
			i++;
		}
		else {
			c[k]=array[j];
			k++;
			j++;
		}
	}
	while (i<=mid){
		c[k]=array[i];
		k++;
		i++;
	}
	while (j<=high){
		c[k]=array[j];
		k++;
		j++;
	}
	for (i=low; i<k; i++){
		array[i]=c[i];
	}

	printf("Array c: ");
	for (int m=0; m<k; m++){
		printf("%d  ", c[m]);
		printf("m: %d", m);
	}
	printf("\n");
	for (int n=0; n<5; n++){
		printf("%d", array[n]);
	}
	printf("\n");

}

void merge_sort(int *array, int low, int high){
	if (high > low) {
		int mid = (high + low)/2;
		for (int i=0; i<5; i++){
		printf("%d", array[i]);
		}
		printf("\n");
		merge_sort(array, low, mid);
		merge_sort(array, mid+1, high);
		merge(array, low, mid, high);
	}
}



int main(){
	int array[5] = {5,4,3,2,1};
	merge_sort(array, 0, 4);
	for (int i=0; i<5; i++){
		printf("%d", array[i]);
	}
	printf("\n");
	return 0;
}
