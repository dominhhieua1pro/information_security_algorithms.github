#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long a, b, number, d, i, tmp, r;

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void algorithm(long long number)
{
    a = 2, b = 2;
    printf("\nPhan tich %lld voi f(x) = x^2 + 1", number);
    do
    {
        b = (b * b + 1) % number;
        b = (b * b + 1) % number;
        a = (a * a + 1) % number;
        d = gcd(abs(b - a), number);
        printf("\na = %5.lld\tb = %5.lld\td = %5.lld", a, b, d);
        if (d > 1 && d < number)
            printf("\n-> %lld = %lld x %lld\n", number, d, number / d);
        else if (d == number)
        {
            printf("\n-> Phan tich %d that bai.\n", d);
            break;
        }
    }
    while (d == 1);
}
int main()
{
    printf("Pollard's Rho Algorithm tim thua so khong tam thuong!\n\n");
    printf("Enter a composite number: ");
    scanf("%lld", &number);
    algorithm(number);
    return 0;
}
