#include <stdio.h>
//You cannot use the string library 

#define MAX_STRING_ARRAY_SIZE 20


void append(char* a, char* b)
{
  //fill the function body. Do not change the arguments and the return parameter
  int count_a = 0;
  while(a[count_a] != '\0') {
  	count_a++;
  }
  
  int count_b = 0;
  while(b[count_b] != '\0') {
  	count_b++;
  }
  
  if (count_a + count_b + 1 > MAX_STRING_ARRAY_SIZE) {
  	printf("Error");
  } else {
  	a += count_a;
  	a[0] = ' ';
  	a++;
  	for(int i = 0; i <= count_b; i++) {
  		a[i] = b[i];
	}
	a -= (count_a + 1);
	for (int i = 0; i < count_a + count_b + 1; i++) {
		printf("%c", a[i]);
	} 
  }
  
  return;
}

int main()
{
	char a[MAX_STRING_ARRAY_SIZE];
	char b[MAX_STRING_ARRAY_SIZE];
	scanf("%s",a);
	scanf("%s",b);
	append(a,b);
	return 0;
}
