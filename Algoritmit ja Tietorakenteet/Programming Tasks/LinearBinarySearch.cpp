// Programming Tasks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <random>

using std::cout;
using std::endl;
using std::cin;

int LinearSearch(int arr[], int size, int searchedNumber, bool printResult);
int BinarySearch(int arr[], int size, int searchedNumber, bool printResult);
void Task2A();
void Task2B();
void CallLinearSearch(int array[], int size, int searchNumber);
void CallBinarySearch(int array[], int size, int searchNumber);

int main()
{
    Task2A();
    Task2B();
}

void Task2A() //search a number from an array with both linear and binary search
{
    cout << "-----------------Task 2.1-----------------" << endl;

    int array[20] = { 1, 4, 6, 11, 13, 16, 19, 20, 25, 27, 29, 30, 32, 36, 39, 42, 45, 48, 49, 53 };
    int numberToSearch;

    cout << "Array = [1, 4, 6, 11, 13, 16, 19, 20, 25, 27, 29, 30, 32, 36, 39, 42, 45, 48, 49, 53]" << endl << endl;

    cout << "Please enter a number you want to search from the array: ";
    cin >> numberToSearch;
    cout << endl;

    cout << "LinearSearch result: " << endl;
    LinearSearch(array, 20, numberToSearch, true);

    cout << "BinarySearch result: " << endl;
    BinarySearch(array, 20, numberToSearch, true);
}

void Task2B() //measure the time it takes to search a specific number from arrays of different sizes using both linear and binary search
{
    std::random_device rd;
    std::mt19937 generator(rd());

    cout << "--------------------Task 2.2-------------------" << endl << endl;

    int* arr1 = new int[100000];
    int* arr2 = new int[1000000];
    int* arr3 = new int[10000000];

    int size1 = 100000;
    int size2 = 1000000;
    int size3 = 10000000;

    int numberToSearch;

    cout << "Setting up arrays" << endl;

    for (int i = 0; i < size1; i++)
    {
        arr1[i] = i;
    }

    for (int i = 0; i < size2; i++)
    {
        arr2[i] = i;
    }

    for (int i = 0; i < size3; i++)
    {
        arr3[i] = i;
    }

    cout << "Calling linear and binary search part 1" << endl;

    std::uniform_int_distribution<int> distribution1(0, size1 - 1);
    numberToSearch = distribution1(generator);
    CallLinearSearch(arr1, size1, numberToSearch);
    CallBinarySearch(arr1, size1, numberToSearch);
    cout << endl;

    cout << "calling linear and binary search part 2" << endl;

    std::uniform_int_distribution<int> distribution2(0, size2 - 1);
    numberToSearch = distribution2(generator);
    CallLinearSearch(arr2, size2, numberToSearch);
    CallBinarySearch(arr2, size2, numberToSearch);
    cout << endl;

    cout << "calling linear and binary search part 3" << endl;

    std::uniform_int_distribution<int> distribution3(0, size3 - 1);
    numberToSearch = distribution3(generator);
    CallLinearSearch(arr3, size3, numberToSearch);
    CallBinarySearch(arr3, size3, numberToSearch);
    cout << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}

void CallLinearSearch(int array[], int size, int searchNumber) //measures the time it takes for the 100 searches in task2B using linear search
{
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < 100; i++)
    {
        LinearSearch(array, size, searchNumber, false);
    }

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    cout << "Linear search duration for number " << searchNumber << " took: " << duration.count() << " microseconds" << endl;
}

void CallBinarySearch(int array[], int size, int searchNumber) //measures the time it takes for the 100 searches in task2B using binary search
{
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < 100; i++)
    {
        BinarySearch(array, size, searchNumber, false);
    }

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    cout << "Binary search duration for number " << searchNumber << " took: " << duration.count() << " microseconds" << endl;
}

int LinearSearch(int arr[], int size, int searchedNumber, bool printResult) //search a specific number from an array using linear search
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == searchedNumber)
        {
            if (printResult)
            {
                cout << "The number " << searchedNumber << " was found on index: " << i << endl << endl;
            }
            return i;
        }
    }
    if (printResult)
    {
        cout << "The number " << searchedNumber << " was not found in the array" << endl << endl;
    }
    return -1;
}

int BinarySearch(int arr[], int size, int searchedNumber, bool printResult) //search a specific number from an array using binary search
{
    int low = 0;
    int high = size - 1;
    int iterations = 0;

    while (low <= high)
    {
        iterations++;
        int mid = (low + high)/2;

        if (arr[mid] == searchedNumber)
        {
            if (printResult)
            {
                cout << "The number " << searchedNumber << " was found with " << iterations << " iteration and was located in index: " << mid << endl << endl;
            }
            return mid;
        }
        else if (arr[mid] < searchedNumber)
        {
            low = mid + 1;
            continue;
        }
        else if (arr[mid] > searchedNumber)
        {
            high = mid - 1;
            continue;
        }
    }

    if (printResult)
    {
        cout << "The number " << searchedNumber << " was not found in the array" << endl << endl;
    }
    return -1;
}

