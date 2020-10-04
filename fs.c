#include <stdio.h>
#include <stdlib.h>

void input(void);
int  min(int a , int b);
void fw(void);
void print(void);


int v,adj[20][20];

void fw(void)
{
    for(int k = 0 ; k < v ; k++)
    {
        for(int i = 0 ; i < v; i++)
        {
            for(int j = 0 ; j < v ; j++)
                adj[i][j] = min(adj[i][j] ,adj[i][k]+adj[k][j]);
        }
    }
}

void input(void)
{
    printf("\nEnter the adjacency matrix :\n");
    for(int i = 0;i < v ; i++)
    {
        for(int j = 0 ; j < v ; j++)
            scanf("%d",&adj[i][j]);
    }
}

void print(void)
{
    printf("\nAll Pair Shortest Path is:\n");
    for(int i = 0 ; i < v ; i++)
    {
        for(int j = 0 ; j < v; j++)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
}

int min(int a , int b)
{
    return a<b ? a : b;
}

int main()
{
    printf("\nEnter no of vertices : ");
    scanf("%d",&v);
    input();
    fw();
    print();
    return 0;
}

/*

0 4 11
6 0 2
3 1000 0

*/