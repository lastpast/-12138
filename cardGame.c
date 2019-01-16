 #include<stdio.h>
 #define SIZE 3 
 /**
   小猫钓鱼的游戏：
   规则：两个人手里有6张牌，每张牌的大小在1-9之间，按照小猫钓鱼的规则，手中没牌者负。
   算法：首先两个人手牌应该是两个队列，按照FIFO的原则来出牌。而桌上的牌由于赢牌的方式，所以应该选择栈的方式。
 */
 
 struct queue{
    int data[100];   // 这个就是手牌
    int head;
    int tail;
 };
 
 struct strack{
    int data[10];    // 这个是在桌上的牌
    int top;
 };
 
 int main()
 {
    struct queue q1, q2;   // 两个玩家
    struct strack desk;    // 桌面上的栈
    int temp;    // 用来表示出的牌
    int book[10];   // 利用桶排序的原理，来统计哪个牌存在
    
    // 初始化数据
    q1.head = 0;
    q1.tail = 0;
    q2.head = 0;
    q2.tail = 0;
    desk.top = 0;
    
    for(int i = 0; i < 10; i++)  // 桌面上的牌清0
        book[i] = 0;
    
    printf("first people cards\n");    // 第一个玩家的手牌
    for(int i = 0; i < SIZE; i++){
        scanf("%d", &q1.data[q1.tail]);
        q1.tail++;
    }
     
    printf("second people cards\n");   // 第二个玩家的手牌
    for(int i = 0; i < SIZE; i++){
        scanf("%d", &q2.data[q2.tail]);
        q2.tail++;
    }

    
    // 游戏开始
    while(1){
        if(q1.head == q1.tail && q2.head != q2.tail){    // 玩家一的手牌为空
            printf("paly 1 lose\n");
            break;
        }
        if(q2.head == q2.tail && q1.head != q1.tail){    // 玩家二的手牌为空
            printf("play 2 lose\n");
            break;
        }
        if(q1.head == q1.tail && q2.head == q2.tail){
            printf("no one win\n");
            break;
        }
        
        // 玩家一出牌
        temp = q1.data[q1.head];
        book[temp]++;
        desk.data[desk.top] = q1.data[q1.head];
        q1.head++; 
        desk.top++;
        
        // 如果玩家一赢牌了
        if(book[temp] == 2){
            desk.top--;   // 将上面多加的一减掉
            do{
                q1.data[q1.tail] = desk.data[desk.top];  
                book[desk.data[desk.top]] = 0;
                q1.tail++;
                desk.top--;
            }while(desk.data[desk.top] != temp);
            // 把第二张一样的也给玩家一
            q1.data[q1.tail] = desk.data[desk.top];
            q1.tail++;
        }
        
        // 玩家二出牌
        temp = q2.data[q2.head]; 
        book[temp]++;
        desk.data[desk.top] = q2.data[q2.head];
        q2.head++; 
        desk.top++;
        
        // 如果玩家二赢牌了
        if(book[temp] == 2){
            desk.top--;   // 将上面多加的一减掉
            do{
                q2.data[q2.tail] = desk.data[desk.top];  
                book[desk.data[desk.top]] = 0;
                q2.tail++;
                desk.top--;
            }while(desk.data[desk.top] != temp);
            // 把第二张一样的也给玩家一
            q2.data[q2.tail] = desk.data[desk.top]; 
            q2.tail++; 
        }
    }
    
    return 0;
 }
