#include "van.h"
#include "bold.h"
#include "cautious.h"
#include <memory>
#include "rules.h"
#include "vehicle_factory.hpp"


van::van( lane_iterator it,
         lane_iterator pass_end, unsigned int speed)
                :vehicle(it,pass_end,speed,40){

     this->m_accLimit = 40;
     this->m_accCo = 4;

    if(speed > 40)
        this->set_speed(40);




    if(dice::if_dice(50))
        this->m_vehicle_driver= std::make_shared<BoldDriver>();
    else
        this->m_vehicle_driver= std::make_shared<CautiousDriver>();
    
}


van::~van(){

}

std::string van::get_name(){
    return "van"+std::to_string(this->get_score());
}



unsigned int van::get_speedlimit(){
    return 40;
}
