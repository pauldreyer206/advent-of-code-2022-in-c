#include "helpers.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// day 8

struct tree_s {
  int height;
  int was_counted;
};
// find and mark all ascending trees in a col in 2d array of structs
// forward
int mark_ascending_trees_column(struct tree_s trees[99][99], int len, int col) {
  int i = 0;
  int previous_largest_height = 0;
  for (i = 0; i < len; i++) {
    if (i == 0 || i == len - 1) {
      trees[i][col].was_counted = 1;
    }
    if (trees[i][col].height > previous_largest_height) {
      trees[i][col].was_counted = 1;
      previous_largest_height = trees[i][col].height;
    }
  }
  return 0;
}

// find and mark all ascending trees in a col in 2d array of structs
// reverse
int mark_ascending_trees_column_reverse(struct tree_s trees[99][99], int len,
                                        int col) {
  int i = 0;
  int previous_largest_height = 0;
  for (i = len - 1; i >= 0; i--) {
    if (i == 0 || i == len - 1) {
      trees[i][col].was_counted = 1;
    }
    if (trees[i][col].height > previous_largest_height) {
      trees[i][col].was_counted = 1;
      previous_largest_height = trees[i][col].height;
    }
  }
  return 0;
}

// find and mark all ascending trees in a row in 2d array of structs
// forward
int mark_ascending_trees_row(struct tree_s trees[99][99], int len, int row) {
  int i = 0;
  int previous_largest_height = 0;
  for (i = 0; i < len; i++) {
    if (i == 0 || i == len - 1) {
      trees[row][i].was_counted = 1;
    }
    if (trees[row][i].height > previous_largest_height) {
      trees[row][i].was_counted = 1;
      previous_largest_height = trees[row][i].height;
    }
  }
  return 0;
}

// find and mark all ascending trees in a row in 2d array of structs
// reverse
int mark_ascending_trees_row_reverse(struct tree_s trees[99][99], int len,
                                     int row) {
  int i = 0;
  int previous_largest_height = 0;
  for (i = len - 1; i >= 0; i--) {
    if (i == 0 || i == len - 1) {
      trees[row][i].was_counted = 1;
    }
    if (trees[row][i].height > previous_largest_height) {
      trees[row][i].was_counted = 1;
      previous_largest_height = trees[row][i].height;
    }
  }
  return 0;
}

// function that marks all trees that are shorter than tree at row,col
// moving
// north, south, east, west until a taller tree is found
int mark_trees_in_line_of_sight(struct tree_s trees[99][99], int len, int row,
                                int col) {
  int i = 0;
  int j = 0;
  int north = 0;
  int south = 0;
  int east = 0;
  int west = 0;
  int current_height = trees[row][col].height;
  // north
  for (i = row - 1; i >= 0; i--) {
    if (trees[i][col].height >= current_height) {
      trees[i][col].was_counted = 1;
      north++;
      break;
    }
    trees[i][col].was_counted = 1;
    north++;
  }
  // south
  for (i = row + 1; i < len; i++) {
    if (trees[i][col].height >= current_height) {
      trees[i][col].was_counted = 1;
      south++;
      break;
    }
    trees[i][col].was_counted = 1;
    south++;
  }
  // east
  for (i = col + 1; i < len; i++) {
    if (trees[row][i].height >= current_height) {
      trees[row][i].was_counted = 1;
      east++;
      break;
    }
    trees[row][i].was_counted = 1;
    east++;
  }
  // west
  for (i = col - 1; i >= 0; i--) {
    if (trees[row][i].height >= current_height) {
      trees[row][i].was_counted = 1;
      west++;
      break;
    }
    trees[row][i].was_counted = 1;
    west++;
  }
  return north * south * east * west;
}

int print_counted_trees(struct tree_s trees[99][99], int len) {
  int i = 0;
  int j = 0;
  int count = 0;
  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++) {
      printf("%d", trees[i][j].was_counted);
    }
    printf("\n");
  }
  return count;
}

int count_trees(struct tree_s trees[99][99], int len) {
  int i = 0;
  int j = 0;
  int count = 0;
  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++) {
      if (trees[i][j].was_counted == 1) {
        count++;
      }
    }
  }
  return count;
}

int main() {
  FILE *fptr;
  char lines[101];
  int j = 0;
  // int answer = 0;
  int answer2 = 0;
  struct tree_s trees[99][99] = {0};
  if ((fptr = fopen("C:\\input_day8.txt", "r")) == NULL) {
    printf("Error! opening file");
    return 0;
  }
  while (fgets(lines, 101, fptr) != NULL) {
    // printf("%s", lines);
    for (int i = 0; i < 99; i++) {
      trees[j][i].height = lines[i] - '0';
      printf("%d", trees[j][i].height);
    }
    j++;
    printf("\n");
  }
  for (int i = 0; i < 99; i++) {
    for (j = 0; j < 99; j++) {
      if (mark_trees_in_line_of_sight(trees, 99, i, j) > answer2) {
        answer2 = mark_trees_in_line_of_sight(trees, 99, i, j);
        // print_counted_trees(trees, 99);
      }
      // for (int k = 0; k < 99; k++) {
      //   for (int l = 0; l < 99; l++) {
      //     trees[k][l].was_counted = 0;
      //   }
      // }
    }
  }
  // for loop to find first descending pair in each row
  // for (int i = 0; i < 99; i++) { // part 1
  //   mark_ascending_trees_column(trees, 99, i);
  //   mark_ascending_trees_column_reverse(trees, 99, i);
  //   mark_ascending_trees_row(trees, 99, i);
  //   mark_ascending_trees_row_reverse(trees, 99, i);
  // }
  // answer = count_trees(trees, 99); // this works
  printf("%d\n", answer2);

  fclose(fptr);
  return 0;
}