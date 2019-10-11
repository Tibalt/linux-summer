#include "road.h"
//#include "rules.h"
#include <iostream>
#include "vehicle_factory.hpp"
#include <assert.h>



Road::~Road(){
    

}
Road::Road(){
    //this->right_lane= std::list<vehicle*>{};
    //this->left_lane=std::list<vehicle*>{};
    this->m_left_lane_green = true;
    this->m_right_lane_green = true;
}
void Road::list_vehicles(){
    std::cout<<"vehicles:"<<  std::endl;
    std::cout << "[L:";
    if(!m_left_lane_green)
        std::cout << "X:";
    else
        std::cout << "O:";
    std::cout <<m_left_lane.size()<<"]";

    std::cout << "[R:";
    if(!m_right_lane_green)
        std::cout << "X:";
    else
        std::cout << "O:";
    std::cout <<m_right_lane.size()<<"]";
    std::cout <<std::endl;
        
    for(auto const& pVehicle:this->m_left_lane){
        std::cout <<pVehicle->get_score()<<","<<pVehicle->get_position() <<","<<pVehicle->get_speed()<<",";
        if(pVehicle->get_frontVehicle_otherlane() == m_right_lane.end())
                     std::cout << "NULL,L";
        else
            std::cout << (*pVehicle->get_frontVehicle_otherlane())->get_position()<<","<<"L";
        
        std::cout <<std::endl;
    }

    for(auto const& pVehicle:this->m_right_lane){
        std::cout <<pVehicle->get_score()<<","<<pVehicle->get_position() <<","<<pVehicle->get_speed()<<",";
        if(pVehicle->get_frontVehicle_otherlane() == m_left_lane.end())
                     std::cout << "NULL,R";
        else
            std::cout << (*pVehicle->get_frontVehicle_otherlane())->get_position()<<","<<"R";
        std::cout <<std::endl;
     }
}

bool Road::is_alive(){
    return this->m_left_lane_green || this->m_right_lane_green;
}

bool Road::get_vehicle_distances(int& fs,int& fs_ol,int& rs_ol,
        std::list<std::shared_ptr<vehicle>>::iterator& it,
        bool if_left){
    //return true;

    std::list<std::shared_ptr<vehicle>>  *this_lane, *other_lane;

    if(if_left){
        this_lane = &(this->m_left_lane);
        other_lane = &(this->m_right_lane);
    }
    else{
        this_lane = &(this->m_right_lane);
        other_lane =&(this->m_left_lane);
    }

    if(it == this_lane->end()){
        std::cout<<"invalid this lane iterator"<<std::endl;
        return false;     
    }
    if(it == other_lane->end()){
        std::cout<<"invalid other lane iterator"<<std::endl;
        return false;
    }

    fs = LANE_LENGTH;
    fs_ol=LANE_LENGTH;
    rs_ol=(*it)->get_position();


    if(it != this_lane->begin())
        fs = (*std::prev(it))->get_position() - (*it)->get_position();


    auto pFV_ol_it = (*it)->get_frontVehicle_otherlane() ;
    //auto pFrontVechile = *((*it)->get_frontVehicle_otherlane()) ;


    assert(pFV_ol_it != this_lane->end());

    if( pFV_ol_it != other_lane->end()){
        fs_ol = (*pFV_ol_it)->get_position() 
            - (*it)->get_position(); 

        auto pFV_ol_it_next = std::next(pFV_ol_it); 
        assert(pFV_ol_it_next != this_lane->end());

        if(pFV_ol_it_next != other_lane->end()){
            rs_ol = (*it)->get_position() - 
                (*pFV_ol_it_next)->get_position(); 
        }
    }
    return true;
}
void Road::status(){

    //current tick
    //todo:
    //total cars in each lane
    //number of dangerous vehicles #1: have changed lanes for 5 times in the last 5 ticks
    //number of dangerous vehicles #2: front space less than 50 meters

    //vehicles in first 100 meters

    std::cout<<"tick:"<< this->m_tick_tag << std::endl;


    if(this->m_left_lane_green){

        for(int i=0;i<100;i++){
            auto it =this->m_left_lane.rbegin();
            for(;it!=this->m_left_lane.rend();it++) {
                //std::cout<<(*it)->get_position();
                if((*it)->get_position() == i){
                    std::cout<<"v";
                    break;
                }

                else if((*it)->get_position() > i){
                    std::cout<<"-";
                    break;
                }
                else
                    continue;
            }
            if(it == this->m_left_lane.rend())
                std::cout<<"-";
        }
        std::cout << std::endl;
    }

    if(this->m_right_lane_green){
        for(int i=0;i<100;i++){
            auto it =this->m_right_lane.rbegin();
            for(;it!=this->m_right_lane.rend();it++) {
                //std::cout<<(*it)->get_position();
                if((*it)->get_position() == i){
                    std::cout<<"v";
                    break;
                }
                else if((*it)->get_position() > i){
                    std::cout<<"-";
                    break;
                }
                else
                    continue;
            }
            if(it == this->m_right_lane.rend())
                std::cout<<"-";
        }
        std::cout << std::endl;
    }
/*
    std::cout << "\e[A";
    if(this->left_lane_green){
        std::cout << "\e[A";
    }
    if(this->right_lane_green){
        std::cout << "\e[A";
    }
*/
}

