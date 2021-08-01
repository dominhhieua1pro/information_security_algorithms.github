#include <stdio.h>

long long p, a, u, v, x1, x2, r, q, x;
// handling exception neu de bai cho snt p va a thuoc [1,p-1]
long long inverse(long long a, long long p)
{
	u = a;
	v = p;
	x1 = 1;
	x2 = 0;
	while (u != 1)
	{
		q = (long long)(v / u);
		r = v % u;
		x = x2 - q * x1;
		v = u;
		u = r;
		x2 = x1;
		x1 = x;
	}
	if (x1 < 0)
		return x1 + p;
	else
		return x1;
}
void display()
{
	printf("\n%lld^-1 = %lld (mod %lld)", a, inverse(a, p), p);
}
int main()
{
	printf("Phep tinh nghich dao a^-1 (mod p)\n");
	printf("\nEnter a, p: ");
	scanf("%lld %lld", &a, &p);
	display();
	return 0;
}
