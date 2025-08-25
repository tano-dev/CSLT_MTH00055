//Dùng hàm scanf để nhập chuỗi không có khoảng trắng.
//fgets(Tên biến chuỗi, Số phần tử tối đa, stdin);
/*
Note fgets trong terminal se lay them '\n' vi enter se xuong dong
nen them dieu kiện str[length] != '\n' để loại bỏ ký tự xuống dòng.
but if u are using text terminal, it will not add '\n' at the end of the string cuz no enter pressed 
(test it in gdbonline)

*/
/*
1. Viết chương trình tính độ dài của một chuỗi không sử dụng các hàm của thư viện
string.h. Ví dụ, nhập chuỗi “Hello”, xuất ra:
Độ dài của chuỗi là: 5
*/

#include <stdio.h>
int main() {
	char str[100] = "";
	printf("Nhap chuoi: \n");
	//fgets(str, sizeof(str), stdin);

	int length = 0;
	while (str[length] != '\0' && str[length] != '\n') {
		length++;
	}
	printf("Do dai cua chuoi la: %d\n", length);
	return 0;
}

/*
2. Viết chương trình xuất các ký tự của một chuỗi theo thứ tự ngược lại. Ví dụ, nhập
chuỗi "Hello", xuất ra:
Các ký tự của chuỗi đảo ngược là: o l l e H
*/

#include <stdio.h>
int main() {
	char str[100] = "";
	printf("Nhap chuoi: \n");
	fgets(str, sizeof(str), stdin);

	int length = 0;
	while (str[length] != '\0' && str[length] != '\n') {
		length++;
	}
	printf("Cac ky tu cua chuoi dao nguoc la: ");
	for (int i = length - 1; i >= 0; i--) {
		printf("%c ", str[i]);
	}
	printf("\n");
	return 0;
}

/*
3. Viết chương trình đếm tổng số từ trong một chuỗi. Ví dụ, nhập chuỗi "Hello world",
xuất ra:
Tổng số từ trong chuỗi là: 2
*/
#include<stdio.h>
int main() {
	//1
	char str[100];
	fgets(str, sizeof(str), stdin);
	int length = 0;
	while (str[length] != '\0' && str[length] != '\n') {
		length++;
	}
	printf("do dai chuoi: %d \n", length);
	//2
	for (int i = length - 1; i >= 0; i--) {
		printf("%c ", str[i]);
	}
	//3
	int words = 1;
	for (int i = 0; i < length - 1; i++) {
		if (str[i] == ' ' && str != ' ') {
			words++;
		}
	}
	printf("\ntong so chu: %d \n", words);
	return 0;
}

