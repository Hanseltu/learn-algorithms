#include<stdio.h>
#include<string.h>
int native_string_matcher(const char* T,const char* P){
    int n = strlen(T);
    int m = strlen(P);
    int s = 0, i = 0;
    for (s = 0;s < n - m + 1;s++) /* 文本串从0至n-m偏移，以匹配模式串 */
    {
        for (i = 0;i < m;i++) /* 模式串从0-m开始分别匹配模式串中字符是否与原串相等 */
        {
            if (P[i] != T[s+i])  /* 如果不相等，则从s的下一位重新匹配 */
            {
                break;
            }
            if (i == m -1)
            {
                printf("Matched!");
                return s;
            }
        }
    }
    return 0;
}

int main (){
   const char* P = "llo";
   const char* T = "hello";
    printf("%d\n",native_string_matcher(T,P));
    return 0;
}
