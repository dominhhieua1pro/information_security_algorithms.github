#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000

char P[MAX], T[MAX], T_i;
int i, j, L[MAX], count_char, len_P, count_string;
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
	count_string = 0;
	while(i < strlen(T)){
		count_char = 0;
		while(T[i] == P[j]){
			count_char++;
			if(count_char == len_P){
				count_string++;
				printf("\nString P xuat hien lan thu %d tai vi tri [%d,%d] trong String T", count_string, i, i + len_P - 1);
			}
			i--;
			j--;
		}
		i = i + len_P - min(j, T[i]);
		j = len_P - 1;
	}
	if(!count_string) 	printf("\nString P khong nam trong String T");
	else 	printf("\n\n-> P xuat hien %d lan trong T\n", count_string);
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

