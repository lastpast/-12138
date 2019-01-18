#include<stdio.h>
#define SIZE 5

/*
   快速排序，时间复杂度比起冒泡低了许多，占用空间不多，常用。
   原理：每一次都是将最左边的数字放到他应该的位置，通过两个哨兵，左边的哨兵把比最左边数大的数找到，右边的哨兵把比其小的数找到，然后交换，直到两个哨兵
   相遇，此时哨兵的位置就是最左边那个数应该的位置，之后递归下去。
*/

void quicksort(int , int );

int a[SIZE];

int main()
{
    // 读取数组
    for(int i = 0; i < SIZE; i++)
        scanf("%d", &a[i]);
    
    // 通过这个函数递归来排序
    quicksort(0, SIZE - 1);
    
    // 打印出来
    for(int i = 0; i < SIZEn; i++)
        printf("%d  ", a[i]);
    
    return 0;
}

void quicksort(int left, int right)
{
    int i, j, temp, t;
    
    if(left > right)
        return;
    
    // 将最左边的数给temp
    temp = a[left];
    i = left;
    j = right;
    
    while(i != j){
        // 右边的哨兵检查是否有比temp小的数
        while(a[j] >= temp && j > i)
            j--;
        // 左边的哨兵检查是否有比temp大的数
        while(a[i] <= temp && i < j)
            i++;
        
        // 交换这两个数
        if(i < j){
            t = a[j];
            a[j] = a[i];
            a[i] = t;
        }
    }
    
    // 将最左边合适的位置与第一个交换
    a[left] = a[i];
    a[i] = temp;
    
    // 递归排序两个部分
    quicksort(left, i - 1);
    quicksort(i + 1, right);
    return;
}
