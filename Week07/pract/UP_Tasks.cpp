#include <iostream>
using namespace std;

void swapWithRef(int &a, int &b) 
{
	int temp = a;
	a = b;
	b = temp;
}

void swapWithPtr(int *a, int *b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//END OF TASK 0

void reverseArr(int arr[], const int arrSize) 
{
	int* slapElement = arr + arrSize - 1;

	while (arr < slapElement) 
	{
		swapWithPtr(arr, slapElement);
		arr++;
		slapElement--;
	}
}
//END OF TASK 1

void printArr(int arr[], const int arrSize) 
{
	for (size_t i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " ";
	}
}

int *searchElementInArr(int searchElement, int arr[], const int arrSize) 
{
	int *result(0);
	for (size_t i = 0; i < arrSize; i++)
	{
		if (arr[i] == searchElement)
		{
			result = arr + i;
			return result;
		}	
	}

	return result;
}
//END OF TASK 2

int arrSum(const int arr[], const int arrSize) 
{
	int sum = 0;
	for (size_t i = 0; i < arrSize; i++)
	{
		sum += arr[i];
	}
	return sum;
}

void ptrToArrWithMinSum(int firstArr[], int firstArrSize, int secondArr[], int secondArrSize, int **ptr)
{
	int firstArraySum = arrSum(firstArr, firstArrSize);
	int secondArraySum = arrSum(secondArr, secondArrSize);

	if (firstArraySum < secondArraySum) 
	{
		*ptr = firstArr;
	}
	else 
	{
		*ptr = secondArr;
	}
}
//END OF TASK 4

int main() 
{
	const int FIRST_ARR_SIZE = 4;
	const int SECOND_ARR_SIZE = 3;
	int firstArr[FIRST_ARR_SIZE] = { 1,7,3,5 };
	int secondArr[SECOND_ARR_SIZE] = { 6,2,4 };
	int* arrMin;

	ptrToArrWithMinSum(firstArr, FIRST_ARR_SIZE, secondArr, SECOND_ARR_SIZE, &arrMin);
}