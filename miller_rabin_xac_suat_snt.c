#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int k[50], i, j, t, tmp, so_bit, flag;
double prob, decimal;
long long a, A, number, so_mu, y, s, result_mod, r;

void input(){
    while(1){
        printf("\nEnter a number: ");
        scanf("%I64d", &number);
        if(number < 0)
            printf("Nhap khong hop le. Vui long nhap lai!");
        else    break;
	}
	while(1){
        printf("\nNhap xac suat p(0 < p < 1): ");
        scanf("%lf", &prob);
        if(prob <= 0 || prob >= 1)
            printf("Nhap khong hop le. Vui long nhap lai!");
        else    break;
	}
	decimal = log(1 - prob) / log(0.25);
	if(decimal != (int)(decimal))    t = (int)(decimal) + 1;
	else    t = (int)(decimal);
	printf("-> t = %d\n", t);
}
void  convert_decimal_to_binary(int k[], int *so_bit, long long so_mu ){
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
int nhan_binh_phuong_co_lap(long long a, long long so_mu, long long number){
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
void split_n(long long *r){
	s = 0;
	while(!(*r % 2)){
		s++;
		*r = *r / 2;
	}
	printf("\ns = %I64d, r = %I64d voi %I64d = 2^s * r", s, *r, number - 1);
}
int algorithm(long long number, int t){
	flag = 0;
	r = number - 1;
	if(r == 1 || r == 2) 	return 1;
	else if(r == 3 || r == -1 || r == 0)	  return 0;
	split_n(&r);
	for(i = 1; i <= t; i++){
		while(1){
			a = rand();
			if(a >= 2 && a <= number-2)
			 	break;
		}
		printf("\n\nt = %d\ta = %I64d", i, a);
		y = nhan_binh_phuong_co_lap(a, r, number);
		if(y != 1 && y != number - 1){
			j = 1;
			while(j <= s - 1 && y != number - 1){
				y = y*y % number;
                printf("\n\tj = %d\ty = %d", j, y);
				if(y == 1)	 return 0;
				j++;
			}
			if(y != number - 1)	return 0;
		}
	}
	return 1;
}
void display(long long number, int t){
	if(algorithm(number, t))	printf("\n\n=> %I64d la so nguyen to\n", number);
	else	printf("\n\n=> %I64d la hop so\n", number);
}
int main(){
	printf("Thuat toan Miller - Rabin. Kiem tra tinh nguyen to cua so nguyen le theo xac suat\n");
    input();
	display(number, t);
	return 0;
}
