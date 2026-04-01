#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void init(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 201 - 100;
    }
}

void print(int* arr, int n) {
    printf("Масив:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, arr[i]);
    }
}


int sumOfIndex(int* arr, int n) {
    int sum = 0;
    for (int i = 1; i < n; i += 2) {
        sum += arr[i];
    }
    return sum;
}


int productBetwenNegatives(int* arr, int n) {
    int first = -1, last = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (first == -1)
                first = i;
            last = i;
        }
    }

    if (first == -1 || first == last)
        return 0;

    int product = 1;
    for (int i = first + 1; i < last; i++) {
        product *= arr[i];
    }
    if (product == 1)
		product = 0;
    return product;
}

int main() {
	setlocale(LC_ALL, "Ukrainian");
    int cor = 1;
    while (cor == 1) {
        int n;
        int corCorect = 1;
        while (corCorect == 1) {
            printf("Введiть розмiр масиву: ");
            scanf_s("%d", &n);
            if (n > 0 && n <= 100) {
                corCorect = 0;
            }
            else {
                printf("Розмiр масиву повинен бути вiд 1 до 100. Спробуйте ще раз.\n");
			}
        }
        int arr[100];
        int* P = arr;
        srand(time(0));

        init(P, n);
        print(P, n);

        printf("Сума непарних iндексiв: %d\n", sumOfIndex(P, n));
        if (productBetwenNegatives(P, n) == 0) {
            printf("Немає вiд'ємних чисел або лише одне вiд'ємне число.\n");
        }
        else {
            printf("Добуток мiж вiд'ємними: %d\n", productBetwenNegatives(P, n));
           
        }
        printf("\nБажаєте повторити? (1 - так, 0 - ні) \n");
        scanf_s("%d", &cor);
    }

}