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

/*
10. Viết chương trình đọc một câu và thay thế các ký tự chữ thường bằng chữ hoa và ngược
lại. Ví dụ: nhập chuỗi "This Is A Test String.", xuất ra:
Câu đã cho là: This Is A Test String.
Sau khi thay đổi chữ hoa chữ thường, chuỗi là: tHIS iS a tEST sTRING.
*/

#include <stdio.h>
int main() {
	char str[100];
	printf("Nhap chuoi: \n");
	fgets(str, sizeof(str), stdin);
	for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - ('a' - 'A'); // Chuyển chữ thường thành chữ hoa
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + ('a' - 'A'); // Chuyển chữ hoa thành chữ thường
		}
	}
	printf("Cau sau khi thay doi chu hoa chu thuong: %s", str);
	return 0;
}
/*
11. Viết chương trình tính số lần một từ xuất hiện trong chuỗi đã cho. Ví dụ: nhập chuỗi
"The string where the word the present more than once.", từ "the", xuất ra:
Tần suất xuất hiện của từ "the" là: 3
*/
#include <stdio.h>
#include <string.h>
int main() {
	char str[200];
	char word[50];
	printf("Nhap chuoi: \n");
	fgets(str, sizeof(str), stdin);
	printf("Nhap tu can dem: \n");
	fgets(word, sizeof(word), stdin);
	// Loại bỏ ký tự xuống dòng ở cuối từ
	int lenWord = 0;
	while (word[lenWord] != '\0' && word[lenWord] != '\n') lenWord++;
	word[lenWord] = '\0';
	int count = 0;
	int lenStr = 0;
	while (str[lenStr] != '\0' && str[lenStr] != '\n') lenStr++;
	for (int i = 0; i <= lenStr - lenWord; i++) {
		int j;
		for (j = 0; j < lenWord; j++) {
			if (str[i + j] != word[j]) {
				break;
			}
		}
		if (j == lenWord) {
			count++;
			i += lenWord - 1; // Di chuyển chỉ số i để tránh đếm chồng lắp
		}
	}
	printf("Tan suat xuat hien cua tu \"%s\" la: %d\n", word, count);
	return 0;
}
// khong dung string.h

#include <stdio.h>
int main() {
	char str[200];
	char word[50];
	printf("Nhap chuoi: \n");
	fgets(str, sizeof(str), stdin);
	printf("Nhap tu can dem: \n");
	fgets(word, sizeof(word), stdin);
	// Loại bỏ ký tự xuống dòng ở cuối từ
	int lenWord = 0;
	while (word[lenWord] != '\0' && word[lenWord] != '\n') lenWord++;
	word[lenWord] = '\0';
	int count = 0;
	int lenStr = 0;
	while (str[lenStr] != '\0' && str[lenStr] != '\n') lenStr++;
	for (int i = 0; i <= lenStr - lenWord; i++) {
		int j;
		for (j = 0; j < lenWord; j++) {
			if (str[i + j] != word[j]) {
				break;
			}
		}
		if (j == lenWord) {
			count++;
			i += lenWord - 1; // Di chuyển chỉ số i để tránh đếm chồng lắp
		}
	}
	printf("Tan suat xuat hien cua tu \"%s\" la: %d\n", word, count);
	return 0;
}
/*
12. Viết chương trình xóa các ký tự khỏi một chuỗi ngoại trừ các chữ cái. Ví dụ nhập chuỗi
“227 Nguyen Van Cu, Q. 5”, xuất ra:
Chuỗi sau khi loại bỏ: Nguyen Van Cu Q
*/
#include <stdio.h>
int main() {
	char str[100];
	printf("Nhap chuoi: \n");
	fgets(str, sizeof(str), stdin);
	char result[100];
	int index = 0;
	for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == ' ') {
			result[index++] = str[i];
		}
	}
	result[index] = '\0'; // Kết thúc chuỗi
	printf("Chuoi sau khi loai bo: %s\n", result);
	return 0;
}

