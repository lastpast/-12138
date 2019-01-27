#include<stdio.h>

//===================================================================
//《啊哈算法》p106页的宝岛探险，利用DFS算法。
//===================================================================


int book[10][10], sum;  // 标记是否走过
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


void dfs(int , int );   // 深度优先函数

int main()
{
    // 定义以及初始化变量
    int startX, startY;   // 开始坐标和总数
    // 输入起始位置
    printf("enter the station of start\n");
    scanf("%d%d", &startX, &startY);
    
    book[startX][startY] = 1;
    sum++;
    dfs(startX, startY);
    printf("%d\n", sum);
    
    
    return 0;
}

void dfs(int x, int y)
{
    int tempX = 0, tempY = 0;
    for(int i = 0; i < 4; i++){
        tempX = x + next[i][0];
        tempY = y + next[i][1];
        
        // 判断是否越界
        if(tempX < 0 || tempX >= 10 || tempY < 0 || tempY >= 10)
            continue;
        
        if(map[tempX][tempY] > 0 && book[tempX][tempY] ==0){
            book[tempX][tempY] = 1;
            sum++;
            dfs(tempX, tempY); 
        }
    }
    return;
}
