#include "vehicle.h"
#include "rules.h"
#include <math.h>



vehicle::vehicle(std::list<std::shared_ptr<vehicle>>::iterator it,
            std::list<std::shared_ptr<vehicle>>::iterator pass_end,unsigned int speed,unsigned int speed_limit){

    //this->changeLane_willingness=c_w;
    this->frontVehicle_otherlane = it;
    this->pass_end_otherlane = pass_end;

    this->speed = speed;
    this->speed_limit = speed_limit;
    this->position = 0;
    this->isInsane = false;
    this->changing_tick =0;
}

unsigned int vehicle::get_score(){
    return this->score;
}
void vehicle::set_score(unsigned int tick){
    this->score = tick;
}
int vehicle::get_speed(){
    return this->speed;
}

int vehicle::set_speed(const unsigned int speed){
    return this->speed=speed;
}

int vehicle::get_position(){
    return this->position;
}

void vehicle::set_position(const int pos){
    this->position = pos;
}
unsigned int vehicle::get_frontSpace(){
    if( this->frontVehicle_otherlane != this->pass_end_otherlane )
       return  (*this->frontVehicle_otherlane)->get_position() - this->position;
    else
       return LANE_LENGTH;
}

bool vehicle::is_Insane(){
    return this->isInsane;
}

std::list<std::shared_ptr<vehicle>>::iterator vehicle::get_frontVehicle_otherlane(){
    return frontVehicle_otherlane;
}


void vehicle::set_frontVehicle_otherlane(std::list<std::shared_ptr<vehicle>>::iterator it,
                                        std::list<std::shared_ptr<vehicle>>::iterator pass_end){
    this->frontVehicle_otherlane = it;
    this->pass_end_otherlane = pass_end;
}
void vehicle::set_frontVehicle_otherlane(std::list<std::shared_ptr<vehicle>>::iterator it){
    this->frontVehicle_otherlane = it;
}

bool vehicle::get_changeLane_willingness(int fs,int fs_o,int rs_o){
    return this->vehicle_driver->change_lane(fs,fs_o,rs_o);
}
unsigned int vehicle::get_changingTick(){
    return this->changing_tick;
}
void vehicle::set_changingTick(unsigned int tick){
    this->changing_tick = tick;
}
bool vehicle::is_Shadow(){
    return this->isShadow;
}
void vehicle::set_Shadow(bool s){
    this->isShadow = s;
}
int vehicle::acceleration(){
    if(this->speed >= this->speed_limit){
       this->speed = this->speed_limit; 
       return 0;
    }

    if(!this->is_Insane()) {
        if(this->get_frontSpace() > MIN_SPACE )
            set_speed(this->get_speed() + ceil(static_cast<float>(this->accLimit)/this->accCo));
    }
    else
        set_speed(this->get_speed() + this->accLimit);
    return 0;
}

int vehicle::brake(){
    if(!this->is_Insane()) {
            int speed = this->get_speed() - ceil(static_cast<float>(this->accLimit)/this->accCo);
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
