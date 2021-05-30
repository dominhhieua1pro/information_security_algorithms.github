#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define MAX 1000

char T[MAX], P[MAX];
int count, i, j, flag, tmp, k, len_F, find_string, len_P, F[MAX] = {-1,0};
void failure_function(char P[]){
	for(j = 2; j < len_P; j++){
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
	len_P = strlen(P) - 1;
	failure_function(P);
	flag = 0;
	i = j = 0;
    count = 0;
    while(i < (strlen(T) - len_P + 1)){
        if(T[i + j] == P[j]){
			count++;
			if (count == (len_P)) {
            	printf("\nString P bat dau tu vi tri thu %d trong String T", i);
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
    printf("\nString P khong nam trong String T");
}
int main(){
	printf("Thuat toan Knuth_Morris_Pratt - doi sanh mau!\n");
	printf("\nEnter String T: ");
    fgets(T, sizeof(T), stdin); 
    printf("\nEnter String P: ");
   	fgets(P, sizeof(P), stdin);
    algorithm();
    return 0;
}
