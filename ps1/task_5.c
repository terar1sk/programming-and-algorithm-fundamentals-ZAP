#include <superkarel.h>
#define SPEED 100
#define FIC front_is_clear()
#define NBP no_beepers_present()

void check();
void check_all();
void turn_right();
void start_pos();
void ret();
void find();
void find_bep();
void rem();
void pick_bep_up();
void moveto();
void bep_wall();
void frame();

int main(){
    turn_on("task_5.kw");
    set_step_delay(SPEED);

    start_pos();
    check_all();
    turn_left();
    while(FIC){
        step();
    }
    turn_left();
    frame();
    turn_left();
    step();
    while(NBP){
        step();
    }
    pick_beeper();
    while(not_facing_north()){
        turn_left();
    }

    turn_off();
    return 0;
}

void frame(){
    while(NBP){
        if(NBP && FIC){
            put_beeper();
            step();
        }
        else if(!FIC && NBP){
            put_beeper();
            turn_left();
            step();
        }
    }
}

void check_all(){
    check();
    turn_left();
    pick_beeper();
    check();
}

void start_pos(){
    while(not_facing_south()){
        turn_left();
    }
    while(FIC){
        step();
    }
    turn_right();
    while(FIC){
        step();
    }
    while(not_facing_east()){
        turn_left();
    }
}

void check(){
    put_beeper();
    if(FIC){
        step();
        if(FIC){
            find();
            rem();
            moveto();
        }
        else{
            ret();
            step();
            moveto();
        }
    }
}

void bep_wall(){
    while(FIC){
        step();
    }
    put_beeper();
    ret();
    step();
}

void moveto(){
    while(NBP){
        step();
    }
}

void find(){
    bep_wall();
    while(NBP){
        step();
        if(!NBP){
            ret();
            step();
            put_beeper();
        }
        find_bep();
    }
}

void find_bep(){
    if(NBP){
        while(NBP){
            step();
        }
        ret();
        step();
        put_beeper();
        step();
    }
}

void rem(){
    pick_bep_up();
    ret();
    moveto();
    pick_bep_up();
    ret();
}

void pick_bep_up(){
    while(FIC){
        step();
        pick_beeper();
    }
}

void ret(){
    set_step_delay(0);
    turn_left();
    set_step_delay(SPEED);
    turn_left();
}

void turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(SPEED);
    turn_left();
}

