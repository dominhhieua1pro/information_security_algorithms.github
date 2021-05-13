#include<stdio.h>

int p, a, u, v, x1, x2, r, q, x;

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
	printf("\nd = %d", x1);
	printf("\n%d^-1 = %d (mod %d)", a, x1, p);
	printf("\n%d.%d = 1 (mod %d)", a, x1, p);
}
int main(){
	printf("Phep tinh nghich dao a^-1 = d (mod p) hay a.d = 1 (mod p)\n");
	printf("\nEnter p, a: ");
	scanf("%d %d", &p, &a);
	inverse();
	display();
	return 0;
}
