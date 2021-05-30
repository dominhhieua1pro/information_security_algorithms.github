#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000

char P[MAX], T[MAX], T_i;
int i, j, L[MAX], count, len_P;
void build_last_occurrence(char P[]){
	for(i = 0; i <= 122; i++){
		L[i] = -1;
	}
	for(j = 0; j < len_P; j++){
		L[(int)(P[j])] = j;
	}
}
int min(int a, char T_i){
	return (a < (1 + L[(int)(T_i)])) ? a : 1 + L[(int)(T_i)];
}
void algorithm(){
    len_P = strlen(P) - 1;
	build_last_occurrence(P);
	i = j = len_P - 1;
	while(i < strlen(T)){
		count = 0;
		while(T[i] == P[j]){
			count++;
			if(count == len_P){
				printf("\nString P bat dau tu vi tri thu %d trong String T\n", i);
				exit(0);
			}
			i--;
			j--;
		}
		i = i + len_P - min(j, T[i]);
		j = len_P - 1;
	}
	printf("\nString P khong nam trong String T\n");
}
int main(){
	printf("Thuat toan Boyer_Moore - doi sanh mau!\n");
    printf("\nEnter String T: ");
    fgets(T, sizeof(T), stdin); // ham fgets ket thuc boi '\n'
    printf("\nEnter String P: ");
    fgets(P, sizeof(P), stdin);
    algorithm();
    return 0;
}

