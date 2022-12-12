#include "helpers.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// day 6
int find_n_unique_set(char *str, int len, int n) {
  int i = 0;
  int j = 0;
  int k = 0;
  int found = 0;
  for (i = 0; i < len - n; i++) {
    found = 0;
    for (j = 0; j < n; j++) {
      for (k = 0; k < n; k++) {
        if (str[i + j] == str[i + k]) {
          found++;
        }
      }
    }
    if (found == n) {
      return i;
    }
  }
  return -1;
}

int main() {
  FILE *fptr;
  char chars[4096];
  int answer;

  if ((fptr = fopen("C:\\input_day6.txt", "r")) == NULL) {
    printf("Error! opening file");
    return 0;
  }
  while (fgets(chars, 4096, fptr) != NULL) {
    printf("%s", chars);
  }
  // answer = 4 + find_n_unique_set(chars, 4096, 4);//part 1
  answer = 14 + find_n_unique_set(chars, 4096, 14); // part 2
  printf("%d", answer);
  fclose(fptr);
  return 0;
}