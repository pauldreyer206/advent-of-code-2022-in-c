#include "helpers.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// day 13
int main() {
  char str[60];
  FILE *fptr;

  if ((fptr = fopen("C:\\input_day1.txt", "r")) == NULL) {
    printf("Error! opening file");
    return 0;
  }
  while (fgets(str, 60, fptr) != NULL) {
    printf("%s", str);
  }
  fclose(fptr);
  return 0;
}
