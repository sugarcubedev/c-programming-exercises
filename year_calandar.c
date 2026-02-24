#include <stdio.h>

int is_leap(int year);

int main(void) {
	int year;
	printf("년도를 입력하세요 : ");
	scanf_s("%d", &year);

	int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (is_leap(year)) mdays[1] = 29;

	int dow = 1;									//이전처럼 하면 예시로 규칙발견하기로 하면 예외 생기니까 하지마.
	for (int h = 1900; h < year; h++) {				//이전처럼 하면 100의 배수가 빠지고 400배수가 들어가야할 때를 못 셈.
		if (is_leap(h))
			dow = (dow + 366) % 7;
		else
			dow = (dow + 365) % 7;
	}
	

	for (int k = 1; k <= 12; k++) {
		int count = 0;										//밑에 count = 0;을 해도, count =6으로 끝났더라면 if를 안 지나기에 여기에 count 6인 상태로 올라옴
		printf("================%d월=============\n", k);
		printf("   일   월   화   수   목   금   토\n");

		for (int j = 0; j < dow; j++) {
			printf("     ");			
			count++;
		}

		for (int i = 1; i <= mdays[k-1]; i++) {
			printf("%5d", i);
			count++;
			if (count == 7) {
				printf("\n");
				count = 0;						// 여기다 비교연산자 == 를 써서 틀림
			}
		}
		if (count != 0) {
			printf("\n");
		}
		dow = (dow + mdays[k - 1]) % 7;
	}

	return 0;
}



int is_leap(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return 1;
	}
	return 0;
}