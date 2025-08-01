#include <stdio.h>
// Additional Functions
int isPrimeNumber(int num) {
	if (num < 2) return 0; // 0 and 1 are not prime numbers
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return 0; // Not a prime number
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
int arrLength(int a[]) {
	return sizeof(a) / sizeof(a[0]);
}
/*
1. Viết chương trình tính tổng các phần tử là số nguyên tố của một mảng nguyên
*/

int main() {
	int n;
	printf("Nhap so luong phan tu cua mang: ");
	scanf_s("%d", &n);
	int arr[n];
	printf("Nhap cac phan tu cua mang:\n");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (isPrimeNumber(arr[i])) {
			sum += arr[i];
		}
	}
	printf("Tong cac phan tu la so nguyen to: %d\n", sum);
	return 0;
}

/*
2. Viết chương trình cho phép nhập một mảng số nguyên. Sau đó, chương trình phải tính
được mean (trung bình) của mảng trên, và đồng thời đếm được có bao nhiêu phần tử
lớn hơn mean của mảng
*/

int main() {
	int n;
	printf("Nhap so luong phan tu cua mang: ");
	scanf("%d", &n);
	int arr[n];
	printf("Nhap cac phan tu cua mang:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	float aver = mean(arr, n);
	int higherAver = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > aver) {
			higherAver++;
		}
	}
	printf("Trung binh cua mang: %.2f\n", aver);
	printf("So phan tu lon hon trung binh: %d\n", higherAver);
}

/*
Giả sử cách tính thuế thu nhập cá nhân dựa trên biểu thuế như sau:
Bậc 
1
2
3
4
Thu nhập tính thuế/month (triệu đồng)
Đến 10
Đến 15
Đến 20
Trên 20
Thuế suất (%)
0
5
10
15
Ví dụ, nếu thu nhập cá nhân một tháng là 16 triệu thì thuế thu nhập cá nhân sẽ được
tính như sau:
 Từ 0-10 triệu sẽ được miễn thuế.
 Từ 10-15 triệu thì phải đóng thuế 5%. Vì vậy, cá nhân phải đóng thuế trong khoảng
này là 5 triệu x 5% = 250 ngàn đồng.
 Từ 15-16 triệu thì phải đóng thuế 10%. Vì vậy, cá nhân phải đóng thuế trong khoảng
này là 1 triệu x 10% = 100 ngàn đồng.
 Do đó, cá nhân phải đóng thuế thu nhập là 250 + 100 = 350 ngàn đồng.
Viết chương trình cho phép nhập thu nhập cá nhân của một tháng và tính thuế thu nhập
cá nhân của tháng đó.
*/

int main() {
	int tier[4] = {1,2,3,4};
	int moneyRange[4] = {0, 10, 15, 20}; // Triệu đồng
	int taxRate[4] = { 0, 5, 10, 15 }; // Tỷ lệ thuế phần trăm
	int income;
	float tax = 0;
	printf("Nhap thu nhap ca nhan trong thang (trieu dong): ");
	scanf("%d", &income);
	for (int i = 0; i < 4; i++) {
		if (income > moneyRange[i]) {
			if (i == 0) {
				tax += (moneyRange[i + 1] - moneyRange[i]) * taxRate[i] / 100.0; // Tính thuế cho bậc 1
			}
			else if (i == 3) {
				tax += (income - moneyRange[i]) * taxRate[i] / 100.0; // Tính thuế cho bậc 4
			}
			else {
				tax += (moneyRange[i + 1] - moneyRange[i]) * taxRate[i] / 100.0; // Tính thuế cho các bậc trung gian
			}
		}
		else {
			break; // Dừng khi không còn bậc thuế nào phù hợp
		}
	}
	printf("Tong thue thu nhap ca nhan phai dong la: %.2f trieu dong\n", tax);

	return 0;
}