int Road::tick(){
    std::cout<<"-------------------------------"<<std::endl;
    this->m_tick_tag++;
    //spit vehicle for left lane

    
    
    if(this->m_left_lane_green &&
        ( this->m_left_lane.empty() || (this->m_left_lane.back())->get_position() > MIN_SPACE)
                    && dice::if_dice(50)){

        std::shared_ptr<vehicle> p = vehicleFactory::spit_vehicle(
          this->m_right_lane.empty()?  this->m_right_lane.end():
                           std::next(this->m_right_lane.begin(),this->m_right_lane.size()-1),
                            this->m_right_lane.end());

        p->set_score(this->m_tick_tag);

        if (p != nullptr)
            this->m_left_lane.push_back(p);
        else
            std::cout << "factory spit out a nullptr"<<std::endl;
    }

    //spit vehicle for right lane
    if(this->m_right_lane_green &&
           ( this->m_right_lane.empty() || (this->m_right_lane.back())->get_position() > MIN_SPACE)
                     &&dice::if_dice(50)){

        std::shared_ptr<vehicle> p = vehicleFactory::spit_vehicle(
          this->m_left_lane.empty()? this->m_left_lane.end():
                           std::next(this->m_left_lane.begin(),this->m_left_lane.size()-1),
                            this->m_left_lane.end());
        p->set_score(this->m_tick_tag);

        if (p != nullptr)
            this->m_right_lane.push_back(p);
        else
            std::cout << "factory spit out a nullptr"<<std::endl;
    }

    this->vehicle_move();
    return 0;
}


//to make the code clear, do below 3 actions for EACH lane:

//1) change lane
//2) move vehicle
//3) update speed and see if crash

