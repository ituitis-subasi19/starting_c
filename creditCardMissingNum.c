#include <stdio.h>
#include <stdlib.h>

void fix_num(char number[]) {
	int count = 0;
	while(number[count] != '\0') {
		count++;
	}
	
	int total = 0;
	int num;
	int location, unknown;
	
	for(int i = count - 1; i >= 0; i--) {
		if(number[i] == '?') {
			location = i;
			i--;
		}
		num = number[i] - '0';
		if((count - 1 - i) % 2 == 1) {
			total += num * 2 > 9 ? num * 2 - 9 : num * 2;
		} else {
			total += num;
		}
	}
	
	if((count - 1 - location) % 2 == 1) {
		if((10 - (total % 10)) % 2 == 0) {
			unknown = (10 - (total % 10)) / 2;
		} else {
			unknown = (10 - (total % 10) + 9) / 2; 
		}
	} else {
		unknown = 10 - (total % 10);
	}
	printf("%d", unknown);
	number[location] = unknown - '0';
}

int main() {
	char number[] = "41231?5904981754";
	fix_num(number);
	return 0;
}
