#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX 1000

int k[MAX], arr[MAX], i, j, t, tmp, so_bit, K, B, flag1;
long long a, A, so_mu, y, s, result_mod, r, decimal;
bool isPrime[MAX];

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
long long nhan_binh_phuong_co_lap(long long a, long long so_mu, long long decimal)
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
			A = A * A % decimal;
			if (k[j] == 1)
				result_mod = (A * result_mod) % decimal;
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
}
int miller_rabin_algorithm(long long decimal, int t)
{
	r = decimal - 1;
	if (r == 1 || r == 2)
		return 1;
	else if (r == 0 || r == -1 || r == 3)
		return 0;
	split_n(&r);
	for (i = 1; i <= t; i++)
	{
		a = rand() % (decimal - 3) + 2;
		y = nhan_binh_phuong_co_lap(a, r, decimal);
		if (y != 1 && y != decimal - 1)
		{
			j = 1;
			while (j <= s - 1 && y != decimal - 1)
			{
				y = y * y % decimal;
				if (y == 1)
					return 0;
				j++;
			}
			if (y != decimal - 1)
				return 0;
		}
	}
	return 1;
}
void sinh_so_random(int arr[], long long *decimal)
{
	for (i = 0; i < K; i++)
	{
		arr[K - i - 1] = rand() % 2;
	}
	*decimal = 0;
	for (i = 0; i < K; i++)
	{
		*decimal += (arr[i] * pow(2, i));
	}
}
void sangEratosthenes(int B)
{
	for (i = 2; i <= B; i++)
	{
		isPrime[i] = true;
	}
	for (i = 2; i <= sqrt(B); i++)
	{
		if (isPrime[i])
		{
			for (j = i * i; j <= B; j += i)
				isPrime[j] = false;
		}
	}
}
void sinh_so_prime(int K, int B, int t)
{
	sangEratosthenes(B);
	while (true)
	{
		flag1 = 0;
		sinh_so_random(arr, &decimal);
		for (i = 2; i <= B; i++)
		{
			if (isPrime[i])
			{
				if ((decimal % i == 0) && (decimal != i))
				{
					flag1++;
					break;
				}
			}
		}
		if (flag1 == 0)
		{
			if (miller_rabin_algorithm(decimal, t))
			{
				printf("\n-> %lld sinh ngau nhien la so nguyen to.\n", decimal);
				break;
			}
		}
	}
}
int main()
{
	printf("Thuat toan sinh ngau nhien ra mot so nguyen to!\n");
	printf("\nEnter so K-bit, gioi han B, tham so an toan: ");
	scanf("%d %d %d", &K, &B, &t);
	sinh_so_prime(K, B, t);
	return 0;
}
