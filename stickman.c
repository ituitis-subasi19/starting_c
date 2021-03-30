#include <stdio.h>
#include <stdlib.h>

int main() {
	int stickman_height = 0;
	int stair_height = 0;
	
	printf("Enter stickman height and stair height (stickman height must be bigger than stair height + 2): ");
	scanf("%d %d", &stickman_height, &stair_height);
	
	for (int x = 0; x <= stair_height; x++) {
		for (int i = 0; i < (stickman_height - stair_height - 1 - x); i++) {
			printf("\n");
		}
		for (int i = 0; i < x; i++) {
			printf("   ");
		}
		printf(" O \n");
		for (int i = 0; i < x; i++) {
			printf("   ");
		}
		printf("/|\\\n");
		for (int i = 0; i < (stickman_height - stair_height - 3 + x); i++) {
			for (int j = 0; j < x; j++) {
				printf("   ");
			}
			printf(" | \n");
		}
		for (int i = 0; i <= (stair_height - x);) {
			for (; i == (stair_height - x); i++) {
				for (int y = 0; y < x; y++) {
					printf("   ");
				}
				printf("/ \\");
				for (int j = 0; j < (stair_height - i - x); j++) {
					printf("   ");
				}
				printf("___|");
				for (int h = 0; h < i; h++) {
					printf("***");
				}
				printf("|\n");
				for (; i < stair_height; i++) {
					for (int j = 0; j < (stair_height - i); j++) {
						printf("   ");
					}
					printf("___|");
					for (int h = 0; h <= i; h++) {
						printf("***");
					}
					printf("|\n");
				}
			}
			for (; i < (stair_height - x); i++) {
				for (int y = 0; y < x; y++) {
					printf("   ");
				}
				printf(" | ");
				for (int j = 0; j < (stair_height - i - x); j++) {
					printf("   ");
				}
				printf("___|");
				for (int h = 0; h < i; h++) {
					printf("***");
				}
				printf("|\n");
			}
		}
		printf("\n\n\n");
	}
	return 0;
}
