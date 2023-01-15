#include <iostream>
#include <cmath>

using namespace std;

bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

int charToNum(char symbol)
{
    return symbol - '0';
}

bool isValidString(char *string)
{
    while (*string != '\0')
    {
        if ((*string < 'A' || *string > 'Z') && (*string < '0' || *string > '9') && (*string != '(' && *string != ')'))
        {
            return false;
        }
        string++;
    }

    return true;
}

char *validateInput()
{
    size_t stringSize;
    cout << "Enter number for expected string size" << endl;
    cin >> stringSize;

    char *string = new char[stringSize];
    do
    {
        cout << "Enter text containing only capital letters or number followed by brackets" << endl;
        cin >> string;
    } while (!isValidString(string));

    return string;
}

int getNumberFromString(char *string)
{
    int result = 0;
    while (isDigit(*string) && *string != '\0')
    {
        result *= 10;
        result += charToNum(*string);
        string++;
    }

    return result;
}

void printTextMultipleTimes(char *startPoint, unsigned short timesToPrint)
{
    for (size_t i = 0; i < timesToPrint; i++)
    {
        size_t j = 1;
        while (startPoint[j] != ')')
        {
            cout << startPoint[j++];
        }
    }
}

void decryptString(char *string)
{
    while (*string != '\0')
    {
        if (*string == ')')
        {
            string++;
            break;
        }

        if (*string >= 'A' && *string <= 'Z')
        {
            cout << *string;
        }

        else if (*string >= '0' && *string <= '9')
        {
            size_t timesRepeating = getNumberFromString(string);
            string++;

            for (size_t i = 0; i < timesRepeating; i++)
            {
                decryptString(string);
            }

            while (*string != ')')
            {
                string++;
            }
        }
        string++;
    }
}

int main()
{
    char *encoded = validateInput();

    decryptString(encoded);

    delete[] encoded;
}

// MAKE OWN FUNCTIONS TO REMOVE CSTRING