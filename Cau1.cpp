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
void tinhTongTungDong(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		printf("tong dong %d la: %d\n", i, tinhTong1Dong(a, m, n, i));
	}
}
int timPhanTuLonNhatTrenCot(int a[][MAX], int m, int n, int cot)
{
	int max = a[cot][0];
	for (int i = 1; i < m; i++)
	{
		if (max < a[cot][i])
		{
			max = a[cot][i];
		}
	}
	return max;
}
void timPhanTuLonNhatTrenTungCot(int a[][MAX], int m, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Phan tu lon nhat tren cot %d la: %d\n",i,timPhanTuLonNhatTrenCot(a,m,n,i));
	}
}
void xuatCacPhanTuBien(int a[][MAX], int m, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[0][i]);
	}

	for (int i = 1; i < m - 1; i++) {
		printf("%d ", a[i][n - 1]);
	}

	if (m > 1) {
		for (int i = n - 1; i >= 0; i--) {
			printf("%d ", a[m - 1][i]);
		}
	}

	if (n > 1) {
		for (int i = m - 2; i > 0; i--) {
			printf("%d ", a[i][0]);
		}
	}

	printf("\n");
}
int timPhanTuCucDai(int a[][MAX], int m, int n, int i, int j) {
	int value = a[i][j];

	if (i > 0 && value < a[i - 1][j]) return 0;        
	if (i < m - 1 && value < a[i + 1][j]) return 0;
	if (j > 0 && value < a[i][j - 1]) return 0;
	if (j < n - 1 && value < a[i][j + 1]) return 0;

	return 1;
}

void xuatPhanTuCucDai(int a[][MAX], int m, int n) {
	printf("Cac phan tu cuc dai trong mang la:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (timPhanTuCucDai(a, m, n, i, j)) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}
bool dongChiChuaSoChan(int a[][MAX], int m, int n,int dong)
{
	for (int i = 0; i < n; i++)
	{
		if (a[dong][i] % 2 != 0)
		{
			return false;
		}
	}
	return true;
}
void swap(int &a, int &b)
{
	int x = a;
	a = b;
	b = x;
}
void sapXepTangDanTrenDong(int a[][MAX], int m, int n, int dong)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[dong][j] > a[dong][j + 1])
				swap(a[dong][j], a[dong][j + 1]);
		}
	}
}
void sapXepTangDanTrenMang(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		sapXepTangDanTrenDong(a, m, n, i);
	}
}
void showMenu()
{
	printf("\n*******************************************************");
	printf("\n*                        MENU                         *");
	printf("\n*  1.Tao Ma Tran ngau nhien                           *");
	printf("\n*  2.Xem Noi dung ma tran so nguyen                   *");
	printf("\n*  3.Tinh va xuat tong gia tri tung dong              *");
	printf("\n*  4.Xuat phan tu lon nhat tren cot                   *");
	printf("\n*  5.Xuat cac phan tu bien                            *");
	printf("\n*  6.Xuat cac phan tu cuc dai                         *");
	printf("\n*  7.Xuat dong chi chua so chan                       *");
	printf("\n*  8.Xap xep mang tang dan theo tung dong             *");
	printf("\n*  0.Thoat chuong trinh                               *");
}
int main()
{
	int a[MAX][MAX], m, n;
	taoMang2C_SoNguyen(a, m, n);
	xuatMang2C_SoNguyen(a, m, n);
	//printf("tonhg dong la: %d", tinhTong1Dong(a, m, n, 1));
	//tinhTongTungDong(a, m, n);
	//timPhanTuLonNhatTrenTungCot(a, m, n);
	//xuatCacPhanTuBien(a, m, n);
	//xuatPhanTuCucDai(a, m, n);
	/*for (int i = 0; i < m; i++)
	{
		if (dongChiChuaSoChan(a, m, n, i))
			printf("dong %d chi chua so chan\n", i);
		else
			printf("dong %d co so le\n", i);
	}*/
	//sapXepTangDanTrenDong(a, m, n, 1);
	sapXepTangDanTrenMang(a, m, n);
	printf("mang da sap xep: \n");
	xuatMang2C_SoNguyen(a, m, n);
}
