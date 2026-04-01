#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
int* init(int* arr, int Columns) {
	printf("Ведіть значення масиву\n");
	for (int i = 0; i < Columns; i++) {
		printf("arr[%d] = ", i);
		scanf_s("%d", &arr[i]); 
	}
	return arr;
}
int sum_between_negatives(int* arr, int n) {
	int first = -1, second = -1;


	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			if (first == -1)
				first = i;
			else {
				second = i;
				break;
			}
		}
	}

	
	if (first == -1 || second == -1)
		return 0;

	int sum = 0;
	for (int i = first + 1; i < second; i++) {
		sum += arr[i];
	}

	return sum;
}
void print(int* arr, int Columns) {
	for (int i = 0; i < Columns; i++)
		printf("[%d] = %d \n",i, arr[i]);
	printf("\n");
}
int min(int* arr, int Columns) {
	int min = arr[0];
	for (int i = 1; i < Columns; i++)
		if (abs(arr[i]) < abs(min))
			min = arr[i];
	return min;
}
void main() {
	setlocale(LC_ALL, "Ukrainian");
	int colCount = 5;
	int cor = 1;
	while (cor) {
		int corCorect = 1;
		while (corCorect) {
			printf("Ведіть розмір масиву: \n");
			scanf_s("%d", &colCount);
			if (colCount > 0 && colCount <= 100)
				corCorect = 0;
			else
				printf("Розмір масиву має бути від 1 до 100\n");
		}
		int b[100];
		int* p = init(b, colCount);
		int Fmin = min(p, colCount);
		int sumBtw = sum_between_negatives(p, colCount);
		print(p, colCount);

		printf("\nМінімальне за модулем %d", Fmin);
		if (sumBtw == 0)
			printf("\nНемає двох від'ємних елементів для обчислення суми між ними");
		else {
			printf("\nСума між першим та другим від'ємними елементами: %d", sumBtw);
		}
		printf("\nБажаєте повторити? (1 - так, 0 - ні) \n");
		scanf_s("%d", &cor);
	}
}