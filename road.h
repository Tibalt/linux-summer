#ifndef ROAD_H
#define ROAD_H


#include <string>
#include <list>
#include <memory>

class vehicle;



class Road{

public:
    ~Road();
    Road();
    void list_vehicles();
    int tick();
    void status();
    int vehicle_move();
    bool is_alive();

private:
    int change_lane( std::list<std::shared_ptr<vehicle>>::iterator& it,bool);


    int move( std::shared_ptr<vehicle>);
    int acceleration_checkcrash( const std::list<std::shared_ptr<vehicle>>::iterator it,
                                 bool if_left);


    bool get_vehicle_distances(int& fs,int& fs_ol,int& rs_ol,
                    std::list<std::shared_ptr<vehicle>>::iterator& it,
                    bool if_left);


    unsigned int m_length=100*1000;
    float m_alert_threshold=0.3;
    float m_warning_threshold=50;

    std::list<std::shared_ptr<vehicle>> m_alert_vehicles;
    std::list<std::shared_ptr<vehicle>> m_warning_vehicles;

    std::list<std::shared_ptr<vehicle>> m_left_lane;
    std::list<std::shared_ptr<vehicle>> m_right_lane;
    bool m_left_lane_green=true;
    bool m_right_lane_green=true;
    unsigned int m_tick_tag=0;


};


#endif
