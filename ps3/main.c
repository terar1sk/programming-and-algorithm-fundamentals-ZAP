#include "hangman.h"

int main(){
    char secret[30];
    get_word(secret);
    hangman(secret); 

    return 0;
}
