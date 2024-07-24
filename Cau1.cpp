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
	printf("Hay cho biet so dong ma tran");
	nhapSoNguyenDuong(m);
	printf("Hay cho biet so cot ma tran");
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
int tinhTong1Dong(int a[][MAX],int m, int n,int dong)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += a[dong][i];
	}
	return tong;
}
int main()
{
	int a[MAX][MAX], m, n;
	taoMang2C_SoNguyen(a, m, n);
	xuatMang2C_SoNguyen(a, m, n);
	printf("tonhg dong la: %d", tinhTong1Dong(a, m, n, 1));

}
