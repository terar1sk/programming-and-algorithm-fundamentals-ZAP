#include <superkarel.h>
#define SPEED 100
#define FIC front_is_clear()
#define FIB front_is_blocked()
#define BP beepers_present()
#define BIB beepers_in_bag()
#define NBP no_beepers_present()
#define NFE not_facing_east()

bool check();
void create();
void go_next();

int main(){
    turn_on("task_4.kw");
    set_step_delay(SPEED);

    while(FIC){
        if(check()){
            create();
        }
        else{
            go_next();
        }
    }
    if(check()){
        create();
    }
    else{
        go_next();
    }

    turn_off();
    return 0;
}

bool check(){
    turn_left();
    while(FIC && NBP){
        step();
    }  
    if(BP){
        while(FIC){
            step();
        }
        turn_left();
        turn_left();
        return true;
    }
    turn_left();
    turn_left();
    return false;
}

void create(){
    while(FIC){
        if(NBP){
            put_beeper();
        }
        step();
    }
    if(NBP){
        put_beeper();
    }
    turn_left();
    if(FIC){
        step();
    }
}

void go_next(){
    while(FIC){
        step();
    }
    turn_left();
    if(FIC){
        step();
    }
}
