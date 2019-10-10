#include "road.h"
//#include "rules.h"
#include <iostream>
#include "vehicle_factory.hpp"



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
    for(auto const& pVehicle:this->m_left_lane){
        std::cout <<pVehicle->get_score()<<","<<pVehicle->get_position() <<","<<pVehicle->get_speed()<<",";
        if(pVehicle->get_frontVehicle_otherlane() == m_right_lane.end())
                     std::cout << "NULL,L";
        else
            std::cout << (*pVehicle->get_frontVehicle_otherlane())->get_position()<<"L";
        std::cout <<std::endl;
    }

    for(auto const& pVehicle:this->m_right_lane){
        std::cout <<pVehicle->get_score()<<","<<pVehicle->get_position() <<","<<pVehicle->get_speed()<<",";
        if(pVehicle->get_frontVehicle_otherlane() == m_left_lane.end())
                     std::cout << "NULL,R";
        else
            std::cout << (*pVehicle->get_frontVehicle_otherlane())->get_position()<<"R";
        std::cout <<std::endl;
     }
}

bool Road::is_alive(){
    return this->m_left_lane_green || this->m_right_lane_green;
}

bool Road::get_vehicle_distances(int& fs,int& fs_ol,int& rs_ol,
        std::list<std::shared_ptr<vehicle>>::iterator& it,
        bool if_left){

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

    //std::cout << "get_frontVehicle_otherlane"<<std::endl;


    if( (*it)->get_frontVehicle_otherlane() != other_lane->end()){
        fs_ol = (*(*it)->get_frontVehicle_otherlane())->get_position() 
            - (*it)->get_position(); 

        if(std::next((*it)->get_frontVehicle_otherlane()) != other_lane->end()){
            rs_ol = (*it)->get_position() - 
                (*std::next((*it)->get_frontVehicle_otherlane()))->get_position(); 
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

/*
    if(dice::if_dice(50)){
        std::shared_ptr<vehicle> p = vehicleFactory::spit_vehicle(
          this->right_lane.empty()?0:(this->right_lane).back()->get_position(),
          this->left_lane.empty()? 0:(this->left_lane).back()->get_position()) ;
        if(p!= nullptr)
            this->right_lane.push_back(p);
        else
            std::cout << "factory spit out a nullptr"<<std::endl;
    }
*/
    //std::cout <<"moving...."<<std::endl;
    this->list_vehicles();

    this->vehicle_move();
    return 0;
}


//to make the code clear, we iteration the list for 3 times to
//complete below 3 actions for every vehicle:

//1) change lane
//2) move vehicle
//3) update speed and see if crash
int Road::vehicle_move(){


    //change lane
    if(this->m_left_lane_green){
        //std::cout << "start l change lane"<<std::endl;
    
        if( this->m_right_lane_green){
            for(auto it_l = this->m_left_lane.begin(); it_l!=this->m_left_lane.end();){
               //std::cout << "change l lane iteration"<<std::endl;

                int fs,fs_ol,rs_ol;

                if(this->get_vehicle_distances(fs,fs_ol,rs_ol,it_l,true)){
                    if((*it_l)->get_changeLane_willingness(fs,fs_ol,rs_ol))    {
                        //std::cout << "l change"<<std::endl;
                        //as delete will make iterator invalid, 
                        //we move iterator inside "change_lane"
                        change_lane(it_l,true);
                    }
                    else
                        it_l++;
                }
                else
                    it_l++;
            }
        }
        //move 
        //std::cout <<"move left lane"<<std::endl;
        //std::cout <<"left lane size:"<<this->left_lane.size()<<std::endl;
        //for(auto it_l = this->m_left_lane.begin(); it_l!=this->m_left_lane.end();it_l++){
            //move(it_l);
        //}
        for(auto const &pVehicle:this->m_left_lane){
            move(pVehicle);
        }

        //update speed and see if crash
        for(auto it_l = this->m_left_lane.begin(); it_l!=this->m_left_lane.end();it_l++){
            acceleration_checkcrash(it_l,true);
        }
    }
    if(this->m_right_lane_green){
        //std::cout << "start r change lane"<<std::endl;
        if( this->m_left_lane_green){
            //std::cout << "r change lane"<<std::endl;
            for(auto it_r = this->m_right_lane.begin(); it_r!=this->m_right_lane.end();){
               //std::cout << "change r lane iteration"<<std::endl;

                int fs,fs_ol,rs_ol;

                if(this->get_vehicle_distances(fs,fs_ol,rs_ol,it_r,false)){
                    if((*it_r)->get_changeLane_willingness(fs,fs_ol,rs_ol)){
                        change_lane(it_r,false);
                        //std::cout << "l change"<<std::endl;
                    }
                    else
                        it_r++;
                }
                else
                    it_r++;
            }
        }

        for(auto const &pVehicle:this->m_right_lane){
            move(pVehicle);
        }
        //std::cout << "update speed"<<std::endl;
        for(auto it_r=this->m_right_lane.begin(); it_r!=this->m_right_lane.end();it_r++){
            acceleration_checkcrash(it_r,false);
        }
    }

    if(this->m_left_lane_green && this->m_right_lane_green){
        for(auto it_l=this->m_left_lane.begin(); it_l!=this->m_left_lane.end();it_l++){
            for(auto it_r=this->m_right_lane.begin(); it_r!=this->m_right_lane.end();it_r++){
                if((*it_l)->get_position() < (*it_r)->get_position()){
                    continue;
                }
                else{
                    if(it_r == m_right_lane.begin())
                        (*it_l)->set_frontVehicle_otherlane(m_right_lane.end());
                    else
                        (*it_l)->set_frontVehicle_otherlane(it_r);

                    break;
                }
            }
        }
        for(auto it_r=this->m_right_lane.begin(); it_r!=this->m_right_lane.end();it_r++){
            for(auto it_l=this->m_left_lane.begin(); it_l!=this->m_left_lane.end();it_l++){
                if((*it_r)->get_position() < (*it_l)->get_position()){
                    continue;
                }
                else{
                    if(it_r == m_right_lane.begin())
                        (*it_r)->set_frontVehicle_otherlane(m_left_lane.end());
                    else
                        (*it_r)->set_frontVehicle_otherlane(it_l);

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

int Road::change_lane( std::list<std::shared_ptr<vehicle>>::iterator& it,bool if_left){
    //std::cout << "start changing"<<std::endl;

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




    if((*it)->get_changingTick() == this->m_tick_tag){
        //std::cout<<"move without change 
        //as the vehicle has changed once
        it = std::next(it);
        return 0;
    }

    if(if_left)
        std::cout << "l change"<<std::endl;
    else
        std::cout << "r change"<<std::endl;
    //#-1 move the vehicle
   const auto it_cur = it;
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

#if 0
    //#0 update moving vehicle's frontVehicle_otherlane
    if(it_cur == this_lane->begin())
        (*it_moved)->set_frontVehicle_otherlane(this_lane->end(),this_lane->end());
    else
        (*it_moved)->set_frontVehicle_otherlane(std::prev(it_cur),this_lane->end());

    //#1 update vehicle on this lane 
    //update the-front-car-in-other-lane of the vehicles after moved vehicle 
    //until no affection from changing lane 
    //std::cout << "number 1"<<std::endl;
    auto it_next= std::next(it_cur);

    while(it_next != this_lane->end()){
        //std::cout <<"#1"<<std::endl;

        auto temp = (*it_next)->get_frontVehicle_otherlane();

        if(temp == other_lane->end())
            break;
        if(temp == this_lane->end()){
            std::cout << "temp is end of this lane!"<<std::endl;
            break;
        }
        if((*temp)->get_position() > (*it)->get_position()){
            (*it_next)->set_frontVehicle_otherlane(it);
            it_next++;
        }
        else
            break;
    };

    //#2 update vehicle on the other lane
    //deal with the vehicle in other lane linking to the moved vehicle
    //if there is
    //std::cout << "number 2"<<std::endl;

    //std::cout << "number 2"<<std::endl;
    auto it_cur_front = this_lane->end();
    if(it_cur == this_lane->begin())
        it_cur_front = this_lane->end();
    else
        it_cur_front = std::prev(it_cur);

    auto it_next_otherlane = std::next(it);
    while(it_next_otherlane != other_lane->end()){
        //std::cout <<"#2"<<std::endl;

        if((*it_next_otherlane)->get_frontVehicle_otherlane() == it_cur){ //&&
            //(*(*it_next_otherlane)->get_frontVehicle_otherlane())->get_position() > (*it_cur)->get_position())

            (*it_next_otherlane)->set_frontVehicle_otherlane(it_cur_front); 
            it_next_otherlane++;
        }
        else
            break;
    };
#endif

    it = std::next(it_cur);
    this_lane->erase(it_cur); 
    return 0;
}
int Road::acceleration_checkcrash( const std::list<std::shared_ptr<vehicle>>::iterator it,bool if_left){

    //assert(green_light == true);

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

    if( (*it)->get_position() >  100*1000){
        lane->erase(it);
        return 1;
    }
    return 0;
        
}

