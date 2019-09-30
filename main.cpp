#include <iostream>
#include <unistd.h>



int main(){


    for(int i=0;i<100;i++){
        if(i==20){
            std::cout <<"t";
            continue;
        }
        std::cout <<"-";
    }
    std::cout <<std::endl;

    for(int i=0;i<100;i++)
        std::cout <<"-";
    std::cout <<std::endl;


    std::cout << "\e[A";
    std::cout << "\e[A";

    sleep(5);

    for(int i=0;i<100;i++){
        if(i==30){
            std::cout <<"t";
            continue;
        }
        std::cout <<"-";
    }
    std::cout <<std::endl;

    for(int i=0;i<100;i++){
        if(i==80){
            std::cout <<"c";
            continue;
        }
        std::cout <<"-";
    }
    std::cout <<std::endl;



}
