#include "road.h"
//#include "rules.h"
#include <iostream>
#include "vehicle_factory.hpp"



road::~road(){
    

}
road::road(){
    //this->right_lane= std::list<vehicle*>{};
    //this->left_lane=std::list<vehicle*>{};
}
void road::list_vehicles(){
    std::cout<<"left lane vehicle:"<<  std::endl;
    for(auto it=this->left_lane.rbegin();it!=this->left_lane.rend();it++)
        std::cout <<"ID:"<<(*it)->get_score()<<",pos:"<<(*it)->get_position()<<",""speed:"<<(*it)->get_speed()<<std::endl; 

    std::cout<<"right lane vehicle:"<<  std::endl;
    for(auto it=this->right_lane.rbegin();it!=this->right_lane.rend();it++)
        std::cout <<"ID:"<<(*it)->get_score()<<",pos:"<<(*it)->get_position()<<",""speed:"<<(*it)->get_speed()<<std::endl; 
}

bool road::is_alive(){
    return this->left_lane_green || this->left_lane_green;
}

bool road::get_vehicle_distances(int& fs,int& fs_ol,int& rs_ol,
        std::list<std::shared_ptr<vehicle>>::iterator& it,
        bool if_left){

    std::list<std::shared_ptr<vehicle>>  *this_lane, *other_lane;

    if(if_left){
        this_lane = &(this->left_lane);
        other_lane = &(this->right_lane);
    }
    else{
        this_lane = &(this->right_lane);
        other_lane =&(this->left_lane);
    }

    if(it == this_lane->end())
        return false;     
        
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
void road::status(){

    //current tick
    //total cars in each lane
    //number of dangerous vehicles #1: have changed lanes for 5 times in the last 5 ticks
    //number of dangerous vehicles #2: front space less than 50 meters

    //vehicles in first 100 meters

    std::cout<<"tick:"<< this->tick_tag << std::endl;


    if(this->left_lane_green){

        for(int i=0;i<100;i++){
            auto it =this->left_lane.rbegin();
            for(;it!=this->left_lane.rend();it++) {
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
            if(it == this->left_lane.rend())
                std::cout<<"-";
        }
        std::cout << std::endl;
    }

    if(this->right_lane_green){
        for(int i=0;i<100;i++){
            auto it =this->right_lane.rbegin();
            for(;it!=this->right_lane.rend();it++) {
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
            if(it == this->right_lane.rend())
                std::cout<<"-";
        }
        std::cout << std::endl;
    }

    std::cout << "\e[A";
    if(this->left_lane_green){
        std::cout << "\e[A";
    }
    if(this->right_lane_green){
        std::cout << "\e[A";
    }
}

int road::tick(){
    //std::cout<<"tick"<<std::endl;
    this->tick_tag++;
    //spit vehicle for left lane

    
    
    if(this->left_lane_green && dice::if_dice(20)){

        std::shared_ptr<vehicle> p = vehicleFactory::spit_vehicle(
          this->right_lane.empty()?  this->right_lane.end():
                           std::next(this->right_lane.begin(),this->right_lane.size()-1),
                            this->right_lane.end());

        p->set_score(this->tick_tag);

        if (p != nullptr)
            this->left_lane.push_back(p);
        else
            std::cout << "factory spit out a nullptr"<<std::endl;
    }

    //spit vehicle for right lane
    if(this->right_lane_green && dice::if_dice(30)){

        std::shared_ptr<vehicle> p = vehicleFactory::spit_vehicle(
          this->left_lane.empty()? this->left_lane.end():
                           std::next(this->left_lane.begin(),this->left_lane.size()-1),
                            this->left_lane.end());
        p->set_score(this->tick_tag);

        if (p != nullptr)
            this->right_lane.push_back(p);
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

    this->vehicle_move();
    return 0;
}



    //change lane
    //move vehicle
    //update speed and see if crash
int road::vehicle_move(){

    //change lane
    if(this->left_lane_green){
        //std::cout << "l change lane"<<std::endl;
        if(this->right_lane_green){
            for(auto it_l = this->left_lane.begin(); it_l!=this->left_lane.end();){

                int fs,fs_ol,rs_ol;

                if(this->get_vehicle_distances(fs,fs_ol,rs_ol,it_l,true)){
                    if((*it_l)->get_changeLane_willingness(fs,fs_ol,rs_ol))    {
                        std::cout << "l change"<<std::endl;
                        change_lane(it_l,right_lane,left_lane);
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
        for(auto it_l = this->left_lane.begin(); it_l!=this->left_lane.end();it_l++){
            move(it_l);
        }
        //update speed and see if crash
        for(auto it_l = this->left_lane.begin(); it_l!=this->left_lane.end();it_l++){
            acceleration_checkcrash(it_l,this->left_lane_green,this->left_lane);
        }
    }

    if(this->right_lane_green){
        if(this->left_lane_green){
            //std::cout << "r change lane"<<std::endl;
            for(auto it_r = this->right_lane.begin(); it_r!=this->right_lane.end();){

                int fs,fs_ol,rs_ol;

                if(this->get_vehicle_distances(fs,fs_ol,rs_ol,it_r,false)){
                    if((*it_r)->get_changeLane_willingness(fs,fs_ol,rs_ol)){
                        change_lane(it_r,right_lane,left_lane);
                        //std::cout << "l change"<<std::endl;
                    }
                    else
                        it_r++;
                }
                else
                    it_r++;
            }
        }
 
        //for(auto it_r=this->right_lane.begin();it_r!=this->right_lane.end();){
            //change_lane(it_r,left_lane,right_lane);
        //    std::cout << "r change"<<std::endl;
        //}


        //std::cout << "move"<<std::endl;
        //std::cout <<"move right lane"<<std::endl;
        for(auto it_r=this->right_lane.begin();it_r!=this->right_lane.end();it_r++){
            move(it_r);
        }

        //std::cout << "update speed"<<std::endl;
        for(auto it_r=this->right_lane.begin(); it_r!=this->right_lane.end();it_r++){
            acceleration_checkcrash(it_r,this->right_lane_green,this->right_lane);
        }
    }
    return 0;
}    


int road::move(std::list<std::shared_ptr<vehicle>>::iterator it){
    (*it)->set_position((*it)->get_position() + (*it)->get_speed());
    //std::cout<<"cur pos is " <<(*it)->get_position()<<std::endl;
    return (*it)->get_position();
}

int road::change_lane( std::list<std::shared_ptr<vehicle>>::iterator& it,
        std::list<std::shared_ptr<vehicle>>& other_lane,
        std::list<std::shared_ptr<vehicle>>& this_lane){//,std::list<vehicle*> lane){
    //std::cout << "start changing"<<std::endl;
    if( it == this_lane.end()){
        std::cout<<"it is invalid for this lane"<<std::endl;    
        return -1;
    }
    if((*it)->get_changingTick() == this->tick_tag){
        it = std::next(it);
        return 0;
    }

    const auto it_cur = it;
    //change lane
    //if( dice::if_dice((*it)->get_changeLane_willingness()) ){
    //(it*)->set_score((it*)->get_score()+1);
    //        if(static_cast<float>((it*)->get_score()) / static_cast<float>(this->tick_tag) >
    //                                            this->alert_threshold)
    //            this->alert_vehicles.push_back(it);


    //std::cout << "inserting into other lane"<<std::endl;
    //insert into other lane
    if((*it)->get_frontVehicle_otherlane() == other_lane.end()){
        other_lane.push_front(*it);
        it = other_lane.begin();
    }
    else{
        auto temp = std::next((*it)->get_frontVehicle_otherlane());
        if(temp !=other_lane.end()){
            other_lane.push_back(*it);
            it = std::prev(other_lane.end(),1);
        }
        else
            it = other_lane.insert(temp,*it);
    }

    (*it)->set_changingTick(this->tick_tag);

    //std::cout << "update moving vehicle's frontvehicle_otherlane"<<std::endl;

    //update moving vehicle's frontVehicle_otherlane
    if(it_cur == this_lane.begin())
        (*it)->set_frontVehicle_otherlane(this_lane.end(),this_lane.end());
    else
        (*it)->set_frontVehicle_otherlane(std::prev(it_cur),this_lane.end());

    //#1 update vehicle on this lane 
    //update the-front-car-in-other-lane of the vehicles after moved vehicle 
    //until no affection from changing lane 
    /*
       std::cout << "number 1"<<std::endl;
       auto it_next= std::next(it_cur);

       while(it_next != this_lane.end()){

       auto temp = (*it_next)->get_frontVehicle_otherlane();

       if(temp == other_lane.end())
       break;
       if((*temp)->get_position() > (*it)->get_position()){
       (*it_next)->set_frontVehicle_otherlane(it);
       it_next++;
       }
       else
       break;
       };
     */

    //#2 update vehicle on the other lane
    //deal with the vehicle in other lane linking to the moved vehicle
    //if there is
    /*
       std::cout << "number 2"<<std::endl;

       auto it_cur_front = this_lane.end();
       if(it_cur == this_lane.begin())
       it_cur_front = this_lane.end();
       else
       it_cur_front = std::prev(it_cur);

       auto it_next_otherlane =std::next(it);
       while(it_next_otherlane != other_lane.end()){

       if((*it_next_otherlane)->get_frontVehicle_otherlane() == it_cur){ //&&
    //(*(*it_next_otherlane)->get_frontVehicle_otherlane())->get_position() > (*it_cur)->get_position())

    (*it_next_otherlane)->set_frontVehicle_otherlane(it_cur_front); 
    it_next_otherlane++;
    }
    else
    break;
    };
     */
    //std::cout << "erase done?"<<std::endl;
    it = std::next(it_cur);
    this_lane.erase(it_cur); 
    //std::cout << "erase done!"<<std::endl;

    //std::cout<<"return from change lane"<<std::endl;
    return 0;
    //update position
    //(*it)->set_position((*it)->get_position() + (*it)->get_speed());
    //(*it)->set_tick(tick_tag);
}
int road::acceleration_checkcrash( const std::list<std::shared_ptr<vehicle>>::iterator it,bool& green_light,std::list<std::shared_ptr<vehicle>>& lane){

    //assert(green_light == true);

    if(green_light == false)
        return 1; 



    if(it != lane.begin()){
        int space = (*(std::prev(it)))->get_position() - (*it)->get_position();

        if(space <= 0){
            green_light = false; 
            return 1;
        }
        else if( space <=20 && dice::if_dice(100) ){
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
        (*it)->acceleration();

    }

    std::cout << "speed after changing:"<<(*it)->get_speed()<<std::endl;

    if( (*it)->get_position() >  100*1000){
        lane.erase(it);
        return 1;
    }
    return 0;
        
}

