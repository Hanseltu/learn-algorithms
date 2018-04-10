#include<stdio.h>
#include<string.h>

#define MAX_LEN 20

int PI[MAX_LEN];

void Compute_prefix_fun(char P[]){
    int m,k,q;
    m = strlen(P);
    PI[0] = 0;
    k = 0;
    for (q = 1; q < m; q++)
    {
        while (k > 0 && P[k] != P[q])
        {
            k = PI[k];
        }
        if (P[k] == P[q])
        {
            k = k + 1;
        }
        PI[q] = k;
    }
}

void KMP_matcher(char T[],char P[]){
    int n,m,q,i;
    n = strlen(T);
    m = strlen(P);
    Compute_prefix_fun(P);
    q = 0;
    for (i = 0; i < n; i++)
    {
        while ((q > 0) && P[q] != T[i])
        {
            q = PI[q-1];
        }
        if (P[q] == T[i])
        {
            q = q + 1;
        }
        if (q == m)
        {
            printf ("%d \n",i-m+1);
            q = PI[q-1];
        }
    }
}
int main(){
    char T[] = "abcaabccsfs";
    char P[] = "aabc";
    //scanf("%s",T);
    //scanf("%s",P);
    KMP_matcher(T,P);
    return 0;
}
