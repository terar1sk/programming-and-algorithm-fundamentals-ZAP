#include <superkarel.h>
#define SPEED 200
#define FIC front_is_clear()
#define LIC left_is_clear()
#define RIC right_is_clear()
#define NBP no_beepers_present()

void turn_right();
void check();
void next();
void back();

int main(){
    turn_on("task_7.kw");
    set_step_delay(SPEED);

    while(FIC){
        if(LIC){
            put_beeper();
        }
        step();
    }
    if(LIC){
        put_beeper();
        turn_left();
        turn_left();
    }
    check();
    turn_left();
    turn_left();
    while(FIC){
        step();
    }

    turn_off();
    return 0;
}

void check(){
    while(FIC && NBP){
        step();
    }
    if(NBP){
        return;
    }
    turn_right();
    step();
    put_beeper();
    next();
    if(!FIC){
        pick_beeper();
        turn_left();
        turn_left();
        step();
        put_beeper();
        back();
        step();
        pick_beeper();
        turn_right();
    }
    else{
        pick_beeper();
        step();
        if(!NBP){
            pick_beeper();
            turn_right();
        }
        else{
            turn_left();
            turn_left();
            step();
            pick_beeper();
            back();
            step();
            pick_beeper();
            turn_right();
        }
    }
    check();
}

void next(){
    do{
        if(!LIC && FIC){
            step();
        }
        else if(LIC && FIC){
            turn_left();
            step();
        }
        else if(!LIC && !FIC){
            turn_right();
        }
        else{
            turn_left();
            step();
        }
    }while(NBP);
}

void back(){
    do{
        if(!RIC && FIC){
            step();
        }
        else if(RIC && FIC){
            turn_right();
            step();
        }
        else if(!RIC && !FIC){
            turn_left();
        }
        else{
            turn_right();
            step();
        }
    }while(NBP);
}

void turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(SPEED);
    turn_left();
}

