#include <string>
#include <iostream>

bool get_input(std::string& a)
{
	a.clear();
	std::cout << "\n==> ";
	std::getline(std::cin, a);
	return !(a.empty());
}

int main()
{
	std::string input;
	std::cout << "Entry" << std::endl;

	while(get_input(input)) {}

	std::cout << "Exit" << std::endl;

	return 0;
}