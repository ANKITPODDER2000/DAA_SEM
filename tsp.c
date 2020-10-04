#include <stdio.h>
#define INF 10000

int tsp(int );
int left(void);

int flag[20], adj[20][20], n;

int tsp(int vertex)
{
    int min_cost = INF;
    if(left()==0)
    {
        if(adj[vertex][0])
            return adj[vertex][0];
        return INF;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if(flag[i])
                continue;
            flag[i] = 1;
            int temp = adj[vertex][i] + tsp(i);
            flag[i] = 0;
            if(temp < min_cost)
                min_cost = temp;
        }
        return min_cost;
    }
        
}

int left(void)
{
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if(!flag[i])
            l++;
    }
    return l;
}

int main()
{
    printf("\nEnter total no of vertices : ");
    scanf("%d", &n);
    
    printf("\nEnter the adjacency graph : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
        flag[i] = 0;
    }

    flag[0] = 1;
    int cost = tsp(0);
    printf("\nMin Cost by the sellsman : %d", cost);

    return 0;
}

/*
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
===============================
0 2 9 10
1 0 6 4
15 7 0 8
6 3 12 0
*/