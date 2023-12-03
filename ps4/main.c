#include "ballsortpuzzle.h"

int main() {
    ball_sort_puzzle();
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


