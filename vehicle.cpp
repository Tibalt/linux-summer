#include "vehicle.h"
#include "rules.h"
#include <math.h>



vehicle::vehicle(std::list<std::shared_ptr<vehicle>>::iterator it,
            std::list<std::shared_ptr<vehicle>>::iterator pass_end,unsigned int speed,unsigned int speed_limit){

    //this->changeLane_willingness=c_w;
    this->m_frontVehicle_otherlane = it;
    this->m_end_otherlane = pass_end;

    this->m_speed = speed;
    this->m_speed_limit = speed_limit;
    this->m_position = 0;
    this->m_isInsane = false;
    this->m_changing_tick =0;
}

unsigned int vehicle::get_score(){
    return this->m_score;
}
void vehicle::set_score(unsigned int tick){
    this->m_score = tick;
}
int vehicle::get_speed(){
    return this->m_speed;
}

int vehicle::set_speed(const unsigned int speed){
    return this->m_speed=speed;
}

int vehicle::get_position(){
    return this->m_position;
}

void vehicle::set_position(const int pos){
    this->m_position = pos;
}
unsigned int vehicle::get_frontSpace(){
    if( this->m_frontVehicle_otherlane != this->m_end_otherlane )
       return  (*this->m_frontVehicle_otherlane)->get_position() - this->m_position;
    else
       return LANE_LENGTH;
}

bool vehicle::is_Insane(){
    return this->m_isInsane;
}

std::list<std::shared_ptr<vehicle>>::iterator vehicle::get_frontVehicle_otherlane(){
    return m_frontVehicle_otherlane;
}


void vehicle::set_frontVehicle_otherlane(std::list<std::shared_ptr<vehicle>>::iterator it,
                                        std::list<std::shared_ptr<vehicle>>::iterator pass_end){
    this->m_frontVehicle_otherlane = it;
    this->m_end_otherlane = pass_end;
}
void vehicle::set_frontVehicle_otherlane(std::list<std::shared_ptr<vehicle>>::iterator it){
    this->m_frontVehicle_otherlane = it;
}

bool vehicle::get_changeLane_willingness(int fs,int fs_o,int rs_o){
//    return false;
    return this->m_vehicle_driver->change_lane(fs,fs_o,rs_o);
}
unsigned int vehicle::get_changingTick(){
    return this->m_changing_tick;
}
void vehicle::set_changingTick(unsigned int tick){
    this->m_changing_tick = tick;
}

int vehicle::acceleration(){
    if(this->m_speed >= this->m_speed_limit){
       this->m_speed = this->m_speed_limit; 
       return 0;
    }

    if(!this->is_Insane()) {
        if(this->get_frontSpace() > MIN_SPACE )
            set_speed(this->get_speed() + ceil(static_cast<float>(this->m_accLimit)/this->m_accCo));
    }
    else
        set_speed(this->get_speed() + this->m_accLimit);
    return 0;
}

int vehicle::brake(){
    if(!this->is_Insane()) {
            int speed = this->get_speed() - ceil(static_cast<float>(this->m_accLimit)/this->m_accCo);
            if(speed < 0)
                set_speed(0);
            else
                this->set_speed(speed);
    }
    //else
    //    set_speed(this->get_speed() - rand()%(this->accLimit));
    return 0;
}
/*
unsigned int vehicle::get_tick(){
    this->tick;
}
int vehicle::set_tick(unsigned int tick){
    this->tick = tick;
}
*/
