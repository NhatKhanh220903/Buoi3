#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
void nhapSoNguyenDuong(int& x)
{
	do
	{
		scanf("%d", &x);
		if (x <= 0)
			printf("Nhap lai so nguyen duong!\n");
	} while (x <= 0);
}
void taoMaTranVuong(int a[][MAX],int& n)
{
	do {
		printf("Hay cho biet bac ma tran vuong va lon hon 5: ");
		nhapSoNguyenDuong(n);
	} while (n < 5);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x;
			x = rand() % 199 - 99;
			a[i][j] = x;
		}
	}
}

void xuatMaTranVuong(int a[][MAX],int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n\n");
	}
}
void xuatDCC(int a[][MAX], int n)
{
	printf("Cac phan tu duong cheo chinh la: ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i==j)
				printf("%5d", a[i][j]);
		}
	}
}
void inDCSS(int a[][MAX], int n, int k) {
	if (k > 0) {
		for (int i = 0; i < n - k; i++) {
			printf("%d ", a[i][i + k]);
		}
	}
	else if (k < 0) {
		k = -k;
		for (int i = 0; i < n - k; i++) {
			printf("%d ", a[i + k][i]);
		}
	}
	printf("\n");
}
void cau3(int a[][MAX], int n)
{
	for (int k = 1; k < n; k++) {
		printf("duong cheo tren: ", k);
		inDCSS(a, n, k);

		printf("duong cheo duoi: ", k);
		inDCSS(a, n, -k);
	}
}
int main()
{
	int a[MAX][MAX], n;
	taoMaTranVuong(a, n);
	xuatMaTranVuong(a, n);
	//xuatDCC(a, n);
	
}