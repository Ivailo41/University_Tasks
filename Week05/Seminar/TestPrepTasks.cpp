#include <iostream>
#include <cmath>
using namespace std;

int timesContainingNum(int number, int lookedNum) // how many times a digit is contained in a num
{
    int counter = 0;
    while(number > 0)
    {
        if(number % 10 == lookedNum)
        counter++;

        number /= 10;
    }
    return counter;
}

int sortNumber(int num) // sorts the digit of a number
{
    int newNum = 0;

    for (size_t i = 1; i < 10; i++)
    {
        int numCount = timesContainingNum(num, i);

        while(numCount > 0)
        {
            (newNum *= 10) += i;
            numCount--;
        }
    }
    return newNum;
    
}

int reverseNum(int num) // reverses a number
{
    int reversedNum = 0;
    while(num > 0)
    {
        int lastDigid = num % 10;
        (reversedNum *= 10) += lastDigid;
        num /= 10;
    }
    return reversedNum;
}

bool isPalindrom(int number) // checks if a number is palindropm
{
    if(number == reverseNum(number))
    return true;
    
    return false;
}

int concatTwoNums(int firstNum, int secondNum) // combines 2 numbers like a string
{
    int reverseScndNum = reverseNum(secondNum);

    while (reverseScndNum > 0)
    {
        int lastDigit = reverseScndNum % 10;
        (firstNum *= 10) += lastDigit;
        reverseScndNum /= 10;
    }
    return firstNum;
}

bool isPrime(int num) //checks if a number is prime;
{
    if(num < 2)
    return false;

    int sqrtOfNum = sqrt(num);
    for(size_t i = 2; i <= sqrtOfNum; i++)
    {
        if(num % i == 0)
        return false;
    }

    return true;
}

void printPrimeInfxes(int num) //prints all infixes of number that are prime
{
    while(num > 0)
    {
        for (size_t i = 10; ; i *= 10)
        {
            int primeCandidate = num % i;

            if(isPrime(primeCandidate))
            cout << primeCandidate << " ";
            if(primeCandidate == num)
            break;
        }
        num /= 10;
    }
}

int main()
{
    printPrimeInfxes(1234);
}