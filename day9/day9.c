#include "helpers.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// day 9
#define MAX_ARRAY_SIZE 600
#define MIDDEL_ARRAY_SIZE MAX_ARRAY_SIZE / 2

struct link_s {
  int x;
  int y;
  struct link_s *next;
  struct link_s *prev;
};

struct move_s {
  char direction;
  int distance;
};

struct move_s move;
struct link_s *head = NULL;
static int visited_positions[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

// add a link to the linked list of chain links
int add_link(int x, int y) {
  struct link_s *current = head;
  struct link_s *new_link = malloc(sizeof(struct link_s));
  new_link->x = x;
  new_link->y = y;
  new_link->next = NULL;
  new_link->prev = NULL;
  if (head == NULL) {
    head = new_link;
    return 0;
  }
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_link;
  new_link->prev = current;
  return 0;
}

// print the linked list of chain links with their x and y coordinates
int print_links() {
  struct link_s *current = head;
  while (current != NULL) {
    printf("x:%d y:%d -> ", current->x, current->y);
    current = current->next;
  }
  printf(" NULL \n");
  return 0;
}

// move the chain link 1 unit in the direction and distance specified in
// the
// move
void move_link_north(struct link_s *link_to_move) {
  link_to_move->y++;
  if (link_to_move->next == NULL)
    visited_positions[link_to_move->x][link_to_move->y] = 1;
}
void move_link_north_east(struct link_s *link_to_move) {
  link_to_move->x++;
  link_to_move->y++;
  if (link_to_move->next == NULL)
    visited_positions[link_to_move->x][link_to_move->y] = 1;
}
void move_link_east(struct link_s *link_to_move) {
  link_to_move->x++;
  if (link_to_move->next == NULL)
    visited_positions[link_to_move->x][link_to_move->y] = 1;
}
void move_link_south_east(struct link_s *link_to_move) {
  link_to_move->x++;
  link_to_move->y--;
  if (link_to_move->next == NULL)
    visited_positions[link_to_move->x][link_to_move->y] = 1;
}
void move_link_south(struct link_s *link_to_move) {
  link_to_move->y--;
  if (link_to_move->next == NULL)
    visited_positions[link_to_move->x][link_to_move->y] = 1;
}
void move_link_south_west(struct link_s *link_to_move) {
  link_to_move->x--;
  link_to_move->y--;
  if (link_to_move->next == NULL)
    visited_positions[link_to_move->x][link_to_move->y] = 1;
}
void move_link_west(struct link_s *link_to_move) {
  link_to_move->x--;
  if (link_to_move->next == NULL)
    visited_positions[link_to_move->x][link_to_move->y] = 1;
}
void move_link_north_west(struct link_s *link_to_move) {
  link_to_move->x--;
  link_to_move->y++;
  if (link_to_move->next == NULL)
    visited_positions[link_to_move->x][link_to_move->y] = 1;
}

// function to check direction of previous link compared to current link
int check_direction(struct link_s *current_link) {
  if (current_link->x == current_link->prev->x) {
    if (current_link->y + 1 < current_link->prev->y) {
      return 1; // north
    } else if (current_link->y - 1 > current_link->prev->y) {
      return 2; // south
    }
  } else if (current_link->y == current_link->prev->y) {
    if (current_link->x + 1 < current_link->prev->x) {
      return 3; // east
    } else if (current_link->x - 1 > current_link->prev->x) {
      return 4; // west
    }
  } else if (current_link->x + 1 < current_link->prev->x) {
    if (current_link->y < current_link->prev->y) {
      return 5; // north east
    } else if (current_link->y > current_link->prev->y) {
      return 6; // south east
    }
  } else if (current_link->x - 1 > current_link->prev->x) {
    if (current_link->y < current_link->prev->y) {
      return 7; // north west
    } else if (current_link->y > current_link->prev->y) {
      return 8; // south west
    }
  } else if (current_link->y + 1 < current_link->prev->y) {
    if (current_link->x < current_link->prev->x) {
      return 5; // north east
    } else if (current_link->x > current_link->prev->x) {
      return 7; // north west
    }
  } else if (current_link->y - 1 > current_link->prev->y) {
    if (current_link->x < current_link->prev->x) {
      return 6; // south east
    } else if (current_link->x > current_link->prev->x) {
      return 8; // south west
    }
  }
  return 0; // no direction
}

void update_rest_of_chain(struct link_s *current_link) {
  int direction = check_direction(current_link);
  switch (direction) {
  case 0:
    break;
  case 1:
    move_link_north(current_link);
    break;
  case 2:
    move_link_south(current_link);
    break;
  case 3:
    move_link_east(current_link);
    break;
  case 4:
    move_link_west(current_link);
    break;
  case 5:
    move_link_north_east(current_link);
    break;
  case 6:
    move_link_south_east(current_link);
    break;
  case 7:
    move_link_north_west(current_link);
    break;
  case 8:
    move_link_south_west(current_link);
    break;
  }
  if (current_link->next != NULL) {
    update_rest_of_chain(current_link->next);
  }
}

int count_visited_positions() {
  int count = 0;
  for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
    for (int j = 0; j < MAX_ARRAY_SIZE; j++) {
      if (visited_positions[i][j] == 1) {
        count++;
      }
    }
  }
  return count;
}

int main() {
  FILE *fptr;
  char lines[60];
  for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
    for (int j = 0; j < MAX_ARRAY_SIZE; j++) {
      visited_positions[i][j] = 0;
    }
  }
  // make 10 links
  for (int i = 0; i < 10; i++) {
    add_link(MIDDEL_ARRAY_SIZE, MIDDEL_ARRAY_SIZE);
  }
  print_links();

  if ((fptr = fopen("C:\\input_day9.txt", "r")) == NULL) {
    printf("Error! opening file");
    return 0;
  }
  while (fgets(lines, 60, fptr) != NULL) {
    move.direction = lines[0];
    move.distance = atoi(&lines[2]);
    for (int i = 0; i < move.distance; i++) {
      switch (move.direction) {
      case 'U':
        move_link_north(head);
        break;
      case 'D':
        move_link_south(head);
        break;
      case 'R':
        move_link_east(head);
        break;
      case 'L':
        move_link_west(head);
        break;
      }
      update_rest_of_chain(head->next);
    }
    // print_links();
  }
  print_links();
  printf("P1:%d\n", count_visited_positions());
  fclose(fptr);
  return 0;
}
