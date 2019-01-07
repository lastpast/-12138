#include<stdio.h>
#define SIZE 5


void quicksort(int , int );

int a[SIZE];

int main()
{
    for(int i = 0; i < SIZE; i++)
        scanf("%d", &a[i]);
    
    quicksort(0, SIZE - 1);
    
    for(int i = 0; i < SIZEn; i++)
        printf("%d  ", a[i]);
    
    return 0;
}

void quicksort(int left, int right)
{
    int i, j, temp, t;
    
    if(left > right)
        return;
    
    temp = a[left];
    i = left;
    j = right;
    
    while(i != j){
        while(a[j] >= temp && j > i)
            j--;
        while(a[i] <= temp && i < j)
            i++;
        
        if(i < j){
            t = a[j];
            a[j] = a[i];
            a[i] = t;
        }
    }
    
    a[left] = a[i];
    a[i] = temp;
    
    quicksort(left, i - 1);
    quicksort(i + 1, right);
    return;
}
