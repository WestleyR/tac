// created by: WestleyR
// email: westleyr@nym.hush.com
// https://github.com/WestleyR/list-files
// date: Nov 5, 2019
// version-1.0.0
//
// The Clear BSD License
//
// Copyright (c) 2019 WestleyR
// All rights reserved.
//
// This software is licensed under a Clear BSD License.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int print_file_line(FILE* fp, int line) {
  int l = 1;
  char c;

  c = fgetc(fp);
  while (c != EOF) {
    if (c == '\n') l++;
    if (c != '\n' && l == line) printf("%c", c);
    c = fgetc(fp);
  }
  printf("\n");

  return(0);
}

int get_file_len(FILE* fp) {
  int ret = -1;

  char c;

  c = fgetc(fp);
  while (c != EOF) {
    if (c == '\n') ret++;
    c = fgetc(fp);
  }

  return(ret);
}

int main(int argc, char** argv) {
  FILE *fptr;

  char filename[100];

  // TODO: Need to loop throught all the files!
  strcpy(filename, argv[1]);

  fptr = fopen(filename, "r");
  if (fptr == NULL) {
    perror(filename);
    return(1);
  }

  int lines = get_file_len(fptr);

  // Not the best way, but it will work for now...
  for (int i = lines+1; i > 0; i--) {
    rewind(fptr);
    print_file_line(fptr, i);
  }

  fclose(fptr);

  return(0);
}

// vim: tabstop=2 shiftwidth=2 expandtab
