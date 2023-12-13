#include <stdio.h>
#include <ctype.h>

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
    fprintf(file, "%d\n", con);
    fclose(file);

    return 0;
}

