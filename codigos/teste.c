#include <stdio.h>
#include <stdlib.h>

void sum(int *a){
	*a = *a + 1;
}

int main(){
	int a = 1;
	printf("%d\n", a);
	a++;
	printf("%d\n", a);
	sum(&a);
	printf("%d\n", a);
	return 0;
}
