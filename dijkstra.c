#include <stdio.h>
#include <limits.h>

void dijkstra(void);
void input(void);
int  minVertex(void);
void printDetails(void);


int v,adj[20][20],weight[20],visit[20],start;

void dijkstra(void)
{
    printf("\nEnter the starting vertex : ");
    scanf("%d",&start);
    weight[start] =  0;

    for(int k = 0 ; k < v-1 ; k++)
    {
        int u = minVertex();
        visit[u] = 1;
        
        for(int i = 0 ; i < v ; i++)
        {
            if(adj[u][i] &&  weight[u]!=INT_MAX && adj[u][i]+weight[u] < weight[i])
                weight[i] = adj[u][i] + weight[u];
        }
    }

    printDetails();
}

int minVertex(void)
{
    int min_ind;
    int min = INT_MAX;
    for(int i = 0 ; i < v ; i++)
    {
        if(visit[i]==0 && weight[i] < min)
        {
            min_ind = i;
            min = weight[i];
        }
    }
    return min_ind;
}

void printDetails(void)
{
    printf("Distance from starting vertex() to all vertices is : ",start);
    for(int i = 0 ; i < v ; i++)
    {
        if(weight[i]==INT_MAX)
            printf("INF ");
        else
            printf("%d ",weight[i]);
    }
}

void input()
{
    printf("\nEnter the adjacency metrix :\n");
    for(int i = 0 ; i < v ; i++)
    {
        for(int j = 0 ; j < v ; j++)
            scanf("%d",&adj[i][j]);
        visit[i]  =  0;
        weight[i] = INT_MAX;
    }
}

int main()
{
    printf("Enter no of vertices : ");
    scanf("%d",&v);
    input();
    dijkstra();
    return 0;
}

/*
ver -> 7

adj:
0 0 2 0 0 0 0
4 0 0 0 0 0 0
0 0 0 0 0 0 0
0 15 0 0 0 5 23
0 17 0 0 0 0 11
0 0 9 0 0 0 13
0 0 0 0 0 0 0

start -> 3 (D)

*/