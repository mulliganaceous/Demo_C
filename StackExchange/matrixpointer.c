#include <stdio.h>
void printOutput(int row, int col, int array[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {   
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int m1[2][2] = {{1,2},{-2,0}};
    int m2[3][3] = {{1,5,6},{3,2,7},{8,4,9}};
    int m3[2][5] = {{0,1,2,3,4},{5,6,7,8,9}};
    int m4[1][7] = {{-3,-2,-1,0,1,2,3}};

    printOutput(2, 2, m1);
    printOutput(3, 3, m2);
    printOutput(2, 5, m3);
    printOutput(1, 7, m4);
    return 0;
}