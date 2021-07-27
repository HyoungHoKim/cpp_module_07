#include <iostream>
#include "Array.hpp"

#define MAX_VAL 5
int main(int, char**)
{
	std::cout << "------ Check Array[0] data ------" << std::endl;
	Array<int> zero;
	std::cout << &zero << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

	std::cout << "------ Check MyArray data ------" << std::endl;
	for (size_t i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << "\n";
	std::cout << "------ Check IntArray data ------" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
		std::cout << mirror[i] << " ";
	std::cout << "\n";

    //SCOPE
    {
        Array<int> tmp = numbers;
		std::cout << "------ Check =operator data ------" << std::endl;
		for (size_t i = 0; i < tmp.size(); i++)
			std::cout << tmp[i] << " ";
		std::cout << "\n";
        Array<int> test(tmp);
		std::cout << "------ Check Copy Constructor data ------" << std::endl;
		for (size_t i = 0; i < test.size(); i++)
			std::cout << test[i] << " ";
		std::cout << "\n";
    }

	std::cout << "------ Check Deep Copy ------" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

	std::cout << "------ Check Out of Range Exception ------" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	std::cout << "------ Check []operator data ------" << std::endl;
	for (size_t i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << "\n";

	std::cout << "------ Check zero allocate data ------" << std::endl;
	Array<int> *test = new Array<int>(0);
	*test = numbers;
	delete test;
    delete[] mirror;
	system("leaks ex02");
    return 0;
}