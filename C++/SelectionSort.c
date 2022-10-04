#include<stdio.h>

void swap(int *jp, int *jpp){
	int temp = *jp;
	*jp = *jpp;
	*jpp = temp;
}

void selectionSort(int array[], int n){
	int i,j,min;
	
	for(i=0; i<n-1; i++){
		min = i; // assume it is the min element at first
		for(j=i+1; j<n; j++){
			if(array[j]< array[min]){
				min = j;
			}
		}
		if(min != i){
			swap(&array[min], &array[i]);
		}
	}
}

void print(int array[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ",array[i] );
	}
}

int main(){
	int array[100], i, j, n;
	printf("Enter total number: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		printf("Enter %d st/nd/rd/th element: ", i+1);
		scanf("%d", &array[i]);
	}
	
	selectionSort(array, n);
	printf("After sorting: ");
	print(array, n);
	return 0;
}
