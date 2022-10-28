#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
    int sqrtOfNum = sqrt(num);
    for(int i = 2; i < sqrtOfNum; i++)
    {
        if(num % i ==0)
        return false;
    }
    return true;
}

bool isSufix(int number, int sufix)
{

    if(sufix == 0)
    {
        if(number % 10 == 0)
        return true;
        else
        return false;
    }

    do
    {
        if(number%10 != sufix%10)
        return false;
        else
        number /= 10;
        sufix /= 10;
    }
    while(sufix > 0);

    return true;
}

int reverseNumber(int num)
{
    int result = 0;
    while(num > 0)
    {
        result *= 10;
        result += num % 10;
        num /= 10;
    }

    return result;
}

bool isPalindrom(int num)
{
    return num == reverseNumber(num);
}

void printPrimeNumsToRange(int range)
{
    int firstNum, secondNum;
    for(int i = 0; i <= range/6-1; i++)
    {
        firstNum = 6*i-1;
        secondNum = 6*i+1;

        if(firstNum > 1)
        {
            if(isPrime(firstNum) && isPrime(secondNum))
            cout << firstNum << " : " << secondNum << endl;
        }  
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    n = reverseNumber(n);
    k = reverseNumber(k);
    cout << boolalpha << isSufix(n,k);
}