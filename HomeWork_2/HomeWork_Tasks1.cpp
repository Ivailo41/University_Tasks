#include <iostream>
using namespace std;

const size_t START_MARKHOLDER_SIZE = 2;

void printDouble(double num)
{
    int value = (int)(num * 100 + .5);

    cout << value / 100 << '.' << value % 100 / 10 << value % 10;
}

void copyArray(double *toArray, double *fromArray, size_t fromSize)
{
    for (size_t i = 0; i < fromSize; i++)
    {
        toArray[i] = fromArray[i];
    }
}

void validateInput(double &mark)
{
    cout << "Enter valid mark: ";
    cin >> mark;

    while ((mark < 3.00 || mark > 6.00) && mark != 2.00 && mark != 0)
    {
        cout << " //Invalid mark, try again//" << endl;

        cout << "Enter valid mark: ";
        cin >> mark;
    }
}

void printMarks(double *array, size_t arraySize)
{
    cout << "Data: ";
    for (size_t i = 0; i < arraySize; i++)
    {
        printDouble(array[i]);
        cout << ' ';
    }
}

double *extendArrayFib(double *array, size_t &arraySize, size_t &previosSize)
{
    size_t tempSize = arraySize;
    arraySize = previosSize + arraySize;
    previosSize = tempSize;

    double *outputArray = new double[arraySize];

    copyArray(outputArray, array, previosSize);
    delete[] array;

    return outputArray;
}

double *createMarks(size_t &markHolderSize, size_t &markCount)
{
    size_t previosSize = 1;

    double currentMark;

    double *markHolder = new double[markHolderSize];

    while (true)
    {
        validateInput(currentMark);

        if (currentMark == 0)
            break;

        markCount++;

        if (markCount > markHolderSize)
        {
            markHolder = extendArrayFib(markHolder, markHolderSize, previosSize);
        }

        markHolder[markCount - 1] = currentMark;
    }

    return markHolder;
}

int main()
{
    size_t capacity = START_MARKHOLDER_SIZE;
    size_t markCount = 0;
    double *markHolder = createMarks(capacity, markCount);

    cout << "Size: " << markCount << endl;
    cout << "Capacity: " << capacity << endl;

    printMarks(markHolder, markCount);

    delete[] markHolder;
}
