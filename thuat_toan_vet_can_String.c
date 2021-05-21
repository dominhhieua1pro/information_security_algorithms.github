#include <stdio.h>
#include <string.h>
#define MAX 1000

char T[MAX], P[MAX];
int count, i, j, flag;
int algorithm(){
	flag = 0;
    for(i = 0; i < strlen(T); i++) {
        count = 0;
        for(j = 0; j < strlen(P); j++){
            if (T[i + j] == P[j])	count++;
        }
        if (count == (strlen(P))) {
            printf("\nString P: %s bat dau tu vi tri thu %d trong String T: %s", P, i, T);
            flag++;
        }
	}
	if(!flag) 	printf("\nString P: %s khong nam trong String T: %s", P, T);
}
int main(){
	printf("Thuat toan vet can - doi sanh mau!\n");
    printf("\nEnter String T: ");
    scanf("%s", &T);
    printf("\nEnter String P: ");
    scanf("%s", &P);
    algorithm();
    return 0;
}
