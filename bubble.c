#include<stdio.h>
#define SIZE 5

/*
  冒泡排序
  时间复杂度高，占用空间也就那样
*/

int main()
{
    int arr[SIZE], t;
    // 输入数字，暂时宏定义为5个
    for(int i = 0; i < SIZE; i++){
        scanf("%d", &arr[i]);
    }
    
    // 开始排序
    for(int i = 0; i < SIZE - 1; i++){
        for(int j = 0; j < SIZE - i - 1; j++){  // 这里这个 i 是重点
            if(arr[j] > arr[j + 1]){   // 现在是从小到大  改一下大于小于号就行了   if(arr[j] < arr[j + 1])
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
    
    // 打印
    for(int i = 0; i < SIZE; i++)
        printf("%d   ", arr[i]);
    
    return 0;
}
