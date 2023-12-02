#include <stdio.h>
#include <stdlib.h> 
#include "ballsortpuzzle.h"
#include <time.h>

void generator(const int rows, const int columns, char field[rows][columns]){
    srand(time(NULL));
    int colon1 = rand() % columns;
    int colon2;
    do{
        colon2 = rand() % columns;
    }while(colon2 == colon1);

    char symbols[] = {'*', '^', '@', '+'};
    int count[4] = {0};

    for(int a = 0; a < columns; ++a){
        if(a == colon1 || a == colon2){
            for(int b = 0; b < rows; ++b){
                field[b][a] = ' ';
            }
        }
        else{
            for(int b = 0; b < rows; ++b){
                int ran;
                do{
                    ran = rand() % (sizeof(symbols) / sizeof(symbols[0]));
                }while(count[ran] >= rows);
                field[b][a] = symbols[ran];
                count[ran]++;
            }
        }
    }
}

int main() {
    const int rows = 4;
    const int columns = 6;
    char field[rows][columns];

    generator(rows, columns, field);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%c | ", field[i][j]);
        }
        printf("\n--- --- --- --- --- ---\n");
    }

    return 0;
}

