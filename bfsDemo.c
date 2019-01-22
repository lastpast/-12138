#include<stdio.h>
#define N 5
#define M 4

/**
  这是迷宫问题的另一种解法，也就是广度优先搜索。方法就是利用队列的思想，遍历完一个迷宫之后，就出列。
*/

struct note{
    int x;    // 坐标和步数
    int y;
    int step;
};

int book[10][10];   // 用来标记是否走过, 放在这里只是懒得赋0

int main()
{
    struct note que[100];   // 定义100个节点，也就是最多的地图也就是10*10
    int startX, startY, endX, endY;
    int map[10][10]= {{0,0,1,0},{0,0,0,0},{0,0,1,0},{0,1,0,0,},{0,0,0,1}};   // 这是存放地图的数组
    int head, tail, tempX, tempY;    // 队列的头、尾、临时的X和Y
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};  // 方位数组
    int flag = 0;  // 用来判断是否结束循环
    
    // 输入地图
/*    printf("enter the map\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            scanf("%d", &map[i][j]);
    }*/
    
    printf("enter the start and the end\n");
    scanf("%d%d%d%d", &startX, &startY, &endX, &endY);
    
    // 做好入列的准备和将起点入列
    head = 0;
    tail = 0;
    que[tail].x = startX;
    que[tail].y = startY;
    que[tail].step = 0;
    book[startX][startY] = 1;
    tail++;
    
    // 开始广度优先搜索
    while(head < tail)
    {
        // 四个方位遍历
        for(int i = 0; i < 4; i++){
            tempX = que[head].x + next[i][0];
            tempY = que[head].y + next[i][1];
            
            // 如果出界了，则视为无效格子，则继续
            if(tempX < 0 || tempX >= N || tempY < 0 || tempY >= M)
                continue;
            
            // 没有出界格子有效，并且没走过
            if(map[tempX][tempY] == 0 && book[tempX][tempY] == 0){
                // 入列
                que[tail].x = tempX;
                que[tail].y = tempY;
                que[tail].step = que[head].step + 1;   // 这里注意，一定是父步数加一
                tail++;
                book[tempX][tempY] = 1;  // 标记走过
            }
            
            // 是否到达目标位置
            if(tempX == endX && tempY == endY){
                flag = 1;
                break;
            }
            
        }
        if(flag == 1)
            break;
        head++;   // 遍历四个方位结束以后，出队
        
    }
    
    // 注意这里，要减一，因为之前加一加过了
    printf("the step is %d\n", que[tail - 1].step);
    return 0;
}
