#include <stdio.h>

long long a, b, r;

void gcd(long long a, long long b)
{
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    printf("\nUCLN(a,b) = %lld", a);
}
int main()
{
    printf("Thuat toan tim uoc chung lon nhat!\n");
    printf("\nEnter a, b: ");
    scanf("%lld %lld", &a, &b);
    gcd(a, b);
    return 0;
}
