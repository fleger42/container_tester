#include "../container_tester.hpp"

int main () {
	std::cout << "1" << std::endl;
  ACCESS::vector<int> myvector;
  for (int i=0; i<10; i++) myvector.push_back(i);
  typedef ACCESS::vector<int>::iterator iter_type;                                                  
  iter_type from (myvector.begin());                                                                
  iter_type until (myvector.end());                                           
  ACCESS::reverse_iterator<iter_type> rev_until (from); 
  ACCESS::reverse_iterator<iter_type> rev_from (until); 
  int i = 0;
  while (rev_from != rev_until)
  {
    std::cout << ' ' << rev_from[i];
	rev_from++;
	i++;
  }
  std::cout << '\n';
  return 0;
}
