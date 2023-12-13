#include <stdio.h>

void wrt(FILE *file, int num){
    if(num == 0){
        fputc('0', file);
        return;
    }
    char digits[10];
    int a = 0;
    
    while(num > 0){
        digits[a] = '0' + num % 10;
        num /= 10;
        a++;
    }
    for(int b = a - 1; b >= 0; b--){
        fputc(digits[b], file);
    }
}

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s <input/output file>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r+");
    if(file == NULL){
        perror("Error opening file");
        return 1;
    }
    int con = 0;
    int cur;
    int ind = 0;
    while((cur = fgetc(file)) != EOF){
        char lowerChar = (char)tolower(cur);
        if(lowerChar == "ananas"[ind]){
            ind++;
            if("ananas"[ind] == '\0'){
                con++;
                ind = 0;
            }
        }
        else{
            ind = 0;
        }
    }
    rewind(file);
    wrt(file, con);
    fputc('\n', file); 
    fclose(file);

    return 0;
}

