#include <iostream>
using namespace std;

int main()
{
    int inputNum;
    cin >> inputNum;
    bool b_middleReached = false;

    for(int i = 1; i <= inputNum*2+1; i++)
    {
        if(b_middleReached)
        {
            for(int j = 0; j < inputNum-(i-(inputNum+2)); j++)
            {
                cout << " ";
            }
            
            for(int j = 0; j < 2*(i-inputNum-1)+1; j++) // The same 2(n+1) example as below but i grows to input number, gives the number of stars on each row after the middle
            {
                cout << "*";
            }
            cout << endl;
        }
        else
        {
            for(int j = 0; j < i; j++)
            {
                cout << " ";
            }

            for(int j = 0; j < 2*(inputNum-(i-1))+1; j++) // inputNum-(i-1)" = n; is the input number lowering as i grows, 2(n+1) gives the number of stars on each row
            {
                cout << "*";
            }
            cout << endl;
        }

        b_middleReached = i/(inputNum+1);
    }
}