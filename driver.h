#ifndef DRIVER_H
#define DRIVER_H

class driver{
public:
    virtual bool change_lane(int front_space, int frontspace_otherlane,int rearspace_otherlane)=0;
    virtual int speed_change(int front_space)=0;
};

#endif
