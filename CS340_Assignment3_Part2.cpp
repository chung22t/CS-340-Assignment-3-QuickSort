// CS340_Assignment3_Part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
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
   the pivot element at its correct position in sorted array,
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


/* This function implements the quicksort algorithm
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


//This function prints the array
void PrintArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


//This is the main function
int main()
{
	int i = 0; 
	int n = 0;
	int * p;

	cout << "How many numbers would you like to sort (enter list size): ";
	cin >> i;
	p = new (nothrow) int[i];
	if (p == nullptr)
		cout << "ERROR";
	else
	{
		for (n = 0; n < i; n++)
		{
			cout << "Please enter number: ";
			cin >> p[n];
		}
		cout << "You have entered: ";
		for (n = 0; n < i; n++)
		{
			cout << p[n] << ", ";
		}
		cout << endl;

		QuickSort(p, 0, n - 1);
		cout << "Sorted List: ";
		PrintArray(p, n);

		delete[] p;
	}

	return 0;  //exit program
}