/*
4. Một công ty muốn thống kê số lượng người phụ thuộc của các nhân viên. Người phụ
thuộc của nhân viên có thể là con còn nhỏ, cha mẹ hết tuổi lao động, ... Giả sử rằng
công ty không có nhân viên nào có quá 5 người phụ thuộc, thì một báo cáo thường có
dạng như sau:
Số người phụ thuộc 
0
1
2
3
4
5
Số lượng nhân viên
43
35
24
11
5
6
Bảng dữ liệu trên cho thấy rằng số lượng nhân viên có 2 người phụ thuộc là 24 nhân
viên.Viết chương trình cho phép nhập lần lượt số người phụ thuộc của từng nhân viên. Số
người phụ thuộc nhập vào phải nằm trong khoảng từ 0 đến 5, ngược lại thì chương
trình sẽ dừng nhập rồi in ra bảng thống kê như ví dụ trên.
*/

int main() {
	int relatives[6] = { 0 };
	int input;
	do {
		scanf("%d", &input);
		if (input < 0 || input > 5) {
			printf("invalid.\n");
			break;
		}
		relatives[input]++;
	} while (1);
	printf("So nguoi phu thuoc\tSo luong nhan vien\n");
	for (int i = 0; i < 6; i++) {
		printf("%d | %d\n", i, relatives[i]);
	}
	return 0;
}

/*
5. Viết một chương trình để đếm tần suất xuất hiện của từng phần tử của một mảng. Ví
dụ, nhập mảng {25, 12, 43, 12}, xuất ra:
Tần suất của tất cả các phần tử của một mảng:
25 1
12 2
43 1
*/

int main() {
	int n;
	printf("Nhap do dai cua mang: \n");
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++) {
		printf("arr[%d]: \n",i);
		scanf("%d", &arr[i]);
	}
	int maxValue = getMax(arr, n);
	int holderArr[maxValue + 1] = {};
	for (int i = 0; i <= maxValue; i++) holderArr[i] = 0;
	for (int i = 0; i < n; i++) {
		holderArr[arr[i]]++;
	}
	for (int i = 0; i <= maxValue; i++) {
		if (holderArr[i] != 0) {
			printf("%d | %d \n", i, holderArr[i]);
		}
	}
}

