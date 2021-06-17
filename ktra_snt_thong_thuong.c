#include<stdio.h>
#include<math.h>
int i, j, n, number;
int checkPrime(int n){
    for(i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}
void display(int number){
    for(j = 2; j <= number; j++){
        if(checkPrime(j))
            printf("%d ", j);
    }
}
int main(){
    printf("\nEnter a number: ");
    scanf("%d", &number);
    display(number);
    return 0;
}
