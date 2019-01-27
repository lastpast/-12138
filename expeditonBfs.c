#include<stdio.h>

//=========================================================
//《啊哈算法》p106页的宝岛探险，利用BFS算法。
//=========================================================

// 定义节点的结构体
struct node{
    int x;
    int y;
};

int book[10][10];  // 用来标记点是否走过

int main()
{
    // 定义以及初始化变量
    int startX, startY, sum, head, tail, tempX, tempY;   // 开始坐标和岛屿总数量,节点队列的头和尾,中间坐标
    struct node que[100];   // 定义100个节点
    head = 0;
    tail = 0;
    sum = 0;
    // 地图，0表示海洋
    int map[10][10] = {{1,2,1,0,0,0,0,0,2,3}, 
                        {3,0,2,0,1,2,1,0,1,2}, 
                        {4,0,1,0,1,2,3,2,0,1}, 
                        {3,2,0,0,0,1,2,4,0,0}, 
                        {0,0,0,0,0,0,1,5,3,0},
                        {0,1,2,1,0,1,5,4,3,0},
                        {0,1,2,3,1,3,6,2,1,0},
                        {0,0,3,4,8,9,7,5,0,0},
                        {0,0,0,3,7,8,6,0,1,2,},
                        {0,0,0,0,0,0,0,0,1,0}};
    // 定义方向数组
    int next[4][2] = {{0,1},
                      {1,0},
                      {0,-1},
                      {-1,0}};
    
    
    // 输入起点坐标
    printf("enter the station of start:\n");
    scanf("%d%d", &startX, &startY);
    
    // 将起点入列
    que[tail].x = startX;
    que[tail].y = startY;
    tail++;
    book[startX][startY] = 1;
    sum++;
    
    // 开始广度优先
    while(head < tail)  // 由于广度优先需要遍历队列中所有点，所以只需要这一个出口就好
    {
        for(int i = 0; i < 4; i++){
            tempX = que[head].x + next[i][0];
            tempY = que[head].y + next[i][1];
            
            // 判断是否越界
            if(tempX < 0 || tempX >= 10 || tempY < 0 || tempY >= 10)
                continue;
            
            // 如果在岸上，并且没有走过
            if(map[tempX][tempY] > 0 && book[tempX][tempY] == 0){
                // 入队，计数
                que[tail].x = tempX;
                que[tail].y = tempY;
                tail++;
                book[tempX][tempY] = 1;
                sum++;
            }
            
        }
        head++;  // 遍历之后出队
    }
    
    printf("%d\n", sum);
    return 0;
}