//then maintain iterator of front vehicle in other lane for two lanes
int Road::vehicle_move(){


    if(this->m_left_lane_green){
        //change lane
        if( this->m_right_lane_green){
            for(auto it_l = this->m_left_lane.begin(); it_l!=this->m_left_lane.end();it_l++){
                int fs,fs_ol,rs_ol;

                if(this->get_vehicle_distances(fs,fs_ol,rs_ol,it_l,true)){
                    if((*it_l)->get_changeLane_willingness(fs,fs_ol,rs_ol))    {
                        //as change_lane may delete it_l  and make it invalid, 
                        //we do it_l--
                        if(change_lane(it_l--,true) == -1)
                            it_l++;
                    }
                }
            }
        }
        //move 
        for(auto const &pVehicle:this->m_left_lane){
            move(pVehicle);
        }

        //update speed and see if crash
        for(auto it_l = this->m_left_lane.begin(); it_l!=this->m_left_lane.end();it_l++){
            acceleration_checkcrash(it_l,true);
        }
    }
    if(this->m_right_lane_green){
        //change lane
        if( this->m_left_lane_green){
            for(auto it_r = this->m_right_lane.begin(); it_r!=this->m_right_lane.end();it_r++){

                int fs,fs_ol,rs_ol;

                if(this->get_vehicle_distances(fs,fs_ol,rs_ol,it_r,false)){
                    if((*it_r)->get_changeLane_willingness(fs,fs_ol,rs_ol)){
                        if(change_lane(it_r--,false) == -1)
                            it_r++;
                    }
                }
            }
        }
        //move 
        for(auto const &pVehicle:this->m_right_lane){
            move(pVehicle);
        }
        //update speed and see if crash
        for(auto it_r=this->m_right_lane.begin(); it_r!=this->m_right_lane.end();it_r++){
            acceleration_checkcrash(it_r,false);
        }
    }

    //update iterator in the other lane for two lanes
    if(this->m_left_lane_green ){
        for(auto it_l=this->m_left_lane.begin(); it_l!=this->m_left_lane.end();it_l++){
            if( (*it_l)->get_position() >  100*1000){
                std::cout <<"erase vehicle moved out in left lane"<<std::endl;
                m_left_lane.erase(it_l--);
                continue;
            }
            if((*it_l)->get_position() <  100*1000 && !this->m_right_lane_green)
                break;


            auto it_r = this->m_right_lane.begin();

            if(it_l != this->m_left_lane.begin()){
                it_r=(*std::prev(it_l))->get_frontVehicle_otherlane();
                if(it_r == this->m_right_lane.end())
                    it_r = this->m_right_lane.begin();
            }

            for(;it_r!=this->m_right_lane.end();it_r++){
                //vehicles's position getting smaller as iterator goes
                //here we are finding the vehicle in front in the other lane
                if( (*it_r)->get_position() > 100*1000 ||
                    (*it_l)->get_position() < (*it_r)->get_position()){
                    continue;
                }
                else{
                    if(it_r == m_right_lane.begin())
                        (*it_l)->set_frontVehicle_otherlane(m_right_lane.end());
                    else
                        (*it_l)->set_frontVehicle_otherlane(std::prev(it_r));

                    break;
                }
            }
        }
    }
    if(this->m_right_lane_green ){
        for(auto it_r=this->m_right_lane.begin(); it_r!=this->m_right_lane.end();it_r++){

            if( (*it_r)->get_position() >  100*1000){
                std::cout <<"erase vehicle moved out in right lane"<<std::endl;
                m_right_lane.erase(it_r--);
                continue;
            }
            if((*it_r)->get_position() <  100*1000 && !this->m_left_lane_green)
                break;


            auto it_l = this->m_left_lane.begin();

            if(it_r != this->m_right_lane.begin()){
                it_l=(*std::prev(it_r))->get_frontVehicle_otherlane();
                if(it_l == this->m_left_lane.end())
                    it_l = this->m_left_lane.begin();
            }

            for(;it_l!=this->m_left_lane.end();it_l++){
                if((*it_r)->get_position() < (*it_l)->get_position()){
                    continue;
                }
                else{
                    if(it_l == m_left_lane.begin())
                        (*it_r)->set_frontVehicle_otherlane(m_left_lane.end());
                    else
                        (*it_r)->set_frontVehicle_otherlane(std::prev(it_l));

                    break;
                }
            }
        }

    }
    return 0;
}    


int Road::move(std::shared_ptr<vehicle> pVehicle){
    if(pVehicle->get_changingTick() == this->m_tick_tag)
        return pVehicle->get_position();

    pVehicle->set_position(pVehicle->get_position() + pVehicle->get_speed());
    //std::cout<<"cur pos is " <<(*it)->get_position()<<std::endl;
    return pVehicle->get_position();
}

