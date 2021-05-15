#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define MAX 1000

int number, delta, i, j, p, start_segment, end_segment, smallest_multiple_of_p;
bool first_segment[MAX];
void Sieve_of_Eratosthenes(int delta){
	// Sang Eratosthenes voi segment dau tien
	for(i = 2; i <= delta + 1; i++){
		first_segment[i] = true;
	}
	p = 2;
    while (p <= (int)(sqrt(delta + 1))){
    	if (first_segment[p]){
            for(i = p*p; i <= delta + 1; i = i + p){
            	first_segment[i] = false;
            }
        p++;
        }
    }
    printf("\n");
	for(i = 2; i <= delta + 1; i++){
		if(first_segment[i]) {
		printf("%d ", i);
		}	
	}
	printf("\t is primes in [%d, %d)\n", 2, delta + 2);
}
void Segmented_Eratosthenes(int number){
	delta = (int)(sqrt(number));	//minh chon delta = phan nguyen cua can(number) 
	Sieve_of_Eratosthenes(delta);
	start_segment = delta + 2;	 // gia tri dau tien cua segment thu 2
	end_segment = start_segment + delta; //segment = [start, end) not [start, end] nha
	bool mark[delta];
	while(start_segment <= number){
		if((end_segment > number)){
			end_segment = number + 1; // when last array is not enough delta elements
		}
		for(i = 0; i < (end_segment - start_segment); i++){	// tuc la mang mark co delta phan tu
			mark[i] = true;
		}
		//duyet p tu 2 den sqrt(max_m) voi max m = end - 1 trong segment [start, end) 
		for(p = 2; p <= sqrt(end_segment - 1); p++){
			if(first_segment[p]){
				smallest_multiple_of_p = (((int)(start_segment / p)) * p);// tim boi nho nhat cua p
				if(smallest_multiple_of_p < start_segment)
					smallest_multiple_of_p = smallest_multiple_of_p + p;
				for(j = smallest_multiple_of_p; j < end_segment; j = j + p){
					mark[j - start_segment] = false;	// dich chuyen ve he quy chieu mark[0,1,...,delta)
				}
			}
		}
		for(i = start_segment; i < end_segment; i++){
			if(mark[i - start_segment]){	// print nhung index chua bi danh dau
				printf("%d ", i);
			}
		}
		printf("\t is primes in [%d, %d)\n", start_segment, end_segment);
		start_segment = start_segment + delta;	//start cua segment tiep theo 
		end_segment = end_segment + delta;		//end cua segment tiep theo
	}	
}
int main(){
	printf("Segmented sieve of Eratosthenes!\n\n");
	printf("Enter a number: ");
	scanf("%d", &number);
	Segmented_Eratosthenes(number);
	return 0;
}
	
