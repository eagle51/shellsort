#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
#define RANDOM(i) (rand()%i)
#define N          250000

void shellsort(int a[], int len)
{
	int step, i, j, temp;
	for (step = len / 2;step > 0;step /= 2) {
		for (i = step;i < len;++i) {
			temp = a[i];
			for (j = i;j >= step && temp < a[j - step];j -= step)
				a[j] = a[j - step];
			a[j] = temp;
		}
	}
}

//���������и�ΪHibbard�����1,3,7��...��2^k
void shellsort2(int a[], int len)
{
	int i, j, k, temp, dk, t;
	t = (int)(log(len + 1) / log(2));
	for (k = 1;k <= t;++k) {
		dk = (int)(pow(2, t - k + 1) - 1);
		for (i = dk;i < len;++i) {
			temp = a[i];
			for (j = i - dk;(j >= i%dk) && a[j] > temp;j -= dk)//�Ƚ����¼����ͬʱ����
				a[j + dk] = a[j];
			if (j != i - dk)
				a[j + dk] = temp;//����
		}
	}
}
int main(void)
{
	int rand_no = 0;
	int a[N];               //n��ʾ���鳤��

	printf("==============================����ǰ=========================================");
	printf("\n");
	for (rand_no = 0;rand_no < N;rand_no++){

		a[rand_no] = RANDOM(32767);
		printf("%ld ", a[rand_no]);
		if (rand_no % 15 == 0)
			printf("\n");

	}
	printf("\n");
	printf("==============================�����=========================================\n");
	shellsort(a, N);
	for (long j = 0; j < N; j++){
		printf("%ld ", a[j]);
		if (j % 15 == 0)
			printf("\n");
	}
	printf("\n");
	system("pause");
	return 0;
}