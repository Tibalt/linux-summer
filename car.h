#ifndef CAR_H
#define CAR_H



typedef struct str_car{
    unsigned int ID;
    int position;      //m
    int speed;         //m/s
    int insane_mode;
    float lane_change_possibility;
    struct str_car *rear_car_samelane;
    struct str_car *front_car_otherlane;
    struct str_car *rear_car_otherlane;
} str_car; 



str_car* car_factory();





#endif 



