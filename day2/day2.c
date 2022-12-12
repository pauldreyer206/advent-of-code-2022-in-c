#include "helpers.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// day 2
int win_lose_draw(char player1, char player2) {
  int score = 0;
  // if ((player1 - player2) == -23) {
  //   score = 3;
  //   return score;
  // }
  switch (player1) {
  case 'A':               // rock
    if (player2 == 'Y') { // paper
      score = 1;
    } else if (player2 == 'Z') { // scissors
      score = 2;
    } else {
      score = 3;
    }
    break;
  case 'B':               // paper
    if (player2 == 'X') { // rock
      score = 1;
    } else if (player2 == 'Z') { // scissors
      score = 3;
    } else {
      score = 2;
    }
    break;
  case 'C':               // scissors
    if (player2 == 'X') { // rock
      score = 2;
    } else if (player2 == 'Y') { // paper
      score = 3;
    } else {
      score = 1;
    }
    break;
  default:
    break;
  }
  return score;
}

int main() {
  char input_pairs[2500][2];
  int i = 0;
  FILE *fptr;
  char str[5];
  int total_score = 0;
  if ((fptr = fopen("C:\\input_day2.txt", "r")) == NULL) {
    printf("Error! opening file");
    return 0;
  }

  while (fgets(str, 60, fptr) != NULL) {
    input_pairs[i][0] = str[0];
    input_pairs[i][1] = str[2];
    i++;
  }
  for (i = 0; i < 2500; i++) {
    // printf("%c %c %d", input_pairs[i][0], input_pairs[i][1], i);
    switch (input_pairs[i][1]) { // sorting the choices
      {
      case 'X': // rock
        // printf(" 1");
        total_score += 0;
        break;
      case 'Y': // paper
        // printf(" 2");
        total_score += 3;
        break;
      case 'Z': // scissors
        // printf(" 6");
        total_score += 6;
        break;
      default:
        break;
      }
    }
    total_score += win_lose_draw(input_pairs[i][0], input_pairs[i][1]);
    printf(" %d\n", win_lose_draw(input_pairs[i][0], input_pairs[i][1]));
  }
  printf("%d", total_score);
  fclose(fptr);
  return 0;
}
