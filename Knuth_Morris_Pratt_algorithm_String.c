#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define MAX 1000

char T[MAX], P[MAX];
int count, i, j, flag, F[MAX], tmp, k, len_F, find_string;
void failure_function(char P[]){
	F[0] = -1;
	F[1] = 0;
	for(j = 2; j < strlen(P); j++){
		flag = 0;
		for(find_string = j - 2; find_string >= 0; find_string--){
			tmp = find_string;
        	len_F = 0;
        	k = j - 1;
        	while(P[tmp] == P[k]){
            	len_F++;
            	if(tmp == 0){
            		F[j] = len_F;
            		flag = 1;
            		break;
            	}
           		else{
            		tmp--;
            		k--;
            	}
        	}
			if(flag)	break;
		}
    	if(!flag){
       		F[j] = 0;
    	}	
	}
}
void algorithm(){
	failure_function(P);
	flag = 0;
	i = 0, j = 0;
    count = 0;
    while(i < (strlen(T) - strlen(P) + 1)){
        if(T[i + j] == P[j]){
			count++;
			if (count == (strlen(P))) {
            	printf("\nString P: %s bat dau tu vi tri thu %d trong String T: %s", P, i, T);
            	exit(0);
            }
            j++;
        }
        else{
            i = i + j - F[j];
            if(F[j] == -1)	  j = 0;
            else 	j = F[j];
            count = 0;
        }
    }
    printf("\nString P: %s khong nam trong String T: %s", P, T);
}
int main(){
	printf("Thuat toan Knuth_Morris_Pratt - doi sanh mau!\n");
	printf("\nEnter String T: ");
    scanf("%s", &T);
    printf("\nEnter String P: ");
    scanf("%s", &P);
    algorithm();
    return 0;
}
