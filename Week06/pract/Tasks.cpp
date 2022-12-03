#include <iostream>
using namespace std;

const int MAX_ROW = 128;
const int MAX_COL = 128;

void printMatrixRowSum(const int matrix[MAX_ROW][MAX_COL], int rows, int cols)
{
    int sum = 0;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }
        cout << sum << endl;
        sum = 0;
    }
}

void printSumOfMatrixDiagonals(const int matrix[MAX_ROW][MAX_COL], int rows, int cols)
{
    int sum = 0;
    int offset = 0;
    for (size_t i = 0; i < rows; i++)
    {
        sum += matrix[i][offset] + matrix[i][cols - offset - 1];
        offset++;
    }
    cout << sum;
}

void setMatrixValues(int matrix[MAX_ROW][MAX_COL], int rows, int cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void setMatrixValues(int matrix[MAX_ROW][MAX_COL], int rows, int cols, int valueRiser) // add number to each elemet
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
            matrix[i][j] += valueRiser;
        }
    }
}

void printMatrix(int matrix[MAX_ROW][MAX_COL], int rows, int cols)
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

int getSumOfRow(const int matrix[MAX_ROW][MAX_COL], int row, int size)
{
    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += matrix[row - 1][i];
    }

    return sum;
}

int getSumOfCol(const int matrix[MAX_ROW][MAX_COL], int col, int size)
{
    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += matrix[i][col - 1];
    }

    return sum;
}

int getSumOfDiagonal(const int matrix[MAX_ROW][MAX_COL], int size)
{
    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += matrix[i][i];
    }

    return sum;
}

int getSumOfSecondDiagonal(const int matrix[MAX_ROW][MAX_COL], int size)
{
    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += matrix[i][size - i - 1];
    }

    return sum;
}

int getSumBelowDiagonal(const int matrix[MAX_ROW][MAX_COL], int size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (j < i)
                sum += matrix[i][j];
        }
    }

    return sum;
}

int getSumAboveDiagonal(const int matrix[MAX_ROW][MAX_COL], int size)

    int main()
{
    int matrix[MAX_ROW][MAX_COL];
    int rows, cols;

    cin >> rows >> cols;

    setMatrixValues(matrix, rows, cols, 10);
    printMatrix(matrix, rows, cols);
}