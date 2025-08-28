#include <stdio.h>

void inMang(int luotXemVideo[], int soVideo) {
	for (int i = 0; i < soVideo; i++) {
		printf("%d ", luotXemVideo[i]);
	}
}

void nhapSoLuotXem(int luotXemVideo[], int soVideo) {
	for (int i = 0; i < soVideo; i++) {
		printf("video  %d: ", i + 1);
		scanf("%d", &luotXemVideo[i]);
	}
}

int timSoLuotViewCaoNhat(int luotXemVideo[], int soVideo) {
	int max = 0;
	for (int i = 1; i < soVideo; i++) {
		if (luotXemVideo[i] > luotXemVideo[max]) {
			max = i;
		}
	}
	return max;
}


double tinhLuotXemTrungBinh(int luotXemVideo[], int soVideo) {
	double sum = 0;
	for (int i = 0; i < soVideo; i++) {
		sum += luotXemVideo[i];
	}
	return (double) sum / soVideo;
}


int main() {
	int soVideo = 7;

	int luotXemVideo[soVideo];
	printf("\nSo luot xem:\n");

	nhapSoLuotXem(luotXemVideo, soVideo);
	inMang(luotXemVideo, soVideo);

	int videoViewCaoNhat = timSoLuotViewCaoNhat(luotXemVideo, soVideo);
	printf("\nVideo co view cao nhat la %d: %d", videoViewCaoNhat + 1, luotXemVideo[videoViewCaoNhat]);

	double viewTrungBinh = tinhLuotXemTrungBinh(luotXemVideo, soVideo);
	printf("\nSo luot view  trung binh: %.2f", viewTrungBinh);


	printf("\nVideo co luot view lon hon trung binh: ");
	for (int i = 0; i < soVideo; i++) {
		if ((double) luotXemVideo[i] > viewTrungBinh) {
			printf("\nvideo %d: %d ", i+1,luotXemVideo[i]);
			
		}
	}
	return 0;
}

/*
input: 100 100 300 400 200 500 50
output:

So luot xem:
video  1: video  2: video  3: video  4: video  5: video  6: video  7: 100 100 300 400 200 500 50
Video co view cao nhat la 6: 500
So luot view  trung binh: 235.71
Video co luot view lon hon trung binh:
video 3: 300
video 4: 400
video 6: 500
*/