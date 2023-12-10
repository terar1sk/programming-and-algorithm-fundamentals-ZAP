#include <ncurses.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


char fill[14][21];
int i, key;
int sp = 0, speed;
int x = 5, y = 11;
int ax = 8, ay = 3;
int ox, oy;

struct pyt{
    int old_x, old_y;
}pyt_old[216];

void pytmov(void);
char lvl(int sp);

int main(){
    initscr();
    start_color();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK); 
    
    do{
        strcpy(fill[0], "####################");
        for(i = 1; i < 13; i++)
            strcpy(fill[i], "#                  #");
        strcpy(fill[13], "####################");

        attron(COLOR_PAIR(1));
        if(x > ox)
        fill[y][x] = '>';
        else if(x < ox)
        fill[y][x] = '<';
        else if(y < oy)
        fill[y][x] = '^';
        else if(y > oy)
        fill[y][x] = 'v';
        else
        fill[y][x] = '@';
        attroff(COLOR_PAIR(1));

        if(sp > 0){
            for(i = 0; i < sp; i++)
                fill[pyt_old[i].old_y][pyt_old[i].old_x] = '#';
        }

        attron(COLOR_PAIR(2));
        fill[ay][ax] = '*';
        attroff(COLOR_PAIR(2));

        move(0, 0);
        printw("Apples: %5d\n", sp);
        printw("Level         ");
        lvl(sp);
        for(i = 0; i < 14; i++)
            printw("%s\n", fill[i]);

        refresh();
        curs_set(0);
        noecho();

        if((sp >= 0) && (sp < 3))
            speed = 10;
        else if((sp >= 3) && (sp < 6))
            speed = 7;
        else if((sp >= 6) && (sp < 9))
            speed = 5;
        else if(sp >= 9)
            speed = 3;

        halfdelay(speed);
        key = getch();

        ox = x;
        oy = y;

        switch(key){
            case 'w':
                    y--;
                break;
            case 's':
                    y++;
                break;
            case 'a':
                    x--;
                break;
            case 'd':
                    x++;
                break;
            case ERR:
                    pytmov();
                break;
        }

        if(fill[y][x] == '#'){
            x = ox;
            y = oy;
        }

        if(fill[y][x] != '#'){
            for(i = sp; i >= 0; i--){
                pyt_old[i + 1].old_x = pyt_old[i].old_x;
                pyt_old[i + 1].old_y = pyt_old[i].old_y;
            }
            pyt_old[0].old_x = ox;
            pyt_old[0].old_y = oy;
        }

        if(fill[y][x] == '#'){
            cbreak();
            move(9, 5);
            printw("GAME OVER     #\n");
            refresh();
            getch();
            break;
        }

        if((x == ax) && (y == ay)){
            ax = rand() % (18 - 1) + 1;
            ay = rand() % (12 - 1) + 1;
            sp++;
        }

        if((fill[ay][ax] == '#') || (ax == x) && (ay == y) || ((ax == ox) && (ay == oy))){
            while(((ax == x) && (ay == y)) || (fill[ay][ax] == '#') || ((ax == ox) && (ay == oy))){
                ax = rand() % (18 - 1) + 1;
                ay = rand() % (12 - 1) + 1;
            }
        }
    }while(key != 'q');

    endwin();
    return 0;
}

void pytmov(void){
    if(fill[y][x] == '^') y--;
    if(fill[y][x] == 'v') y++;
    if(fill[y][x] == '<') x--;
    if(fill[y][x] == '>') x++;
}

char lvl(int sp){
    if((sp >= 0) && (sp < 3))
        printw("1 (x1)\n");
    else if((sp >= 3) && (sp < 6))
        printw("2 (x1,50)\n");
    else if((sp >= 6) && (sp < 9))
        printw("3 (x2,00)\n");
    else if(sp >= 9)
        printw("4 (x2,50)\n");
}

