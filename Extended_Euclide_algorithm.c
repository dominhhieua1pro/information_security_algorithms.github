#include<stdio.h>
#include <stdlib.h>

int main(){
	printf("Thuat toan Euclide mo rong!\n");
	int a, b, d, x, y, r, q;
	int x2 = 1, x1 = 0, y2 = 0, y1 = 1;
	do{
		printf("\nEnter a, b: ");
		scanf("%d %d", &a, &b);
		if(a < 0 || b < 0)
			printf("Co loi xay ra. Vui long nhap lai (a, b >= 0)");
	}while(a < 0 || b < 0);

	if(b == 0){
		d = a;
		x = 1;
		y = 0;
		printf("\n(d, x, y) = (%d, %d, %d) thoa man phuong trinh ax + by = d", d , x, y);
		exit(0);
	}
	else {
		while(b > 0){
			q = (int) (a / b);
			r = a % b;
			x = x2 - q*x1;
			y = y2 - q*y1;
			a = b;
			b = r; 
			x2 = x1;
			x1 = x;
			y2 = y1;
			y1 = y;
		}
	d = a;
	x = x2;
	y = y2;
	printf("\n(d, x, y) = (%d, %d, %d) thoa man phuong trinh ax + by = d", d , x, y);
	}
	return 0;
}
			
		
