#include "helpers.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// day 1
int main() {
  int num;
  char str[60];
  FILE *fptr;
  int current_elf_index = 0;
  int sum = 0;
  int vals[10000] = {0};

  if ((fptr = fopen("C:\\input_day1.txt", "r")) == NULL) {
    printf("Error! opening file");
    return 0;
  }

  while (fgets(str, 60, fptr) != NULL) {
    if (str[0] == '\n') {
      vals[current_elf_index] = sum;
      current_elf_index++;
      sum = 0;
    } else {
      sscanf(str, "%d", &num);
      sum += num;
    }
  }

  qsort(vals, 10000, sizeof(int), compare_function);
  printf("%d", sum_integer_array(vals, 3));
  fclose(fptr);
  return 0;
}
