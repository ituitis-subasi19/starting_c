#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	const int RUN = 1000;
	int* counts[10];
	srand(time(NULL));
	
	for (int i = 0; i < 10; i++) {
		counts[i] = (int*) (malloc((i + 1) * sizeof(int)));
		for (int j = 0; j <= i; j++) {
			counts[i][j] = 0;
		}
	}
	
	for (int run = 0; run < RUN; run++) {
		counts[0][0]++;
		int j = 0;
		for (int i = 1; i < 10; i++) {
			int r = rand() % 2;
			if (r == 1) {
				j++;
			}
			counts[i][j]++;
		}
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%5d", counts[i][j]);
		}
		printf("\n");
	}
	
	for (int i = 0; i < 10; i++) {
		free(counts[i]);
	}
	return 0;
}
