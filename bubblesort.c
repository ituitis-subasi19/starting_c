#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 20

void swap(int* first, int* second) {
	*first = *first + *second;
	*second = *first - *second;
	*first = *first - *second;
}

void fill_array(int size, int* array) {
	int filled[SIZE] = {0};
	int rand_num;
	
	for (int i = 0; i < size; i++) {
		do {
			rand_num = rand() % size;
		} while(filled[rand_num] == 1);
		
		filled[rand_num] = 1;
		array[i] = rand_num;
	}
}

void order(int size, int* array, bool ascending) {
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (ascending) {
				if (array[j] > array[j+1]) {
					swap(&array[j], &array[j+1]);
				}
			} else {
				if (array[j] < array[j+1]) {
					swap(&array[j], &array[j+1]);
				}
			}
		}
	}
}

int main() {
	int size;
	printf("Write the array size(max 20): ");
	scanf("%d", &size);
	
	int array[SIZE];
	fill_array(size, array);
	
	printf("Array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	printf("Ascending order: ");
	order(size, array, true);
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	printf("Descending order: ");
	order(size, array, false);
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	return 0;
}
