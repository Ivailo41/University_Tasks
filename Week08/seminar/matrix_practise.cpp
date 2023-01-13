#include <iostream>
using namespace std;

const short MAX_ROW = 100;
const short MAX_COL = 100;

const short SQUARE_MAX_SIZE = 100;

// SORTING MATRIX FUNCTIONS
void swapNumbers(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int *arr, short arrSize)
{
    for (size_t i = 0; i < arrSize - 1; i++)
    {
        int *currentMin = arr + i;
        for (size_t j = i; j < arrSize; j++)
        {
            if (arr[j] < *currentMin)
            {
                currentMin = arr + j;
            }
        }
        swapNumbers(*currentMin, *(arr + i));
    }
}

void printArr(const int *arr, short arrSize)
{
    for (size_t i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
}

void printMatrix(const int matrix[MAX_ROW][MAX_COL], short size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void sortMatrixColumn(int matrix[MAX_ROW][MAX_COL], short size, short col)
{
    int columnArr[size];

    for (size_t i = 0; i < size; i++)
    {
        columnArr[i] = *(*(matrix + i) + col);
    }

    selectionSort(columnArr, size);

    for (size_t i = 0; i < size; i++)
    {
        *(*(matrix + i) + col) = columnArr[i];
    }
}

void sortMatrix(int matrix[MAX_ROW][MAX_COL], short size)
{
    const int MATRIX_ARR_SIZE = size * size;
    int arrFromMatrix[MATRIX_ARR_SIZE];

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            arrFromMatrix[j + size * i] = matrix[i][j];
        }
    }

    selectionSort(arrFromMatrix, MATRIX_ARR_SIZE);

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            matrix[i][j] = arrFromMatrix[j + size * i];
        }
    }
}

// Other matrix functions
void rotateSquareMatrix(int matrix[][SQUARE_MAX_SIZE], short size)
{
    int rotatedMatrix[SQUARE_MAX_SIZE][SQUARE_MAX_SIZE];

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i; j < size; j++)
        {
            swapNumbers(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{
    const short MATRIX_SIZE = 5;
    int matrix[MAX_ROW][MAX_COL] = {{10, 2, 46, 13, 5},
                                    {8, 53, 6, 32, 89},
                                    {7, 8, 19, 23, 76},
                                    {21, 4, 46, 61, 69},
                                    {11, 9, 33, 54, 78}};

    sortMatrix(matrix, MATRIX_SIZE);
    rotateSquareMatrix(matrix, MATRIX_SIZE);
    printMatrix(matrix, MATRIX_SIZE);
}