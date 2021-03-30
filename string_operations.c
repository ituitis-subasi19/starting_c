#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int str_length(char* string)
{
	int i;
	for (i = 0; string[i] != '\0'; i++);
	return i;
}

char* str_copy(char* destination, char* source)
{
	int length = str_length(source);
	for (int i = 0; i <= length; i++) {
		destination[i] = source[i];
	}
	return destination;
}

char* str_cat(char* base, char* add)
{
	int length = str_length(base);
	base += length;
	return str_copy(base, add);
}

char* sub_string(char* destination, char* source, int start, int size)
{
	int length = str_length(source);
	if (start + size <= length) {
		source += start;
		int i;
		for (i = 0; i < size; i++) {
			destination[i] = source[i];
		}
		destination[i] = '\0';
	}
	return destination;
}

void swap(char* first, char* second)
{
	*first += *second;
	*second = *first - *second;
	*first -= *second;
}

char* inttostring(int input, char* string)
{
	int i;
	for (i = 0; input > 0; i++) {
		string[i] = input % 10 + '0';
		input /= 10;
	}
	string[i] = '\0';
	int length = i;
	for(i = 0; i < length / 2; i++) {
		swap(string + i, string + length - i - 1);
	}
	return string;
}

void generate(char* name, char* surname, int year)
{
	char candidate1[50] = "";
	char candidate2[50] = "";
	char candidate3[50] = "";
	char ending[50] = "@itu.edu.tr";
	char temp[50] = "";
	
	str_cat(candidate1, sub_string(temp, name, 0, 1));
	str_cat(candidate1, surname);
	str_cat(candidate1, sub_string(temp, inttostring(year, temp), 2, 2));
	str_cat(candidate1, ending);
	
	str_cat(candidate2, sub_string(temp, name, 0, 2));
	str_cat(candidate2, sub_string(temp, surname, 0, 2));
	str_cat(candidate2, inttostring(rand() % 10000, temp));
	str_cat(candidate2, ending);
	
	str_cat(candidate3, surname);
	str_cat(candidate3, name);
	str_cat(candidate3, inttostring(year, temp));
	str_cat(candidate3, ending);
	
	printf("Email candidate1: %s\n", candidate1);
	printf("Email candidate2: %s\n", candidate2);
	printf("Email candidate3: %s\n", candidate3);
}

int main()
{
	srand(time(NULL));
	
	char name[50] = "";
	char surname[50] = "";
	int year;
	
	printf("Enter your name: ");
	scanf("%s", name);
	
	printf("Enter your surname: ");
	scanf("%s", surname);
	
	printf("Enter your birthyear: ");
	scanf("%d", &year);
	
	generate(name, surname, year);
	
	return 0;
}
