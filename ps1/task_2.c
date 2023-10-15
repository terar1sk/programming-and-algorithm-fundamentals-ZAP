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
void turn_right();

int main(){
     turn_on("task_2.kw");
     set_step_delay(SPEED);
  
     walk();
     bep();
     walk_back();

     turn_off();
     return 0;
}
   
void walk(){
    while(NBP){
        if(FIB){
            turn_left();
        }
        else{
            step();
        }
    }
}
   
void bep(){
    while(BP){
        pick_beeper();
    }
}
    
void walk_back(){
    while(NBP){
        if(FIB && RIB){
            turn_left();
        }
        else if(FIC && LIB){
            step();
        }
        else if(FIB && LIB){
            turn_right();
        }
         if(FIB && RIB && LIB){
            break;
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
