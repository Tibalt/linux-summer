#ifndef ROAD_H
#define ROAD_H


#include <string>
#include <list>
#include <memory>

class vehicle;



class road{

public:
    int tick();
    std::string status();
    ~road();
    road();

private:
   unsigned int tick_tag=0;


};


#endif
