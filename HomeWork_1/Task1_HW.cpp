#include <iostream>
using namespace std;

const unsigned short NUMERIC_SYSTEM = 14;
const size_t MAX_DATE_STRING_SIZE = 8;
const size_t DATE_ARR_SIZE = 3;

bool isDateInputValid(char *inputString)
{
    size_t offset = 0;

    // Checks if the characters are within the numeric system characters and if the dots are misplaced
    while (inputString[offset] != '\0')
    {
        if (inputString[offset] < 'a' || inputString[offset] > 'm')
        {
            if (!(offset % 2) || inputString[offset] != '.')
                return false;
        }
        offset++;
    }

    return true;
}

char *createString()
{
    char *dateString = new char[MAX_DATE_STRING_SIZE];

    do
    {
        cout << "Enter valid date format in 14-ary numeric system" << endl;
        cin >> dateString;
    } while (!isDateInputValid(dateString));

    return dateString;
}

size_t strLen(char *string)
{
    if (string == nullptr)
        return 0;

    size_t length = 0;

    while (*string != '\0')
    {
        length++;
        string++;
    }

    return length;
}

unsigned short getIndexOfSymbol(char ch)
{
    if (ch == '0')
    {
        return 0;
    }
    else if (ch >= 'a' && ch <= 'm')
    {
        return 1 + (ch - 'a');
    }
    else
    {
        return -1;
    }
}

char getSymbolByIndex(unsigned short index)
{
    if (index == 0)
    {
        return '0';
    }
    else if (index >= 1 && index <= 14)
    {
        return (index - 1) + 'a';
    }
    else
    {
        return 0;
    }
}

unsigned int randomToDecimal(const char *from, size_t fromSize, unsigned short numSystem)
{
    unsigned int decimalNum = 0;

    for (int i = fromSize - 1, multiplier = 1; i >= 0; i--, multiplier *= numSystem)
    {
        decimalNum += getIndexOfSymbol(from[i]) * multiplier;
    }
    return decimalNum;
}

char *decimalToRandom(unsigned int decimalNum, unsigned short k)
{
    const size_t MAX_TEMP_SIZE = 100;
    char tempConvertedNumString[MAX_TEMP_SIZE];

    size_t stringSize = 0;
    while (decimalNum != 0)
    {
        tempConvertedNumString[stringSize] = getSymbolByIndex(decimalNum % k);
        decimalNum /= k;
        stringSize++;
    }

    char *convertedNumString = new char[stringSize + 1]; // + 1 for the ending zero
    convertedNumString[stringSize] = '\0';

    for (int i = stringSize - 1, j = 0; i >= 0; i--, j++)
    {
        convertedNumString[i] = tempConvertedNumString[j];
    }

    return convertedNumString;
}

unsigned short getDayOfTheWeek(unsigned short year, unsigned short month, unsigned short day)
{
    // The corresponding month starts with this much days after january 1st's day.
    unsigned short daysOffset[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;

    // The math behind calculating which day it is.
    return (year + year / 4 - year / 100 + year / 400 + daysOffset[month - 1] + day) % 7;
}

bool isWeekendDay(unsigned short dayNumber)
{
    return dayNumber < 5;
}

void printIsWeekendDay(unsigned short day, unsigned short month, unsigned short year)
{
    if (isWeekendDay(getDayOfTheWeek(year, month, day)))
    {
        cout << "No, " << day << "." << month << "." << year << " is a working day" << endl;
    }
    else
    {
        cout << "Yes, " << day << "." << month << "." << year << " isn't a working day" << endl;
    }
}

void splitString(const char *fromString, char toArray[DATE_ARR_SIZE][MAX_DATE_STRING_SIZE], char splitter)
{
    int currentRow = 0;
    char *currentSymbPtr = *toArray;

    while (*fromString != '\0')
    {
        if (*fromString == splitter)
        {
            *currentSymbPtr = '\0';
            currentRow++;
            currentSymbPtr = *(toArray + currentRow);
        }
        else
        {
            *currentSymbPtr = *fromString;
            *currentSymbPtr++;
        }
        fromString++;
    }
    *currentSymbPtr = '\0';
}

void translateDate(char *dateString)
{
    char dateArray[DATE_ARR_SIZE][MAX_DATE_STRING_SIZE];

    splitString(dateString, dateArray, '.');

    unsigned short day = randomToDecimal(dateArray[0], strLen(dateArray[0]), NUMERIC_SYSTEM);
    unsigned short month = randomToDecimal(dateArray[1], strLen(dateArray[1]), NUMERIC_SYSTEM);
    unsigned short year = randomToDecimal(dateArray[2], strLen(dateArray[2]), NUMERIC_SYSTEM);

    printIsWeekendDay(day, month, year);
}

int main()
{
    char *dateString = createString();

    int decNum;
    cout << "Enter decimal number: " << endl;
    cin >> decNum;

    translateDate(dateString);

    char *convertedDecNum = decimalToRandom(decNum, NUMERIC_SYSTEM);
    cout << convertedDecNum;

    delete[] dateString;
}