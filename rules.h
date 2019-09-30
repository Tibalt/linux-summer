#ifndef RULES_H
#define RULES_H


const int LANE_LENGTH{100*1000}; 

//we assume that every CAR_MADE_SPEED seconds, 
//there is a car from car factory
const int CAR_MADE_SPEED{10};

const int DEFAULT_SIMULATION_TIME{100};//seconds

//we assume that the brake or accelation speed are the same
//todo: should be different from car to car
#define ACCELERATION 3 





/*
* so for the same car,  it could go insane INSANE_POSSIBILITY times every 1000*1000 seconds 
* and the insane status only last 5 seconds
*/
#define INSANE_POSSIBILITY  1      

/* 
* we assume that the driver is reasonable so that he
* probably follow the rules below
*/
#define MIN_SPEED 15             //   m/s  
//#define MAX_SPEED 40             //   m/s  



/*
* the space is defined so that 
* the reasonable car will slow down if the space with front car 
* is less than MIN_SPACE
*/
#define MIN_SPACE 100            //   m  

/*
* we only consider three numbers for changing lane when the car is sane
* 1. space between the current car and front car in the same lane
* 2. space between the current car and front car in the other lane
* 3. space between the current car and back car in the other lane
*/
#define SAMELANE_FRONTCAR_SPACE 90      //m
#define OTHERLANE_FRONTCAR_SPACE 120    //m
#define OTHERLANE_REARCAR_SPACE 120     //m



#endif 



