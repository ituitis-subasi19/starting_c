#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool chek_num(char* number) {
	bool valid = false;
	int count = 0;
	while(number[count] != '\0') {
		count++;
	}
	
	int total = 0;
	int num;
	
	for(int i = count - 1; i >= 0; i--) {
		num = number[i] - '0';
		if((count - 1 - i) % 2 == 1) {
			total += num * 2 > 9 ? num * 2 - 9 : num * 2;
		} else {
			total += num;
		}
	}
	
	if(total % 10 == 0) {
		valid = true;
	}
	
	return valid;
}

int main() {
	bool valid = chek_num("4123175904981754");
	printf("%s\n", valid ? "true" : "false");
	return 0;
}
