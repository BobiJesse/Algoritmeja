// Programming tasks 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Task3A(int n);
void Task3B(int m, int n);
int ackermanFunction(int m, int n);

int main()
{
    int chosenNumber;
    cout << "Programming tasks 3" << endl << endl;
    cout << "------------------------------Fibonacci numbers-----------------------------------" << endl << endl;

    cout << "Please enter a (number) value for N : f(N) = f(N-1) + f(N-2)" << endl;
    cin >> chosenNumber;
    Task3A(chosenNumber);

    int ackermanNumber1;
    int ackermanNumber2;

    cout << "------------------------------Ackerman function------------------------------------" << endl << endl;

    cout << "Please enter two (number) values to be used in ackerman funciton" << endl;
    cout << "Number1: ";
    cin >> ackermanNumber1;

    cout << "Number2: ";
    cin >> ackermanNumber2;
    Task3B(ackermanNumber1, ackermanNumber2);
}

void Task3A(int n)
{

    int* fibonacciNumbers = new int[n + 1];

    fibonacciNumbers[0] = 1;
    fibonacciNumbers[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fibonacciNumbers[i] = fibonacciNumbers[i - 1] + fibonacciNumbers[i - 2];
    }

    cout << "With array: Fibonacci number f(" << n << ") = " << fibonacciNumbers[n] << endl;

    int previousNumber = 1;
    int currentNumber = 1;

    for (int i = 2; i <= n; i++)
    {
        int nextNumber = previousNumber + currentNumber;

        previousNumber = currentNumber;
        currentNumber = nextNumber;
    }

    cout << "Without array: Fibonacci number f(" << n << ") = " << currentNumber << endl << endl;
}

void Task3B(int m, int n)
{

    if (m < 0 || n < 0)
    {
        cout << "Please only enter positive whole numbers" << endl;
        return;
    }

    int result = ackermanFunction(m, n);

    cout << "Result is: " << result << endl;
}

int ackermanFunction(int m, int n)
{
    if (m == 0) //A(0,n) = n + 1
    {
        return n + 1;
    }

    else if (n == 0) //A(m,0) = A(m-1, 1)
    {
        return ackermanFunction(m - 1, 1);
    }

    else //A(m,n) = A(m-1, A(m, n-1))
    {
        return ackermanFunction(m - 1, ackermanFunction(m, n - 1));
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
