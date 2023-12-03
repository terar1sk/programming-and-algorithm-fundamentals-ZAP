#include "ballsortpuzzle.h"

int main() {
    ball_sort_puzzle();
    const int rows = 4;
    const int columns = 6;
    char field[rows][columns];
    generator(rows, columns, field);
    for(int a = 0; a < rows; ++a){
       for(int c = 0; c < columns; ++c){
           printf("%c | ", field[a][c]);
       }
       printf("\n--- --- --- --- --- ---\n");
    }

    return 0;
}


