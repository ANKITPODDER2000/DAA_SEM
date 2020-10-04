#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void input(int * , int );
void display(int * , int);
void max_min(int * , int , int );

int max , min;

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

void max_min(int *arr , int s , int e)
{
    if(s==e){
        max = min = *(arr+s);
    }
    else if(s+1==e){
        if(*(arr+s) > *(arr+e)){
            max = *(arr+s);
            min = *(arr+e);
        }
        else{
            max = *(arr+e);
            min = *(arr+s);
        }
    }
    else{
        int mid = (s+e) / 2;
        max_min(arr,s,mid);
        int max1 = max;
        int min1 = min;
        max_min(arr,mid+1,e);
        max = max1 > max ? max1 : max;
        min = min1 < min ? min1 : min;
    }
}

int main()
{
    int n , *arr ,i;
    printf("\nEnter the length of the array : ");
    scanf("%d",&n);
    arr = (int * )malloc(sizeof(int) * n);
    input(arr , n);
    display(arr , n);
    max_min(arr , 0 , n - 1);
    printf("\nMax : %4d\nMin : %4d",max,min);
    return 0;
}