#include <stdio.h>

unsigned long long a, b;
void gcd() {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    printf("\nUCLN(a,b) = %d", a);
}
int main() {
	printf("Thuat toan tim uoc chung lon nhat!\n");
    printf("\nEnter a, b: ");
    scanf("%lld %lld", &a, &b);
    gcd();
    return 0;
}
