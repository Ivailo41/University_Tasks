#include <iostream>
using namespace std;

bool isPrefix(char *string, char *patern)
{
    if (*patern == '\0')
    {
        return true;
    }

    return *string == *patern && isPrefix(string + 1, patern + 1);
}

bool isSubstring(char *string, char *patern)
{
    if (*string == '\0')
    {
        return *patern == '\0';
    }

    return isPrefix(string, patern) || isSubstring(string + 1, patern);
}

int main()
{
    char string[] = "Hello world!";
    char patern[] = "world";
    cout << isSubstring(string, patern);
}
