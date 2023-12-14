#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc != 3){
        return 1;
    }
    
    char com[][6] = {"START\0", "STOP\0"};
    int con = 0;
    int all_sec = 0;
    int sec = 0;
    char buf[50];
    char text[5000];
    int tcon = 0;
    
    FILE *input_file = fopen(argv[1], "r");
    if(input_file == NULL){
        return 1;
    }    
    
    char ch = fgetc(input_file);
    while(ch != EOF){
        while(ch != ' ' && ch != EOF){
            buf[con] = ch;
            con++;
            ch = fgetc(input_file);
        }
        buf[con] = ' ';
        con++;
        buf[con] = '\0';
        if(all_sec == 1){
            all_sec = 0;
            for(int a = 0; a < 4; a++){
                if(buf[a] != com[1][a] || buf[5] != '\0'){
                    all_sec = 1;
                    break;
                }
            }
        }
        if(all_sec == 1){
            if(sec == 1){
                for(int a = 0; a < con; a++){
                    text[tcon] = buf[a];
                    tcon++;
                }
                sec = 0;
            }
            else{
                sec = 1;
                text[tcon] = '\0';
            }
        }
        if(all_sec == 0){
            all_sec = 1;
            for(int a = 0; a < 5; a++){
                if(buf[a] != com[0][a] || buf[6] != '\0'){
                    all_sec = 0;
                    break;
                }
            }
        }
        con = 0;
        ch = fgetc(input_file);
    }
    fclose(input_file);
    
    FILE *output_file = fopen(argv[2], "w");
    if(output_file == NULL){
        return 1;
    }
    for(int a = 0; a < tcon-1; a++){
        fputc(text[a], output_file);
    }
    fclose(output_file);
    
    return 0;
}
