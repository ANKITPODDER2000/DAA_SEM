#include <stdio.h>

int  isSafe(int , int );
int  placeQueen(int);
void printSolution(void);

int board[64][64] , N;

int placeQueen(int row)
{
    if(row >= N)
        return 1;
    for(int i = 0 ; i<N ; i++)
    {
        if(isSafe(row , i))
        {
            //printf("\n-========= %d   %d",row , i );
            board[row][i] = 1;
            if(placeQueen(row+1))
                return 1;
            board[row][i] = 0;
        }
    }
    return 0;
}

int isSafe(int row , int col)
{
    //printf("\n------------------%d    %d",row , col);
    for(int i = 0 ; i < row ; i++)
    {
        //printf("\n  %d  %d",i , col);
        if(board[i][col])
            return 0;
    }

    //left dia
    for(int i = row - 1 , j = col - 1 ; i>=0 && j >= 0 ; i-- , j--)
    {
        //printf("\n  %d  %d",i , j);
        if(board[i][j])
            return 0;
    }

    //right dia
    for(int i = row - 1 , j = col + 1 ; i>=0 && j <N ; i-- , j++)
    {
        //printf("\n  %d  %d",i , j);
        if(board[i][j])
            return 0;
    }

    return 1;
}

void printSolution(void)
{
    printf("\nBoard is :\n");
    for(int i = 0 ; i< N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            if(board[i][j])
                printf("%d ",board[i][j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nPositions of queen : ");
    for(int i = 0 ; i< N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            if(board[i][j])
            {
                printf("%d ",j+1);
                break;
            }
        }
    }
}

int main()
{
    printf("\nEnter value of N : ");
    scanf("%d",&N);
    
    for(int i = 0 ; i< N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
            board[i][j] = 0;
    }

    if(placeQueen(0))
        printSolution();
    else
        printf("\nIt is not possible to place all queen!");

    return 0;
}