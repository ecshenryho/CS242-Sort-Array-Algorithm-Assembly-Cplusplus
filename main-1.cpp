#include<iostream>
#include<stdio.h>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;

extern "C"
{
	void sortArray(int[], int,int);
}
void showArray(int[], int);
void sortBubbleUsingCplusplus(int array[], int size,int s);//function prototype
int main() {
	time_t t1, t2;
	int size;
	int order;
	//Prompt user to enter a size they want for the array
	cout << "Enter number elements of array: ";
	cin >> size;
	cout << "Enter 1 for descending order and 0 for ascending order: ";
	cin >> order;
	//Create an array with size user want and loaded randomly
	int *array = new int[size];//declare a dynamic array
	int *duplicateArray = new int[size];
	srand(time(NULL));//give a random seed at random seconds to help generate random number
					  //or can be used srand((unsigned)time(0))

	//Generate random number from 0 to 100
	for (int i = 0; i < size; i++)
	{
		array[i] = (rand() % 1000000 + 1);
	}

	//Display unsorted array elements in arraay
	
	if (size<20)
	{
		cout << "\nUnsorted array elements are: ";
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
	}
	if (size>20)
	{
		cout << "\nUnsorted array only first 20 elements are: ";
		for (int i = 0; i < 20; i++)
		{
			cout << array[i] << " ";
		}
	}
	cout << endl;
	//make a duplicate array to pass to c++ function, w
	for (int i = 0; i < size; i++)
	{
		duplicateArray[i] = array[i];
	}
	cout << endl;

	t1 = clock();//setting clock for recording time begin
	sortArray(array, size, order);//function call
	long int timeASM = clock() - t1;//calculate time running
	cout << "Time to execute function using ASM: " << timeASM << " milliseconds\n";
	showArray(array, size);

	cout << endl;

	t2 = clock();//setting clock for recording time begin
	sortBubbleUsingCplusplus(duplicateArray, size, order);//function call
	long int timeCfunction = clock() - t2;//calculate time running
	cout << "Time to execute function using c++fucntion: " << timeCfunction << " milliseconds\n";
	showArray(duplicateArray,size);

	system("pause");
	return 0;
}

void sortBubbleUsingCplusplus(int array[], int size,int s)
{
	int  temp;
	bool madeAswap;

	do
	{
		madeAswap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (s==0)//ascendin
			{
				if (array[count] > array[count + 1])
				{
					temp = array[count];
					array[count] = array[count + 1];
					array[count + 1] = temp;
					madeAswap = true;
				}
			}
			else
			{
				if (array[count] < array[count + 1])
				{
					temp = array[count];
					array[count] = array[count + 1];
					array[count + 1] = temp;
					madeAswap = true;
				}
			}
		}
	} while (madeAswap);  // Loop again if a swap occurred on this pass.
}
void showArray(int array[], int size) {
	if (size<20)
	{
		cout << "Array after sorted: ";
		for (size_t i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "Array after sorted showing only first 20 element: ";
		for (size_t i = 0; i < 20; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
}
