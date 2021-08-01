#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int k[50], i, j, t, tmp, so_bit, flag;
double prob, decimal;
long long a, A, number, so_mu, y, s, result_mod, r;

void input()
{
	printf("\nEnter a number: ");
	scanf("%lld", &number);
	while (1)
	{
		printf("\nNhap xac suat p(0 < p < 1): ");
		scanf("%lf", &prob);
		if (prob <= 0 || prob >= 1)
			printf("Nhap khong hop le. Vui long nhap lai!");
		else
			break;
	}
	decimal = log(1 - prob) / log(0.25);
	t = (ceil)(decimal);
	printf("-> t = %d\n", t);
}
void convert_decimal_to_binary(int k[], long long so_mu)
{
	for (so_bit = 0; so_mu > 0; (so_bit)++)
	{
		if (so_mu % 2)
		{
			k[so_bit] = 1;
			so_mu = so_mu / 2;
		}
		else
		{
			k[so_bit] = 0;
			so_mu = so_mu / 2;
		}
	}
}
long long nhan_binh_phuong_co_lap(long long a, long long so_mu, long long number)
{
	result_mod = 1;
	A = a;
	if (so_mu == 0)
		return result_mod;
	else
	{
		convert_decimal_to_binary(k, so_mu);
		if (k[0] == 1)
			result_mod = a;
		for (j = 1; j < so_bit; j++)
		{
			A = A * A % number;
			if (k[j] == 1)
				result_mod = (A * result_mod) % number;
		}
		return result_mod;
	}
}
void split_n(long long *r)
{
	s = 0;
	while (!(*r % 2))
	{
		s++;
		*r = *r / 2;
	}
	printf("\ns = %lld, r = %lld voi %lld = 2^s * r\n", s, *r, number - 1);
}
int algorithm(long long number, int t)
{
	r = number - 1;
	split_n(&r);
	for (i = 1; i <= t; i++)
	{
		a = rand() % (number - 3) + 2;
		y = nhan_binh_phuong_co_lap(a, r, number);
		if (y != 1 && y != number - 1)
		{
			j = 1;
			while (j <= s - 1 && y != number - 1)
			{
				y = y * y % number;
				if (y == 1)
				{
					printf("\n t = %3d\ta = %5lld\ty = %2d (hop so)", i, a, y);
					return 0;
				}
				j++;
			}
			if (y != number - 1)
			{
				printf("\n t = %3d\ta = %5lld\ty = %2d (hop so)", i, a, y);
				return 0;
			}
			printf("\n t = %3d\ta = %5lld\ty = %2d (gia nguyen to)", i, a, y);
		}
		else
			printf("\n t = %3d\ta = %5lld\ty = %2d (gia nguyen to)", i, a, y);
	}
	return 1;
}
void display(long long number, int t)
{
	if (algorithm(number, t))
		printf("\n\n=> %lld la so nguyen to\n", number);
	else
		printf("\n\n=> %lld la hop so\n", number);
}
int main()
{
	printf("Thuat toan Miller - Rabin. Kiem tra tinh nguyen to theo xac suat\n");
	input();
	display(number, t);
	return 0;
}


