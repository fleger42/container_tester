#include "../container_tester.hpp"

int main () 
{
 	ACCESS::vector<std::string> cont;
	cont.insert(cont.begin(), "salut");
	cont.insert(cont.begin(), "test");
	cont.insert(cont.begin(), "3");
    ACCESS::vector<std::string> tmp = cont;
	tmp.insert(tmp.begin(), cont.begin(), cont.end());
	for (ACCESS::vector<std::string>::const_iterator it = tmp.begin(); it != tmp.end(); ++it)
        std::cout << *it << " | " << std::endl;
    if (tmp.size())
    {
        ACCESS::vector<std::string>::iterator it = tmp.begin();
        ++it;
        tmp.insert(it, cont.begin(), cont.end());
    }
    tmp.insert(tmp.end(), cont.begin(), cont.end());
    tmp.insert(tmp.end(), cont.begin(), cont.begin());
    for (ACCESS::vector<std::string>::const_iterator it = tmp.begin(); it != tmp.end(); ++it)
        std::cout << *it << " | " << std::endl;
}
