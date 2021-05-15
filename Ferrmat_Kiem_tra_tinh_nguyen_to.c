#include<stdio.h>
#include<stdlib.h>

int a, k[50], result_mod, A, i, j, number, so_mu, t, tmp, r, so_bit;

void  convert_decimal_to_binary(int k[], int *so_bit, int so_mu ){
	for(*so_bit = 0; so_mu > 0; (*so_bit)++){
		if(so_mu % 2){
			k[*so_bit] = 1;
			so_mu = so_mu / 2;
		}
		else{
			k[*so_bit] = 0;
			so_mu = so_mu / 2;
		}
	}
}
int nhan_binh_phuong_co_lap(int a, int so_mu, int number){
	result_mod = 1;
	A = a;
	if(so_mu == 0)	return result_mod;
	else {
		convert_decimal_to_binary(k, &so_bit, so_mu);
		if(k[0] == 1)	result_mod = a;	
		for(j = 1; j < so_bit; j++){
			A = A*A % number;
			if(k[j] == 1)	result_mod = (A*result_mod) % number;
		}
		return result_mod;
	}
}
void checking_prime(){
	for(i = 1; i <= t; i++){
		tmp = 1;
		while(tmp > 0){
			a = rand();
			if(a >= 2 && a <= number-2)
			 	tmp = 0;	
		}
		r = nhan_binh_phuong_co_lap(a, number-1, number);
		if(r != 1){
			printf("\n%d la hop so!", number);
			break;
		}
		else	printf("\n%d la nguyen to voi co so %d", number, a);
	}
}
int main(){
	printf("Thuat toan Fermat. Kiem tra tinh nguyen to cua so nguyen le number\n");
	printf("\nEnter a number, tham so an toan: ");
	scanf("%d %d", &number, &t);
	checking_prime();
	return 0;
}
