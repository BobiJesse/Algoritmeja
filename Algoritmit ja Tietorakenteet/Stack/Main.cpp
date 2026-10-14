#include <iostream>
#include "Stack.h"
#include <cstdio>
#include <string>

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

		std::cout << "File opened successfully!" << std::endl;
		Stack<std::string> tags;

		//Now start reading the file one character at a time
		/*char c;
		while ((c = std::fgetc(fp)) != EOF)
		{
			std::cout << c;
		}*/

		int c;

		while ((c = std::fgetc(fp)) != EOF)
		{
			if (c != '<')
			{
				continue;
			}

			std::string tag;

			while ((c = std::fgetc(fp)) != EOF && c != '>')
			{
				tag += static_cast<char>(c);
			}

			//std::cout << "Found tag: " << tag << std::endl;

			if (tag[0] == '/')
			{
				std::cout << "Closing tag is: " << tag << std::endl;
				tag.erase(0, 1);

				if (!tags.IsEmpty())
				{
					if (tag == tags.Top())
					{
						tags.Pop();
					}
					else
					{
						std::cout << "Error: mismatched tag: " << tag << std::endl;
					}
				}
				else
				{
					std::cout << "Error: closing tag without opening tag: " << tag << std::endl;
				}
			}
			else
			{
				tags.Push(tag);
				std::cout << "Opening tag is: " << tag << std::endl;
			}
		}
		std::cout << std::endl;

		if (!tags.IsEmpty())
		{
			std::cout << "Error: some tags were not closed!" << std::endl;
		}
		std::fclose(fp); //Remember to close the file!
		return EXIT_SUCCESS;
	}


	/*Stack<int> s;

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

	return EXIT_SUCCESS;*/
}