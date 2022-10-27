#include <iostream>
#include <cmath>
using namespace std;


//task container
void zad1()
{
    int n;
    cin >> n;

    printPrimeNumsToRange(n);
}
//end of task container


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
    
}