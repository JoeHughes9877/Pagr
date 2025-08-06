#include <stdio.h>
void open_txt_file(char *file_name) {
  FILE *fptr;

  fptr = fopen(file_name, "r");

  char myString[10000];

  fgets(myString, 100, fptr);

  printf("%s", myString);

  fclose(fptr);
}