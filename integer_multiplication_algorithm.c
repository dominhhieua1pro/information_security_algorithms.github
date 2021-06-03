#include<stdio.h>
#include<math.h>

int w, m, t, i, j, z, e, len_binary, u, v, r, select;
unsigned int a, b, p;
static int A[50], B[50], C[50], k[50];

void convert_integer_to_array(unsigned int a, int A[], int w, unsigned int p){
	m = (int)(log(p) / log(2)) + 1;
	if(m % w != 0)    t = (int)(m / w) + 1;
	else    t = (int)(m / w);
	for(i = 0; i < t ; i++){
		A[t-i-1] = (int) (a / pow(2,(t-i-1)*w));
		a = a - A[t-i-1]*(pow(2,(t-i-1)*w));
	}
}
void convert_decimal_to_binary(int decimal){
	int x = decimal;
	for(r = 0; r < 2*w; r++){
		k[r] = 0;
	}
	for(len_binary = 0; x > 0; len_binary++){
		if(x % 2){
			k[len_binary] = 1;
			x = x / 2;
		}
		else{
			k[len_binary] = 0;
			x = x / 2;
		}
	}
}
void integer_multiplication(){
    convert_integer_to_array(a, A, w, p);
    convert_integer_to_array(b, B, w, p);
	for(i = 0; i < t; i++){
		C[i] = 0;
	}
	for(i = 0; i < t; i++){
		u = 0;
		for(j = 0; j < t; j++){
			convert_decimal_to_binary(C[i+j] + A[i]*B[j] + u);// = (u.v) in binary
			//convert u, v to decimal
			v = 0;
			for(z = 0; z < w; z++){
				v += k[z] * pow(2,z);
			}
			u = 0;
			for(z = w; z < 2*w; z++){
				u += k[z] * pow(2,z-w);
			}
			C[i+j] = v;
		}
		C[i + t] = u;
	}
}
void display(){
	printf("\nm = %d\nt = %d\n", m, t);
	for(i = 2*t-1; i >= 0 ; i--){
		printf("\nC[%d] = %d", i, C[i]);
	}
}
int main(){
    printf("Integer multiplication algorithm!\n");
    printf("\nEnter a, b: ");
    scanf("%d %d", &a, &b);
    printf("\nEnter p, w: ");
    scanf("%d %d", &p, &w);
    integer_multiplication();
    display();
    return 0;
}
