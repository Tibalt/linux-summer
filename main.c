#include "car.h"
#include "rules.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>





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

    while(p_car != NULL && p_car->rear_car_samelane != NULL){

        //move!!!
        p_car->position += p_car->speed;

        //acceleration or brake
        if((p_car->position - p_car->rear_car_samelane->position) < MIN_SPACE){
            if(p_car->rear_car_samelane->speed >MIN_SPEED + ACCELERATION){
                p_car->rear_car_samelane->speed -=ACCELERATION;
            }
        }
        else{
            if(p_car->rear_car_samelane->speed < MAX_SPEED -ACCELERATION){
                p_car->rear_car_samelane->speed +=ACCELERATION;
            }
        }
        
        //move out the cars from lane
        if(p_car->position > LANE_LENGTH){
            p_lane_head = p_car->rear_car_samelane;
            free(p_car);
        }

        p_car = p_car->rear_car_samelane;
    }


    return p_lane_head;
}


int update_car_sideview(str_car *p_car1,str_car *p_car2){
    if(p_car1 == NULL || p_car2 == NULL){
        printf("pass NULL to update_car_sideview");
        return -1; 
    }

    while(p_car1 != NULL){
        while(p_car2 != NULL){
            if(p_car1->position <= p_car2->position &&
                p_car1->position >= p_car2->rear_car_samelane->position){
                p_car1->front_car_otherlane = p_car2;
                //p_car1->rear_car_otherlane  = p_car2->rear_car_samelane;
            }
            p_car2 = p_car2->rear_car_samelane;
        }
        p_car1 = p_car1->rear_car_samelane;
    }
    return 0;
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
                p_lane2_cartail = put_car_onlane(p_lane2_carhead);
            else
                p_lane2_cartail = put_car_onlane(p_lane2_cartail);

            p_lane1_cartail->front_car_otherlane = p_lane2_cartail;
            p_lane2_cartail->front_car_otherlane = p_lane1_cartail;

        }

        //pick up the lane-changing car
        //assume changing lane is OK from lane1 to lane2, not OK the other way around
        //todo: enable lane changing for two lanes
        str_car *p_car = p_lane1_carhead;
        while(p_car != NULL && p_car->rear_car_samelane != NULL){
            str_car *p_rear_car = p_car->rear_car_samelane;

            if( (p_car->position - p_rear_car->position < SAMELANE_FRONTCAR_SPACE) &&  
                    (p_rear_car->position - p_rear_car->front_car_otherlane->rear_car_samelane->position > OTHERLANE_REARCAR_SPACE)&&
                    (p_rear_car->front_car_otherlane->position - p_rear_car->position > OTHERLANE_FRONTCAR_SPACE)){
                //todo: count the possibility
                //quit from lane1
                p_car->rear_car_samelane = p_rear_car->rear_car_samelane;
                //join lane2
                str_car *p_tmp_car = p_rear_car->front_car_otherlane->rear_car_samelane; 
                p_rear_car->front_car_otherlane->rear_car_samelane = p_rear_car;
                p_rear_car->rear_car_samelane = p_tmp_car;
            }
            p_car = p_rear_car;
        }
        //move the car according the speed
        p_lane1_carhead = move_lane(p_lane1_carhead);
        p_lane2_carhead = move_lane(p_lane2_carhead);
    } 
    update_car_sideview(p_lane1_carhead,p_lane2_carhead);

    printf("hello world!\n");
    return 0;
}
