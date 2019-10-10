#ifndef BOLD_H
#define BOLD_H
#include "driver.h"



class BoldDriver:public driver{

public:
    virtual bool change_lane(int front_space, int frontspace_otherlane,int rearspace_otherlane);
    virtual int speed_change(int front_space);
};



#endif
