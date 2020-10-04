#include <stdio.h>
#include <stdlib.h>

void sort(int * , int ,int );
void merge(int * , int ,int ,int);
void input(int * , int );
void display(int * , int);

void merge(int *arr , int start , int mid , int end)
{
    int i , j,k;
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int *arr1 = (int *)malloc(sizeof(int) * n1);
    int *arr2 = (int *)malloc(sizeof(int) * n2);
    for(i = 0 ; i < n1 ; i++)
        arr1[i] = arr[start + i];
    for(i = 0 ; i < n2 ; i++)
        arr2[i] = arr[mid + i + 1];
    for(i = 0 , j = 0 , k = start; i < n1 || j < n2 ; k++)
    {
        if(i==n1){
            *(arr + k) = *(arr2+j);
            j++;
        }
        else if(j==n2){
            *(arr + k) = *(arr1+i);
            i++;
        }
        else if(arr1[i] > arr2[j]){
            *(arr + k) = *(arr2+j);
            j++;
        }
        else{
            *(arr + k) = *(arr1+i);
            i++;
        }
    }
}

void sort(int *arr , int start , int end)
{
    if(start < end)
    {
        int mid = (end + start) / 2;
        //printf("\n%d %d %d",start , mid , end);
        sort(arr , start ,mid);
        sort(arr,mid+1,end);
        merge(arr,start,mid,end);
        printf("\nArray in function (sort) : ");
        for(int i = start ; i <= end ; i++)
            printf("%d ", *(arr+i));
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
    display(arr , n);
    return 0;
}