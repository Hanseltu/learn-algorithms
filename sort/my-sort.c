/*常见的排序算法主要分为两类
 *
 *稳定排序：插冒归基
 *
 *
 *1.比较类非线性时间排序
 *  交换类排序（快速排序和冒泡排序）
 *  插入类排序（简单插入排序和希尔排序）
 *  选择类排序（简单选择排序和堆排序）
 *  归并类排序（二路归并排序和多路归并排序）
 *
 *2.非比较类线性时间排序
 *  计数排序
 *  基数排序
 *  桶排序
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

/*1.交换类排序---冒泡排序*/

void bubble_sort(int* array, int length){
    int temp;
    for(int i = 0; i < length ; i++)
    {
        for(int j = 0; j < length - i; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}


/* 1.交换类排序---快速排序（分治思想）*/

/* 挖坑填数，两边向中间扫描 */
int partion(int* a,int start,int end){
    int i = start,j = end;
    int temp = a[i];
    while(i < j)
    {
        while(i < j && a[j] >= temp)  /* 从右往左扫描，找到第一个小于temp的值，来填充a[i] */
        {
            j--;
        }
        if(i < j)  /* 找到了 */
        {
            a[i++] = a[j];  /* a[j]先给a[i]，i再加1 */
        }

        while(i< j && a[i] < temp)  /* 从左往右扫描，找到第一个大于temp的值，来填充a[j] */
        {
            i++;
        }
        if (i < j)
        {
            a[j++] = a[i];
        }
        /* 扫描完成，此时i==j */
    }
    a[i] = temp;
    return i;
}
void quick_sort(int* a,int left,int right){
    if(left < right)
    {
    int i = partion(a,left,right);
    quick_sort(a,left,i-1);
    quick_sort(a,i+1,right);
    }
}

/* 1.插入类排序---简单插入排序 */
void insert_sort(int* a,int length){
    int i,j,temp;
    for(i = 1;i < length;i++)
    {  /* 从1开始，a[0]的位置默认已经排好 */
        temp = a[i];
        for(j = i; j > 0 && a[j-1] > temp; j--)
        { /* i的下一个比temp要小，则执行，将元素前移，插入到指定位置 */
            a[j] = a[j-1];
        }
        a[j] = temp;
    }
}


/*1.插入类排序---希尔排序
 * 直接插入排序的改进，引入增量step
 */
void shell_sort(int* a,int length){
    int i,j,k;
    int temp,step;
    for (step = length/2; step > 0; step /= 2)
    {
        for(i = 0; i < step; i++)
        {
            for (j = i + step; j < length; j += step)
            {
                if(a[j] < a[j-step])
                {
                    temp = a[j];
                    k = j - step;
                    while (k >= 0 && a[k] > temp)
                    {
                         a[k+step] = a[k];
                         k -= step;
                    }
                    a[k+step] = temp;
                }
            }
        }
    }
}

/*1.选择类排序---简单选择排序
 * 每一轮找到数值最小的下标， 放到相应的位置上
 */
void select_sort(int* a,int length){
    int min_index,temp;
    int i,j;
    for(i = 0;i < length; i++)
    {
        for(j = i + 1,min_index = i;j < length;j++)
        {
            if (a[min_index] > a[j]) /* 找到数值最小的元素下标 */
                min_index = j;
        }
        if (min_index != i) /* 将选择好的元素放在相应的位置上 */
        {
            temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
}

/*
 * 1.选择类排序---堆排序
 * 第一步：将待排数据调整为大根堆或者小根堆
 * 第二步：取出根节点，剩下的数据重新调整为大根堆或者小根堆
 * 第三步：依次取出相应的值，最后即可得到排好的数组
*/

void swap(int* a,int *b){ /* 不引入中间变量交换两个数 */
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

/* 调整当前节点，使其满足大根堆性质 */
void heap_adjust(int *a,int i,int length){
    int lchild = i*2 + 1,rchild = i*2 + 2; /* 数组从0开始索引 */
    int min = i; /* 保存当前节点，左右孩子的最小值 */
    if (lchild < length && a[min] > a[lchild])
    {
        min = lchild;
    }
    if (rchild < length && a[min] > a[rchild])
    {
        min = rchild;
    }
    if (min != i)
    {
        swap(&a[min],&a[i]);
        heap_adjust(a,min,length);
    }
}
/* 保持堆的性质 */
void heapify(int* a,int length){
    int i;
    for (i = length - 1;i >= 0;i--)
    {
        heap_adjust(a,i,length);
    }
}

void heap_sort(int* a,int length){
    for (int i = 0;i < length; i++)
    {
        heapify(a+i,length-i);  /* 调整堆 */
    }
}

/* 1.归并类排序---2-路归并排序*/

int main(){
    int a[] = {10,14,73,25,23,13,27,94,33,39,25,59,94,65,82,45};
   // int b[] = {32,-234,848,34,-1,434,98};
    int len = sizeof(a)/sizeof(int);
    //bubble_sort(a,len);
    //quick_sort(a,0,7);
    //insert_sort(a,len);
    //shell_sort(a,len);
    //select_sort(a,len);
    heap_sort(a,len);
    for(int i = 0; i < len; i++)
    {
        printf(" %d \n",a[i]);
    }
    return 0;
}
