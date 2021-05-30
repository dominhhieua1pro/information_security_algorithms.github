#include <stdio.h>
#include <string.h>
#define MAX 1000

char T[MAX], P[MAX];
int count, i, j, flag, len_P;
int algorithm(){
	len_P = strlen(P) - 1;
	flag = 0;
    for(i = 0; i < strlen(T); i++) {
        count = 0;
        for(j = 0; j < len_P; j++){
            if (T[i + j] == P[j])	count++;
        }
        if (count == len_P) {
            printf("\nString P bat dau tu vi tri thu %d trong String T", i);
            flag++;
        }
	}
	if(!flag) 	printf("\nString P khong nam trong String T");
}
int main(){
	printf("Thuat toan vet can - doi sanh mau!\n");
    printf("\nEnter String T: ");
    fgets(T, sizeof(T), stdin);
    printf("\nEnter String P: ");
    fgets(P, sizeof(P), stdin);
    algorithm();
    return 0;
}
