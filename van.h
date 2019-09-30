#ifndef VAN_H
#define VAN_H
#include "vehicle.h"



class van:public vehicle{

public:
    van(lane_iterator  ,
            lane_iterator,  unsigned int );
    virtual ~van();
    std::string get_name();
    int acceleration();
    int brake();
    static unsigned int get_speedlimit();

private:
    unsigned int speed_limit;
    

};
#endif
