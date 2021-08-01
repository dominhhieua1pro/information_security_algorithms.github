#include <stdio.h>
#include <math.h>

int w, m, t, i, A[50];
long long a, p;

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
void display()
{
	printf("\nm = %d\nt = %d\n", m, t);
	for (i = t - 1; i >= 0; i--)
	{
		printf("\nA[%d] = %d", i, A[i]);
	}
}
int main()
{
	printf("Algorithm to perform the number a as an array in the Fp field and w bit!\n");
	printf("Enter a, p, w: ");
	scanf("%lld %lld %d", &a, &p, &w);
	convert_integer_to_array(a, A, w, p);
	display();
	return 0;
}
