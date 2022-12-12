#include "helpers.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// day 12
#define ROWS 41
#define COLS 172
struct Node {
  int x, y, dist;
};

struct Source {
  int x, y;
};

struct Destination {
  int x, y;
};

void push(int x, int y, int dist, struct Node *queue, int *queue_size) {
  queue[*queue_size].x = x;
  queue[*queue_size].y = y;
  queue[*queue_size].dist = dist;
  *queue_size += 1;
}

void pop(struct Node *queue, int *queue_size) {
  for (int i = 0; i < *queue_size - 1; i++) {
    queue[i] = queue[i + 1];
  }
  *queue_size -= 1;
}

void create_queue(struct Node *queue, int *queue_size) { *queue_size = 0; }

int is_empty(struct Node *queue, int *queue_size) {
  if (*queue_size == 0) {
    return 1;
  }
  return 0;
}

int row_move[] = {-1, 0, 0, 1};
int col_move[] = {0, -1, 1, 0};

int isValid(int mat[][COLS], int visited[][COLS], int row, int col,
            int current_row, int current_col) {
  return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS) &&
         (mat[row][col] <= mat[current_row][current_col] + 1) &&
         !visited[row][col];
}

int findShortestPathLength(int mat[][COLS], struct Source src,
                           struct Destination dest) {
  int visited[ROWS][COLS] = {0};

  struct Node queue[ROWS * COLS];
  int queue_size = 0;
  create_queue(queue, &queue_size);

  visited[src.x][src.y] = 1;
  push(src.x, src.y, 0, queue, &queue_size);

  int min_dist = 1000000;

  while (!is_empty(queue, &queue_size)) {
    struct Node node = queue[0];
    pop(queue, &queue_size);

    int i = node.x, j = node.y, dist = node.dist;

    if (i == dest.x && j == dest.y) {
      min_dist = dist;
      break;
    }

    for (int k = 0; k < 4; k++) {
      if (isValid(mat, visited, i + row_move[k], j + col_move[k], i, j)) {
        visited[i + row_move[k]][j + col_move[k]] = 1;
        push(i + row_move[k], j + col_move[k], dist + 1, queue, &queue_size);
      }
    }
  }

  if (min_dist != 1000000) {
    return min_dist;
  }

  return -1;
}

void print_matrix(int mat[][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}
int main() {
  FILE *fptr;
  int j = 0;
  int i = 0;
  char chars[176];
  int matrix[ROWS][COLS] = {0};

  struct Source src = {20, 0};
  struct Source src2;
  struct Destination dest = {20, 148};
  if ((fptr = fopen("C:\\input_day12.txt", "r")) == NULL) {
    printf("Error! opening file");
    return 0;
  }
  while (fgets(chars, 175, fptr) != NULL) {
    printf("%s", chars);
    for (i = 0; i < 173; i++) {
      matrix[j][i] = chars[i] - 97;
    }
    j++;
  }
  fclose(fptr);

  int min_dist = findShortestPathLength(matrix, src, dest);
  printf("\nThe shortest path length is %d\n", min_dist);

  int overall_min_dist = 1000000;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      src2.x = i;
      src2.y = j;
      if (matrix[i][j] == 0) {
        min_dist = findShortestPathLength(matrix, src2, dest);
        if (min_dist < overall_min_dist && min_dist != -1) {
          overall_min_dist = min_dist;
        }
      }
    }
  }
  printf("The shortest path length for any starting point is %d\n",
         overall_min_dist);

  return 0;
}