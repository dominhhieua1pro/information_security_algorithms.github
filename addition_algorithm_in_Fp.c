#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int w, m, t, i, e, select;
unsigned int a, b, p, c;
static int A[50], B[50], C[50], P[50];

void input(int A[]){
    for(i = 0; i < t; i++){
        scanf("%d", &A[t - i - 1]);
    }
}
void convert_integer_to_array(unsigned int a, int A[], int w, unsigned int p){
	m = (int)(log(p) / log(2)) + 1;
	t = (int)(m / w) + 1;
	for(i = 0; i < t ; i++){
		A[t-i-1] = (int) (a / pow(2,(t-i-1)*w));
		a = a - A[t-i-1]*(pow(2,(t-i-1)*w));
	}
}
void multiprecision_addition(){
	e = 0;
	for(i = 0; i < t; i++){
		C[i] = A[i] + B[i] + e;
		if(C[i] >= pow(2,w)){
			e = 1;
			C[i] = C[i] - ((int)(C[i] / pow(2,w)))*pow(2,w);
		}
		else	e = 0;
	}
}
int convert_array_to_integer(int C[]){
	c = 0;
	for(i = 0; i < t ; i++){
		c += C[t-i-1] * pow(2,(t-i-1)*w);
	}
	return c;
}
void addition_algorithm(){
	convert_integer_to_array(p, P, w, p);
	if(e == 1){
		e = 0;
		for(i = 0; i < t; i++){
			C[i] = C[i] - P[i] - e;
			if(C[i] >= pow(2,w)){
				e = 1;
				C[i] = C[i] - ((int)(C[i] / pow(2,w)))*pow(2,w);
			}
			else if(C[i] < 0){
				e = 1;
				C[i] = C[i] - ((int)(C[i] / pow(2,w)) - 1)*pow(2,w);
			}
			else	e = 0;
		}
	}
	else{
		if(convert_array_to_integer(C) >= p){
			e = 0;
			for(i = 0; i < t; i++){
				C[i] = C[i] - P[i] - e;
				if(C[i] >= pow(2,w)){
					e = 1;
					C[i] = C[i] - ((int)(C[i] / pow(2,w)))*pow(2,w);
				}
				else if(C[i] < 0){
					e = 1;
					C[i] = C[i] - ((int)(C[i] / pow(2,w)) - 1)*pow(2,w);
				}
				else	e = 0;
			}
		}
	}
}
void display(){
	printf("\nm = %d\nt = %d\n", m, t);
	for(i = t-1; i >= 0 ; i--){
		printf("\nC[%d] = %d", i, C[i]);
	}
	printf("\n\ne = %d\n", e);
}
int main(){
	while(1){
		system("cls");
		system("color f0");
		printf("Addition algorithm in the Fp field!\n");
		printf("\nChon cach nhap input:\n");
		printf("1. Integer\n");
		printf("2. Array\n");
		printf("Enter selection: ");
		scanf("%d",&select);
		switch(select){
			case 1:
			    system("color f4");
				printf("\nNhap input tu 2 so nguyen a, b\n");
				printf("\nEnter a, b: ");
				scanf("%d %d", &a, &b);
				printf("\nEnter p, w: ");
				scanf("%d %d", &p, &w);
				convert_integer_to_array(a, A, w, p);
				convert_integer_to_array(b, B, w, p);
				multiprecision_addition();
				addition_algorithm();
				system("color f1");
				display();
				printf("\nPress any key to return.");
				getch();
				break;
			case 2:
			    system("color f1");
				printf("\nNhap input tu 2 mang A, B\n");
				printf("\nEnter p, w: ");
				scanf("%d %d", &p, &w);
				m = (int)(log(p) / log(2)) + 1;
				t = (int)(m / w) + 1;
				printf("\nNhap mang A: ");
				input(A);
				printf("\nNhap mang B: ");
				input(B);
				multiprecision_addition();
				addition_algorithm();
				display();
				printf("\nPress any key to return.");
				getch();
				break;
			default:
			    system("color f2");
				printf("Nhap khong hop le!");
				printf("\nPress any key to return.");
				getch();
		}
	}
	return 0;
}