/*
13. Viết một chương trình để kết hợp hai chuỗi không sử dụng các hàm của thư viện
string.h. Ví dụ, nhập chuỗi thứ nhất "This is string one.", chuỗi thứ hai "This is string
two.", xuất ra:
Sau khi kết hợp chuỗi là: This is string one. This is string two.
*/
#include <stdio.h>
int main() {
	char str1[100];
	char str2[100];
	printf("Nhap chuoi thu nhat: \n");
	fgets(str1, sizeof(str1), stdin);
	printf("Nhap chuoi thu hai: \n");
	fgets(str2, sizeof(str2), stdin);
	// Loại bỏ ký tự xuống dòng ở cuối chuỗi thứ nhất
	int len1 = 0;
	while (str1[len1] != '\0' && str1[len1] != '\n') len1++;
	str1[len1] = ' '; // Thêm khoảng trắng giữa hai chuỗi
	len1++;
	// Kết hợp chuỗi thứ hai vào chuỗi thứ nhất
	int i = 0;
	while (str2[i] != '\0' && str2[i] != '\n') {
		str1[len1++] = str2[i++];
	}
	str1[len1] = '\0'; // Kết thúc chuỗi
	printf("Sau khi ket hop chuoi la: %s\n", str1);
	return 0;
}

/*
14. Viết một chương trình để tách chuỗi thành các từ bởi khoảng trắng. Ví dụ, nhập chuỗi
"This is a test string", xuất ra:
Từ sau khi tách bởi khoảng trắng là:
This
is
a
test
string
*/
#include <stdio.h>
int main() {
	char str[100];
	printf("Nhap chuoi: \n");
	fgets(str, sizeof(str), stdin);
	char word[100];
	int index = 0;
	printf("Tu sau khi tach boi khoang trang la:\n");
	for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
		if (str[i] != ' ') {
			word[index++] = str[i];
		}
		else {
			if (index > 0) {
				word[index] = '\0'; // Kết thúc từ
				printf("%s\n", word);
				index = 0; // Reset chỉ số từ
			}
		}
	}
	// In từ cuối cùng nếu có
	if (index > 0) {
		word[index] = '\0';
		printf("%s\n", word);
	}
	return 0;
}
/*
15. Viết một chương trình để đếm từng ký tự trong một chuỗi. Ví dụ, nhập chuỗi "Hello",
xuất ra:
Số lượng của mỗi ký tự trong chuỗi là:
H 1
e 1
l 2
o 1
*/
#include <stdio.h>
int main() {
	char str[100];
	printf("Nhap chuoi: \n");
	fgets(str, sizeof(str), stdin);
	int frequency[256] = { 0 }; // Mảng đếm tần suất ký tự
	for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
		frequency[(unsigned char)str[i]]++;
	}
	printf("So luong cua moi ky tu trong chuoi la:\n");
	for (int i = 0; i < 256; i++) {
		if (frequency[i] > 0) {
			printf("%c %d\n", (char)i, frequency[i]);
		}
	}
	return 0;
}
/*
16. Viết chương trình nhập nhiều chuỗi và sắp xếp chúng theo chiều tăng dần. Ví dụ: nhập
“one”, rồi “three”, rồi “two”, xuất ra:
one two three
*/
#include <stdio.h>
#include <string.h>
int main() {
	char strings[10][100];
	int n;
	printf("Nhap so luong chuoi: ");
	scanf("%d", &n);
	getchar(); // Đọc ký tự newline sau khi nhập số
	for (int i = 0; i < n; i++) {
		printf("Nhap chuoi thu %d: ", i + 1);
		fgets(strings[i], sizeof(strings[i]), stdin);
		// Loại bỏ ký tự xuống dòng ở cuối chuỗi
		int len = 0;
		while (strings[i][len] != '\0' && strings[i][len] != '\n') len++;
		strings[i][len] = '\0';
	}
	// Sắp xếp chuỗi theo thứ tự tăng dần
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(strings[i], strings[j]) > 0) {
				char temp[100];
				strcpy(temp, strings[i]);
				strcpy(strings[i], strings[j]);
				strcpy(strings[j], temp);
			}
		}
	}
	printf("Chuoi sau khi sap xep theo chieu tang dan:\n");
	for (int i = 0; i < n; i++) {
		printf("%s ", strings[i]);
	}
	printf("\n");
	return 0;
}

