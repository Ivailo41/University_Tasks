#include <iostream>
using namespace std;

const short MAX_ROW = 100;
const short MAX_COL = 100;

void printMatrix(int **matrix, short rows, short cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int getSumOfRow(const int matrix[MAX_ROW][MAX_COL], short row, short size)
{
    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += matrix[row - 1][i];
    }

    return sum;
}

int getSumOfCol(const int matrix[MAX_ROW][MAX_COL], short col, short size)
{
    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += matrix[i][col - 1];
    }

    return sum;
}

int **multiplyMatrices(int matrix1[MAX_ROW][MAX_COL], int matrix2[MAX_ROW][MAX_COL], short rows, short cols)
{
    int **multipliedMatrix = new int *[rows];
    for (size_t i = 0; i < rows; i++)
    {
        *(multipliedMatrix + i) = new int[cols];
        for (size_t j = 0; j < cols; j++)
        {
            multipliedMatrix[i][j] = getSumOfRow(matrix1, i, cols) * getSumOfCol(matrix2, i, rows);
        }
    }

    return multipliedMatrix;
}

int main()
{
    const short MATRIX1_ROWS = 4;
    const short MATRIX_COLS = 3;

    const short MATRIX2_ROWS = 3;
    const short MATRIX2_COLS = 4;

    int matrix1[MAX_ROW][MAX_COL] = {{1, 2, 3},
                                     {4, 5, 6},
                                     {7, 8, 9},
                                     {6, 6, 6}};

    int matrix2[MAX_ROW][MAX_COL] = {{1, 2, 3, 6},
                                     {4, 5, 6, 6},
                                     {7, 8, 9, 6}};

    int **multipliedMatrix = multiplyMatrices(matrix1, matrix2, MATRIX1_ROWS, MATRIX2_COLS);

    printMatrix(matrix1, MATRIX1_ROWS, MATRIX_COLS);
}