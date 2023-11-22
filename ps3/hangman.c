#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include <string.h>
#include <ctype.h>

int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[]){
    for(int a=0; secret[a]!='\0';a++){
        int ges = 0;
        for(int b=0; letters_guessed[b]!='\0';b++){
            if(secret[a]==letters_guessed[b]){
                ges = 1;
                break;
            }
        }
        if(!ges){
            return 0;
        }
    }
    return 1;
}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
    int a;
    for(a = 0;secret[a] != '\0';a++){
        int ges = 0;
        for(int b = 0;letters_guessed[b] != '\0';b++){
            if(secret[a] == letters_guessed[b]){
                ges = 1;
                break;
            }
        }
        guessed_word[a] = (ges) ? secret[a] : '_';
    }
    guessed_word[a] = '\0';
}

void get_available_letters(const char letters_guessed[], char available_letters[]){
    const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    strcpy(available_letters, alphabet);
    for(int a=0; letters_guessed[a]!='\0';a++){
        char *position = strchr(available_letters,letters_guessed[a]);
        if(position != NULL){
            memmove(position, position + 1, strlen(position));
        }
    }
}

void hangman(const char secret[]){
    const int max_at = 8;
    char guessed_word[100];
    char available_letters[27];

    memset(guessed_word, '\0', sizeof(guessed_word));
    get_available_letters(guessed_word, available_letters);

    printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %zu letters long.\n", strlen(secret));

    int at = max_at;

    while (at > 0 && !is_word_guessed(secret, guessed_word)){
        printf("-------------\n");
        printf("You have %d guesses left.\n", at);
        printf("Available letters: %s\n", available_letters);

        char guess;
        printf("Please guess a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        if(isalpha(guess)){
            if(strchr(available_letters, guess)){
                size_t length = strlen(secret);
                for (size_t a = 0; a < length; ++a){
                    if (secret[a] == guess) {
                        guessed_word[a] = guess;
                    }
                }

                get_available_letters(guessed_word, available_letters);
                get_guessed_word(secret, guessed_word, guessed_word);

                printf("Good guess: %s\n", guessed_word);
            }
            else{
                printf("Oops! You've already guessed that letter: %s\n", guessed_word);
            }
        }
        else{
            printf("Oops! '%c' is not a valid letter: %s\n", guess, guessed_word);
        }
        --at;
    }
    printf("-------------\n");
    if(is_word_guessed(secret, guessed_word)){
        printf("Congratulations, you won!\n");
    }
    else{
        printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
    }
}

