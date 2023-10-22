#include <superkarel.h>
#define SPEED 100
#define BP beepers_present()
#define NBP no_beepers_present()
#define FIB front_is_blocked()
#define RIB right_is_blocked()
#define LIB left_is_blocked()
#define FIC front_is_clear()

void walk();
void bep();
void walk_back();
void st();
void turn_right();
void turn_back();

int main(){
    turn_on("task_2.kw");
    set_step_delay(SPEED);

    walk();
    pick_beeper();
    turn_back();
    st();
    walk_back();

    turn_off();
    return 0;
}

void walk(){
    while(NBP){
        while(NBP && LIB){
            step();
        }
        if(NBP){
            turn_left();
            step();
        }
   }
}

void walk_back(){
    while((FIB == 0) || (LIB == 0) || (RIB == 0)){
        while(FIC && RIB){
            step();
        }
        if(!RIB){
            turn_right();
            step();
        }
    }
}

void st(){
    if(NBP){
        step();
    }
}

void turn_back(){
    turn_left();
    turn_left();
}

void turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    turn_left();
    set_step_delay(SPEED);
}

