// Programming tasks 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
#include <chrono>
#include <cstdlib>
using std::cout;
using std::endl;

void SimpleSort(float numbers[], int n);

int main()
{
    int n1 = 100000;
    int n2 = 1000000;
    int n3 = 10000000;

    float* numbers1 = new float[n1];
    float* numbers2 = new float[n2];
    float* numbers3 = new float[n3];

    SimpleSort(numbers1, n1); //13400ms completion
    SimpleSort(numbers2, n2); //760435ms completion
    SimpleSort(numbers3, n3); //En jaksanut odottaa 20 tuntia että valmistuu :( jos aika nousee n^2 mukaan

    delete[] numbers1;
    delete[] numbers2;
    delete[] numbers3;
}

void SimpleSort(float numbers[], int n)
{

    for (int i = 0; i < n; i++) //arrayn alustukset arvoilla
    {
        numbers[i] = static_cast<float>(std::rand());
    }

    auto start = std::chrono::high_resolution_clock::now(); //kellon aloitusaika

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (numbers[i] < numbers[j])
            {
                std::swap(numbers[j], numbers[i]);
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now(); //kellon lopetusaika

    std::chrono::duration<double, std::milli> elapsed = end - start; //aikojen erotus

    cout << "Array size: " << n << endl;
    cout << "Time: " << elapsed.count() << " ms" << endl;
}