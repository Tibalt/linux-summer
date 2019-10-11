#include "cautious.h"
#include "rules.h"
#include "vehicle_factory.hpp"



bool CautiousDriver::change_lane(int front_space, int frontspace_otherlane,int rearspace_otherlane){//never change lane
    if(front_space < MIN_SPACE && frontspace_otherlane > MIN_SPACE && rearspace_otherlane > MIN_SPACE)
        return true;
    else
        return false;
}
int CautiousDriver::speed_change(int front_space){
    if(front_space*2 <= MIN_SPACE)
        return -90;
    if(front_space <= MIN_SPACE)
        return -60;
    if(front_space > MIN_SPACE*2)
        return  40;
    if(front_space > MIN_SPACE)
        return  0;
    
    return 0;
}



