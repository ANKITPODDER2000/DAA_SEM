#include <stdio.h>

int main()
{
    int arr[100],left,right,n,key,flag=0;
    printf("\nEnter total number of element : ");
    scanf("%d",&n);
    printf("\nEnter the array in sorted order : ");
    for(int i = 0 ; i < n ; i++)
        scanf("%d",&arr[i]);
    printf("Enter the element to search : ");
    scanf("%d",&key);
    left = 0;
    right = n - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid]==key)
        {
            flag = 1;
            break;
        }
        else if(arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if(flag)
        printf("\n%d is found",key);
    else
        printf("\n%d is not found",key);
    return 0;
}