#include <iostream>
using namespace std;

unsigned short findIndexOfNthElement(char *string, char simbol, unsigned short n, size_t startIndex)
{
    if (*string == '\0')
    {
        return 0;
    }

    if (*string == simbol)
    {
        n--;
        if (n == 0)
        {
            return startIndex;
        }
    }

    string++;
    startIndex++;
    return findIndexOfNthElement(string, simbol, n, startIndex);
}

int main()
{
    char string[] = "asd4tsjy6assasd";
    size_t nthSymbol, startIndex;

    cin >> nthSymbol >> startIndex;

    cout << findIndexOfNthElement(string, 's', nthSymbol, startIndex);
}