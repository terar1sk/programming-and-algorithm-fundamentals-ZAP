#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        return 1;
    }
    
    int con = 0;
    char word[] = "ananas";
    int ind = 0;
    
    FILE *file = fopen(argv[1], "r");
    if(file == NULL){
        return 1;
    }

    char ch = fgetc(file);
    while(ch != EOF){
        if(ch == word[ind] || ch == word[ind]-32){
            ind++;
        }
        else if(ch == word[0]){
            ind = 1;
        }
        else{
            ind = 0;
        }
        ch = fgetc(file);
        if(ind == 6){
            con++;
            ind = 0;
        }
    }
    fclose(file);
    
    FILE *fl = fopen(argv[1], "w");
    for(int a = 100; a >= 1; a /= 10){
        if(con >= a){
            fputc(con/a+48, fl);
            con -= con/a * a;
        }
        else if(con == 0){
            fputc(con+48, fl);
            break;
        }
    }
    fclose(fl);
    
    return 0;
}

