#include <iostream>
#include "Stack.h"
#include <cstdio>

int main(int argc, char** argv)
{
	//Check amount of parameters (argc)
	if (argc < 2)
	{
		std::cout << "Not enough arguments! You called: " << argv[0] << std::endl;
		return EXIT_FAILURE;
	}
	else
	{
		std::cout << "OK, You called: " << argv[0] << " " << argv[1] << std::endl;
		FILE* fp = NULL;
		errno_t error = fopen_s(&fp, argv[1], "r");
		if (fp == NULL)
		{
			std::cout << "Error opening file: " << argv[1] << std::endl;
			return EXIT_FAILURE;
		}
		//Now start reading the file one character at a time
		while (char c = std::fgetc(fp) != NULL)
		{
			std::cout << c;
		}
		std::cout << std::endl;

		std::fclose(fp); //Remember to close the file!
		return EXIT_SUCCESS;
	}

	Stack<int> s;

	for (int i = 0; i < 10; i++)
	{
		s.Push(i);
		std::cout << s.Top() << std::endl;
	}

	std::cout << "---------------------------------" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		int value = s.Pop();
		std::cout << value << std::endl;
	}

	return EXIT_SUCCESS;
}