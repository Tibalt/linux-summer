#include "car.h"
#include <stdlib.h>




str_car* car_factory(){
    static int nextID=1;
    str_car * p_car = malloc(sizeof(str_car));    
    if(p_car == NULL)
        return NULL;

    p_car->ID = nextID++;
    p_car->position = 0;
    p_car->insane_mode = 0;
    p_car->speed = 0;   //between MIN_SPEED ~ MAX_SPEED,assume all the car from car factory is sane  
    p_car->lane_change_possibility = 0; //random number gennerator, between 0 ~ 100
    p_car->next_car = NULL;

    return p_car;

}