/*
4. Viết chương trình đếm tổng số chữ cái, chữ số và ký tự đặc biệt trong một chuỗi. Ví
dụ, nhập chuỗi “227 Nguyen Van Cu, Q. 5”, xuất ra:
Số chữ cái trong chuỗi là: 12
Số chữ số trong chuỗi là: 4
Số ký tự đặc biệt trong chuỗi là: 7
*/
#include <stdio.h>
int main() {
	char str[100];
	printf("Nhap chuoi: \n");
	fgets(str, sizeof(str), stdin);
	int letters = 0, digits = 0, specialChars = 0;
	for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			letters++;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			digits++;
		}
		else if (str[i] != ' ') {
			specialChars++;
		}
	}
	printf("So chu cai trong chuoi la: %d\n", letters);
	printf("So chu so trong chuoi la: %d\n", digits);
	printf("So ky tu dac biet trong chuoi la: %d\n", specialChars);
	return 0;
}
/*
5. Viết chương trình sao chép chuỗi này sang chuỗi khác. Ví dụ nhập chuỗi “Thuc hanh
Co so lap trinh.”, kết quả mong đợi:
Chuỗi thứ nhất là: Thuc hanh Co so lap trinh.
Chuỗi thứ hai là: Thuc hanh Co so lap trinh.
Số ký tự được sao chép: 26
*/
#include <stdio.h>
int main() {
	char str1[100];
	printf("Nhap chuoi: \n");
	fgets(str1, sizeof(str1), stdin);
	char str2[100];
	int i = 0;
	while (str1[i] != '\0' && str1[i] != '\n') {
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0'; // Kết thúc chuỗi
	printf("Chuoi thu nhat la: %s", str1);
	printf("Chuoi thu hai la: %s", str2);
	printf("So ky tu duoc sao chep: %d\n", i);
	return 0;
}

/* 
6. Viết chương trình tìm số ký tự lớn nhất trong một chuỗi. Ví dụ, nhập chuỗi "Hello
world", xuất ra:
Tần suất xuất hiện cao nhất của ký tự 'l' là: 3
*/
#include <stdio.h>
int main() {
	char str[100];
	printf("Nhap chuoi: \n");
	fgets(str, sizeof(str), stdin);
	int frequency[256] = { 0 }; // Mảng đếm tần suất ký tự
	int maxFreq = 0;
	char maxChar = '\0';
	for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
		frequency[(unsigned char)str[i]]++;
		if (frequency[(unsigned char)str[i]] > maxFreq) {
			maxFreq = frequency[(unsigned char)str[i]];
			maxChar = str[i];
		}
	}
	if (maxFreq > 0) {
		printf("Tan suat xuat hien cao nhat cua ky tu '%c' la: %d\n", maxChar, maxFreq);
	}
	else {
		printf("Khong co ky tu nao trong chuoi.\n");
	}
	return 0;
}
/*
7. Viết chương trình để trích xuất một chuỗi con từ một chuỗi cho trước không sử dụng
các hàm của thư viện string.h. Ví dụ nhập chuỗi “Dai hoc Khoa hoc tu nhien”, vị trí
bắt đầu trích xuất 8, độ dài chuỗi con 4, xuất ra:
Chuỗi con lấy ra từ chuỗi là: Khoa
*/
#include <stdio.h>
int main() {
	char str[100];
	printf("Nhap chuoi: \n");
	fgets(str, sizeof(str), stdin);
	int start, length;
	printf("Nhap vi tri bat dau trich xuat: ");
	scanf("%d", &start);
	printf("Nhap do dai chuoi con: ");
	scanf("%d", &length);
	if (start < 0 || start >= 100 || length < 0 || start + length > 100) {
		printf("Vi tri hoac do dai khong hop le.\n");
		return 1;
	}
	char substring[100];
	for (int i = 0; i < length && str[start + i] != '\0' && str[start + i] != '\n'; i++) {
		substring[i] = str[start + i];
	}
	substring[length] = '\0'; // Kết thúc chuỗi
	printf("Chuoi con lay ra tu chuoi la: %s\n", substring);
	return 0;
}
/*
8. Viết chương trình kiểm tra xem một chuỗi có tồn tại chuỗi con hay không. Ví dụ, nhập
chuỗi “Co so lap trinh”, chuỗi con cần tìm “Toan”, xuất ra:
Chuỗi con không tồn tại trong chuỗi.
*/
#include <stdio.h>
int main() {
	char str[100];
	char substring[100];
	printf("Nhap chuoi: \n");
	fgets(str, sizeof(str), stdin);
	printf("Nhap chuoi con can tim: \n");
	fgets(substring, sizeof(substring), stdin);
	// Loại bỏ ký tự xuống dòng ở cuối chuỗi
	int lenStr = 0, lenSub = 0;
	while (str[lenStr] != '\0' && str[lenStr] != '\n') lenStr++;
	while (substring[lenSub] != '\0' && substring[lenSub] != '\n') lenSub++;
	int found = 0;
	for (int i = 0; i <= lenStr - lenSub; i++) {
		int j;
		for (j = 0; j < lenSub; j++) {
			if (str[i + j] != substring[j]) {
				break;
			}
		}
		if (j == lenSub) {
			found = 1;
			break;
		}
	}
	if (found) {
		printf("Chuoi con ton tai trong chuoi.\n");
	}
	else {
		printf("Chuoi con khong ton tai trong chuoi.\n");
	}
	return 0;
}

/*
9. Viết chương trình để tìm từ ngắn nhất và từ dài nhất trong một chuỗi. Ví dụ: nhập chuỗi
“This is a string with smallest and largest word", xuất ra:
Từ ngắn nhất: "a"
Từ dài nhất: "smallest"
*/
#include <stdio.h>
int main() {
	char str[100];
	printf("Nhap chuoi: \n");
	fgets(str, sizeof(str), stdin);
	int minLength = 100, maxLength = 0;
	char minWord[100], maxWord[100];
	char currentWord[100];
	int currentLength = 0;
	for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
		if (str[i] == ' ' || str[i] == '\0') {
			if (currentLength > 0) {
				currentWord[currentLength] = '\0'; // Kết thúc từ hiện tại
				if (currentLength < minLength) {
					minLength = currentLength;
					strcpy(minWord, currentWord);
				}
				if (currentLength > maxLength) {
					maxLength = currentLength;
					strcpy(maxWord, currentWord);
				}
				currentLength = 0; // Reset độ dài từ hiện tại
			}
		}
		else {
			currentWord[currentLength++] = str[i]; // Thêm ký tự vào từ hiện tại
		}
	}
	// Xử lý từ cuối cùng nếu có
	if (currentLength > 0) {
		currentWord[currentLength] = '\0';
		if (currentLength < minLength) {
			minLength = currentLength;
			strcpy(minWord, currentWord);
		}
		if (currentLength > maxLength) {
			maxLength = currentLength;
			strcpy(maxWord, currentWord);
		}
	}
	printf("Tu ngan nhat: \"%s\"\n", minWord);
	printf("Tu dai nhat: \"%s\"\n", maxWord);
	return 0;
}