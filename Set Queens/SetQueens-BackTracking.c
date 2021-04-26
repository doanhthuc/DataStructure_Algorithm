#include <stdio.h>

#define N 8

void showResult(int board[][N]){
    int i, j;
    for (i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            printf("%4d", board[i][j]);
        }
        printf("\n\n");
    }
}

int isOk(int board[][N], int row, int col){
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return 0;
        }
    }

    //trai tren
    i = row; j = col;
    while (i >= 0 && j>= 0)
    {
        if (board[i][j] == 1)   // khong dat duoc hau
        {
            return 0;
        }

        i--;
        j--;
    }
    
    //trai duoi

    i = row; j = col;
    while (i < N && j >= 0) 
    {
        if (board[i][j] == 1) 
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int setQueen(int board[][N], int col){
    int i, j;
    if (col >= N)
    {
        return 1;
    }
    for ( i = 0; i < N; i++)
    {
        if (isOk(board, i, col) == 1)
        {
            board[i][col] = 1; // dat hau
            if (setQueen(board, col+1) == 1)
            {
                return 1;
            }
            board[i][col] = 0;
        }
        
    }
    
    return 0;
}

int main(){
    int board[N][N], i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
    if (setQueen(board, 0) == 1)
    {
        showResult(board);
    }else printf("NO SOLUTION!");
    
    return 0;
}