#include "helpers.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// day 10
#define MAX_CYCLES 250

void print_array(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("During cycle: %d Value: %d\n", i, array[i]);
  }
}

void print_screen(int pixels[6][40]) {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 40; j++) {
      if (pixels[i][j] == 0) {
        printf(".");
      } else {
        printf("#");
      }
    }
    printf("\n");
  }
}

int main() {
  int cpu_cycles[MAX_CYCLES] = {0};
  cpu_cycles[0] = 1;
  int pixels[6][40] = {0};
  FILE *fptr;
  int answer = 0;
  int cycle_count = 0;
  int value_to_add = 0;
  char lines[60];
  if ((fptr = fopen("C:\\input_day10.txt", "r")) == NULL) {
    printf("Error! opening file");
    return 0;
  }
  while (fgets(lines, 60, fptr) != NULL) {
    // printf("%s", lines);
    value_to_add = atoi(&lines[5]);
    if (lines[0] == 'a') {
      cycle_count++;
      cpu_cycles[cycle_count] = cpu_cycles[cycle_count - 1];
      if (cpu_cycles[cycle_count] == cycle_count % 40 ||
          cpu_cycles[cycle_count] - 1 == cycle_count % 40 ||
          cpu_cycles[cycle_count] + 1 == cycle_count % 40) {
        pixels[(cycle_count / 40)][(cycle_count % 40)] = 1;
      }
      cycle_count++;
      cpu_cycles[cycle_count] = cpu_cycles[cycle_count - 1];
      cpu_cycles[cycle_count] += value_to_add;
      if (cpu_cycles[cycle_count] == cycle_count % 40 ||
          cpu_cycles[cycle_count] - 1 == cycle_count % 40 ||
          cpu_cycles[cycle_count] + 1 == cycle_count % 40) {
        pixels[cycle_count / 40][cycle_count % 40] = 1;
      }
    } else {
      cycle_count++;
      cpu_cycles[cycle_count] = cpu_cycles[cycle_count - 1];
      if (cpu_cycles[cycle_count] == cycle_count % 40 ||
          cpu_cycles[cycle_count] - 1 == cycle_count % 40 ||
          cpu_cycles[cycle_count] + 1 == cycle_count % 40) {
        pixels[cycle_count / 40][cycle_count % 40] = 1;
      }
    }
  }
  print_array(cpu_cycles, MAX_CYCLES);
  for (int j = 20; j < 241; j = j + 40) {
    printf("Cycle: %d Value: %d\n", j, cpu_cycles[j - 1]);
    answer += cpu_cycles[j - 1] * j;
  }
  printf("Answer: %d\n", answer);
  fclose(fptr);
  print_screen(pixels);
  return 0;
}
