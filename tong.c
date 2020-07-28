#include<stdio.h>

/*桶排序  
  这是一个将0到10十一个中的五个数快速排列的方法。
  算法：1.将数字装入桶中。2.将每个桶里的数字打印出来。
  这只是简化版的桶排序。
  
  评价：这是一个挺好的以空间来换取时间的办法。



*/

int main()
{
    int arr[11], t;
    
    // 将每一个桶置0
    for(int i = 0; i < 11; i++)
        arr[i] = 0;
    
    // 把数字装入桶
    for(int i = 0; i < 5; i++){
        scanf("%d", &t);
        arr[t]++;
    }
    
    // 这里是将数据从小到大打印，也可从大到小
    for(int i = 0; i >= 0; i++){   // 从大到小 for(int i = 10; i >= 0; i--){
        for(int j = 0; j < arr[i]; j++)
            printf("%d  ", i);
    }
    return 0;
}
