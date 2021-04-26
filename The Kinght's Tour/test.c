#include <stdio.h>
#define M 8

//khoi tao ban co rong
void initial(int board[][M]){
    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            board[i][j] = 0;
        }
    }
}
// kiem tra xem vi tri (i, j) co nam trong ban co hay khong
int check(int i, int j){
    return (i >= 0 && i < M && j >=0 && j < M);
}
// hien thi ket qua di tuan
void show(int board[][M]){
    int i, j;
    for ( i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%4d", board[i][j]);
        }
        printf("\n\n");
    }
}

void try(int step, int i, int j, int board[][M], int I[], int J[], int *OK){
    int m, inext, jnext;
    for ( m = 0; m < 8; m++)
    {
        inext = i + I[m];
        jnext = j + J[m];
        if (check(inext, jnext) && board[inext][jnext] == 0){
            board[inext][jnext] = step + 1; // thu di toi
            if (step == M*M - 1)
            {
                *OK = 1;
            }else{
                try(step + 1, inext, jnext, board, I, J, &*OK); // di tiep
                if (*OK == 0)
                {
                    board[inext][jnext] = 0;
                }
            }
        }
    }
}

int main(){
    int board[M][M], OK = 0, i = 0, j =0;  // xuat phat tai (2, 0)
    int I[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int J[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    initial(board);
    board[i][j] = 1;
    try(1, i, j, board, I, J, &OK);
    printf("\n==============\n");
    if (OK)
    {
        show(board);
    }else printf("NO SOLUTION!");

    return 0;
}
