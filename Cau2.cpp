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
void taoMaTranVuong(int a[][MAX], int& n)
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

void xuatMaTranVuong(int a[][MAX], int n)
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
			if (i == j)
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
void cau4(int a[][MAX], int n)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	printf("Phan tu lon nhat tam giac tren DCC la: %d\n", max);
}
void swap(int& a, int& b)
{
	int x = a;
	a = b;
	b = x;
}
void cau5(int a[][MAX], int n, int b[])
{
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[k++] = a[i][j];
		}
	}
	for (int i = 0; i < k - 1; i++) {
		for (int j = 0; j < k - 1 - i; j++) {
			if (b[j] > b[j + 1]) {
				swap(b[j], b[j + 1]);
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", b[i]);
	}
	k = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				a[i][j] = b[k++];
			}
		}
		else {
			for (int j = n - 1; j >= 0; j--) {
				a[i][j] = b[k++];
			}
		}
	}

	printf("Ma tran sau khi xep la: \n");
	xuatMaTranVuong(a, n);
}
void cau6(int a[][MAX], int n, int b[])
{
	for (int i = 0; i < n; i++) {
			b[i] = a[i][i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (b[j] > b[j + 1]) {
				swap(b[j], b[j + 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		a[i][i] = b[i];
	}
	printf("Ma tran sau khi xep la: \n");
	xuatMaTranVuong(a, n);
}
int main()
{
	int a[MAX][MAX], n,b[MAX*MAX];
	taoMaTranVuong(a, n);
	xuatMaTranVuong(a, n);
	//xuatDCC(a, n);
	cau6(a,n,b);
}