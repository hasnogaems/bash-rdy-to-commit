#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#include "h.h"
#define no_argument 0
#define required_argument 1
#define optional_argument 2
int main(int argc, char *argv[]) {
  if (argc == 1)
    printf(
        "Usage: grep [OPTION]... PATTERNS [FILE]...\nTry 'grep --help' for "
        "more information.\n");
  else {
    FILE *fp;
    int eflags = 0;

    char *line_ = (char *)malloc(1025 * sizeof(char));
    // printf("Where?\n");
    Flags flag = parse_flags(argc, argv);  // parse flags
    int y = parse_pattern(argc, argv);     // parse pattern
    int error=0;
    while (optind < argc) {
      error=open_file_and_i_flag(&fp, &flag, argv, &eflags);
      if (error == 0) {
        optind++;
        continue;
      }
      

      grep(flag, fp, line_, argv, y);

      optind++;
    }
    if(error==0&&!flag.s){
        printf("grep: %s: No such file or directory\n", argv[optind-1]);
      }
    // free(pattern);
    // free(e_ptrns);
    // fclose(fp);
    free(line_);
  }
  return 0;
}
