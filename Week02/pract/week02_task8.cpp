#include <iostream>
using namespace std;

int main()
{
    int tomatos, peppers, carrots, olives, patatos, flavors;
    bool hasFriend;

    cin >> tomatos >> peppers >> carrots >> olives >> patatos >> flavors >> hasFriend;

    if(tomatos >= 5 && peppers >= 6 && carrots >= 12 && olives >= 7 && patatos >= 12 && flavors >= 300 && hasFriend)
        cout << "Can make giuvech" << endl;
    else if (tomatos >= 2 && peppers >= 3 && carrots >= 5 && olives >= 6 && patatos >= 10 && flavors >= 200 && hasFriend)
        cout << "Can make soup" << endl;
    else if (tomatos >= 1 && peppers >= 2 && carrots >= 4 && olives >= 3 && patatos >= 3 && flavors >= 150)
        cout << "Can make salad" << endl;
    else
        cout << "Cant make anything" << endl;
        
}