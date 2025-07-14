/*
1. Viết chương trình nhập vào 3 số nguyên dương là độ dài của 3 cạnh. Chương trình cho
biết đó có phải là 3 cạnh của một tam giác hay không? Nếu có, cho biết đó là tam giác
gì (thường, cân, vuông, đều, cân vuông).
*/
//#include <stdio.h>
//int main() {
//	int a, b, c;
//	printf("Nhap 3 canh cua tam giac: ");
//	scanf_s("%d %d %d", &a, &b, &c);
//	// Kiểm tra điều kiện tam giác
//	if (a + b > c && a + c > b && b + c > a) {
//		printf("Day la 3 canh cua mot tam giac.\n");
//		// Kiểm tra loại tam giác
//		if (a == b && b == c) {
//			printf("Tam giac deu.\n");
//		}
//		else if (a == b || b == c || a == c) {
//			printf("Tam giac can.\n");
//		}
//		else if (a * a + b * b == c * c ||
//			a * a + c * c == b * b ||
//			b * b + c * c == a * a) {
//			printf("Tam giac vuong.\n");
//		}
//		else {
//			printf("Tam giac thuong.\n");
//		}
//	}
//	else {
//		printf("Day khong phai la 3 canh cua mot tam giac.\n");
//	}
//	return 0;
//}

/*
2. Viết chương trình nhập vào tháng và năm. Chương trình cho biết tháng đó có bao nhiêu
ngày.
*/

//#include <stdio.h>
//int main() {
//	int month, year;
//	printf("Nhap thang (1-12): ");
//	scanf_s("%d", &month);
//	if (month < 1 || month > 12) {
//		printf("Thang khong hop le.\n");
//		return 0;
//	}
//	printf("Nhap nam: ");
//	scanf_s("%d", &year);
//	
//	int days;
//	switch (month) {
//	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
//		days = 31;
//		break;
//	case 4: case 6: case 9: case 11:
//		days = 30;
//		break;
//	case 2:
//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
//			days = 29; // Năm nhuận
//		}
//		else {
//			days = 28; // Năm không nhuận
//		}
//		break;
//	default:
//		days = -1; // Không hợp lệ
//	}
//	if (days != -1) {
//		printf("Thang %d nam %d co %d ngay.\n", month, year, days);
//	}
//	else {
//		printf("Thang khong hop le.\n");
//	}
//	return 0;
//}

/*
3. Viết chương trình cho giám đốc bán hàng của Đại lý xe cũ Henry. Chương trình sẽ xác
định lợi nhuận cho bất kỳ chiếc xe nào được bán. Đầu vào bao gồm giá bán và giá mua
thực tế của một chiếc ô tô. Đầu ra là lợi nhuận, tức là giá bán trừ đi giá mua. Chỉnh
sửa cho phép chương trình có thể chạy liên tục cho số lượng xe bất kỳ và chỉ kết thúc
khi giá bán là 0.
*/

//#include <stdio.h>
//int main() {
//	float sellingPrice, buyingPrice, profit;
//	while (1) {
//		printf("Nhap gia ban cua xe (Nhap 0 de ket thuc): ");
//		scanf_s("%f", &sellingPrice);
//
//		if (sellingPrice == 0) {
//			break; // Kết thúc chương trình khi giá bán là 0
//		}
//		printf("Nhap gia mua cua xe: ");
//		scanf_s("%f", &buyingPrice);
//		profit = sellingPrice - buyingPrice;
//		printf("Loi nhuan tu viec ban xe la: %.2f\n", profit);
//	}
//	printf("Chuong trinh ket thuc.\n");
//	return 0;
//}

/*
4. Viết chương trình cho Công ty Xây dựng River Falls Homes. Thiết kế một chương
trình nhắc người dùng nhập số lô đất nền trong phân khu River Falls và dữ liệu về ngôi
nhà sẽ được xây ở đó, bao gồm số phòng ngủ, số phòng tắm và số lượng ô tô trong
gara. Đầu ra là giá của ngôi nhà, với giá cơ bản là 50.000 USD cộng với 17.000 USD
cho mỗi phòng ngủ, 12.500 USD cho mỗi phòng tắm và 6.000 USD cho mỗi chiếc ô
tô trong gara. Chương trình chấp nhận số lô đất nền liên tục cho đến khi nhập số 0.

*/

