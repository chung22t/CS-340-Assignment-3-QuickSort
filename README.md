//# CS-340-Assignment-3-QuickSort

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

//function to swap two elements
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


/* This function takes the last element as pivot, places
   the pivot element at its corretn position in sorted array,
   and places all smaller than pivot to the left of pivot and
   all greater elements to right of pivot
   */
int Partition(int arr[], int low, int high)
{
	int pivot = arr[high];  //pivot
	int i = (low - 1);  //index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		//if curent element is smaller than or equal to pivot
		if (arr[j] <= pivot)
		{
			i++;  //increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);

	return (i + 1);
}


/* The main function hat implements QuickSort
   arr[] ---> Array to be sorted
   low   ---> Starting index
   high  ---> Ending index
   */
void QuickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int Partition_Index = Partition(arr, low, high);

		//separatley sort elements before
		//partition and after partition
		QuickSort(arr, low, Partition_Index - 1);
		QuickSort(arr, Partition_Index + 1, high);
	}
}


//print function
void PrintArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main()
{
	int i, n;
	int * p;

	cout << "How many numbers would you like to type? ";
	cin >> i;
	p = new (nothrow) int[i];
	if (p == nullptr)
		cout << "Error: memory could not be allocated";
	else
	{
		for (n = 0; n < i; n++)
		{
			cout << "Enter number: ";
			cin >> p[n];
		}
		cout << "You have entered: ";
		for (n = 0; n < i; n++)
		{
			cout << p[n] << ", ";
		}

		QuickSort(p, 0, n - 1);
		cout << "Sorted array: ";
		PrintArray(p, n);
		delete[] p;
	}


	/*
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	QuickSort(arr, 0, n - 1);
	cout << "Sorted array: ";
	PrintArray(arr, n);

	cout << endl;*/
	return 0;
}
