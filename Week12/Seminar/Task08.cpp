#include <iostream>

using namespace std;

// Recursive function to generate all possible combinations of splitting the water
void splitWater(int water, int numBottles, int *combination, int curr)
{
    // If we have used up all the bottles, print the current combination if all of the water was used
    if (numBottles == 0)
    {
        if (water == 0)
        {
            for (int i = 0; i < curr; i++)
            {
                cout << combination[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    // Try filling the current bottle with all possible amounts of water
    for (int i = 0; i <= water; i++)
    {
        combination[curr] = i;
        splitWater(water - i, numBottles - 1, combination, curr + 1);
    }
}

int main()
{
    // Read in the amount of water and the number of bottles
    int water, numBottles;
    cout << "Enter the amount of water: ";
    cin >> water;
    cout << "Enter the number of bottles: ";
    cin >> numBottles;

    // Array to store the current combination of bottle sizes
    int *combination = new int[numBottles];

    // Generate all possible combinations
    splitWater(water, numBottles, combination, 0);

    delete[] combination;

    return 0;
}