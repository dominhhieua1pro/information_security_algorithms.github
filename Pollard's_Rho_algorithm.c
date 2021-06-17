#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long a, b, number, d, i, tmp, r;
int checkPrime(int n){
    for(i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}
long long gcd(long long a, long long b) {
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void algorithm(long long number){
	i = 1, a = 2, b = 2;
	printf("\nPhan tich %I64d voi f(x) = x^2 + %I64d\n", number, i);
	do {
        b = (b * b + i) % number;
        b = (b * b + i) % number;
        a = (a * a + i) % number;
        d = gcd(abs(b - a), number);
        printf("a = %5.I64d\tb = %5.I64d\td = %3.I64d\n", a, b, d);
        if(d > 1 && d < number){
            if(!checkPrime(d) && !checkPrime(number/d)){
                tmp = number / d;
                printf("-> %I64d = %I64d x %I64d\n", number, d, number/d);
                algorithm(d);
                algorithm(tmp);
            }
            else if(!checkPrime(d)){
                printf("-> %I64d = %I64d x %I64d\n", number, d, number/d);
                algorithm(d);
            }
            else if(!checkPrime(number/d)){
                printf("-> %I64d = %I64d x %I64d\n", number, d, number/d);
                algorithm(number/d);
            }
            else
                printf("-> %I64d = %I64d x %I64d\n", number, d, number/d);
        }
        else if (d == number){
        	i++;
        	printf("Ket thuc that bai. Thay f(x) = x^2 + %I64d\n", i);
        	a = 2, b = 2;
        }
    } while (d == 1 || d == number);
}
int main() {
	printf("Pollard's Rho Algorithm tim thua so khong tam thuong!\n\n");
    printf("Enter a composite number: ");
    scanf("%I64d", &number);
    algorithm(number);
    return 0;
}
