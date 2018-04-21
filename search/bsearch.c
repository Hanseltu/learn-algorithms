#include<stdio.h>

/*
 *二分查找算法
 *
 *查找成功返回数组下标，查找失败返回-1
 *
 */
int binary_search(int* a,int length,int target){
    int low = 0;
    int high = length - 1;
    int mid;

    while (low < high)
    {
        mid = (low + high) / 2;
        if (a[mid] < target)
            low = mid + 1;
        if (a[mid] > target)
            return high = mid - 1;
        if (a[mid] == target)
            return mid;
    }
    return -1;
}

int main(){
    int a[] = {1,2,3,4,5,6,7,8};
    int len = sizeof(a)/sizeof(int);
    int result = binary_search(a,len,6);
    printf("The result is %d \n",result);
    return 0;
}
