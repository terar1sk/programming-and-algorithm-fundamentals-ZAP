#include <superkarel.h>

#define SPEED 200
#define NBP no_beepers_present()
#define NFE not_facing_east()
#define FIC front_is_clear()
#define NFN not_facing_north()

void check();
void turn_right();

int main(){
    turn_on("task_6.kw");
    set_step_delay(SPEED);

    check();

    turn_off();
    return 0;
}

void check(){
    while(FIC && NBP){
        step();
    }

    while(NFE){
        turn_left();
    }
    pick_beeper();
    turn_left();
    if(NBP){
        check();
    }
    else{
        while(!NBP){
            pick_beeper();
            turn_left();
        }
        if(NFN){
            check();
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
