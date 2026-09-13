// Programming Tasks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
using std::cout;
using std::endl;
using std::cin;

int LinearSearch(int arr[], int size, int searchedNumber);
int BinarySearch(int arr[], int size, int searchedNumber);
void Task2A();
void Task2B();

int main()
{
    Task2A();
    Task2B();
}

void Task2A()
{
    cout << "Task 2.1" << endl;

    int array[20] = { 1, 4, 6, 11, 13, 16, 19, 20, 25, 27, 29, 30, 32, 36, 39, 42, 45, 48, 49, 53 };
    int numberToSearch;

    cout << "Array = [1, 4, 6, 11, 13, 16, 19, 20, 25, 27, 29, 30, 32, 36, 39, 42, 45, 48, 49, 53]" << endl << endl;

    cout << "Please enter a number you want to search from the array: ";
    cin >> numberToSearch;
    cout << endl;

    cout << "LinearSearch result: " << endl;
    LinearSearch(array, 20, numberToSearch);

    cout << "BinarySearch result: " << endl;
    BinarySearch(array, 20, numberToSearch);
}

void Task2B()
{

}

int LinearSearch(int arr[], int size, int searchedNumber)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == searchedNumber)
        {
            cout << "The number " << searchedNumber << " was found on index: " << i << endl << endl;
            return i;
        }
    }

    cout << "The number " << searchedNumber << " was not found in the array" << endl << endl;
    return -1;
}

int BinarySearch(int arr[], int size, int searchedNumber)
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
            cout << "The number " << searchedNumber << " was found with " << iterations << " iteration and was located in index: " << mid << endl << endl;
            return mid;
            break;
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

    cout << "The number " << searchedNumber << " was not found in the array" << endl << endl;
    return -1;
}

