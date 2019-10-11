
#include <forward_list>
#include "road.h"
#include <unistd.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>     /* srand, rand */


int main(int argc,char* args[]){
    srand (time(NULL));

    Road highway;
    //highway.status();
    std::cout <<"simulation started"<<std::endl;
    while(true){
        highway.tick();
        highway.list_vehicles();
        //usleep(1000);
        if(!highway.is_alive()){
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "******the road is blocked!******"<<std::endl;
            highway.list_vehicles();
            break;
        }
        //highway.status();
    }
}
