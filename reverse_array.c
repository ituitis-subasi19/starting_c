#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void swap(int* first, int* second) {
	*first = *first + *second;
	*second = *first - *second;
	*first = *first - *second;
}

void random_fill_array(int* arr) {
	srand(time(NULL));
	
	int filled[SIZE] = {0};
	
	int rand_num;
	int i;
	
	for (i = 0; i < SIZE; i++) {
		do {
			rand_num = rand() % SIZE;
		} while (filled[rand_num] == 1);
		
		filled[rand_num] = 1;
		arr[i] = rand_num;
	}
}

int main() {
	int my_array[SIZE];
	
	random_fill_array(my_array);
	
	printf("Original array: ");
	
	for(int i = 0; i < SIZE; i++) {
		printf("%d ", my_array[i]);
	}
	printf("\n");
	
	for (int i = 0; i < SIZE/2; i++) {
		swap(&my_array[i], &my_array[SIZE-i-1]);
	}
	
	printf("Reverse array: ");
	
	for(int i = 0; i < SIZE; i++) {
		printf("%d ", my_array[i]);
	}
	printf("\n");
	
	return 0;
}
