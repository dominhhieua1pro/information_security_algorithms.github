#include <stdio.h>
#include <stdlib.h>

int k[50], i, j, t, so_bit;
long long a, A, number, so_mu, r, result_mod;

void convert_decimal_to_binary(int k[], long long so_mu)
{
	for (so_bit = 0; so_mu > 0; so_bit++)
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
int checking_prime(long long number, int t)
{
	for (i = 1; i <= t; i++)
	{
		a = rand() % (number - 3) + 2;
		r = nhan_binh_phuong_co_lap(a, number - 1, number);
		printf("\n t = %3d\ta = %5lld\tr = %2lld", i, a, r);
		if (r != 1)
			return 0;
	}
	return 1;
}
void display()
{
	if (checking_prime(number, t))
		printf("\n\n-> %lld la so nguyen to\n", number);
	else
		printf("\n\n-> %lld la hop so!\n", number);
}
int main()
{
	printf("Thuat toan Fermat. Kiem tra tinh nguyen to\n");
	printf("\nEnter a number, tham so an toan: ");
	scanf("%lld %d", &number, &t);
	display();
	return 0;
}
