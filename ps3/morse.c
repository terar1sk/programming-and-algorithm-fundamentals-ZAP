#include <stdio.h>
#include <string.h>
#include "morse.h"

void text_to_morse(const char text[], char output[]){
    const char *mor[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ""}; 
    size_t textl = strlen(text);
    output[0] = '\0';
    for (size_t a = 0;a<textl;a++){
        if (text[a] == ' ') {
            strcat(output," "); 
        }
        else{
            int index = text[a] - 'A';
            if(index >= 0 && index < 26){
                strcat(output,mor[index]);
                strcat(output, " "); 
            }
        }
    }
}


