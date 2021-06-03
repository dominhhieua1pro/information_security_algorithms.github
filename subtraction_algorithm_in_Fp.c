#include<stdio.h>
#include<math.h>

int w, m, t, i, e, select;
unsigned int a, b , p, c;
static int A[50], B[50], C[50], P[50];

void convert_integer_to_array(unsigned int a, int A[], int w, unsigned int p){
	m = (int)(log(p) / log(2)) + 1;
	if(m % w != 0)    t = (int)(m / w) + 1;
	else    t = (int)(m / w);
	for(i = 0; i < t ; i++){
		A[t-i-1] = (int) (a / pow(2,(t-i-1)*w));
		a = a - A[t-i-1]*(pow(2,(t-i-1)*w));
	}
}
void multiprecision_subtraction(){
    convert_integer_to_array(a, A, w, p);
    convert_integer_to_array(b, B, w, p);
	e = 0;
	for(i = 0; i < t; i++){
		C[i] = A[i] - B[i] - e;
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
void subtraction_algorithm(){
	convert_integer_to_array(p, P, w, p);
	if(e == 1){
		e = 0;
		for(i = 0; i < t; i++){
			C[i] = C[i] + P[i] + e;
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
void display(){
	printf("\nm = %d\nt = %d\n", m, t);
	for(i = t-1; i >= 0 ; i--){
		printf("\nC[%d] = %d", i, C[i]);
	}
	printf("\n\ne = %d\n", e);
}
int main(){
    printf("Subtraction algorithm in the Fp field!\n");
    printf("\nEnter a, b: ");
    scanf("%d %d", &a, &b);
    printf("\nEnter p, w: ");
    scanf("%d %d", &p, &w);
    multiprecision_subtraction();
    subtraction_algorithm();
    display();
    return 0;
}
