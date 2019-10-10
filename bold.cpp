#include "bold.h"
#include "rules.h"
#include "vehicle_factory.hpp"



bool BoldDriver::change_lane(int front_space, int frontspace_otherlane,int rearspace_otherlane){
    if( frontspace_otherlane > MIN_SPACE && rearspace_otherlane > MIN_SPACE)
        return true;
    else
        return false;
}
int BoldDriver::speed_change(int front_space){
    if(front_space*2 <= MIN_SPACE)
        return -80;
    if(front_space <= MIN_SPACE)
        return -50;
    if(front_space > MIN_SPACE*2)
        return  80;
    if(front_space > MIN_SPACE)
        return  20;

    return 0;
}







