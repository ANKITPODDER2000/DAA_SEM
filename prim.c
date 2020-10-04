#include <stdio.h>
#include <limits.h>

int  prim(void);
void input(void);
int  minVertex(void);
int  visitLeft(void);
void printDetails(void);


int v,adj[20][20],parent[20],weight[20],visit[20];

int prim()
{
    parent[0] = -1;
    weight[0] =  0;
    while(visitLeft())
    {
        int u = minVertex();
        visit[u] = 1;
        
        for(int i = 0 ; i < v ; i++)
        {
            if(adj[u][i] && adj[u][i] < weight[i])
            {
                weight[i] = adj[u][i];
                parent[i] = u;
            }
        }
    }
    int min_weight = 0;
    for(int i = 0 ; i < v; i++)
        min_weight += weight[i];
    printDetails();
    return min_weight;
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

int visitLeft(void)
{
    for(int i = 0 ; i < v ; i++)
    {
        if(visit[i]==0)
            return 1;
    }
    return 0;
}

void printDetails(void)
{
    printf("\n  Vertex  |  Parent  |  weight  \n------------------------------\n");
    for(int i = 0 ; i < v ; i++)
    {   
        if(parent[i]==-1)
            printf("%5d     | %s |%5d     \n",i,"STARTING",weight[i]);
        else
            printf("%5d     |%5d     |%5d     \n",i,parent[i],weight[i]);
    }
}

void input()
{
    printf("\nEnter the adjacency metrix :\n");
    for(int i = 0 ; i < v ; i++)
    {
        for(int j = 0 ; j < v ; j++)
            scanf("%d",&adj[i][j]);
        parent[i] = -2;
        visit[i]  =  0;
        weight[i] = INT_MAX;
    }
}

int main()
{
    printf("Enter no of vertices : ");
    scanf("%d",&v);
    input();
    int min_weight = prim();
    printf("Min weight of the graph is : %d\n",min_weight);
    return 0;
}

/*

0 7 3 0 0
7 0 4 9 11
3 4 0 10 0
0 9 10 0 0
0 11 0 0 0

*/