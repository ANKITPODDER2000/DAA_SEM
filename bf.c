#include <stdio.h>
#include <limits.h>
#define INF 40000

void input(void);
void bf(void);
void print(void);


int v,adj[20][20],weight[20],start;

void bf(void)
{
    printf("\nEnter the starting node : ");
    scanf("%d",&start);
    weight[start] = 0;
    
    for(int k = 0 ; k < v-1 ; k++)
    {
        for(int i = 0 ; i < v ; i++)
        {
            for(int j = 0 ; j < v ; j++)
            {
                if(adj[i][j]!=0 && adj[i][j]+weight[i] < weight[j])
                {   weight[j] = adj[i][j]+weight[i];
                    //printf("\n%d %d %d",weight[j],adj[i][j],weight[i]);
                    //print();
                }
            }
        }
    }

    for(int i = 0 ; i < v ; i++)
    {
        for(int j = 0 ; j < v ; j++)
        {
            if(adj[i][j]!=0 && adj[i][j]+weight[i] < weight[j])
                printf("\nGraph contains negative weight cycle!");
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
        weight[i] = INF;
    }
}

void print(void)
{
    printf("\nAll paths from starting vertex(%d) : ",start);
    for(int i = 0 ; i < v ; i++)
    {
        if(weight[i]>=INF)
            printf("INF ");
        else
            printf("%d ",weight[i]);
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
    bf();
    print();
    return 0;
}

/*

0 -1 4 0 0
0 0 3 2 2
0 0 0 0 0
0 1 5 0 0
0 0 0 -3 0

*/