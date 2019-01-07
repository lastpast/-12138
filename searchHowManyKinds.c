#include<stdio.h>
#define SIZE 6

/*
  这是比较一个6个数字的数组中有多少种数的代码
  原理：两个两个比较，如果相同则将最后一个替换第二个字串，同时总个数减一。
*/

int main()
{
    int a[SIZE], num;
    num = SIZE;
    
    // 输入
    for(int i = 0; i < SIZE; i++)
        scanf("%d", &a[i]);
    
    // 开始找
    for(int i = 0; i < num; i++){
        for(int j = i + 1; j < num; j++){
            while(a[i] == a[j] && j < num){  // 这个j < num比较关键，因为num的信息来不及更新，所以在这里要来判断一下
                a[j] = a[num - 1];
                num--;
            }
        }
    }
    
    // 打印几种
    printf("\n%d", num);
    
    return 0;
}
