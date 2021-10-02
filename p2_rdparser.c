

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int i;
char str[SIZE];

void A() {

	if(str[i] == 'a') {
		i++;
		if(str[i] == 'b') {
			printf("\n A -> ab");
			i++;
		}
		else
			printf("\n A -> a");
	}
	else {
		printf("\n ERROR\n");
		exit(0);
	}

}

void S() {

	if(str[i] == 'c') {
		i++;
		A();

		if (str[i] == 'd')
			printf("\n S -> cAd");
		else
			printf("\n ERROR");
	}
	else
		printf("\n ERROR");
}



int main() {

	printf("HARIKRISHNAN PS   23  S7 CSE BETA");
	printf("\nEnter string: ");
	scanf("%[^\n]", str);
	

	S();
	printf("\n");

	return 0;

}