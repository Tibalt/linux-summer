#ifndef RULES_H
#define RULES_H

#define LANE_LENGTH 100*1000           //m

/*
* so for the same car,  it could go insane INSANE_POSSIBILITY times every 1000*1000 seconds 
* and the insane status only last 5 seconds
*/
#define INSANE_POSSIBILITY  1      

/* 
* we assume that the driver is reasonable so that he
* probably follow the rules below
*/
#define MIN_SPEED 20             //   m/s  
#define MAX SPEED 40             //   m/s  



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
#define OTHERLANE_BACKCAR_SPACE 120     //m



#endif 



