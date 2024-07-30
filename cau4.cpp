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


void swap(int& a, int& b)
{
	int x = a;
	a = b;
	b = x;
}

void sortArray(int b[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (b[j] > b[j + 1]) {
				swap(b[j], b[j + 1]);
			}
		}
	}
}
void cau1_Tang(int a[][MAX], int n,int b[])
{
	for (int i = 0; i < n; i++) {
		b[i] = a[i][n - 1 - i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (b[j] > b[j + 1]) {
				swap(b[j], b[j + 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		a[i][n - 1 - i] = b[i];
	}
	printf("Ma tran sau khi sap xep la:\n");
	xuatMaTranVuong(a, n);
}
void cau1_Giam(int a[][MAX], int n, int b[])
{
	for (int i = 0; i < n; i++) {
		b[i] = a[i][n - 1 - i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (b[j] < b[j + 1]) {
				swap(b[j], b[j + 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		a[i][n - 1 - i] = b[i];
	}
	printf("Ma tran sau khi sap xep la:\n");
	xuatMaTranVuong(a, n);
}
void sapXepTangDanTrenDong(int a[][MAX],int n, int dong)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[dong][j] > a[dong][j + 1])
				swap(a[dong][j], a[dong][j + 1]);
		}
	}
}
void sapXepGiamDanTrenDong(int a[][MAX],int n, int dong)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[dong][j] < a[dong][j + 1])
				swap(a[dong][j], a[dong][j + 1]);
		}
	}
}
void sapXepTangDanTrenCot(int a[][MAX], int n, int cot)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j][cot] > a[j + 1][cot])
				swap(a[j][cot], a[j + 1][cot]);
		}
	}
}
void sapXepGiamDanTrenCot(int a[][MAX], int n, int cot)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j][cot] < a[j + 1][cot])
				swap(a[j][cot], a[j + 1][cot]);
		}
	}
}
void cau2(int a[][MAX],int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			sapXepGiamDanTrenDong(a,n, i);
		}
		else
			sapXepTangDanTrenDong(a,n, i);
	}
	printf("Ma tran sau khi sap xep la:\n");
	xuatMaTranVuong(a, n);
}
void cau3(int a[][MAX],int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			sapXepTangDanTrenCot(a,n, i);
		}
		else
		{
			sapXepGiamDanTrenCot(a,n, i);
		}
	}
	printf("Ma tran sau khi sap xep la:\n");
	xuatMaTranVuong(a, n);
}
void duongCheoTren(int a[][MAX], int size, int k) {
	int b[MAX];
	int count = 0;

	for (int i = 0; i < size - k; i++) {
		b[count++] = a[i][i + k];
	}

	sortArray(b, count);

	count = 0;
	for (int i = 0; i < size - k; i++) {
		a[i][i + k] = b[count++];
	}
}

void duongCheoDuoi(int a[][MAX], int size, int k) {
	int b[MAX];
	int count = 0;

	for (int i = 0; i < size - k; i++) {
		b[count++] = a[i + k][i];
	}

	sortArray(b, count);

	count = 0;
	for (int i = 0; i < size - k; i++) {
		a[i + k][i] = b[count++];
	}
}
void cau4(int a[][MAX], int n, int b[])
{
	for (int k = 0; k < n; k++) {
		duongCheoTren(a, n, k);
		if (k > 0) {
			duongCheoDuoi(a, n, k);
		}
	}
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
void cau5(int a[][MAX], int n)
{
	int mangChan[MAX * MAX];
	int mangLe[MAX * MAX];
	int demChan = 0, demLe = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 == 0)
			{
				mangChan[demChan++] = a[i][j];
			}
			else
				mangLe[demLe++] = a[i][j];
		}
	}
	int k = 0;
	for (int i = 0; i < n && k < demChan; i++) {
		for (int j = 0; j < n && k < demChan; j++) {
			a[i][j] = mangChan[k++];
		}
	}
	k = 0;
	for (int i = demChan / n; i < n && k < demLe; i++) {
		for (int j = 0; j < n && k < demLe; j++) {
			a[i][j] = mangLe[k++];
		}
	}
	printf("Ma tran sau khi xep la: \n");
	xuatMaTranVuong(a, n);
}

int kiemTraDX(int a[][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != a[j][i]) {
				return 0;
			}
		}
	}
	return 1;
}
int main()
{
	int a[MAX][MAX], n, b[MAX * MAX];
	taoMaTranVuong(a, n);
	xuatMaTranVuong(a, n);
	cau5(a, n);
}