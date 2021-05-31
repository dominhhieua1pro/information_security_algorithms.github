#include<stdio.h>

int k[50], i, j, t, tmp, so_bit, flag;
unsigned long long a, A, number, so_mu, y, s, result_mod, r;
void  convert_decimal_to_binary(int k[], int *so_bit, unsigned long long so_mu ){
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
int nhan_binh_phuong_co_lap(unsigned long long a, unsigned long long so_mu, unsigned long long number){
	result_mod = 1;
	A = a;
	if(so_mu == 0)	return y;
	else {
		convert_decimal_to_binary(k, &so_bit, so_mu);
		if(k[0] == 1)	result_mod = a;
		for(j = 1; j < so_bit; j++){
			A = A*A % number;
			if(k[j] == 1)	result_mod = (A * result_mod) % number;
		}
		return result_mod;
	}
}
void split_n(unsigned long long *r){
	s = 0;
	while(!(*r % 2)){
		s++;
		*r = *r / 2;
	}
	printf("\ns = %I64u, r = %I64u voi %I64u = 2^s * r\n", s, *r, number - 1);
}
int algorithm(unsigned long long number){
	flag = 0;
	r = number - 1;
	if(r == 1 || r == 2) 	return 1;
	else if(r == 3 || r == -1 || r == 0)	  return 0;
	split_n(&r);
	for(i = 1; i <= t; i++){
		tmp = 1;
		while(tmp > 0){
			a = rand();
			if(a >= 2 && a <= number - 2)
			 	tmp = 0;
		}
		printf("\nt = %d\ta = %I64u", i, a);
		y = nhan_binh_phuong_co_lap(a, r, number);
		if(y != 1 && y != number - 1){
			j = 1;
			while(j <= s - 1 && y != number - 1){
				y = y*y % number;
				if(y == 1)	 return 0;
				j++;
			}
			if(y != number - 1 && y != 1)	return 0;
		}
	}
	return 1;
}
void display(){
	if(algorithm(number))	printf("\n\n%I64u la so nguyen to\n", number);
	else	printf("\n%I64u la hop so\n", number);
}
int main(){
	printf("Thuat toan Miller - Rabin. Kiem tra tinh nguyen to cua so nguyen le number\n");
	printf("\nEnter a odd integer, tham so an toan: ");
	scanf("%I64u %d", &number, &t);
	display();
	return 0;
}
