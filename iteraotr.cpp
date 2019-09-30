// erasing from list
#include <iostream>
#include <list>

int main ()
{
  std::list<int> mylist;
  std::list<int>::iterator it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) mylist.push_back(i*10);

                              // 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist.begin(); // ^^
  --it1;
  if(it1 == mylist.end())
    std::cout <<"being -1 = end"<<std::endl; 
  advance (it2,6);            // ^                 ^
  ++it1;                      //    ^              ^

  it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
                              //    ^           ^

  it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
                              //    ^           ^

  ++it1;                      //       ^        ^
  --it2;                      //       ^     ^

  std::cout<< *it1<<std::endl;
  std::cout<< *it2<<std::endl;

  mylist.erase (it1,it2);     // 10 30 60 80 90
  std::cout<< "after erase"<<std::endl;
                              //        ^
  std::cout<< *it1<<std::endl;
  std::cout<< *it2<<std::endl;


std::cout <<*std::next(it2)<<std::endl;

  std::cout << "mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';

  std::cout<< *it2;

  return 0;
}
