#include <stdio.h>
#include <limits.h>

int chainmultiply(void);

int matrix[20],n;

int chainmultiply(void)
{
    int store[n][n];
    for(int i = 1 ; i < n ; i++)
        store[i][i] = 0;

    for (int L = 2; L < n; L++) { 
        for (int i = 1; i < n - L + 1; i++) { 
            int j = i + L - 1; 
            if (j == n) 
                continue; 
            store[i][j] = INT_MAX; 
            for (int k = i; k <= j - 1; k++) {
                int q = store[i][k] + store[k + 1][j] + matrix[i - 1] * matrix[k] * matrix[j]; 
                if (q < store[i][j]) 
                    store[i][j] = q; 
            } 
        } 
    } 

    return store[1][n-1];
}

int main()
{
    printf("\nEnter total no of element : ");
    scanf("%d",&n);
    printf("\nEnter element of the araay : ");
    for(int i = 0;i<n;i++)
        scanf("%d",&matrix[i]);
    printf("\nMinimum multipication cost is : %d",chainmultiply());
    return 0;
}