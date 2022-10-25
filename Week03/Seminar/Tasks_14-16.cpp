#include <iostream>
using namespace std;

void task14();
void task15();
void task16();

int main()
{
    task16();
}

void task14()
{
    int a, b, result;
    cin >> a >> b;

    result = 0;

    if(a > b)
    {
        cout << 0 << endl;
        return;
    }

    while(a <= b)
    {
        int currentA = a;
        int sum = 0;
        int multiplication = 1;

        while(currentA > 1)
        {
            sum += currentA%10;
            multiplication *= currentA%10;
            currentA /=10;
        }

        if(sum == multiplication)
        result++;

        a++;
    }

    cout << result << endl;
}

void task15()
{
    int base, argument, baseFirstVal;
    int exponent = 0;
    cin >> argument >> base;

    baseFirstVal = base;

    while(base <= argument)
    {
        base *= baseFirstVal;
        exponent++;
    }

    cout << exponent << endl;

}

void task16()
{
    int n,k;
    bool isInfix = false;
    cin >> n >> k;

    int kTemp = k;
    int nTemp = n;

    while(k == 0)
    {
        cout << "k cant be 0" << endl;
        cin >> k;
    }

    while(n >= 1)
    {
        while(nTemp%10 == kTemp%10)
        {
            if(kTemp < 10)
            {
                isInfix = true;
                break;
            }
            else
            {
                nTemp /= 10;
                kTemp /= 10;
            }

        }
         n /= 10;
         nTemp = n;
         kTemp = k;
    }

    cout << boolalpha << isInfix;
}