#include <stdio.h>
#include <stdbool.h>

void encode_char(const char character, bool bits[8]){
    for(int a = 7;a >= 0;--a){
        bits[a]=(character >>(7-a))&1;
    }
}

char decode_byte(const bool bits[8]){
    char res = 0;
    for(int a = 0;a < 8;++a){
        res = (res << 1)|bits[a];
    }
    return res;
}

void encode_string(const char string[], bool bytes[strlen(string) + 1][8]){
    int chis = strlen(string);
    for(int b = 0;b <= chis;b++){
        char character = (b ==chis)? '\0': string[b];
        for(int s = 7;s >= 0;s--){
            bytes[b][s] = (character >> (7-s))&1;
        }
    }
}

void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]){
    for(int b = 0;b < rows;b++){
        char charac = 0;
        for(int a = 0;a < 8;a++){
            charac = (charac << 1)|bytes[b][a];
        }
        string[b] = charac;
    }
}

int main(){

    return 0;
}
