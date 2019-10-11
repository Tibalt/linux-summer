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


    int get_speed();
    int set_speed(const int );

    int get_position();
    void set_position(const int pos);


    unsigned int get_frontSpace();
    int set_frontSpace(const unsigned int);


    int accelerate(int);

    //int get_rearSpace_otherlane();
    //int set_rearSpace_otherlane(const unsigned int);

    //int get_frontSpace_otherlane();
    //int set_frontSpace_otherlane(const unsigned int);


    std::list<std::shared_ptr<vehicle>>::iterator get_frontVehicle_otherlane();
    void set_frontVehicle_otherlane(std::list<std::shared_ptr<vehicle>>::iterator,std::list<std::shared_ptr<vehicle>>::iterator);
    void set_frontVehicle_otherlane(std::list<std::shared_ptr<vehicle>>::iterator);

    //std::list<vehicle*>::iterator get_frontVehicle_otherlane();
    //int set_frontVehicle_otherlane(std::list<vehicle*>::iterator);

    bool get_changeLane_willingness(int,int,int);

    unsigned int get_score();
    void set_score(unsigned int tick);

    unsigned int get_changingTick();
    void set_changingTick(unsigned int tick);




private:
    std::string m_name;
    bool m_isInsane;

    //iterator for front vehicle in other lane,
    //the benefit of iterator is that
    //we have all the information of the other lane
    //so that we can update vehicle when some vehicles change lane
    std::list<std::shared_ptr<vehicle>>::iterator m_frontVehicle_otherlane;


    //we need end iterator to validate the iterator
    std::list<std::shared_ptr<vehicle>>::iterator m_end_otherlane;


    
    //auto frontVehicle_otherlane;
    //std::list<std::shared_ptr<vehicle>>::iterator rearVehicle_leftlane;
    int m_speed_limit;

    int m_brake_max;

    int m_position;
    int m_speed;
    int m_score;

    unsigned int m_changing_tick;


protected: 
    unsigned int m_accLimit;
    unsigned int m_accCo;
    std::shared_ptr<driver> m_vehicle_driver;
    


};
typedef std::list<std::shared_ptr<vehicle>>::iterator lane_iterator;
#endif
