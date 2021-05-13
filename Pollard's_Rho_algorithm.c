#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int gcd(unsigned long long a, unsigned long long b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
	printf("Pollard's Rho Algorithm tim thua so khong tam thuong!\n\n");
    unsigned long long a = 2, b = 2, number, factor;
    printf("Enter a number: ");
    scanf("%lld", &number);
    printf("\n");
    do {
        b = (b * b + 1) % number;
        b = (b * b + 1) % number;
        a = (a * a + 1) % number;
        factor = gcd(abs(b - a), number);
        printf("a = %7lld\tb = %7lld\tfactor = %4lld\n", a, b, factor);
    } while (factor == 1);
    printf("\nfactor is %lld\n", factor);
    return number / factor;
}
