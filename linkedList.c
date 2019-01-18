#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
/**
  该程序是为了熟悉链表的使用而做的练习程序，功能是输入一串连续的数字和一个数字，可以将单个数字按照正确的位置放在一组数中。
*/

struct node{
    int data;
    struct node * next;
};

int main()
{
    struct node *head, *p, *q, *t;
    int temp, toInsert;
    head = NULL;   // 这里要让head为空，因为下面是以此来判断的
     
    // 输入数据存入链表
    printf("please enter %d numbers\n", SIZE);
    for(int i = 0; i < SIZE; i++){
        scanf("%d", &temp);
        p = (struct node *)malloc(sizeof(struct node));
        p->data = temp;
        p->next = NULL;
        if(head ==  NULL)
            head = p;
        else
            q->next = p;
        q = p;
    }
    
    // 输入需要插入的数据
    printf("please enter the number\n");
    scanf("%d", &toInsert);
    
    q = head;
    while(q != NULL){
        if(q->data >= toInsert){  // 如果第一个数就比数据大
            p = (struct node *)malloc(sizeof(struct node));
            head = p;
            p->data = toInsert;
            p->next = q;
            break;
        }
        
        // 如果第一个数不比插入的数大
        if(q->next == NULL || q->next->data >= toInsert){
            p = (struct node *)malloc(sizeof(struct node));
            p->data = toInsert;
            p->next = q->next;
            q->next = p;
            break;
        }
        q = q->next;
    }
    
    // 打印链表
    t = head;
    while(t != NULL){
        printf("%d   ", t->data);
        t = t->next;
    }
    
    
    return 0;
}
