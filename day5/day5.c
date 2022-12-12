#include "helpers.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// day 5
//     [H]         [D]     [P]
// [W] [B]         [C] [Z] [D]
// [T] [J]     [T] [J] [D] [J]
// [H] [Z]     [H] [H] [W] [S]     [M]
// [P] [F] [R] [P] [Z] [F] [W]     [F]
// [J] [V] [T] [N] [F] [G] [Z] [S] [S]
// [C] [R] [P] [S] [V] [M] [V] [D] [Z]
// [F] [G] [H] [Z] [N] [P] [M] [N] [D]
//  1   2   3   4   5   6   7   8   9
struct move_s {
  int amount;
  int from;
  int to;
};
int string_length(char *str) {
  int len = 0;
  while (*str != '\0') {
    len++;
    str++;
  }
  return len;
}

void add_char(char *str, char c) { // not safe, don't care
  int len = string_length(str);
  str[len] = c;
  str[len + 1] = '\0';
}

char remove_char(char *str) { // not safe, don't care
  int len = string_length(str);
  char c = str[len - 1];
  str[len - 1] = '\0';
  return c;
}

void add_string(char *str, char *str2) { // not safe, don't care
  int len = string_length(str);
  int len2 = string_length(str2);
  int i = 0;
  for (i = 0; i < len2; i++) {
    str[len + i] = str2[i];
  }
  str[len + len2] = '\0';
}

int main() {
  FILE *fptr;
  struct move_s move;

  char stacks[9][1000] = {"FCJPHTW", "GRVFZJBH", "HPTR", "ZSNPHT", "NVFZHJCD",
                          "PMGFWDZ", "MVZWSJDP", "NDS",  "DZSFM"};

  char str[60];
  int i = 0;
  char *token;

  if ((fptr = fopen("C:\\input_day5.txt", "r")) == NULL) {
    printf("Error! opening file");
    return 0;
  }
  while (fgets(str, 60, fptr) != NULL) { // put data in array

    // printf("%s", str);
    token = strtok(str, "move");
    move.amount = atoi(token);
    // printf("start: %d \n", move.start);
    token = strtok(NULL, "from");
    move.from = atoi(token);
    token = strtok(NULL, "to");
    move.to = atoi(token);
    printf("amount: %d from: %d to: %d \n", move.amount, move.from, move.to);
    // for (i = 0; i < move.amount; i++) {//part 1
    //   add_char(stacks[move.to - 1], remove_char(stacks[move.from - 1]));
    // }
    add_string(stacks[move.to - 1],
               &stacks[move.from - 1][string_length(stacks[move.from - 1]) -
                                      move.amount]); // part 2
    stacks[move.from - 1][string_length(stacks[move.from - 1]) - move.amount] =
        '\0'; // part 2
  }
  for (i = 0; i < 9; i++) {
    printf("%s \n", stacks[i]);
  }
  fclose(fptr);
  return 0;
}