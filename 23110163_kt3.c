#include <stdio.h>
int isPrimeNumber(int num) {
	if (num < 2) return 0; 
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return 0;
	}
	return 1; // Is a prime number
}
int sumArr(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}
float mean(int a[], int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum / n;
}
void initArr(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}
}
int getMax(int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}
int getMin(int a[], int n) {
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int n;
	printf("Do dai mang: \n");
	scanf_s("%d", &n);
	int a[n];
	printf("Phan tu:\n");
	for (int i = 0; i < n; i++) {
		printf("\narr[%d] = ", i);
		scanf_s("%d", &a[i]);
	}

	return 0;
}