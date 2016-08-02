/*
 * main.c
 *
 *  Created on: 2016Äê7ÔÂ4ÈÕ
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>

void println(int array[], int len) {
	int i = 0;
	for (i = 0; i < len; ++i) {
		printf("%d,", array[i]);
	}

	printf("\n");
}

void swap(int array[], int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void selectsort(int array[], int len) {
	int i = 0, j = 0, k = -1;
	for (i = 0; i < len; ++i) {
		k = i;
		for (j = i; j < len; ++j) {
			if (array[j] < array[k]) {
				k = j;
			}
		}
		swap(array, i, k);
	}
}

void insertsort(int array[], int len) {
	int i = 0, j = 0, k = -1, temp = -1;

	for (i = 1; i < len; ++i) {
		k = i;
		temp = array[k];
		for (j = i - 1; (j >= 0) && (array[j] > temp); ++j) {
			array[j + 1] = array[j];
			k = j;
		}
		array[k] = temp;
	}
}

void bubblesort(int array[], int len) {
	int i = 0, j = 0, exchange = 1;

	for (i = 0; (i < len) && exchange; ++i) {
		exchange = 0;
		for (j = len - 1; j > i; j--) {
			if (array[j] < array[j - 1]) {
				swap(array, j, j - 1);
				exchange = 1;
			}
		}
	}
}

int main(int argc, char *argv[]) {

	int array[] = { 2, 4, 8, 1, 0, 22, 66, 11, 3, 5, 7, 55 };
	int len = sizeof(array) / sizeof(*array);

	println(array, len);
	bubblesort(array, len);
	println(array, len);
/*
	int arra[] = { 1, 2, 3, 4, 45, 65, 5, 65, 7, 6, 7, 67, 6, 6, 7, 6 };
	int le = sizeof(arra) / sizeof(*arra);

	println(arra, le);
	insertsort(arra, le);
	println(arra, le);

	int arr[] = { 6545, 75675, 265, 345, 1, 4, 55, 6, 7, 6, 787, 8, 98, 9, 89,
			8, 8 };
	int l = sizeof(arr) / sizeof(*arr);
	println(arr, l);
	selectsort(arr, l);
	println(arr, l);*/

	return EXIT_SUCCESS;
}
