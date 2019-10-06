#include <string>
#include <memory>
#include <iostream>
#include <stdlib.h>
#include "vehicle.h"
//#include "car.h"
//#include "truck.h"
//#include "bus.h"
#include "van.h"
#include "rules.h"


static const int VEHICLETYPE=4 ;

class dice{
    public:
        static bool if_dice(unsigned int possibility){
            if(possibility >=100)
                return true; 

            if(static_cast<unsigned int>(rand())%100 > possibility) {
                return false;
            }
            else
                return true;
        }

        static unsigned int possibility_dice(){
            return rand()%100;
        }

        static unsigned int number_dice(int nu){
            return rand()%nu;
        }
        
};

class vehicleFactory{

public:
    static std::shared_ptr<vehicle> spit_vehicle(lane_iterator it,lane_iterator pass_end){

        std::shared_ptr<vehicle> p = nullptr ;

        int type = rand()%VEHICLETYPE;

        type = 3;

        if(type == 0);
            //p = std::make_shared<car()>();
        else if(type == 1);
            //p = std::make_shared<truck()>();
        else if(type == 2);
            //p = std::make_shared<bus()>();
        else if(type == 3){
            //unsigned int cw =dice::possibility_dice(); 
            //std::cout << "cw is "<<cw<<std::endl;
            unsigned int speed = dice::number_dice(40);
            p = std::make_shared<van>(it,pass_end,speed < MIN_SPEED? MIN_SPEED:speed);
            std::cout  << " position = " << p->get_position()
                << " speed = " << p->get_speed()
                << " if_insane = " <<p->is_Insane()<<std::endl;
        }
        else
            std::cout << "check how many vehicle types do you have?"<<std::endl;
       /* 
        if(p != nullptr)
            std::cout  << " position = " << p->get_position()
                << " speed = " << p->get_speed()
                << " if_insane = " <<p->is_Insane()<<std::endl;
        else
            std::cout <<"no vehicle is generated!"<<std::endl;
        */

        return p;
    }
};



