#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
	std::fstream file("header.txt", std::fstream::in);
	std::stringstream ss;
	std::string buffer;
	std::vector <std::string> tab;
	ss << file.rdbuf();
	std::fstream out("container_tester.hpp", std::fstream::out);

	for(int i = 0; std::getline(ss, buffer); i++)
	{
		tab.push_back(buffer);
		tab[i].insert(0, "#include \"");
		tab[i].append("\"");
		out << tab[i] << std::endl;
	}
}