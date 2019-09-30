#ifndef CAU_H
#define CAU


#include "driver.h"


class cautious:public driver{

public:
    virtual bool change_lane(int front_space, int frontspace_otherlane,int rearspace_otherlane);
    virtual int speed_change(int front_space);
};



#endif
