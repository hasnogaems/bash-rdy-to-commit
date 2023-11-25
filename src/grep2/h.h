#ifndef HEADERS_H
#define HEADERS_H
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
typedef struct Flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int file;
  int o;
  int count;
} Flags;

static struct option long_options[] = {{"number-nonblank", no_argument, 0, 'b'},
                                       {0, 0, 0, 0}};
int regex(char pattern[], char line[], int);
int parse_pattern(int argc, char **argv, char **e_ptrns, int *);
int parse_file_name(int pattern_index, char **argv, int argc);
Flags parse_flags(int argc, char **argv, char **e_ptrns, int *);
int open_file_and_i_flag(FILE** fp,Flags* flag, int file_name, char** argv, int* eflags);
int raw_pattern(Flags flag, FILE* fp, int eflags, char* line_, char** argv, int y);
#endif