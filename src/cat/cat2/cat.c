#include <stdio.h>
#include <stdlib.h>
#include "parse_flags.h"


int main(int argc, char *argv[]) {
    FILE *fp;
    int line_index = 0;
    int previous = 10;
    int current = 0;
    int count = 0;
    int line_count=1;
    int new_line=1;
    int s;

    flags Flag = parse_flags(argc, argv);
    fp = fopen(argv[argc - 1], "r");

    int c;
    while (1) {
        c = fgetc(fp);
        current = c;
        if (feof(fp)) break;

        if (previous == 10 && current == 10) {
            count++;
        }

        

        if (Flag.s == 1 && previous == 10 && current == 10 && count > 1) { //flag s
            continue;
        }
        if (current != 10) {
            //if (extra_line == 1) {printf("\n");}
            count = 0;
        }

        if(Flag.b==0){
        if (Flag.n == 1&&line_count==new_line){ //flag n
        printf("%6.d\t", line_count);
        new_line=line_count+1;} //make it print line number only once for each new line
        if (Flag.n == 1&&current==10)
        line_count++;}
        if(Flag.b==1 &&line_count==new_line&&c!=10){
        printf("%6.d\t", line_count);
        new_line=line_count+1;}//тут рассинхрон
        if (Flag.b==1&&current==10&&!(previous == 10 && current == 10))
        line_count++;  //как комментить сразу несколько строк
        previous = c;
        if (Flag.e==1&&Flag.E!=1){
            if(c<32&&c!=10&&c!=9){
            printf("^%c", c+64);
            
            continue;}
            if(c==127){
            printf("^%c", c-128);continue;
            }

            if(c==10)
            printf("$");
        }
        if (Flag.t==1){
            if(c<32&&c!=10&&c!=9){
                printf("^%c", c+64);continue;
            }
            if(c==127){
                printf("^%c", c-128);continue;
            }
        }


        
        printf("%c", c);
        
        
    }
if(argc==1){

}
    fclose(fp);
    return 0;
}
