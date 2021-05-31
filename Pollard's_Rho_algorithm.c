#include <stdio.h>
#include <stdlib.h>
#include<math.h>

unsigned long long a = 2, b = 2, number, d, i;
int gcd(unsigned long long a, unsigned long long b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void algorithm(){
	i = 1;
	printf("\nf(x) = x^2 + %I64u\n", i);
	do {
        b = (b * b + i) % number;
        b = (b * b + i) % number;
        a = (a * a + i) % number;
        d = gcd(abs(b - a), number);
        printf("a = %7.I64u\tb = %7.I64u\td = %4.I64u\n", a, b, d);
        if(d > 1 && d < number)
        	printf("\n%I64u = %I64u x %I64u", number, d, number/d);
        else if (d == number){
        	i++;
        	printf("\nKet thuc that bai. Thay f(x) = x^2 + %I64u\n", i);
        }
    } while (d == 1 || d == number);
}
int main() {
	printf("Pollard's Rho Algorithm tim thua so khong tam thuong!\n\n");
    printf("Enter a composite number: ");
    scanf("%I64u", &number);
    algorithm();
    printf("\n");
    return 0;
}
