#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc != 3){
        return 1;
    }

    FILE *inp = fopen(argv[1], "r");
    if(inp == NULL){
        return 1;
    }

    FILE *otp = fopen(argv[2], "w");
    if(otp == NULL){
        fclose(inp);
        return 1;
    }

    int ss = 0;
    int sec = 0;

    int cur;
    while((cur = fgetc(inp)) != EOF){
        if(ss){
            if(cur == ' ' || cur == '\n' || cur == '\t'){
                sec = !sec;
            }
            if(sec){
                fputc(cur, otp);
            }
        }
        if(cur == 'S'){
            int mt = 1;
            for(int a = 1; a < 5; ++a){
                cur = fgetc(inp);
                if(cur != "START"[a]){
                    mt = 0;
                    break;
                }
            }
            if(mt){
                ss = 1;
                sec = 0;
            }
            else{
                fputc('S', otp);
                fseek(inp, -4, SEEK_CUR);
            }
        }
        else if(cur == 'S' && ss){
            int mt = 1;
            for(int a = 1; a < 4; ++a){
                cur = fgetc(inp);
                if(cur != "STOP"[a]){
                    mt = 0;
                    break;
                }
            }
            if(mt){
                break; 
            }
            else{
                fputc('S', otp);
                fseek(inp, -3, SEEK_CUR);
            }
        }
    }

    fclose(inp);
    fclose(otp);

    return 0;
}

