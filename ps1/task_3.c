#include <superkarel.h>
#define SPEED 200
#define FIC front_is_clear()
#define BP beepers_present()
#define NBP no_beepers_present()
#define RIB right_is_blocked()
#define FIB front_is_blocked()
#define RIC right_is_clear()
#define BIB beepers_in_bag()
#define RIC right_is_clear()
#define FN facing_north()

bool sort();
void next_lvl();
void comeback();
void pick_bep();
void put_bep();
void ret();
void turn_right();
void cometo_north();
bool checking();

int main(){
    turn_on("task_3.kw");
    set_step_delay(SPEED);

    while(sort()){
        next_lvl();
    }
    comeback();

    turn_off();
    return 0;
}

bool sort(){
    pick_bep();
    if(BIB){
        ret();
        put_bep();
        return true;
    }
    return false;
}

bool checking(){
    if(RIB){
        return true;
    }
    turn_right();
    step();
    ret();
    if(NBP){
        step();
        turn_right();
        return true;
    }
    step();
    turn_right();
    return false;
}

void next_lvl(){
    turn_left();
    if(FIC){
        step();
        turn_left();
    }
}

void comeback(){
    while(NBP){
        while(NBP && FIC){
            step();
        }
        if(NBP){
            cometo_north();
            step();
            if(RIB){
                turn_left();
            }
            else{
                turn_right();
            }
        }
    }
    cometo_north();
    while(FIC){
        step();
    }
    turn_left();
    while(FIC){
        step();
    }
    ret();
}

void pick_bep(){
    while(FIC){
        if(BP){
            pick_beeper();
        }
        step();
    }
    if(BP){
        pick_beeper();
    }
}

void put_bep(){
    while(FIC){
        if(BIB){
            if(checking()){
                put_beeper();
            }
        }
        step();
    }
    if(BIB){
        if(checking()){
            put_beeper();
        }
    }
}

void ret(){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(SPEED);
}

void cometo_north(){
    while(!FN){
        turn_left();
    }
}

void turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    turn_left();
    set_step_delay(SPEED);
}

1
