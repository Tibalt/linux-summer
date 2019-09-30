#include "road.h"
#include <iostream>



road::~road(){
}
road::road(){
}

std::string road::status(){
    std::cout<<"tick:"<< this->tick_tag << std::endl;
}


