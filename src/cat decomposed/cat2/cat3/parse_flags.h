#ifndef PARSE_FLAGS_H
#define PARSE_FLAGS_H
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
typedef struct flags{
    int b;
    int e;
    int n;
    int s;
    int t;
    int E;
    int T;
    int v;

    //if(b==e==n==s==t==0)

  }flags;
  static struct option long_options[] = {
            {"number-nonblank", no_argument, 0, 'b'},
            {"number", no_argument, 0, 'n'},
            {"squeeze-blank", no_argument, 0, 's'},
            {0, 0, 0, 0}
        };
flags parse_flags(int argc, char **argv);
int extralines(FILE *fp);
int big_while(int argc, char **argv);
#endif