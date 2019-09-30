
#include <forward_list>
#include "road.h"
#include <unistd.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */


int main(int argc,char* args[]){
    srand (time(NULL));

    road highway;
    highway.status();
    while(true){
        highway.tick();    
        usleep(1000*1000);
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
