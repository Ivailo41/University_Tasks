#include <iostream>
using namespace std;

bool recStringPalindromCheck(char *string, size_t stringSize, size_t startIndex)
{
    if (string[startIndex] != string[stringSize - 1])
    {
        return false;
    }

    if (stringSize == startIndex || stringSize == 0)
    {
        return true;
    }

    return recStringPalindromCheck(string, stringSize - 1, startIndex + 1);
}

bool isStringPalindrom(char *string, size_t stringSize)
{
    recStringPalindromCheck(string, stringSize, 0);
}

int main()
{
    char string[] = "asdffdsa";
    size_t stringSize = sizeof(string) - 1;

    cout << isStringPalindrom(string, stringSize);
}