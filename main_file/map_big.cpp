#include "../container_tester.hpp"
#include <cassert>
#include <iostream>

void printMapContainer(ACCESS::map<std::string, int> const & cont)
{
	for (ACCESS::map<std::string, int>::const_iterator it = cont.begin(); it != cont.end(); it++)
		std::cout << "[" << it->first << "][" << it->second << "] | ";
	std::cout << std::endl;
}
void execNonConst(ACCESS::map<std::string, int> & cont)
{
	ACCESS::map<std::string, int> tmp = cont;

	ACCESS::map<std::string, int>::value_type* x = new ACCESS::map<std::string, int>::value_type();

	tmp.insert(tmp.begin(), *x);
	printMapContainer(tmp);

	if (cont.size())
	{
		ACCESS::map<std::string, int> tmp2 = cont;
		tmp2.insert(--tmp2.end(), *x);
		printMapContainer(tmp2);
	}
	if (cont.size() >= 2)
	{
		ACCESS::map<std::string, int> tmp3(++cont.begin(), cont.end());
		tmp3.insert(--tmp3.end(), *cont.begin());
		printMapContainer(tmp3);
	}
	delete x;
}

int main()
{
	 const int arrInt[20] = {58966, 2147483647, 256, -2147483648, 0, 
                            -1, 2, 3, 4, 5, 6, 7, 7, 8, 54634152, 9, 
                            10, 11, 56, 56465};

    const std::string arrString[20] = {"hello coco", "j'arrive", "oui-oui", "kafeolait", 
                                        "jul d'ananas", "jul d'ananas", "42", "jura", 
                                        "saperlipopette", "anticonstitutionnellement", 
                                        "Pneumonoultramicroscopicsilicovolcanoconiosis", "Blue", 
                                        "Red", "Orange", "Yellow", "boulette de viande hache",
                                        "raviolis du nord est", "PNY", "street bangkok", "confifi"};
	ACCESS::map<std::string, int> c0;
	for (int i = 0; i < 10; i++)
	{
		ACCESS::pair<std::string, int> pair(arrString[i], arrInt[i]);
		c0.insert(pair);
		execNonConst(c0);
	}
	ACCESS::pair<std::string, int> pair1 = ACCESS::make_pair(arrString[19], arrInt[19]);
	ACCESS::pair<std::string, int> pair2 = ACCESS::make_pair(arrString[1], arrInt[14]);
	ACCESS::map<std::string, int> cont(c0);
	cont.insert(pair1);
	cont.insert(pair2);
	ACCESS::map<std::string, int> tmp = cont;
	ACCESS::map<std::string, int>::value_type* x = new ACCESS::map<std::string, int>::value_type();

	if (cont.size())
	{
		std::cout << "return value (testing boolean): " << tmp.insert(*(tmp.begin())).second << std::endl;
		ACCESS::map<std::string, int>::value_type pa(tmp.begin()->first, tmp.begin()->second);
		tmp.erase(tmp.begin());
		std::cout << "return value (testing iterator, the mapped content): " << tmp.insert(pa).first->second << std::endl;
	}

	std::cout << "return value (testing iterator, the key): " << (tmp.insert(*x)).first->first << std::endl;

	std::cout << "size of tmp = " << tmp.size() << std::endl;
	printMapContainer(tmp);

	delete x;   

	if (cont.size())
	{
		if (tmp.equal_range(tmp.begin()->first).first != tmp.end())
		{
			std::cout << "return value: " << tmp.equal_range(tmp.begin()->first).first->first;
			if (tmp.equal_range(tmp.begin()->first).second != tmp.end())
			{
				std::cout << "return value: " << tmp.equal_range(tmp.begin()->first).second->first;
			}
		}
	}

	// Return range of iterator of last elem
	if (cont.size())
	{   
		std::cout << "----- iterator of end -----";

		ACCESS::map<std::string, int> tmp = cont;   std::cout << "size of tmp = " << tmp.size();
		printMapContainer(tmp);

		if (tmp.equal_range(tmp.begin()->first).first != tmp.end())
		{
			std::cout << "return value: " << tmp.equal_range(tmp.begin()->first).first->first;

			if (tmp.equal_range(tmp.begin()->first).second != tmp.end())
			{
				std::cout << "return value: " << tmp.equal_range(tmp.begin()->first).second->first;
			}
		}
	}

	// Return range of iterator of second elem
	if (cont.size() > 1)
	{   std::cout << "----- iterator to third elem -----";
		ACCESS::map<std::string, int> tmp = cont;   std::cout << "size of tmp = " << tmp.size();
		printMapContainer(tmp);

		if (tmp.equal_range(tmp.begin()->first).first != tmp.end())
		{

			std::cout << "return value: " << tmp.equal_range(tmp.begin()->first).first->first;

			if (tmp.equal_range(tmp.begin()->first).second != tmp.end())
			{
	
				std::cout << "return value: " << tmp.equal_range(tmp.begin()->first).second->first;
			}
		}
	}

	// Return range of iterator just after a key value-initialized
	{   std::cout << "----- iterator just after a key value-initialized -----";

		ACCESS::map<std::string, int> tmp = cont;   std::cout << "size of tmp = " << tmp.size();
		printMapContainer(tmp);

		if (tmp.equal_range(tmp.begin()->first).first != tmp.end())
		{

			std::cout << "return value: " << tmp.equal_range(tmp.begin()->first).first->first;

			if (tmp.equal_range(tmp.begin()->first).second != tmp.end())
			{
	
				std::cout << "return value: " << tmp.equal_range(tmp.begin()->first).second->first;
			}
		}
	}
}