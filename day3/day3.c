#include "helpers.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// day 3
int find_common_char(char *arr1, char *arr2, int len) {
  int i = 0, j = 0;
  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++) {
      if (arr1[i] == arr2[j]) {
        if (arr1[i] < 91) {
          printf("Common char: %c Value: %d\n", arr1[i],
                 (int)(arr1[i] - 38)); // use some ascii magic to get the value
          return (int)(arr1[i] - 38);
        } else {
          printf("Common char: %c Value: %d\n", arr1[i], (int)(arr1[i] - 96));
          return (int)(arr1[i] - 96);
        }
      }
    }
  }
  return 1;
}

int find_common_char_3_arrays(char *arr1, char *arr2, char *arr3, int len1,
                              int len2, int len3) {
  int i = 0, j = 0, k = 0;
  for (i = 0; i < len1; i++) {
    for (j = 0; j < len2; j++) {
      for (k = 0; k < len3; k++) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
          if (arr1[i] < 91) {
            // printf("Common char: %c Value: %d\n", arr1[i], (int)(arr1[i]
            // -
            // 38));
            return (int)(arr1[i] - 38); // use some ascii magic to get the value
          } else {
            // printf("Common char: %c Value: %d\n", arr1[i], (int)(arr1[i]
            // -
            // 96));
            return (int)(arr1[i] - 96);
          }
        }
      }
    }
  }
  return 1;
}
// part 2
int main() {
  FILE *fptr;
  int answer = 0;
  char str[60];
  char lines[300][100];
  int line_lenghts[300];
  int i = 0;
  int j = 0;

  if ((fptr = fopen("C:\\input_day3.txt", "r")) == NULL) {
    printf("Error! opening file");
    return 0;
  }

  while (fgets(str, 60, fptr) != NULL) { // put data in array
    while (str[j] != '\0') {
      lines[i][j] = str[j];
      j++;
    }
    if (str[j] == '\0') {
      lines[i][j - 1] = '\0';
      line_lenghts[i] = j - 1;
    }
    j = 0;
    i++;
  }
  for (int k = 0; k < 300; k += 3) {
    answer += find_common_char_3_arrays(lines[k], lines[k + 1], lines[k + 2],
                                        line_lenghts[k], line_lenghts[k + 1],
                                        line_lenghts[k + 2]);
  }
  printf("Answer: %d", answer);
  fclose(fptr);
  return 0;
}
