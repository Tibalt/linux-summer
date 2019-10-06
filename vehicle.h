#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <list>
#include <memory>
#include "driver.h"


class vehicle{
public:
    vehicle( std::list<std::shared_ptr<vehicle>>::iterator,
            std::list<std::shared_ptr<vehicle>>::iterator,unsigned int,unsigned int );

    virtual std::string get_name()=0;
    virtual unsigned int get_speedlimit()=0;

    int acceleration();
    int brake();

    int get_speed();
    int set_speed(unsigned int );

    int get_position();
    void set_position(const int pos);


    bool is_Insane();

    bool is_Shadow();
    void set_Shadow(bool);

    unsigned int get_frontSpace();
    int set_frontSpace(const unsigned int);

    //int get_rearSpace_otherlane();
    //int set_rearSpace_otherlane(const unsigned int);

    //int get_frontSpace_otherlane();
    //int set_frontSpace_otherlane(const unsigned int);


    std::list<std::shared_ptr<vehicle>>::iterator get_frontVehicle_otherlane();
    void set_frontVehicle_otherlane(std::list<std::shared_ptr<vehicle>>::iterator,std::list<std::shared_ptr<vehicle>>::iterator);

    //std::list<vehicle*>::iterator get_frontVehicle_otherlane();
    //int set_frontVehicle_otherlane(std::list<vehicle*>::iterator);

    bool get_changeLane_willingness(int,int,int);

    unsigned int get_score();
    void set_score(unsigned int tick);

    unsigned int get_changingTick();
    void set_changingTick(unsigned int tick);




private:
    //unsigned int changeLane_willingness;

    std::string name;
    bool isInsane;

    //int frontSpace;
    //int rearSpace_otherlane;
    //int frontSpace_otherlane;

    std::list<std::shared_ptr<vehicle>>::iterator frontVehicle_otherlane;
    std::list<std::shared_ptr<vehicle>>::iterator pass_end_otherlane;


    
    //auto frontVehicle_otherlane;
    //std::list<std::shared_ptr<vehicle>>::iterator rearVehicle_leftlane;
    unsigned int speed_limit;

    int acceleration_max;
    int brake_max;

    unsigned int position;
    unsigned int speed;
    unsigned int score;

    unsigned int changing_tick;

    bool isShadow = false;

protected: 
    unsigned int accLimit;
    unsigned int accCo;
    std::shared_ptr<driver> vehicle_driver;
    


};
typedef std::list<std::shared_ptr<vehicle>>::iterator lane_iterator;
#endif
