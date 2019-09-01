#include "car.h"
#include "rules.h"
#include <assert.h>
#include <stdlib.h>




str_car *put_car_onlane(str_car *p_car_lane){

    str_car *p_car = car_factory();
    assert(p_car != NULL);

    if(p_car_lane == NULL)
        p_car_lane = p_car;
    else
        p_car_lane->rear_car_samelane = p_car;

    return p_car;
}


str_car * move_lane(str_car *p_car_lane){
    if(p_car_lane == NULL){
        printf("NULL pointer to function move_lane\n");
        return NULL; 
    }
    str_car *p_lane_head=p_car_lane;
    str_car *p_car = p_car_lane;

    //move out the cars from lane
/*
    while(p_car != NULL){
        p_car->position += p_car->speed;
        if(p_car->position > LANE_LENGTH){
            p_1ane_head = p_car->rear_car_samelane;
            delete p_car;
            p_car = NULL;
        }
        else
            p_car = p_lane_head;
    }

*/
    //move the car, and change the speed
    p_car  = p_lane_head;

    //while(p_car != NULL){
       //if(
       // p_car = p_car->rear_car_samelane;
    //}

    return p_lane_head;
}



//todo: we should let user run the program with arguments 
int main(int argc, char **argv)
{
    str_car *p_lane1_carhead = NULL;   
    str_car *p_lane1_cartail = NULL;   
    str_car *p_lane2_carhead = NULL;   
    str_car *p_lane2_cartail = NULL;   



    for(int i=0;i<DEFAULT_SIMULATION_TIME;i++){

        if(i%CAR_MADE_SPEED == 0){
            if(p_lane1_carhead == NULL)
                p_lane1_cartail = put_car_onlane(p_lane1_carhead);
            else
                p_lane1_cartail = put_car_onlane(p_lane1_cartail);



            if(p_lane2_carhead == NULL)
                p_lane1_cartail = put_car_onlane(p_lane2_carhead);
            else
                p_lane1_cartail = put_car_onlane(p_lane2_cartail);

            p_lane1_cartail->front_car_otherlane = p_lane2_cartail;
            p_lane1_cartail->front_car_otherlane = p_lane1_cartail;

        }

        //pick up the lane-changing car
        //assume changing lane is OK from lane1 to lane2, not OK the other way around
        //todo: enable lane changing for two lanes
        str_car *p_car = p_lane1_carhead;
        while(p_car != NULL && p_car->rear_car_samelane != NULL){
            str_car *p_rear_car = p_car->rear_car_samelane;

            if( (p_car->position - p_rear_car->position < SAMELANE_FRONTCAR_SPACE) &&  
                    (p_rear_car->position - p_rear_car->rear_car_otherlane->position > OTHERLANE_REARCAR_SPACE)&&
                    (p_rear_car->front_car_otherlane->position-p_rear_car->position> OTHERLANE_FRONTCAR_SPACE)){
                //todo: count the possibility
                //quit from lane1
                p_car->rear_car_samelane = p_rear_car->rear_car_samelane;
                //join lane2
                p_rear_car->front_car_otherlane->rear_car_samelane = p_rear_car;
                p_rear_car->rear_car_samelane = p_rear_car->rear_car_otherlane;
            }
            p_car = p_rear_car;
        }
        //move the car according the speed
        p_lane1_carhead = move_lane(p_lane1_carhead);
        p_lane2_carhead = move_lane(p_lane2_carhead);
    } 

    printf("hello world!\n");
    return 0;
}
