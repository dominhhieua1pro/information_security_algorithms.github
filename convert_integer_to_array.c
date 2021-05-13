#include<stdio.h>
#include<math.h>

int w, m, t, i;
unsigned int a, p;
static int A[50];

void convert_integer_to_array(unsigned int a, int A[], int w, unsigned int p){
	m = (int)(log(p) / log(2)) + 1;
	t = (int)(m / w) + 1;
	for(i = 0; i < t ; i++){
		A[t-i-1] = (int)(a / pow(2,(t-i-1)*w));
		a = a - A[t-i-1]*(pow(2,(t-i-1)*w));
	}
}
void display(){
	printf("\nm = %d\nt = %d\n", m, t);
	for(i = t-1; i >= 0 ; i--){
		printf("\nA[%d] = %d", i, A[i]);
	}
}
int main(){
	printf("Thuat toan perform number a to array in Fp field and w bit!\n");
	printf("Enter a, p, w: ");
	scanf("%d %d %d", &a, &p, &w);
	convert_integer_to_array(a, A, w, p);
	display();
	return 0;
}
