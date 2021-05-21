#include<stdio.h>

unsigned long long p, a, u, v, x1, x2, r, q, x;

int inverse(){
	u = a % p;
	v = p;
	x1 = 1;
	x2 = 0;
	while( u != 1){
		q = (int)(v / u);
		r = v % u;
		x = x2 - q*x1;
		v = u;
		u = r;
		x2 = x1;
		x1 = x;
	}
	return x1;
}
void display(){
	printf("\nd = %lld", x1);
	printf("\n%lld^-1 = %lld (mod %lld)", a, x1, p);
	printf("\n%lld.%lld = 1 (mod %lld)", a, x1, p);
}
int main(){
	printf("Phep tinh nghich dao a^-1 = d (mod p) hay a.d = 1 (mod p)\n");
	printf("\nEnter p, a: ");
	scanf("%lld %lld", &p, &a);
	inverse();
	display();
	return 0;
}
