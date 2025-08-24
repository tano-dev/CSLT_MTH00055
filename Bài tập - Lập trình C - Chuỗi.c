/*
1. Viết chương trình tính độ dài của một chuỗi không sử dụng các hàm của thư viện
string.h. Ví dụ, nhập chuỗi “Hello”, xuất ra:
Độ dài của chuỗi là: 5
*/

#include <stdio.h>
int main() {
	int n;
	printf("Nhap do dai chuoi: ");
	scanf("%d", &n); // Nhập độ dài chuỗi
	char str[n+1];
	printf("Nhap chuoi: ");
	gets(str, n, stdin); // Sử dụng fgets để đọc chuỗi
	int length = 0;

	// Tính độ dài của chuỗi
	while (str[length] != '\0' && str[length] != '\n') {
		length++;
	}

	printf("Do dai cua chuoi la: %d\n", length);
	return 0;
}

