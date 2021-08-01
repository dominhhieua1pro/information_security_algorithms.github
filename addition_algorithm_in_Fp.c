#include <stdio.h>
#include <math.h>

int w, m, t, i, e, select;
long long a, b, p, c;
int A[50], B[50], C[50], P[50];

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
	convert_integer_to_array(a, A, w, p);
	convert_integer_to_array(b, B, w, p);
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
long long convert_array_to_integer(int C[])
{
	c = 0;
	for (i = 0; i < t; i++)
	{
		c += C[t - i - 1] * pow(2, (t - i - 1) * w);
	}
	return c;
}
void addition_algorithm()
{
	convert_integer_to_array(p, P, w, p);
	if (e == 1)
	{
		e = 0;
		for (i = 0; i < t; i++)
		{
			C[i] = C[i] - P[i] - e;
			if (C[i] < 0)
			{
				e = 1;
				C[i] = C[i] + pow(2, w);
			}
			else
				e = 0;
		}
	}
	else
	{
		if (convert_array_to_integer(C) >= p)
		{
			e = 0;
			for (i = 0; i < t; i++)
			{
				C[i] = C[i] - P[i] - e;
				if (C[i] < 0)
				{
					e = 1;
					C[i] = C[i] + pow(2, w);
				}
				else
					e = 0;
			}
		}
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
	printf("Addition algorithm in the Fp field!\n");
	printf("\nEnter a, b: ");
	scanf("%lld %lld", &a, &b);
	printf("\nEnter p, w: ");
	scanf("%lld %d", &p, &w);
	multiprecision_addition();
	addition_algorithm();
	display();
	return 0;
}
