#include <iostream>
using namespace std;

void switchNum(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// END OF TASK 0
double Pow(double num, int exp)
{
    for (size_t i = 0; i < exp; i++)
    {
        num *= num;
    }
    return num;
}

double Min(double a, double b)
{
    int min;
    a < b ? min = a : min = b;

    return min;
}

double Max(double a, double b)
{
    int min;
    a > b ? min = a : min = b;

    return min;
}

double MaxOf3(double first, double second, double third)
{
    return Max(first, (Max(second, third)));
}

double MinOf3(double first, double second, double third)
{
    return Min(first, (Min(second, third)));
}

bool isDigit(char symb)
{
    return '0' <= symb && symb <= '9';
}
// END OF TASK 1
void printMatrix(int rows, int columns)
{
    int matrix[100][100];

    for (size_t i = 1; i <= rows; i++)
    {
        for (size_t j = 1; j <= columns; j++)
        {
            if (j > i)
                matrix[i][j] = j - i;
            else if (j < i)
                matrix[i][j] = i * j;
            else
                matrix[i][j] = i;
        }
    }

    for (size_t i = 1; i <= rows; i++)
    {
        for (size_t j = 1; j <= columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
// END OF TASK 2
double square(double num)
{
    return num * num;
}
// END OF TASK 3
void multyplyArr(int arr[], int arrLength, double multiplier)
{
    for (size_t i = 0; i < arrLength; i++)
    {
        arr[i] *= multiplier;
    }
}

void multyplyArr(double arr[], int arrLength, double multiplier)
{
    for (size_t i = 0; i < arrLength; i++)
    {
        arr[i] *= multiplier;
    }
}
// END OF TASK 4
bool isArrSortedDecreasing(const int arr[], int length)
{
    for (size_t i = 1; i < length; i++)
    {
        if (arr[i - 1] < arr[i])
            return false;

        return true;
    }
}
// END OF TASK 5
int countWords(const char textArr[], int arrLength)
{
    int wordCount = 1;
    bool deadSpace = true;
    for (size_t i = 0; i < arrLength; i++)
    {
        if (textArr[i] == ' ')
        {
            if (deadSpace == false)
            {
                wordCount++;
            }
            deadSpace = true;
        }
        else
        {
            deadSpace = false;
        }
    }
    return wordCount;
}
// END OF TASK 6
int countDigits(const char arr[], int arrLength)
{
    int digitCount = 0;

    for (size_t i = 0; i < arrLength; i++)
    {
        if (isDigit(arr[i]))
        {
            digitCount++;
        }
    }
    return digitCount;
}
// END OF TASK 7
bool isLowerCase(char symb)
{
    return 'a' <= symb && symb <= 'z';
}

bool canBeVarName(const char arr[], int arrLength)
{
    if (isLowerCase(arr[0]) && countWords(arr, arrLength) <= 1)
        return true;
    else
        return false;
}
// END OF TASK 8
int indexOfMin(int arr[], int arrLength, int searchStart)
{
    int currentMin = arr[searchStart];
    int minIndex = searchStart;
    for (size_t i = searchStart; i < arrLength; i++)
    {
        if (arr[i] < currentMin)
        {
            currentMin = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void bubbleSortArr(int arr[], int arrLength)
{
    bool swapped;
    do
    {
        swapped = false;
        for (size_t i = 0; i < arrLength - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                switchNum(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void selectionSortArr(int arr[], int arrLength)
{
    for (size_t i = 0; i < arrLength - 1; i++)
    {
        int minIndex = indexOfMin(arr, arrLength, i);
        switchNum(arr[i], arr[minIndex]);
    }
}

void insertSortArr(int arr[], int arrLength)
{
    for (size_t i = 1; i < arrLength;)
    {
        if (arr[i] < arr[i - 1] && i > 0)
        {
            switchNum(arr[i], arr[i - 1]);
            i--;
        }
        else
        {
            i++;
        }
    }
}
// END OF TASK BONUS 1
void printArray(const int arr[], int arrLength)
{
    for (size_t i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    const int ARR_LENGTH = 12;
    int bubbleArr[ARR_LENGTH] = {7, 9, 15, 24, 26, 28, 40, 41, 55, 67, 72, 77};
    insertSortArr(bubbleArr, ARR_LENGTH);
    printArray(bubbleArr, ARR_LENGTH);
}