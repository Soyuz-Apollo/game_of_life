#include "Life.h"
#include <unistd.h>
#include <cstdlib>

int main(){
  system("clear");
    Life a;
    a.init_world();//initialization of random world

    a.out_world();//console world output

    unsigned int microsec = 1000000;//time of pause im microseconds

//main game loop
    while(a.sigma_of_life()) {
        usleep(microsec);
        a.update_generation();
        system("clear");
        a.out_world();
    }
    return 0;
}