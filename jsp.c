#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void input(int *);
void swap(int * , int *);
int  jsp(void);
void sort(void);

int profit[20],timeline[20],*jobsequence,n,max_day=INT_MIN;

int jsp(void)
{
    int profit_ = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = timeline[i] - 1 ; j >= 0 ; j--)
        {
            if(jobsequence[j]==-1)
            {
                jobsequence[j] = i;
                break;
            }
        }
    }
    for(int i = 0 ; i < max_day ; i++)
    {
        if(jobsequence[i]!=-1)
            profit_ += profit[jobsequence[i]];
    }
    return profit_;
}

void sort()
{
    for(int i = 0 ; i< n ; i++)
    {
        for(int j = 0 ; j<n-i-1 ; j++)
        {
            if(profit[j] < profit[j+1])
            {
                swap(&profit[j] , &profit[j+1]);
                swap(&timeline[j] , &timeline[j+1]);
            }
        }
    }
}

void swap(int * a , int * b)
{
    int temp = *a;
    *a       = *b;
    *b       = temp;
}

void input(int *arr)
{
    for(int i=0 ; i < n ; i++)
        scanf("%d",(arr+i));
        //jobsequence[i] = -1;
}

int main()
{
    printf("\nEnter total no of jobs : ");
    scanf("%d",&n);
    
    printf("\nEnter profit array : ");
    input(profit);
    printf("\nEnter time array : ");
    input(timeline);

    for(int i = 0 ; i<n ; i++)
    {
        if(timeline[i]>max_day)
            max_day = timeline[i];
    }
    
    jobsequence = (int *)malloc(sizeof(int) * max_day);
    for(int i=0 ; i<max_day ; i++)
        jobsequence[i] = -1;

    sort();
    int profit_ = jsp();
    printf("\nMax profit is : %d",profit_);
    return 0;
}

/*
    n -> 4
    profit -> 100 10 15 27
    time req -> 2 1 2 1
*/