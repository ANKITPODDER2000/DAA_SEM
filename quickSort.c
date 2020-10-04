#include <stdio.h>
#include <stdlib.h>

void sort(int * , int ,int );
int  partition(int *, int , int );
void input(int * , int );
void display(int * , int);

int partition(int *arr, int s, int e)
{
    int mark = *(arr + e);
    int i = s-1;
    for(int j = s;j<=e-1;j++){
        if(*(arr+j)<mark){
            i++;
            int c    = *(arr+j);
            *(arr+j) = *(arr+i);
            *(arr+i) = c;
        }
    }
    i++;
    int c      = *(arr+e);
    *(arr+e)   = *(arr+i);
    *(arr+i) = c;
    return i;
}

void sort(int *arr , int start , int end)
{
    if(start < end){
        int n = partition(arr , start , end);
        display(arr , 5);
        sort(arr , start , n-1);
        sort(arr,n+1,end);
    }
}

void input(int *arr , int n)
{
    int i;
    printf("\nEnter the array element : ");
    for(i = 0 ;i < n ; i++)
        scanf("%d",(arr+i));
}

void display(int *arr , int n)
{
    int i;
    printf("\nArray is : ");
    for(i = 0 ;i < n ; i++)
        printf("%4d ",*(arr+i));
}

int main()
{
    int n , *arr ,i;
    printf("\nEnter the length of the array : ");
    scanf("%d",&n);
    arr = (int * )malloc(sizeof(int) * n);
    input(arr , n);
    display(arr , n);
    sort(arr , 0 , n-1);
    printf("\n\n");
    display(arr , n);
    return 0;
}