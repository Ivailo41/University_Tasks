#include <iostream>
using namespace std;

void flipBits(int &num)
{
	num = ~num;
}

int decToBin(int num) 
{
	int result = 0;
	int multiply = 1;

	while (num > 0) 
	{
		result += (num % 2) * multiply;
		multiply *= 10;
		num /= 2;
	}
	return result;
}

int binToDec(int num)
{
	int result = 0;
	int multiplier = 1;
	while(num > 0)
	{
		result += (num % 2) * multiplier;
		multiplier *= 2;
		num /= 10;
	}

	return result;
}

int binNumCount(int num)
{
	int binNum = decToBin(num);
	int binNumCount = 0;

	while(binNum > 0)
	{
		binNumCount++;
		binNum /= 10;
	}

	return binNumCount;
}

int getUniqueNumInArr(int arr[], int arrSize) 
{
	int result = arr[0];
	for (size_t i = 1; i < arrSize; i++)
	{
		result = result ^ arr[i];
	}

	return result;
}

int countOnes(int num) 
{
	int numInBin = decToBin(num);
	int count = 0;

	while (numInBin > 0) 
	{
		if (numInBin % 10 == 1)
			count++;
		numInBin /= 10;
	}

	return count;
}

void flipLastOnBit(int &num) 
{
	int bitFlipper = 1;
	while(!(num & bitFlipper))
	{
		bitFlipper = bitFlipper << 1;
	}
	num = num ^ bitFlipper;
}

int getLastBitsOfNum(int num, int lastBitsCount)
{
	int binNum = decToBin(num);
	int multiplier = 1;
	int result = 0;

	while (lastBitsCount > 0)
	{
		result += (binNum % 10) * multiplier;
		binNum /=10;
		multiplier *= 10;
		lastBitsCount--;
	}
	return binToDec(result);
	
}

bool isBinSufix(int num, int sfxNum)
{
	return decToBin(getLastBitsOfNum(num ,binNumCount(sfxNum))) == decToBin(sfxNum);
}

int main() 
{
	int arr[] = { 1,2,1,2,3,3,5,4,5 };
	const int ARR_LEN = sizeof(arr) / sizeof(int);

	int num = 14; //1100

	cout << isBinSufix(13,7);
}