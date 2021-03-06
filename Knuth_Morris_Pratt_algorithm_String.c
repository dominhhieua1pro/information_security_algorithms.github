#include <stdio.h>
#include <string.h>
#define MAX 1000

char T[MAX], P[MAX];
int count_char, count_string, i, j, flag, tmp, k, len_F, find_substring, len_P, len_T, F[MAX] = {-1, 0};

void failure_function(char P[])
{
    for (j = 2; j < len_P; j++)
    {
        flag = 0;
        for (find_substring = j - 2; find_substring >= 0; find_substring--)
        {
            tmp = find_substring;
            len_F = 0;
            k = j - 1;
            while (P[tmp] == P[k])
            {
                len_F++;
                if (tmp == 0)
                {
                    F[j] = len_F;
                    flag = 1;
                    break;
                }
                else
                {
                    tmp--;
                    k--;
                }
            }
            if (flag)
                break;
        }
        if (!flag)
            F[j] = 0;
    }
    printf("\nFailure function table: \n J\t");
    for (i = 0; i < len_P; i++)
        printf("%3d ", i);
    printf("\n F(J)\t");
    for (i = 0; i < len_P; i++)
        printf("%3d ", F[i]);
}
void algorithm(char T[], char P[])
{
    len_T = strlen(T) - 1;
    len_P = strlen(P) - 1;
    failure_function(P);
    i = j = 0;
    count_string = 0;
    while (i < len_T)
    {
        count_char = 0;
        while (T[i + j] == P[j])
        {
            count_char++;
            if (count_char == len_P)
            {
                count_string++;
                printf("\n\nString P xuat hien lan thu %d tai vi tri [%d,%d] trong String T", count_string, i, i + len_P - 1);
            }
            j++;
        }
        i = i + j - F[j];
        if (F[j] == -1)
            j = 0;
        else
            j = F[j];
    }
    if (!count_string)
        printf("\n\n-> Khong tim thay String P trong String T\n");

    else
        printf("\n\n-> P xuat hien %d lan trong T\n", count_string);
}
int main()
{
    printf("Thuat toan Knuth_Morris_Pratt - doi sanh mau!\n");
    printf("\nEnter String T: ");
    fgets(T, sizeof(T), stdin);
    printf("\nEnter String P: ");
    fgets(P, sizeof(P), stdin);
    algorithm(T, P);
    return 0;
}
