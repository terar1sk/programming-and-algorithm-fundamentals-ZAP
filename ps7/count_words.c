#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r+");
    if(file == NULL){
        return 1;
    }

    int con = 0;
    char word[] = "ananas";
    int ind = 0;
    
    char ch = fgetc(file);
    while(ch != EOF){
        if(ch == word[ind] || ch == word[ind] - 32){
            ind++;
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
    for(int a = 10000; a >= 1; a /= 10){
        if(con >= a){
            printf("%d\n", con / a);
            con -= con / a * a;
        }
    }
    putchar(con + 48);
    
    return 0;
}

