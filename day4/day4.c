#include "helpers.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// day 4

int range_contains_other_range(int min, int max, int min2, int max2) { //
                                                                       // part 1
  return (min >= min2 && min <= max2) || (max >= min2 && max <= max2);
}

int range_overlaps_other_range(int min, int max, int min2, int max2) { //
  // part 2
  return (min >= min2 && min <= max2) || (max >= min2 && max <= max2) ||
         (min2 >= min && min2 <= max) || (max2 >= min && max2 <= max);
}

struct range {
  int min;
  int max;
};

struct range ranges[1000][2];

// part 1
int main() {
  FILE *fptr;
  char str[60];
  int i = 0;
  int j = 0;
  int answer = 0;
  char *token;

  if ((fptr = fopen("C:\\input_day4.txt", "r")) == NULL) {
    printf("Error! opening file");
    return 0;
  }
  while (fgets(str, 60, fptr) != NULL) { // put data in array
    printf("%s", str);
    token = strtok(str, ",-");
    printf("%s\n", token);
    ranges[i][0].min = atoi(token);
    token = strtok(NULL, ",-");
    printf("%s\n", token);
    ranges[i][0].max = atoi(token);
    token = strtok(NULL, ",-");
    printf("%s\n", token);
    ranges[i][1].min = atoi(token);
    token = strtok(NULL, ",-");
    printf("%s\n", token);
    ranges[i][1].max = atoi(token);
    i++;
    printf("%d\n",
           range_overlaps_other_range(ranges[i][1].min, ranges[i][1].max,
                                      ranges[i][0].min, ranges[i][0].max));
  }
  for (j = 0; j < 1000; j++) {
    answer += range_overlaps_other_range(ranges[j][1].min, ranges[j][1].max,
                                         ranges[j][0].min, ranges[j][0].max);
  }
  printf("%d", answer);
  fclose(fptr);
  return 0;
}