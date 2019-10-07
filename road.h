#ifndef ROAD_H
#define ROAD_H


#include <string>
#include <list>
#include <memory>

class vehicle;



class road{

public:
    ~road();
    road();
    void list_vehicles();
    int tick();
    void status();
    int vehicle_move();
    bool is_alive();

private:
    int change_lane( std::list<std::shared_ptr<vehicle>>::iterator& it,bool);

    int move( std::list<std::shared_ptr<vehicle>>::iterator);
    int acceleration_checkcrash( const std::list<std::shared_ptr<vehicle>>::iterator it,
                                 bool if_left);


    bool get_vehicle_distances(int& fs,int& fs_ol,int& rs_ol,
                    std::list<std::shared_ptr<vehicle>>::iterator& it,
                    bool if_left);


    unsigned int length=100*1000;
    float alert_threshold=0.3;
    float warning_threshold=50;

    std::list<std::shared_ptr<vehicle>> alert_vehicles;
    std::list<std::shared_ptr<vehicle>> warning_vehicles;

    std::list<std::shared_ptr<vehicle>> left_lane;
    std::list<std::shared_ptr<vehicle>> right_lane;
    bool left_lane_green=true;
    bool right_lane_green=true;
    unsigned int tick_tag=0;


};


#endif
