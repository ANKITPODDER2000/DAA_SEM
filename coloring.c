#include <stdio.h>

int coloring(int);
int perfectColor(int);

int adj[20][20], color[20], v, n;

int coloring(int vertex)
{
    if(vertex==v)
        return 1;
    else
    {
        for (int i = 0; i < n;i++)
        {
            color[vertex] = i;
            if(perfectColor(vertex))
            {
                if(coloring(vertex+1))
                    return 1;
            }
            color[vertex] = -1;
        }
        return 0;
    }
    
}

int perfectColor(int vertex)
{
    for(int i = 0 ; i < vertex ; i++)
    {
        if(adj[vertex][i] && color[i]==color[vertex])
            return 0;
    }
    return 1;
}

int main()
{
    printf("\nEnter total no of vertices : ");
    scanf("%d", &v);
    printf("\nEnter the adjacency matrix :\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            scanf("%d", &adj[i][j]);
    }
    printf("\nEnter total number of unique color : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        color[i] = -1;
    if (coloring(0) == 0)
        printf("\nIt's not possible to make a graph using these colors!");
    else
    {
        printf("\nColors of the graph vertices : ");
        for (int i = 0; i < v; i++)
            printf("%d ", color[i]+1);
    }
    return 0;
}
/*
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
*/