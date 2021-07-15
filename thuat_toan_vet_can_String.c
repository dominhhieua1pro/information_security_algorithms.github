#include <stdio.h>
#include <string.h>
#define MAX 1000

char T[MAX], P[MAX];
int count_char, i, j, len_P, count_string;
void algorithm(){
	len_P = strlen(P) - 1;
	count_string = 0;
    for(i = 0; i < strlen(T); i++) {
        count_char = 0;
        for(j = 0; j < len_P; j++){
            if (T[i + j] == P[j])	count_char++;
        }
        if (count_char == len_P) {
        	count_string++;
            printf("\nString P xuat hien lan thu %d tai vi tri [%d,%d] trong String T", count_string, i, i + len_P - 1);
        }
	}
	if(!count_string) 	printf("\nString P khong nam trong String T\n");
	else 	printf("\n\n-> P xuat hien %d lan trong T\n", count_string);
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