/*
6. Viết chương trình liệt kê các dãy con không giảm của một dãy số nguyên. Ví dụ, nhập
dãy số {2, 3, 4, 5, 5, 4, 5, 6, 7, 8, 9, 0, 1, 2, 2}, xuất ra:
Dãy con thứ 1: 2, 3, 4, 5, 5
Dãy con thứ 2: 4, 5, 6, 7, 8, 9
Dãy con thứ 3: 0, 1, 2, 2

15
2 3 4 5 5 4 5 6 7 8 9 0 1 2 2
*/
int main() {
	int n;
	printf("Do dai mang: \n");
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) {
		printf("\narr[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int holderArr[n] = {};
	int index = 0;
	for (int i = 1; i < n; i++) {
		int prevValue = a[i - 1];
		if (prevValue > a[i]) {
			holderArr[index] = i;
			index++;
		}
	}
	// 	for (int i = 0; i < n; i++) {
	// 		printf("\nholderArr[%d] = %d", i, holderArr[i]);
	// 	}

	for (int i = 0; i <= index; i++) {
		printf("\nDay con thu %d: ", i + 1);
		if (i == 0) {
			for (int j = 0; j < holderArr[i]; j++) {
				printf("%d, ", a[j]);
			}
		}
		else if (i == index) {
			for (int j = holderArr[i - 1]; j < n; j++) {
				printf("%d, ", a[j]);
			}
		}
		else {
			for (int j = holderArr[i - 1]; j < holderArr[i]; j++) {
				printf("%d, ", a[j]);
			}
		}
	}
}

/*
7. Viết chương trình liệt kê các dãy con không lặp của một dãy số nguyên. Ví dụ, nhập
dãy số {2, 3, 4, 5, 5, 4, 5, 6, 7, 8, 9, 0, 1, 2, 2}, xuất ra:
Dãy con thứ 1: 2, 3, 4, 5
Dãy con thứ 2: 5, 4
Dãy con thứ 3: 5, 6, 7, 8, 9, 0, 1, 2
Dãy con thứ 4: 2

*/

int main() {
	int n;
	printf("Do dai mang: \n");
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) {
		printf("\narr[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int holderArr[n] = {};
	int index = 0;
	int numberCheckArr[getMax(a, n)] = {};
	initArr(numberCheckArr, getMax(a, n));
	for (int i = 0; i < n; i++) {
		if (numberCheckArr[a[i]] == 1) {
			holderArr[index] = i;
			index++;
			initArr(numberCheckArr, getMax(a, n)); // Reset the number check array
		}
		numberCheckArr[a[i]]++;
	}
	 //for (int i = 0; i < n; i++) {
 	//	printf("\nholderArr[%d] = %d", i, holderArr[i]);
 	//}
		for (int i = 0; i <= index; i++) {
			printf("\nDay con thu %d: ", i + 1);
			if (i == 0) {
				for (int j = 0; j < holderArr[i]; j++) {
					printf("%d, ", a[j]);
				}
			}
			else if (i == index) {
				for (int j = holderArr[i - 1]; j < n; j++) {
					printf("%d, ", a[j]);
				}
			}
			else {
				for (int j = holderArr[i - 1]; j < holderArr[i]; j++) {
					printf("%d, ", a[j]);
				}
			}
		}
}

/*
8. Trong một dãy số nguyên, phần tử cực đại là phần tử lớn hơn hai phần tử liền kề. Viết
chương trình tìm phần tử cực đại lớn nhất của một dãy số nguyên. Ví dụ, nhập dãy số
{2, 7, 12, 25, 4, 57, 27, 44}, xuất ra:
Phần tử cực đại lớn nhất là: 57

8
2 7 12 25 4 57 27 44
*/

int main() {
	int n;
	printf("Do dai mang: \n");
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) {
		printf("\narr[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int maxValue = a[0];
	for (int i = 1; i < n - 1; i++) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			if (a[i] > maxValue) {
				maxValue = a[i];
			}
		}
	}

	printf("Phan tu cuc dai lon nhat la: %d\n", maxValue);
	return 0;
}

/*
9. Cho một mảng nguyên A[n] và một số nguyên k. Viết chương trình để:
- Duyệt mảng A từ phần tử đầu tiên, nếu A[i] chia hết cho k thì thêm k phần tử A[i]/k
vào mảng A.
- Tính tổng của các phần tử có thể có của A.
Ví dụ, nhập mảng A = {4, 6, 2} thì các phần tử của A sau khi duyệt mảng là {4, 6, 2,
2, 2, 3, 3, 1, 1, 1, 1, 1, 1}, xuất ra:
Tổng của các phần tử của mảng sau khi duyệt là: 28



*/

// đề ngu, đọc dell hiểu, dell làm. Hết.

/*
10. Viết chương trình sao chép mảng hai chiều sang mảng một chiều
*/

int main() {
	int n, m;
	printf("Nhap so dong cua mang: ");
	scanf("%d", &n);
	printf("Nhap so cot cua mang: ");
	scanf("%d", &m);
	int arr2D[n][m];
	printf("Nhap cac phan tu cua mang:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr2D[i][j]);
		}
	}
	int arr1D[n * m];
	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr1D[index++] = arr2D[i][j];
		}
	}
	printf("Mang mot chieu sau khi sao chep:\n");
	for (int i = 0; i < n * m; i++) {
		printf("%d ", arr1D[i]);
	}
	return 0;
}
/*

11. Viết chương trình nhập vào một ma trận vuông (có giá trị nguyên), kích thước do người
dùng nhập vào. Sau đó, kiểm tra ma trận đó có đối xứng qua đường chéo chính hay
không.

*/

#include <stdio.h>
int main() {
	int n;
	printf("Nhap kich thuoc ma tran vuong: ");
	scanf("%d", &n);
	int matrix[n][n];

	printf("Nhap cac phan tu cua ma tran:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	int isSymmetric = 1; // Giả sử ma trận là đối xứng
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != matrix[j][i]) {
				isSymmetric = 0; // Nếu có phần tử không bằng, không đối xứng
				break;
			}
		}
		if (!isSymmetric) break;
	}
	if (isSymmetric) {
		printf("Ma tran la doi xung qua duong cheo chinh.\n");
	}
	else {
		printf("Ma tran khong doi xung qua duong cheo chinh.\n");
	}
	return 0;
}