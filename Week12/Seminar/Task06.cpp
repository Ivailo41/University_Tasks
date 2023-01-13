#include <iostream>
using namespace std;

char findFirstCapitalLetter(char *string)
{
    if (*string == '\0')
    {
        return 0;
    }

    if (*string >= 'A' && *string <= 'Z')
    {
        return *string;
    }
    else
    {
        string++;
        return findFirstCapitalLetter(string);
    }
}

int main()
{
    char string[] = "asdFjbnsfkgG";

    cout << findFirstCapitalLetter(string);
}