#include<stdio.h>
#include<stdlib.h>

int a, k[100], b, A, i, n, mu_k, t;

void  convert_decimal_to_binary(int k[], int *t, int mu_k ){
	for(*t = 0; mu_k > 0; (*t)++){
		if(mu_k % 2){
			k[*t] = 1;
			mu_k = mu_k / 2;
		}
		else{
			k[*t] = 0;
			mu_k = mu_k / 2;
		}
	}
}
void algorithm(){
	b = 1;
	A = a;
	if(mu_k == 0){
		printf("%d^%d mod %d = %d", a, mu_k, n, b);
		exit(0);
	}
	else {
		convert_decimal_to_binary(k, &t, mu_k);
		if(k[0] == 1)	b = a;	
		for(i = 1; i < t; i++){
			A = A*A % n;
			if(k[i] == 1)	b = (A*b) % n;
		}
		printf("\n%d^%d mod %d = %d", a, mu_k, n, b);
	}
}
int main(){
	printf("Thuat toan nhan binh phuong co lap, tinh gia tri a^k mod n\n");
	printf("\nEnter a, k, n: ");
	scanf("%d%d%d", &a, &mu_k, &n);
	algorithm();
	return 0;
}
