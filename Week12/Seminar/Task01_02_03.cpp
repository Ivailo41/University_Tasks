#include <iostream>
using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

size_t stringLenghtCalculate(char *string, size_t result)
{
    if (*string == '\0')
        return result;

    string++;
    result++;
    stringLenghtCalculate(string, result);
}

size_t getStringLength(char *string)
{
    return stringLenghtCalculate(string, 0);
}

int smallestElementCalculate(int *array, size_t arraySize, int result)
{
    if (arraySize == 0)
    {
        return result;
    }

    if (result > array[arraySize - 1])
    {
        result = array[arraySize - 1];
    }

    return min(result, smallestElementCalculate(array, arraySize - 1, result));
}

int getSmallestElement(int *array, size_t arraySize)
{
    return smallestElementCalculate(array, arraySize, array[arraySize - 1]);
}

bool containsNumber(int *array, size_t arraySize, int number)
{
    if (arraySize == 0)
    {
        return false;
    }

    if (array[arraySize - 1] == number)
    {
        return true;
    }
    else
    {
        return containsNumber(array, arraySize - 1, number);
    }
}

int main()
{
    int array[] = {5, 7, 8, 3, 3, 2, 64};
    size_t arraySize = sizeof(array) / sizeof(int);

    cout << containsNumber(array, arraySize, 15);
}