//#include <stdio.h>
//int main() {
//	int lotNumber, bedrooms, bathrooms, garages;
//	int basePrice = 50000, pricePerBedroom = 17000, pricePerBathroom = 12500, pricePerGarage = 6000;
//	while (1) {
//		printf("Nhap so lo dat nen (Nhap 0 de ket thuc): ");
//		scanf_s("%d", &lotNumber);
//		if (lotNumber == 0) {
//			break; // Kết thúc chương trình khi số lô đất nền là 0
//		}
//		printf("Nhap so phong ngu: ");
//		scanf_s("%d", &bedrooms);
//		printf("Nhap so phong tam: ");
//		scanf_s("%d", &bathrooms);
//		printf("Nhap so xe trong gara: ");
//		scanf_s("%d", &garages);
//		int totalPrice = basePrice + (bedrooms * pricePerBedroom) + (bathrooms * pricePerBathroom) + (garages * pricePerGarage);
//		printf("Gia cua ngoi nha tren lo dat nen %d la: %d USD\n", lotNumber, totalPrice);
//	}
//	printf("Chuong trinh ket thuc.\n");
//	return 0;
//}

/*
5. Viết chương trình nhập vào số nguyên, chương trình kết thúc khi người dùng nhập số
0. Xuất ra số nhỏ nhất (khác 0) và số lớn nhất (khác 0) trong các số đã nhập vào.
*/

//#include <stdio.h>
//int main() {
//	int number, min = 0, max = 0;
//	while (1) {
//		printf("Nhap mot so nguyen (Nhap 0 de ket thuc): ");
//		scanf_s("%d", &number);
//
//		if (number == 0) {
//			break; // Kết thúc chương trình khi người dùng nhập 0
//		}
//
//		// Xử lý số nhỏ nhất
//		if (min == 0 || number < min) {
//			min = number;
//		}
//
//		// Xử lý số lớn nhất
//		if (max == 0 || number > max) {
//			max = number;
//		}
//	}
//
//	if (min != 0 || max != 0) {
//		printf("So nho nhat da nhap: %d\n", min);
//		printf("So lon nhat da nhap: %d\n", max);
//	}
//	else {
//		printf("Khong co so nao duoc nhap.\n");
//	}
//
//	return 0;
//}

/*
6. Viết chương trình nhập vào một số nguyên dương. Chương trình xuất ra số lượng chữ
số và tổng các chữ số của số đã nhập.
*/

//#include <stdio.h>
//int main() {
//	int number, digitCount = 0, digitSum = 0;
//
//	printf("Nhap mot so nguyen duong: ");
//	scanf_s("%d", &number);
//
//	if (number <= 0) {
//		printf("So nhap vao phai la mot so nguyen duong.\n");
//		return 1; // Kết thúc chương trình nếu số không hợp lệ
//	}
//
//	while (number > 0) {
//		digitSum += number % 10; // Lấy chữ số cuối cùng và cộng vào tổng
//		digitCount = digitCount + 1; // Tăng số lượng chữ số
//		number = number / 10; // Loại bỏ chữ số cuối cùng
//	}
//
//	printf("So luong chu so: %d\n", digitCount);
//	printf("Tong cac chu so: %d\n", digitSum);
//
//	return 0;
//}

/*
7. Viết chương trình nhập vào một một số nguyên dương, chương trình xuất ra số đảo
ngược của số đã nhập. Ví dụ, nhập vào số 12345, xuất ra số 54321.
*/

//#include <stdio.h>
//int main() {
//	int number, reversedNumber = 0;
//	printf("Nhap mot so nguyen duong: ");
//	scanf_s("%d", &number);
//	if (number <= 0) {
//		printf("So nhap vao phai la mot so nguyen duong.\n");
//		return 1; // Kết thúc chương trình nếu số không hợp lệ
//	}
//	while (number > 0) {
//		reversedNumber = reversedNumber * 10 + (number % 10); // Lấy chữ số cuối cùng và thêm vào số đảo ngược
//		number = number / 10; // Loại bỏ chữ số cuối cùng
//	}
//	printf("So dao nguoc: %d\n", reversedNumber);
//	return 0;
//}

/*
8. Viết chương trình chuyển số thập phân sang nhị phân.
 vd 11 -> 1011
 step 1: 11 mod 2 = 1 -> 1 & 11 / 2 = [5]
 step : 5 mod 2 = 1 -> 11 & 5 / 2 = [2]
 step 3: 2 mod 2 = 0 -> 011 & 2 / 2 = [1]
 step 4: 1 mod 2 = 1 -> 1011 & 1 / 2 = [0]
 step 5: 0  --> stop then print 1011
*/

