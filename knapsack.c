#include <stdio.h>

void   input(int *);
void   sort(void);
void   swap_i(int *, int *);
void   swap_f(float *, float *);
float  knapsack(void);

int weight[20],price[20],n,capacity;
float ratio[20];

float knapsack(void)
{
    float profit = 0;
    int c = capacity;
    int i = 0;
    while(c>0 && i < n)
    {
        if(c>=weight[i])
        {
            profit = profit + price[i];
            c = c - weight[i];
        }
        else
        {
            profit = profit + ratio[i] * c;
            c = 0;
        }
        i++;
    }
    return profit;
}

void input(int *arr)
{
    for(int i = 0 ; i< n; i++)
        scanf("%d",(arr+i));
}

void sort(void)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n - i - 1 ; j++)
        {
            if(ratio[j]<ratio[j+1]){
                swap_f(&ratio[j] , &ratio[j+1]);
                swap_i(&weight[j] , &weight[j+1]);
                swap_i(&price[j] , &price[j+1]);
            }
        }
    }
}

void swap_i(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_f(float *a , float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    printf("Enter total no of items : ");
    scanf("%d",&n);
    printf("Enter the weight of items : ");
    input(weight);
    printf("Enter the price of items : ");
    input(price);
    printf("\nEnter the capacity : ");
    scanf("%d",&capacity);
    
    //printf("\nRatio is : ");
    for(int i = 0 ; i < n ; i++)
        ratio[i] = price[i] / ((float)weight[i]);
        //printf("%f ",ratio[i]);

    sort();
    float profit = knapsack();
    printf("\nProfit is : %.3f",profit);
    return 0;
}

/*
    weight   : 18 15 10
    price    : 25 24 15
    capacity : 20
*/