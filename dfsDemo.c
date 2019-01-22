#include<stdio.h>
#define N 5  // 五行四列
#define M 4

/**
  这个程序是深度优先算法的深刻理解。使用这个算法不一定要求每一片树叶有什么确定的数值，重要的是选择的意味，而树叶里的值也不一定非得是数值，可以是选择之后的结果。
  而这个程序是输入一个迷宫，并且输入起点和终点坐标，可以算的最快的步数是多少。
*/

int a[50][50], book[50][50], x_start, y_start, x_end, y_end, min = 99;  // a是存储地图的数组，而book是记录走过的路的数组

void dfs(int , int , int );

int main()
{
    // 输入地图数据
    printf("enter the map\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            scanf("%d", &a[i][j]);
    }
    printf("enter the start and end\n");
    scanf("%d%d%d%d",&x_start, &y_start, &x_end, &y_end);
    
    // 开始寻找
    book[x_start][y_start] = 1;
    dfs(x_start, y_start, 0);  // 传入起始坐标
    
    // 输出几步
    printf("the min is %d\n", min);
    
    return 0;
}

void dfs(int x, int y, int step)
{
    int try_x, try_y;
    int next[4][2] = {{0,1}, {1,0}, {0,-1}, {-1, 0}};   // 定义下一步怎么走， 关键就是这个，将怎么走抽象成树的分支了，很厉害
    
    // 如果到达目标
    if(x == x_end && y == y_end){
        if(step < min)
            min = step;
        return;
    }
    
    for(int i = 0; i < 4; i++){   // 而深度查询就是这一步和下面的递归调用了， 很厉害
        try_x = x + next[i][0];
        try_y = y + next[i][1];
        
        // 如果越界了
        if(try_x < 0 || try_x >= N || try_y < 0 || try_y >= N)
            continue;
        
        if(a[try_x][try_y] == 0 && book[try_x][try_y] == 0){
            book[try_x][try_y] = 1;
            dfs(try_x, try_y, step + 1);  // 进行下一步查找
            book[try_x][try_y] = 0;  // 这里的取消标记很重要
        }
    }
    
    return;
}
