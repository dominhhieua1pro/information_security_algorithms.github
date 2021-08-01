#include <stdio.h>
#include <stdlib.h>

long long a, b, d, x, y, r, q, ex_a, ex_b;
long long x2 = 1, x1 = 0, y2 = 0, y_1 = 1;

void input()
{
    while (1)
    {
        printf("\nEnter a, b: ");
        scanf("%lld %lld", &a, &b);
        if (a < 0 || b < 0)
            printf("Nhap khong hop le. Vui long nhap lai a,b >= 0\n");
        else
            break;
    }
}
void algorithm(long long a, long long b)
{
    ex_a = a, ex_b = b;
    if (b == 0)
    {
        d = a;
        x = 1;
        y = 0;
        printf("\n(d, x, y) = (%lld, %lld, %lld) thoa man phuong trinh ax + by = d\n", d, x, y);
        exit(0);
    }
    else
    {
        while (b > 0)
        {
            q = (long long)(a / b);
            r = a % b;
            x = x2 - q * x1;
            y = y2 - q * y_1;
            a = b;
            b = r;
            x2 = x1;
            x1 = x;
            y2 = y_1;
            y_1 = y;
        }
        d = a;
        x = x2;
        y = y2;
        printf("\ngcd(%lld,%lld) = %lld\n", ex_a, ex_b, d);
        printf("(d, x, y) = (%lld, %lld, %lld)\n\n", d, x, y);
        if (d == 1)
        {
            if (x < 0)
                x += ex_b;
            if (y < 0)
                y += ex_a;
            printf("%lld^-1 = %lld (mod %lld)\n", ex_a, x, ex_b);
            printf("%lld^-1 = %lld (mod %lld)\n", ex_b, y, ex_a);
        }
        else
            printf("Khong tim duoc phan tu nghich dao cua %lld (mod %lld) va %lld (mod %lld)\n", ex_a, ex_b, ex_b, ex_a);
    }
}
int main()
{
    printf("Thuat toan Euclide mo rong!\n");
    input();
    algorithm(a,b);
    return 0;
}
