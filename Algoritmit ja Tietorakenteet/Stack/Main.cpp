#include <iostream>
#include "Stack.h"
#include <cstdio>
#include <string>

//Index.html and Index2.html are found inside the Stack project folder

bool IsVoidElement(std::string tag) //Checks for the void elements
{
	if (tag == "area" || tag == "base" || tag == "br" ||
		tag == "col" || tag == "embed" || tag == "hr" ||
		tag == "img" || tag == "input" || tag == "link" ||
		tag == "meta" || tag == "param" || tag == "source" ||
		tag == "track" || tag == "wbr")
	{
		return true;
	}

	return false;
}

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

		int c;

		while ((c = std::fgetc(fp)) != EOF) //true until the file ends
		{
			if (c != '<') //Skip characters that are not '<'
			{
				continue;
			}

			std::string tag; //Variable to store tag names

			while ((c = std::fgetc(fp)) != EOF && c != '>') //true as long as '>' appears or the file ends
			{
				tag += static_cast<char>(c);
			}

			size_t space = tag.find_first_of(" \t\r\n"); //Search for the first space, tab or newline

			if (space != std::string::npos) //if found space, tab or newline
			{
				tag.erase(space); //remove everything after space
			}

			//std::cout << "Found tag: " << tag << std::endl;

			if (tag[0] == '/') //check the first char of the tag for the '/' character
			{
				tag.erase(0, 1); //remove '/' for the comparison

				if (!tags.IsEmpty()) //check the stack so its not empty before comparing
				{
					if (tag == tags.Top()) //Compare tag with the top of the stack
					{
						std::cout << "Tag " << tags.Top() << " removed from stack" << std::endl;
						tags.Pop(); //Remove the top of the stack
					}
					else
					{
						std::cout << "Error: tag not same as stack.Top " << tag << std::endl;
					}
				}
				else
				{
					std::cout << "Error: closing tag detected with empty stack " << tag << std::endl;
				}
			}
			else
			{
				if (!IsVoidElement(tag)) //Check for void element tags
				{
					tags.Push(tag); //add tag to the stack
					std::cout << "Tag " << tag << " Pushed to stack" << std::endl;
				}
			}
		}
		std::cout << std::endl;

		if (!tags.IsEmpty()) //Check if there are nodes in the stack after going through the file
		{
			std::cout << "Error: some tags were not closed!" << std::endl;
		}
		else
		{
			std::cout << "All tags Cleared from stack" << std::endl;
		}

		std::fclose(fp); //Remember to close the file!
		return EXIT_SUCCESS;
	}

	//Classroom code
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