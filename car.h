#ifndef CAR_H
#define CAR_H



typedef struct str_car{
    unsigned int ID;
    int position;      //m
    int speed;         //m/s
    int insane_mode;
    float lane_change_possibility;
    struct str_car *next_car;
} str_car; 



str_car* car_factory();





#endif 