//#include <stdio.h>
//int main() {
//	int decimalNumber, binaryNumber[32], i = 0;
//	printf("Nhap mot so thap phan: ");
//	scanf_s("%d", &decimalNumber);
//	if (decimalNumber < 0) {
//		printf("So nhap vao phai la mot so nguyen duong.\n");
//		return 1; // Kết thúc chương trình nếu số không hợp lệ
//	}
//	// Chuyển đổi từ thập phân sang nhị phân
//	while (decimalNumber > 0) {
//		binaryNumber[i] = decimalNumber % 2; // Lấy phần dư
//		decimalNumber = decimalNumber / 2; // Chia cho 2
//		i++;
//	}
//	printf("So nhi phan: ");
//	for (int j = i - 1; j >= 0; j--) { // In ra theo thứ tự ngược lại
//		printf("%d", binaryNumber[j]);
//	}
//	printf("\n");
//	return 0;
//}

/*
9. Viết chương trình biểu diễn một số nguyên cho trước dưới dạng tích của các số nguyên
tố. Ví dụ, nhập vào n = 120, xuất ra n = 2 * 2 * 2 *3 * 5.
*/

//#include <stdio.h>
//void primeFactorization(int n) {
//	if (n <= 1) {
//		printf("Khong co phan tich thua so nguyen to cho so %d.\n", n);
//		return;
//	}
//
//	printf("Phan tich thua so nguyen to cua %d: ", n);
//	for (int i = 2; i * i <= n; i++) {
//		while (n % i == 0) {
//			printf("%d ", i);
//			n /= i;
//		}
//	}
//	if (n > 1) {
//		printf("%d", n); // In ra số nguyên tố cuối cùng nếu còn
//	}
//	printf("\n");
//}
//int main() {
//	int number;
//	printf("Nhap mot so nguyen duong: ");
//	scanf_s("%d", &number);
//	primeFactorization(number);
//	return 0;
//}

/*
10. Viết chương trình nhập vào số nguyên dương n và xuất ra giá trị của tổng S = 1 + 1*2
+ 1*2*3 + … + 1*2*…*n.
*/

//#include <stdio.h>
//int main() {
//	int n;
//	long long sum = 0, factorial = 1;
//	printf("Nhap mot so nguyen duong n: ");
//	scanf_s("%d", &n);
//	if (n < 1) {
//		printf("So nhap vao phai la mot so nguyen duong.\n");
//		return 1; // Kết thúc chương trình nếu số không hợp lệ
//	}
//	for (int i = 1; i <= n; i++) {
//		factorial *= i; // Tính giai thừa của i
//		sum += factorial; // Cộng vào tổng
//	}
//	printf("Tong S = 1 + 1*2 + 1*2*3 + ... + 1*2*...*%d = %lld\n", n, sum);
//	return 0;
//}

/*
11. Viết chương trình nhập vào số nguyên dương n (n ≥ 10). Chương trình cho biết n là số
nguyên dương có các chữ số tăng dần, giảm dần hoặc không. Ví dụ, nhập vào 1223,
xuất ra “Số nguyên dương có các chữ số tăng dần”.
vd: 1243
step 1 (before while): n = 1243, prevDigit = 3
step 2 (while): n = 124, currentDigit = 4, prevDigit = 3 -> isIncreasing = 1, isDecreasing = 0
step 3 (while): n = 12, currentDigit = 2, prevDigit = 4 -> isIncreasing = 0, isDecreasing = 0
step 4 (while): n = 1, currentDigit = 1, prevDigit = 2 -> isIncreasing = 0, isDecreasing = 0

*/

#include <stdio.h>
int main() {
	int n, prevDigit, currentDigit;
	int isIncreasing = 1, isDecreasing = 1;
	printf("Nhap mot so nguyen duong n (n >= 10): ");
	scanf_s("%d", &n);
	if (n < 10) {
		printf("So nhap vao phai la mot so nguyen duong lon hon hoac bang 10.\n");
		return 1; // Kết thúc chương trình nếu số không hợp lệ
	}
	prevDigit = n % 10; // Lấy chữ số cuối cùng
	n /= 10; // Loại bỏ chữ số cuối cùng
	while (n > 0) {
		currentDigit = n % 10; // Lấy chữ số tiếp theo
		n /= 10; // Loại bỏ chữ số này
		if (currentDigit < prevDigit) {
			isIncreasing = 0; // Nếu chữ số hiện tại nhỏ hơn chữ số trước đó, không phải tăng dần
		}
		if (currentDigit > prevDigit) {
			isDecreasing = 0; // Nếu chữ số hiện tại lớn hơn chữ số trước đó, không phải giảm dần
		}
		prevDigit = currentDigit; // Cập nhật chữ số trước đó
	}
	if (isIncreasing) {
		printf("So nguyen duong co cac chu so tang dan.\n");
	}
	else if (isDecreasing) {
		printf("So nguyen duong co cac chu so giam dan.\n");
	}
	else {
		printf("So nguyen duong khong co cac chu so tang dan hoac giam dan.\n");
	}
	return 0;
}