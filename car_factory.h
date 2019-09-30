#include <string>
#include <stdlib.h>
#include "vehicle.h"
#include "car.h"
#include "truck.h"
#include "bus.h"
#include "van.h"


static const int VEHICLETYPE=4 



class vehicleFactory{
public:

    static vehicle *spit_vehicle(){

        std::shared_ptr<vechicle> p;

        int type = rand()%CARTYPE;

        if(type == 0)
            p = std::make_shared<car>();
        else if(type == 1)
            p = std::make_shared<truck>();
        else if(type == 2)
            p = std::make_shared<bus>();
        else if(type == 3)
            p = std::make_shared<van>();
        else
            std::cout << "check how many vehicle types do you have?"<<endl;

        return p;
    }



}





