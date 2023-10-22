#include <superkarel.h>
#define SPEED 100
#define RIB right_is_blocked()
#define RIC right_is_clear()
#define FIC front_is_clear()
#define FIB front_is_blocked()
#define NBP no_beepers_present()
#define BP beepers_present()
#define LIB left_is_blocked()
#define LIC left_is_clear()
 
void walk();
void turn_right();
void walk_back();
void put_bep();
 
int main(){
    turn_on("task_1.kw");
    set_step_delay(SPEED);

    put_beeper();
    put_bep();
    walk();
    pick_beeper();
    walk_back();

    turn_off();

    return 0;
}

void walk(){
    while(NBP){
        if(FIC && RIC){
            turn_right();
            step();
        }
        else if(RIB && FIC){
            step();
        }
        else if(FIB && RIC){
            turn_right();
            step();
        }
        else if(FIB && RIB){
            turn_left();
        }
    }
}
void walk_back(){
    while(NBP){
        if(FIB && RIB){
            turn_left();
            turn_left();
        }
        if(FIC && LIB){
            step();
        }
        if(FIC && LIC){
            turn_left();
            step();
        }
        else if(FIB && LIC){
            turn_left();
            step();
        }
	else if(FIB && RIC){
	    turn_left();
	    turn_left();
	    turn_left();
	}
    }
}

void put_bep(){
    while(BP){
        if(FIC){
            step();
        }
        if(FIB && RIB){
            turn_left();
        }
        else if(FIB){
            turn_left();
        }
    }
}
void turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    turn_left();
    set_step_delay(SPEED);
}
