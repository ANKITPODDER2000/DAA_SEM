#include <stdio.h>
#include <stdlib.h>

void input(void);
int queueEmpty(void);
int dequeue(void);
void enqueue(int );

int v , arr[20][20] , queue[20] , visit[20] , start,front = -1,rear=-1;

void input(void)
{
    for(int i = 0;i < v ; i++)
    {
        for(int j = 0 ; j < v ; j++)
            scanf("%d",&arr[i][j]);
        *(visit+i) = 0;
    }
}
int dequeue(void){
    int r;
    if(front==rear){
        r = queue[front];
        front=rear=-1;
    }else{
        r = queue[front];
        front++;
    }
    return r;
}
void enqueue(int pos){
    if(rear==-1)
    {
        rear++;
        front++;
    }
    else{
        rear++;
    }
    queue[rear] = pos;
    visit[pos] = 1;
}
int queueEmpty(void){
    return front==-1 ? 1 : 0;
}

void bfs(){
    printf("\nBFS of the graph : ");
    enqueue(start);
    while(!queueEmpty()){
        int p = dequeue();
        printf("%d ",p);
        for(int i = 0 ; i < v ; i++){
            if(arr[p][i]!=0 && visit[i]==0){
                enqueue(i);
            }
        }
    }
}

int main()
{
    printf("\nEnter total no of vertices : ");
    scanf("%d",&v);
    
    printf("\nEnter the adj matrix : \n");
    input();
    printf("\nEnter the starting vertex : ");
    scanf("%d",&start);
    bfs();
}


/*
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0


0 1 1 0 0 0 0
1 0 0 1 1 0 0
1 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 0
0 0 1 0 0 0 0
*/