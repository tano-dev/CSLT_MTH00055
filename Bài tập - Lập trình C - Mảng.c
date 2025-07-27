#include <stdio.h>
// Additional Functions
int isPrimeNumber(int num) {
	if (num < 2) return 0; // 0 and 1 are not prime numbers
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return 0; // Not a prime number
	}
	return 1; // Is a prime number
}
float mean(int a[], int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum / n;
}
/*
1. Viết chương trình tính tổng các phần tử là số nguyên tố của một mảng nguyên
*/

//int main() {
//	int n;
//	printf("Nhap so luong phan tu cua mang: ");
//	scanf_s("%d", &n);
//	int arr[n];
//	printf("Nhap cac phan tu cua mang:\n");
//	for (int i = 0; i < n; i++) {
//		scanf_s("%d", &arr[i]);
//	}
//	int sum = 0;
//	for (int i = 0; i < n; i++) {
//		if (isPrimeNumber(arr[i])) {
//			sum += arr[i];
//		}
//	}
//	printf("Tong cac phan tu la so nguyen to: %d\n", sum);
//	return 0;
//}

/*
2. Viết chương trình cho phép nhập một mảng số nguyên. Sau đó, chương trình phải tính
được mean (trung bình) của mảng trên, và đồng thời đếm được có bao nhiêu phần tử
lớn hơn mean của mảng
*/

//int main() {
//	int n;
//	printf("Nhap so luong phan tu cua mang: ");
//	scanf("%d", &n);
//	int arr[n];
//	printf("Nhap cac phan tu cua mang:\n");
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//	}
//	float aver = mean(arr, n);
//	int higherAver = 0;
//	for (int i = 0; i < n; i++) {
//		if (arr[i] > aver) {
//			higherAver++;
//		}
//	}
//	printf("Trung binh cua mang: %.2f\n", aver);
//	printf("So phan tu lon hon trung binh: %d\n", higherAver);
//}

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