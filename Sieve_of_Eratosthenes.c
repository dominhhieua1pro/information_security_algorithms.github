#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define MAX 1000000

void sangEratosthenes(int number){
	bool isPrime[MAX];
	int i,j;
//	isPrime[0] = false;
//	isPrime[1] = false;
	for(i = 2; i <= number; i++){
		isPrime[i] = true;
		}
	for(i = 2; i <= sqrt(number) ; i++){
		if(isPrime[i]){
			for(j = i*i ; j <= number; j += i){
				isPrime[j] = false;
				}
			}
		}
	for(i = 2; i <= number; i++){
		if(isPrime[i]) printf("%d ", i);
		}
}
int main(){
	int number;
	printf("Sieve of Eratosthenes!\n\n");
	printf("Enter a number: ");
	scanf("%d", &number);
	sangEratosthenes(number);
	return 0;
}
	
