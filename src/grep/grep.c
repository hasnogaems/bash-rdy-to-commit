#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <regex.h>
#include "h.h"
#define no_argument       0
#define required_argument 1
#define optional_argument 2
int main(int argc, char *argv[]){
    if(argc==1)printf("Usage: grep [OPTION]... PATTERNS [FILE]...\nTry 'grep --help' for more information.\n");
    else{
        int count=0;
        int* e_count=&count;
        FILE *fp;
        int eflags=0;
        char *pattern=malloc(100*sizeof(char));
        char **e_ptrns=(char **)malloc(1025*sizeof(char*));
        int c;
        int x;
        Flags flag=parse_flags(argc, argv, e_ptrns, e_count); //parse flags
        int y=parse_pattern(argc, argv, e_ptrns, &count);  //parse pattern
        int file_name=parse_file_name(y, argv, argc);//parse file name
        
        //printf("OPTIND=%d", optind);
        //printf("file name is %s its index is%d\n", argv[file_name], file_name);
        
        fp=fopen(argv[file_name],"r");//opening file
        if (fp == NULL) 
        {
            printf("Error opening file.\n");
            return -1;//debug
        }
        char *line_=(char *)malloc(1024*sizeof(char)); //here we store line from our file we grabbed with fgets
        if(flag.i==1){ //no distinction between upper and lowercase characters
        eflags=REG_ICASE;
       // printf("EFLAGS IN MAIN=%d\n", eflags);
        }        
        if(flag.e!=1)
        while( fgets(line_, 1024, fp)){ 
            

        x=regex(argv[y], line_, eflags);
        if(!x)
              
            printf("%s", line_);
        }
        
        
        fseek(fp, 0, SEEK_SET);// Move the cursor to the beginning of the file
        fgets(line_, 1024, fp);
        
        fseek(fp, 0, SEEK_SET);
        
        // exec e patterns
        
            if(flag.v==1){
            while(fgets(line_, 1024, fp)){ //print e patterns
                int loop_count=count;
                while(loop_count>0){ // что значат фиолетовые синие и желтые скобки
                x=regex(e_ptrns[loop_count-1], line_, eflags);
                loop_count--;
                //printf("X in E loop=%d\n", x);
                if(x){
                
                printf("%s", line_);}
                }

                
        

            }
            printf("\n");
            }
            if(flag.v!=1&&flag.c!=1){
            while(fgets(line_, 1024, fp)){ //print e patterns
                int loop_count=count;
                while(loop_count>0){ // что значат фиолетовые синие и желтые скобки
                x=regex(e_ptrns[loop_count-1], line_, eflags);
                loop_count--;
                //printf("X in E loop=%d\n", x);
                if(!x){
                
                printf("%s", line_);}
                }
            }
            }
            if(flag.c==1){
                int c_count=0;
            while(fgets(line_, 1024, fp)){ //print e patterns
                int loop_count=count;
                while(loop_count>0){ // что значат фиолетовые синие и желтые скобки
                x=regex(e_ptrns[loop_count-1], line_, eflags);
                loop_count--;
                //printf("X in E loop=%d\n", x);
                if(!x){
                
                c_count++;}
                }
            }
            printf("%d", c_count);
            }
    //         printf("INSIDE THE e_ptrns:\n");     
    // for(int n=0;n<2;n++){        
    //     printf("%s\n", e_ptrns[n]);}
       
    free(pattern);
    free(line_);
    free(e_ptrns);
    

}


}

