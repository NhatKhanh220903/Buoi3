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
void nhapMang2C_SoNguyen(int a[][MAX], int& m, int& n)
{
	printf("Hay cho biet so dong ma tran: ");
	nhapSoNguyenDuong(m);
	printf("Hay cho biet so cot ma tran: ");
	nhapSoNguyenDuong(n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Phan tu a[%d][%d]= ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}
void taoMang2C_SoNguyen(int a[][MAX], int& m, int& n)
{
	printf("Hay cho biet so dong ma tran: ");
	nhapSoNguyenDuong(m);
	printf("Hay cho biet so cot ma tran: ");
	nhapSoNguyenDuong(n);

	srand((unsigned)time(NULL));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x;
			x = rand() % 199 - 99;
			a[i][j] = x;
		}
	}
}

void xuatMang2C_SoNguyen(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n\n");
	}
}
bool dongChiChuaSoLe(int a[][MAX], int m, int n, int dong)
{
	for (int i = 0; i < n; i++)
	{
		if (a[dong][i] % 2 == 0)
		{
			return false;
		}
	}
	return true;
}
void xuatCacPhanTuBien(int a[][MAX], int m, int n)
{
	int b[MAX*MAX],x=0;
	for (int i = 0; i < n; i++)
	{
		b[x++] = a[0][i];
		//printf("%d ", a[0][i]);
	}

	for (int i = 1; i < m - 1; i++) {
		b[x++] = a[i][n - 1];
		//printf("%d ", a[i][n - 1]);
	}

	if (m > 1) {
		for (int i = n - 1; i >= 0; i--) {
			b[x++] = a[m - 1][i];
			//printf("%d ", a[m - 1][i]);
		}
	}

	if (n > 1) {
		for (int i = m - 2; i > 0; i--) {
			b[x++] = a[i][0];
			//printf("%d ", a[i][0]);
		}
	}
	printf("Cac phan tu tren bien ma tran la: ");
	for (int i = 0; i < x; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	int max = b[0];
	for (int i = 1; i < x; i++)
	{
		if (max < b[i])
			max = b[i];
	}
	printf("Phan tu lon nhat tren bien la: %d", max);
}
bool kiemTraTonTaiChuSo2(int x)
{
	x = abs(x);
	while (x > 0) {
		if (x % 10 == 2) {
			return true;
		}
		x /= 10;
	}
	return false;
}
int demSoPhanTuCoSo2(int a[][100], int m, int n) {
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (kiemTraTonTaiChuSo2(a[i][j])) {
				count++;
			}
		}
	}
	return count;
}
int timPhanTuCucTieu(int a[][MAX], int m, int n, int i, int j) {
	int value = a[i][j];

	if (i > 0 && value > a[i - 1][j]) return 0;
	if (i < m - 1 && value > a[i + 1][j]) return 0;
	if (j > 0 && value > a[i][j - 1]) return 0;
	if (j < n - 1 && value > a[i][j + 1]) return 0;

	return 1;
}

void xuatPhanTuCucTieu(int a[][MAX], int m, int n) {
	printf("Cac phan tu cuc tieu trong mang la:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (timPhanTuCucTieu(a, m, n, i, j)) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}
int main()
{


	int a[MAX][MAX], m, n, luachon;
	taoMang2C_SoNguyen(a, m, n);
	xuatMang2C_SoNguyen(a, m, n);
	//xuatCacPhanTuBien(a, m, n);
	//printf("so phan tu co chua chu so 2: %d", demSoPhanTuCoSo2(a, m, n));
	xuatPhanTuCucTieu(a, m, n);
}