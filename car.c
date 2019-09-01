#include "car.h"
#include "rules.h"
#include <stdlib.h>
#include <assert.h>




str_car* car_factory(){
    static int nextID=1;
    str_car * p_car = malloc(sizeof(str_car));    
    if(p_car == NULL)
        return NULL;

    p_car->ID = nextID++;
    p_car->position = 0;

    //assume all the car from car factory is sane
    p_car->insane_mode = 0;

    //between MIN_SPEED ~ MAX_SPEED, 
    p_car->speed = (random()/RAND_MAX)*(MAX_SPEED - MIN_SPEED) + MIN_SPEED;   
    assert(p_car->speed > MIN_SPEED && p_car->speed < MAX_SPEED);

    p_car->lane_change_possibility = random()/RAND_MAX; //random number gennerator

    p_car->rear_car_samelane = NULL;
    p_car->rear_car_otherlane = NULL;
    p_car->front_car_otherlane = NULL;

    return p_car;

}
