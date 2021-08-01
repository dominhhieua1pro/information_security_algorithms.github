#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

int w, m, t, i, e, select;
long long a, b, p;
int A[50], B[50], C[50];

void input(int A[])
{
	for (i = 0; i < t; i++)
	{
		scanf("%d", &A[t - i - 1]);
	}
}
void convert_integer_to_array(long long a, int A[], int w, long long p)
{
	m = (ceil)(log(p) / log(2));
	t = (ceil)((double)m / (double)w);
	for (i = 0; i < t; i++)
	{
		A[t - i - 1] = (int)(a / pow(2, (t - i - 1) * w));
		a = a - A[t - i - 1] * (pow(2, (t - i - 1) * w));
	}
}
void multiprecision_addition()
{
	e = 0;
	for (i = 0; i < t; i++)
	{
		C[i] = A[i] + B[i] + e;
		if (C[i] >= pow(2, w))
		{
			e = 1;
			C[i] = C[i] - pow(2, w);
		}
		else
			e = 0;
	}
}
void display()
{
	printf("\nm = %d\nt = %d\n", m, t);
	for (i = t - 1; i >= 0; i--)
	{
		printf("\nC[%d] = %d", i, C[i]);
	}
	printf("\n\ne = %d", e);
}
int main()
{
	while (1)
	{
		system("cls"); //stdlib.h
		printf("Multiprecision addition algorithm!\n");
		printf("\nChon cach nhap input:\n");
		printf("1. Integer\n");
		printf("2. Array\n");
		printf("Enter selection: ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("\nNhap input tu 2 so nguyen a, b\n");
			printf("\nEnter a, b: ");
			scanf("%lld %lld", &a, &b);
			printf("\nEnter p, w: ");
			scanf("%lld %d", &p, &w);
			convert_integer_to_array(a, A, w, p);
			convert_integer_to_array(b, B, w, p);
			multiprecision_addition();
			display();
			printf("\nPress any key to continue...");
			getch(); //conio.h
			break;
		case 2:
			printf("\nNhap input tu 2 mang A, B\n");
			printf("\nEnter p, w: ");
			scanf("%lld %d", &p, &w);
			m = (ceil)(log(p) / log(2));
			t = (ceil)((double)m / (double)w);
			printf("\nNhap mang A: ");
			input(A);
			printf("\nNhap mang B: ");
			input(B);
			multiprecision_addition();
			display();
			printf("\nPress any key to continue...");
			getch();
			break;
		default:
			printf("Nhap khong hop le!");
			printf("\nPress any key to continue...");
			getch();
		}
	}
	return 0;
}

