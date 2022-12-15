#include <iostream>
using namespace std;

const size_t MAX_STRING_SIZE = 2048;
const size_t MAX_STRINGS = 1024;

void deleteDynamicArray(char **stringArr, size_t arrSize)
{
    for(int i = 0; i < arrSize; ++i) 
    {
        delete[] stringArr[i];   
    }

    delete[] stringArr;
}

void swapStrings(char **string1, char **string2)
{
    char *tempString = *string1;
    *string1 = *string2;
    *string2 = tempString;
}

void sortStringArray(char **stringArr, size_t arrSize)
{
    for (size_t i = 0; i < arrSize - 1; i++)
    {
        char **currentMin = &stringArr[i];

        for (size_t j = i; j < arrSize; j++)
        {
            if (*stringArr[j] < **currentMin)
            {
                currentMin = &stringArr[j];
            }
        }
        swapStrings(&stringArr[i], currentMin);
    }
}

void validateInput(size_t &inputValue, size_t maxValue)
{
    do
    {
        cout << "Please enter value below " << maxValue << " : ";
        cin >> inputValue;
    }
    while(inputValue > maxValue);
}

char *inputString()
{
    char *string = new char[MAX_STRING_SIZE];
    cin >> string;

    return string;
}

char **createStringArr(size_t stringsCount)
{
    char **stringArr = new char *[stringsCount];

    for (size_t i = 0; i < stringsCount; i++)
    {
        stringArr[i] = inputString();
    }
    
    return stringArr;
}

bool areStringEqual(char *string1, char *string2)
{
    if(string1 == nullptr || string2 == nullptr)
    {
        return false;
    }

    while(*string1 != '\0' || *string2 != '\0')
    {
        if(*string1 != *string2)
        return false;

        string1++;
        string2++;
    }
    return true;
}

bool containsElement(char **checkedArray, size_t arrSize, char *searchedElement)
{
    for (size_t i = 0; i < arrSize; i++)
    {
        if(areStringEqual(*(checkedArray + i), searchedElement))
            return true;
    }
    return false;  
}

size_t countWordsInArr(char **stringArr, size_t arrSize, char *lookedWord)
{
    size_t count = 0;
    for (size_t i = 0; i < arrSize; i++)
    {
        if(areStringEqual(*(stringArr + i), lookedWord))
        {
            count++;
        }
    }
    return count;  
}

void printDistinctArrElements(char **stringArr, size_t arrSize)
{
    char **distinctStringArr = new char *[arrSize];
    size_t distinctArrSize = 0;

    //Add each distinct element to separate array
    for (size_t i = 0; i < arrSize; i++)
    {
        if(!containsElement(distinctStringArr, arrSize, stringArr[i]))
        {
            distinctStringArr[distinctArrSize] = stringArr[i];
            distinctArrSize++;
        }
    }

    sortStringArray(distinctStringArr, distinctArrSize);

    for (size_t i = 0; i < distinctArrSize; i++)
    {
        cout << countWordsInArr(stringArr, arrSize, distinctStringArr[i]) << " - " << distinctStringArr[i] << endl;
    }

    deleteDynamicArray(distinctStringArr, distinctArrSize);
}

int main()
{
    size_t stringsCount;

    validateInput(stringsCount, MAX_STRINGS);

    char **stringArr = createStringArr(stringsCount);

    printDistinctArrElements(stringArr, stringsCount);

    deleteDynamicArray(stringArr, stringsCount);
}