#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000

char P[MAX], T[MAX], T_i;
int i, j, L[MAX], count;
void build_last_occurrence(char P[]){
	for(i = 65; i <= 122; i++){
		L[i] = -1;
	}
	for(j = 0; j < strlen(P); j++){
		L[(int)(P[j])] = j;
	}
}
int min(int a, char T_i){
	return (a < (1 + L[(int)(T_i)])) ? a : 1 + L[(int)(T_i)];
}
void algorithm(){
	build_last_occurrence(P);
	i = strlen(P) - 1; 
	j = strlen(P) - 1; 
	while(i < strlen(T)){
		count = 0;
		while(T[i] == P[j]){
			count++;
			if(count == strlen(P)){
				printf("\nString P: %s bat dau tu vi tri thu %d trong String T: %s", P, i, T);
				exit(0);
			}
			i--;
			j--;
		}
		i = i + strlen(P) - min(j, T[i]);
		j = strlen(P) - 1;
	}
	printf("\nString P: %s khong nam trong String T: %s", P, T);
}
int main(){
	printf("Thuat toan Boyer_Moore - doi sanh mau!\n");
    printf("\nEnter String T: ");
    scanf("%s", &T);
    printf("\nEnter String P: ");
    scanf("%s", &P);
    algorithm();
    return 0;
}
