/*
 * main.c
 *
 *  Created on: 2016Äê7ÔÂ4ÈÕ
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>

void reverse(char *);

int fibonacci(int);

void hanoi(int, char, char, char);

void permutation(char[], int, int);

int strlen(const char *);

void reverse(char *s) {
	if ((s != NULL) && (*s != '\0')) {
		reverse(s + 1);
		printf("%c", *s);
	}
}

int fibonacci(int n) {
	if (n > 1) {
		return fibonacci(n - 1) + fibonacci(n - 2);
	} else if (n == 1) {
		return 1;
	} else if (n == 0) {
		return 0;
	}
}

void hanoi(int n, char a, char b, char c) {
	if (n > 0) {
		if (n == 1) {
			printf("%c->%c\n", a, c);
		} else {
			hanoi(n - 1, a, c, b);
			printf("%c->%c\n", a, c);
			hanoi(n - 1, b, a, c);
		}
	}
}

void permutation(char s[], int b, int e) {
	if ((0 <= b) && (b <= e)) {
		if (b == e) {
			printf("%s\n", s);
		} else {
			int i = 0;
			for (i = b; i <= e; ++i) {
				char c = s[b];
				s[b] = s[i];
				s[i] = c;

				permutation(s, b + 1, e);
				c = s[b];
				s[b] = s[i];
				s[i] = c;
			}
		}
	}
}

int strlen(const char* s)
{
	if (s==NULL) {
		return -1;
	}else if (*s=='\0') {
		return 0;
	}else {
		return strlen(s+1)+1;
	}
}



int main(int argc, char *argv[]) {

	reverse("abcdefghijklmnopqrstuvwxyz");
	printf("\n");

	int i=0;
	for (i = 0; i <=10; ++i) {
		printf("fibonacci(%d)=%d\n", i, fibonacci(i));
	}

	hanoi(10, 'a', 'b', 'c');

	char s[]="abcdef";
	permutation(s, 0, 3);


	printf("strlen(\"12345\")=%d\n", strlen("12345"));
	printf("strlen(NULL)=%d\n", strlen(NULL));
	printf("strlen(\"\")=%d\n", strlen(""));




	return EXIT_SUCCESS;
}
