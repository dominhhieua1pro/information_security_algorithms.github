#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX 1000000

int number, delta, i, j, p, number_of_segments;
bool isPrime[MAX];

void Sieve_first_segment(int delta)
{
	for (i = 2; i <= number; i++)
	{
		isPrime[i] = true;
	}
	for (i = 2; i <= sqrt(delta + 1); i++)
	{
		if (isPrime[i])
		{
			for (j = i * i; j <= delta + 1; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}
void Segmented_Eratosthenes(int number)
{
	delta = (int)(sqrt(number));
	Sieve_first_segment(delta);
	number_of_segments = (ceil)((double)(number-1) / (double)delta);
	for (i = 1; i < number_of_segments; i++)
	{
		for (j = (i * delta) + 2; j <= ((i + 1) * delta) + 1 && j <= number; j++)
		{
			for (p = 2; p <= sqrt(((i + 1) * delta) + 1); p++)
			{
				if (isPrime[p] == true)
				{
					if (j % p == 0 && j != p)
					{
						isPrime[j] = false;
						break;
					}
				}
			}
		}
	}
}
void display()
{
	for (i = 0; i < number_of_segments; i++)
	{
		for (j = (i * delta) + 2; j <= ((i + 1) * delta) + 1 && j <= number; j++)
		{
			if (isPrime[j])
				printf("%d ", j);
		}
		printf("\t\tare prime numbers in [%d, %d]\n", (i * delta) + 2, ((i + 1) * delta + 1 < number) ? (i + 1) * delta + 1 : number);
	}
}
int main()
{
	printf("Segmented sieve of Eratosthenes!\n\n");
	printf("Enter a number: ");
	scanf("%d", &number);
	Segmented_Eratosthenes(number);
	display();
	return 0;
}
