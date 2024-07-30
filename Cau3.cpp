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
void swap(int& a, int& b)
{
	int x = a;
	a = b;
	b = x;
}
void sapXepTangDanTrenDong(int a[][MAX], int m, int n, int dong)
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
void sapXepGiamDanTrenDong(int a[][MAX], int m, int n, int dong)
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
void sapXepTangDanTrenCot(int a[][MAX], int m, int n, int cot)
{
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < m - i - 1; j++)
		{
			if (a[j][cot] > a[j+1][cot])
				swap(a[j][cot],a[j + 1][cot]);
		}
	}
}
void sapXepGiamDanTrenCot(int a[][MAX], int m, int n, int cot)
{
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < m - i - 1; j++)
		{
			if (a[j][cot] < a[j + 1][cot])
				swap(a[j][cot], a[j + 1][cot]);
		}
	}
}

void cau5(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		if (i % 2 == 0)
		{
			sapXepGiamDanTrenDong(a, m, n, i);
		}
		else
			sapXepTangDanTrenDong(a, m, n, i);
	}
}
void cau6(int a[][MAX], int m, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			sapXepTangDanTrenCot(a, m, n, i);
		}
		else
		{
			sapXepGiamDanTrenCot(a, m, n, i);
		}
	}
}
bool kiemTraDongGiamDan(int a[][MAX], int m, int n,int dong) {
	for (int j = 0; j < n - 1; j++) {
		if (a[dong][j] < a[dong][j + 1]) {
			return false;
		}
	}
	return true;
}


bool kiemTraCotGiamDan(int a[][MAX], int n, int m,int cot) {
	for (int i = 0; i <  - 1; i++) {
		if (a[i][cot] < a[i + 1][cot]) {
			return false;
		}
	}
	return true;
}

bool cau7(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		if (!kiemTraDongGiamDan(a,m,n,i)) {
			return false;
		}
	}
	for (int j = 0; j < n; j++) {
		if (!kiemTraCotGiamDan(a,m,n,j)) {
			return false;
		}
	}
	return true;
}
bool dongChiChuaSoChan(int a[][MAX], int m, int n, int dong)
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
		
void cau8(int a[][MAX], int m, int n)
{
	printf("dong chi chua so chan la: ");
	for (int i = 0; i < m; i++)
	{
		if (dongChiChuaSoChan(a, m, n, i))
			printf("%d ", i);
	}
}

void cau9(int a[][MAX], int m, int n)
{
	printf("dong chi chua cac gia tri giam dan la: ");
	for (int i = 0; i < m; i++)
	{
		if (kiemTraDongGiamDan(a, m, n, i))
			printf("%d ", i);
	}
}

int timMax(int a[][MAX], int m, int n)
{
	int max = a[0][0];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max < a[i][j])
				max = a[i][j];
		}
	}
	return max;
}
int timMin(int a[][MAX], int m, int n)
{
	int min = a[0][0];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (min > a[i][j])
				min = a[i][j];
		}
	}
	return min;
}

void cau10(int a[][MAX], int m, int n)
{
	int max = timMax(a,m,n);
	int min = timMin(a, m, n);
	int range = max - min + 1;
	int frequency[10000];
	for (int i = 0; i < range; i++)
	{
		frequency[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			frequency[a[i][j]-min]++;
		}
	}
	for (int i = 0; i < range; i++)
	{
		if (frequency[i]>0)
			printf("%d xuat hien %d lan\n", i+min, frequency[i]);
	}
	int maxFrequency = 0;
	for (int i = 0; i < range; i++)
	{
		if (frequency[i] > maxFrequency)
			maxFrequency = frequency[i];
	}
	printf("Cac gia tri xuat hien nhieu nhat la:\n");
	for (int i = 0; i < range; i++) {
		if (frequency[i] == maxFrequency) {
			printf("%d xu?t hi?n %d l?n\n", i + min, maxFrequency);
		}
	}
}
int main()
{


	int a[MAX][MAX], m, n, luachon;
	taoMang2C_SoNguyen(a, m, n);
	xuatMang2C_SoNguyen(a, m, n);
	//xuatCacPhanTuBien(a, m, n);
	//printf("so phan tu co chua chu so 2: %d", demSoPhanTuCoSo2(a, m, n));
	//xuatPhanTuCucTieu(a, m, n);
	//cau6(a, m, n);
	//printf("**************************\n");
	//if(cau7(a,m,n))
		//printf("ma tran giam dan");
	//else
		//printf("ma tran khong giam dan");
	cau10(a, m, n);
}