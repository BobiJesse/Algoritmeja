#include <algorithm>
#include <iostream>
#include <chrono>
#include <cstdlib>

void ShellSort(int arr[], int size);
void MergeSort(int arr[], int left, int right);
void Merge(int arr[], int left, int middle, int right);

void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

void FillArray(int arr[], int size, int type)
{
    for (int i = 0; i < size; i++)
    {
        if (type == 0) // Ordered
        {
            arr[i] = i;
        }
        else if (type == 1) // Reversed
        {
            arr[i] = size - i;
        }
        else // Random
        {
            arr[i] = rand() % 1001;
        }
    }
}

void MeasureSort(int arr[], int size, int type)
{
    auto start = std::chrono::high_resolution_clock::now();

    if (type == 0)
        ShellSort(arr, size);
    else if (type == 1)
        MergeSort(arr, 0, size - 1);
    else
        std::sort(arr, arr + size);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;

    double timePerItem = elapsed.count() / size;

    std::cout << "Time: " << elapsed.count() << " ms" << std::endl;
    std::cout << "Time per item: " << timePerItem << " ms" << std::endl;
}

int main()
{
    std::cout << "=========================Programming Task 9A=======================" << std::endl << std::endl;


    const int Size = 8;

    int shellArray[Size] = { 38, 12, 27, 43, 9, 31, 18, 25 };
    int mergeArray[Size] = { 38, 12, 27, 43, 9, 31, 18, 25 };
    int standardArray[Size] = { 38, 12, 27, 43, 9, 31, 18, 25 };

    std::cout << std::endl << "Printing array" << std::endl;
    PrintArray(shellArray, Size);

    //Shell sorting
    ShellSort(shellArray, Size);
    std::cout << std::endl << "Shell Sorted array: " << std::endl;
    PrintArray(shellArray, Size);

    //Merge sorting
    MergeSort(mergeArray, 0, Size - 1);
    std::cout << std::endl << "Merge Sort:" << std::endl;
    PrintArray(mergeArray, Size);

    //std::sorting
    std::sort(standardArray, standardArray + Size);
    std::cout << std::endl << "std::sort():" << std::endl;
    PrintArray(standardArray, Size);

    std::cout << "=========================Programming Task 9B=======================" << std::endl;

    int Size1 = 100;
    int Size2 = 10000;
    int Size3 = 1000000;

    int sizes[] = { Size1, Size2, Size3 };


    for (int s = 0; s < 3; s++)
    {
        int size = sizes[s];

        std::cout << std::endl << "==============================================ARRAY SIZE: " << size << std::endl;


        int* shellArray = new int[size];
        int* mergeArray = new int[size];
        int* sortArray = new int[size];


        for (int order = 0; order < 3; order++)
        {
            if (order == 0)
                std::cout << std::endl << "=======ORDERED ARRAY=======" << std::endl;
            else if (order == 1)
                std::cout << std::endl << "=======REVERSED ARRAY=======" << std::endl;
            else
                std::cout << std::endl << "=======RANDOM ARRAY=======" << std::endl;

            FillArray(shellArray, size, order);

            for (int i = 0; i < size; i++)
            {
                mergeArray[i] = shellArray[i];
                sortArray[i] = shellArray[i];
            }

            //Shell sorting
            std::cout << "\nShell Sort:\n";
            MeasureSort(shellArray, size, 0);

            //Merge sorting
            std::cout << "\nMerge Sort:\n";
            MeasureSort(mergeArray, size, 1);

            //std::sorting
            std::cout << "\nstd::sort():\n";
            MeasureSort(sortArray, size, 2);
        }


        delete[] shellArray;
        delete[] mergeArray;
        delete[] sortArray;
    }

    return 0;
}

void ShellSort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void Merge(int arr[], int left, int middle, int right)
{
    int size1 = middle - left + 1;
    int size2 = right - middle;

    int* leftArray = new int[size1];
    int* rightArray = new int[size2];


    for (int i = 0; i < size1; i++)
        leftArray[i] = arr[left + i];

    for (int i = 0; i < size2; i++)
        rightArray[i] = arr[middle + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;


    while (i < size1 && j < size2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }

        k++;
    }


    while (i < size1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        MergeSort(arr, left, middle);
        MergeSort(arr, middle + 1, right);

        Merge(arr, left, middle, right);
    }
}