int Road::change_lane( std::list<std::shared_ptr<vehicle>>::iterator it,bool if_left){

    std::list<std::shared_ptr<vehicle>>  *this_lane = &(this->m_right_lane);
    std::list<std::shared_ptr<vehicle>>  *other_lane =& (this->m_left_lane);


    if(if_left){
        this_lane = &(this->m_left_lane);
        other_lane = &(this->m_right_lane);
    }

    if( it == this_lane->end()){
        std::cout<<"it is invalid for this lane"<<std::endl;    
        return -1;
    }

    if( it == other_lane->end()){
        std::cout<<"it is invalid for other lane and it should be in this lane"<<std::endl;    
        return -1;
    }
    assert(it != other_lane->end());


    const auto it_cur = it;
    const auto it_cur_fs_ol = (*it_cur)->get_frontVehicle_otherlane();


    if((*it)->get_changingTick() == this->m_tick_tag){
        //std::cout<<"move without change 
        //as the vehicle has changed once
        //it = std::next(it);
        return -1;
    }

    if(if_left)
        std::cout << "l change"<<std::endl;
    else
        std::cout << "r change"<<std::endl;

    //#0 move the vehicle
    auto it_moved = it;
    if((*it)->get_frontVehicle_otherlane() == other_lane->end()){
        other_lane->push_front(*it);
        it_moved = other_lane->begin();
    }
    else{
        auto temp = std::next((*it)->get_frontVehicle_otherlane());
        if(temp == other_lane->end()){
            other_lane->push_back(*it);
            it_moved = std::prev(other_lane->end(),1);
        }
        else
            it_moved = other_lane->insert(temp,*it);
    }

    (*it_moved)->set_changingTick(this->m_tick_tag);

    //#1 update moving vehicle's frontVehicle_otherlane
    if(it_cur == this_lane->begin())
        (*it_moved)->set_frontVehicle_otherlane(this_lane->end(),this_lane->end());
    else
        (*it_moved)->set_frontVehicle_otherlane(std::prev(it_cur),this_lane->end());

    //#2 update vehicle on the other lane
    //deal with the vehicle in other lane linking to the moved vehicle
    //if there is
    auto it_cur_front = this_lane->end();
    if(it_cur != this_lane->begin())
        it_cur_front = std::prev(it_cur);


    it_cur_fs_ol != other_lane->end();

    auto it_next_ol = std::next(it_moved);

    while(it_next_ol != other_lane->end()){
        if((*it_next_ol)->get_frontVehicle_otherlane() == it_cur){ //&&

            (*it_next_ol)->set_frontVehicle_otherlane(it_cur_front); 
        }
        it_next_ol++;
    };

    this_lane->erase(it_cur); 
    return 0;
}
int Road::acceleration_checkcrash( const std::list<std::shared_ptr<vehicle>>::iterator it,bool if_left){

    std::list<std::shared_ptr<vehicle>>* lane = &(this->m_right_lane);
    bool *green_light = &(this->m_right_lane_green);

    if(if_left){
       lane =& (this->m_left_lane);
       green_light = &(this->m_left_lane_green);
    }

        

    if(*green_light == false)
        return 1; 

    //std::cout << "a_c begin"<<std::endl;

    if(it != lane->begin()){

        //std::cout << "check crash"<<std::endl;
        int space = (*(std::prev(it)))->get_position() - (*it)->get_position();

        if(space <= 0){
            *green_light = false; 
            return 1;
        }

        //std::cout << "check if just changed!"<<std::endl;

        if((*it)->get_changingTick() == this->m_tick_tag)
            return 0; 



        if( space <=20 && dice::if_dice(100) ){
            (*it)->brake();
        }
        else if( space <=50 && dice::if_dice(85) ){
            (*it)->brake();
        }
        else if(space <=100 && dice::if_dice(80))
            (*it)->brake();
        else if(space <150 && dice::if_dice(80))
            (*it)->acceleration();
        else if(space <200 && dice::if_dice(90))
            (*it)->acceleration();
        else if(space <250 && dice::if_dice(95))
            (*it)->acceleration();
        else if(dice::if_dice(95))
            (*it)->acceleration();
        else;
            //nothing happens
    }
    else{
        if((*it)->get_changingTick() == this->m_tick_tag)
            return 0; 
        (*it)->acceleration();
    }

    //std::cout << "speed after changing:"<<(*it)->get_speed()<<std::endl;
    return 0;
        
}

