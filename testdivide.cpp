#include <iostream>
#include <iostream>     // std::cout
#include <iterator>     // std::next
#include <list>         // std::list
#include <algorithm>    // std::for_each

#include <list>
#include "road.h"



std::string func(){
    std::cout<<"hello"<<std::endl;
}

int main(){


#if 0

    int a=1;
    int b=10;
    float c = float(a)/float(b);
    std::cout << c<<std::endl; 


    std::list<int> hello{1,2,3,4,5};

    for(auto it:hello)
        std::cout <<it<<std::endl;



// prev example
    
        std::cout <<"mylist"<<std::endl;
  std::list<int> mylist;
  for (int i=0; i<10; i++) mylist.push_back (i*10);


    for(auto it:mylist)
        std::cout <<it<<std::endl;
        

  std::cout << "The prev element of begin is " << *std::prev(mylist.begin()) << '\n';
  std::cout << "The next element of begin is " << *std::next(mylist.begin()) << '\n';
  std::cout << "The first element is " << *mylist.begin()<< '\n';

  return 0;
#endif

//    road r;
//    r.status();
    func();
    func();
    func();
    func();
    




}
