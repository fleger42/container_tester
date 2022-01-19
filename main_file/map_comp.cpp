#include "../container_tester.hpp"
#include <cassert>
#include <iostream>
#include <map>

struct ModCmp {
    bool operator()(const int lhs, const int rhs) const
    {
        return (lhs % 97) < (rhs % 97);
    }
};
 
int main()
{
    ACCESS::map<int, char, ModCmp> cont;
 
    auto comp_func = cont.key_comp();
 
	std::cout << cont.insert({1, 'a'}).first->first << std::endl;
	std::cout << cont.insert({2, 'b'}).first->first << std::endl;
	std::cout << cont.insert({3, 'c'}).first->first << std::endl;
	std::cout << cont.insert({4, 'd'}).first->first << std::endl;
	std::cout << cont.insert({5, 'e'}).first->first << std::endl;
    for (auto it : cont) {
        bool before = comp_func(it.first, 100);
        bool after = comp_func(100, it.first);
 
        std::cout << '(' << it.first << ',' << it.second;
        if (!before && !after)
            std::cout << ") equivalent to key 100\n";
        else if (before)
            std::cout << ") goes before key 100\n";
        else if (after)
            std::cout << ") goes after key 100\n";
        else
            assert(0); // Cannot happen
    }
}