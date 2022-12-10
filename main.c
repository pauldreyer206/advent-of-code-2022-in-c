#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
  if ((fptr = fopen("C:\\input.txt", "r")) == NULL) {
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// day 9
// #define MAX_ARRAY_SIZE 600
// #define MIDDEL_ARRAY_SIZE MAX_ARRAY_SIZE / 2

// struct link_s {
//   int x;
//   int y;
//   struct link_s *next;
//   struct link_s *prev;
// };

// struct move_s {
//   char direction;
//   int distance;
// };

// struct move_s move;
// struct link_s *head = NULL;
// static int visited_positions[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

// // add a link to the linked list of chain links
// int add_link(int x, int y) {
//   struct link_s *current = head;
//   struct link_s *new_link = malloc(sizeof(struct link_s));
//   new_link->x = x;
//   new_link->y = y;
//   new_link->next = NULL;
//   new_link->prev = NULL;
//   if (head == NULL) {
//     head = new_link;
//     return 0;
//   }
//   while (current->next != NULL) {
//     current = current->next;
//   }
//   current->next = new_link;
//   new_link->prev = current;
//   return 0;
// }

// // print the linked list of chain links with their x and y coordinates
// int print_links() {
//   struct link_s *current = head;
//   while (current != NULL) {
//     printf("x:%d y:%d -> ", current->x, current->y);
//     current = current->next;
//   }
//   printf(" NULL \n");
//   return 0;
// }

// // move the chain link 1 unit in the direction and distance specified in
// the
// // move
// void move_link_north(struct link_s *link_to_move) {
//   link_to_move->y++;
//   if (link_to_move->next == NULL)
//     visited_positions[link_to_move->x][link_to_move->y] = 1;
// }
// void move_link_north_east(struct link_s *link_to_move) {
//   link_to_move->x++;
//   link_to_move->y++;
//   if (link_to_move->next == NULL)
//     visited_positions[link_to_move->x][link_to_move->y] = 1;
// }
// void move_link_east(struct link_s *link_to_move) {
//   link_to_move->x++;
//   if (link_to_move->next == NULL)
//     visited_positions[link_to_move->x][link_to_move->y] = 1;
// }
// void move_link_south_east(struct link_s *link_to_move) {
//   link_to_move->x++;
//   link_to_move->y--;
//   if (link_to_move->next == NULL)
//     visited_positions[link_to_move->x][link_to_move->y] = 1;
// }
// void move_link_south(struct link_s *link_to_move) {
//   link_to_move->y--;
//   if (link_to_move->next == NULL)
//     visited_positions[link_to_move->x][link_to_move->y] = 1;
// }
// void move_link_south_west(struct link_s *link_to_move) {
//   link_to_move->x--;
//   link_to_move->y--;
//   if (link_to_move->next == NULL)
//     visited_positions[link_to_move->x][link_to_move->y] = 1;
// }
// void move_link_west(struct link_s *link_to_move) {
//   link_to_move->x--;
//   if (link_to_move->next == NULL)
//     visited_positions[link_to_move->x][link_to_move->y] = 1;
// }
// void move_link_north_west(struct link_s *link_to_move) {
//   link_to_move->x--;
//   link_to_move->y++;
//   if (link_to_move->next == NULL)
//     visited_positions[link_to_move->x][link_to_move->y] = 1;
// }

// // function to check direction of previous link compared to current link
// int check_direction(struct link_s *current_link) {
//   if (current_link->x == current_link->prev->x) {
//     if (current_link->y + 1 < current_link->prev->y) {
//       return 1; // north
//     } else if (current_link->y - 1 > current_link->prev->y) {
//       return 2; // south
//     }
//   } else if (current_link->y == current_link->prev->y) {
//     if (current_link->x + 1 < current_link->prev->x) {
//       return 3; // east
//     } else if (current_link->x - 1 > current_link->prev->x) {
//       return 4; // west
//     }
//   } else if (current_link->x + 1 < current_link->prev->x) {
//     if (current_link->y < current_link->prev->y) {
//       return 5; // north east
//     } else if (current_link->y > current_link->prev->y) {
//       return 6; // south east
//     }
//   } else if (current_link->x - 1 > current_link->prev->x) {
//     if (current_link->y < current_link->prev->y) {
//       return 7; // north west
//     } else if (current_link->y > current_link->prev->y) {
//       return 8; // south west
//     }
//   } else if (current_link->y + 1 < current_link->prev->y) {
//     if (current_link->x < current_link->prev->x) {
//       return 5; // north east
//     } else if (current_link->x > current_link->prev->x) {
//       return 7; // north west
//     }
//   } else if (current_link->y - 1 > current_link->prev->y) {
//     if (current_link->x < current_link->prev->x) {
//       return 6; // south east
//     } else if (current_link->x > current_link->prev->x) {
//       return 8; // south west
//     }
//   }
//   return 0; // no direction
// }

// void update_rest_of_chain(struct link_s *current_link) {
//   int direction = check_direction(current_link);
//   switch (direction) {
//   case 0:
//     break;
//   case 1:
//     move_link_north(current_link);
//     break;
//   case 2:
//     move_link_south(current_link);
//     break;
//   case 3:
//     move_link_east(current_link);
//     break;
//   case 4:
//     move_link_west(current_link);
//     break;
//   case 5:
//     move_link_north_east(current_link);
//     break;
//   case 6:
//     move_link_south_east(current_link);
//     break;
//   case 7:
//     move_link_north_west(current_link);
//     break;
//   case 8:
//     move_link_south_west(current_link);
//     break;
//   }
//   if (current_link->next != NULL) {
//     update_rest_of_chain(current_link->next);
//   }
// }

// int count_visited_positions() {
//   int count = 0;
//   for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
//     for (int j = 0; j < MAX_ARRAY_SIZE; j++) {
//       if (visited_positions[i][j] == 1) {
//         count++;
//       }
//     }
//   }
//   return count;
// }

// int main() {
//   FILE *fptr;
//   char lines[60];
//   for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
//     for (int j = 0; j < MAX_ARRAY_SIZE; j++) {
//       visited_positions[i][j] = 0;
//     }
//   }
//   // make 10 links
//   for (int i = 0; i < 10; i++) {
//     add_link(MIDDEL_ARRAY_SIZE, MIDDEL_ARRAY_SIZE);
//   }
//   print_links();

//   if ((fptr = fopen("C:\\input.txt", "r")) == NULL) {
//     printf("Error! opening file");
//     return 0;
//   }
//   while (fgets(lines, 60, fptr) != NULL) {
//     move.direction = lines[0];
//     move.distance = atoi(&lines[2]);
//     for (int i = 0; i < move.distance; i++) {
//       switch (move.direction) {
//       case 'U':
//         move_link_north(head);
//         break;
//       case 'D':
//         move_link_south(head);
//         break;
//       case 'R':
//         move_link_east(head);
//         break;
//       case 'L':
//         move_link_west(head);
//         break;
//       }
//       update_rest_of_chain(head->next);
//     }
//     // print_links();
//   }
//   print_links();
//   printf("P1:%d\n", count_visited_positions());
//   fclose(fptr);
//   return 0;
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// day 8

// struct tree_s {
//   int height;
//   int was_counted;
// };
// // find and mark all ascending trees in a col in 2d array of structs
// forward int mark_ascending_trees_column(struct tree_s trees[99][99], int
// len, int col) {
//   int i = 0;
//   int previous_largest_height = 0;
//   for (i = 0; i < len; i++) {
//     if (i == 0 || i == len - 1) {
//       trees[i][col].was_counted = 1;
//     }
//     if (trees[i][col].height > previous_largest_height) {
//       trees[i][col].was_counted = 1;
//       previous_largest_height = trees[i][col].height;
//     }
//   }
//   return 0;
// }

// // find and mark all ascending trees in a col in 2d array of structs
// reverse int mark_ascending_trees_column_reverse(struct tree_s
// trees[99][99], int len,
//                                         int col) {
//   int i = 0;
//   int previous_largest_height = 0;
//   for (i = len - 1; i >= 0; i--) {
//     if (i == 0 || i == len - 1) {
//       trees[i][col].was_counted = 1;
//     }
//     if (trees[i][col].height > previous_largest_height) {
//       trees[i][col].was_counted = 1;
//       previous_largest_height = trees[i][col].height;
//     }
//   }
//   return 0;
// }

// // find and mark all ascending trees in a row in 2d array of structs
// forward int mark_ascending_trees_row(struct tree_s trees[99][99], int len,
// int row) {
//   int i = 0;
//   int previous_largest_height = 0;
//   for (i = 0; i < len; i++) {
//     if (i == 0 || i == len - 1) {
//       trees[row][i].was_counted = 1;
//     }
//     if (trees[row][i].height > previous_largest_height) {
//       trees[row][i].was_counted = 1;
//       previous_largest_height = trees[row][i].height;
//     }
//   }
//   return 0;
// }

// // find and mark all ascending trees in a row in 2d array of structs
// reverse int mark_ascending_trees_row_reverse(struct tree_s trees[99][99],
// int len,
//                                      int row) {
//   int i = 0;
//   int previous_largest_height = 0;
//   for (i = len - 1; i >= 0; i--) {
//     if (i == 0 || i == len - 1) {
//       trees[row][i].was_counted = 1;
//     }
//     if (trees[row][i].height > previous_largest_height) {
//       trees[row][i].was_counted = 1;
//       previous_largest_height = trees[row][i].height;
//     }
//   }
//   return 0;
// }

// // function that marks all trees that are shorter than tree at row,col
// moving
// // north, south, east, west until a taller tree is found
// int mark_trees_in_line_of_sight(struct tree_s trees[99][99], int len, int
// row,
//                                 int col) {
//   int i = 0;
//   int j = 0;
//   int north = 0;
//   int south = 0;
//   int east = 0;
//   int west = 0;
//   int current_height = trees[row][col].height;
//   // north
//   for (i = row - 1; i >= 0; i--) {
//     if (trees[i][col].height >= current_height) {
//       trees[i][col].was_counted = 1;
//       north++;
//       break;
//     }
//     trees[i][col].was_counted = 1;
//     north++;
//   }
//   // south
//   for (i = row + 1; i < len; i++) {
//     if (trees[i][col].height >= current_height) {
//       trees[i][col].was_counted = 1;
//       south++;
//       break;
//     }
//     trees[i][col].was_counted = 1;
//     south++;
//   }
//   // east
//   for (i = col + 1; i < len; i++) {
//     if (trees[row][i].height >= current_height) {
//       trees[row][i].was_counted = 1;
//       east++;
//       break;
//     }
//     trees[row][i].was_counted = 1;
//     east++;
//   }
//   // west
//   for (i = col - 1; i >= 0; i--) {
//     if (trees[row][i].height >= current_height) {
//       trees[row][i].was_counted = 1;
//       west++;
//       break;
//     }
//     trees[row][i].was_counted = 1;
//     west++;
//   }
//   return north * south * east * west;
// }

// int print_counted_trees(struct tree_s trees[99][99], int len) {
//   int i = 0;
//   int j = 0;
//   int count = 0;
//   for (i = 0; i < len; i++) {
//     for (j = 0; j < len; j++) {
//       printf("%d", trees[i][j].was_counted);
//     }
//     printf("\n");
//   }
//   return count;
// }

// int count_trees(struct tree_s trees[99][99], int len) {
//   int i = 0;
//   int j = 0;
//   int count = 0;
//   for (i = 0; i < len; i++) {
//     for (j = 0; j < len; j++) {
//       if (trees[i][j].was_counted == 1) {
//         count++;
//       }
//     }
//   }
//   return count;
// }

// int main() {
//   FILE *fptr;
//   char lines[101];
//   int j = 0;
//   // int answer = 0;
//   int answer2 = 0;
//   struct tree_s trees[99][99] = {0};
//   if ((fptr = fopen("C:\\input.txt", "r")) == NULL) {
//     printf("Error! opening file");
//     return 0;
//   }
//   while (fgets(lines, 101, fptr) != NULL) {
//     // printf("%s", lines);
//     for (int i = 0; i < 99; i++) {
//       trees[j][i].height = lines[i] - '0';
//       printf("%d", trees[j][i].height);
//     }
//     j++;
//     printf("\n");
//   }
//   for (int i = 0; i < 99; i++) {
//     for (j = 0; j < 99; j++) {
//       if (mark_trees_in_line_of_sight(trees, 99, i, j) > answer2) {
//         answer2 = mark_trees_in_line_of_sight(trees, 99, i, j);
//         // print_counted_trees(trees, 99);
//       }
//       // for (int k = 0; k < 99; k++) {
//       //   for (int l = 0; l < 99; l++) {
//       //     trees[k][l].was_counted = 0;
//       //   }
//       // }
//     }
//   }
//   // for loop to find first descending pair in each row
//   // for (int i = 0; i < 99; i++) { // part 1
//   //   mark_ascending_trees_column(trees, 99, i);
//   //   mark_ascending_trees_column_reverse(trees, 99, i);
//   //   mark_ascending_trees_row(trees, 99, i);
//   //   mark_ascending_trees_row_reverse(trees, 99, i);
//   // }
//   // answer = count_trees(trees, 99); // this works
//   printf("%d\n", answer2);

//   fclose(fptr);
//   return 0;
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// day 7... it was pure pain
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_FILES 10
// #define MAX_DIRS 10
// #define MAX_NAME_SIZE 50
// #define MAX_LINE_SIZE 50
// #define SYSTEM_FILE_SIZE 70000000
// #define UPDATE_SIZE 30000000

// typedef enum {
//   LIST_FILES,
//   CHANGE_DIR,
//   CMD_PROCESSING,
// } Command;

// typedef enum {
//   FILE_TYPE,
//   DIRECTORY_TYPE,
// } Type;

// typedef struct {
//   int size;
//   char name[MAX_NAME_SIZE];
// } File;

// typedef struct Directory {
//   char name[MAX_NAME_SIZE];
//   struct Directory *parent;
//   int directory_size;
//   File *files[MAX_FILES];
//   int num_files;
//   int num_subdirs;
//   struct Directory *subdirs[MAX_DIRS];
// } Directory;

// typedef struct {
//   Directory *cur_dir;
// } Cursor;

// Directory *create_directory(Directory *parent, const char *name) {

//   Directory *new_dir = malloc(sizeof(Directory));
//   new_dir->parent = parent;
//   new_dir->num_files = 0;
//   new_dir->num_subdirs = 0;
//   new_dir->directory_size = 0;
//   strcpy(new_dir->name, name);

//   if (parent != NULL) {
//     add_subdir(parent, new_dir);
//   }

//   return new_dir;
// }

// int add_subdir(Directory *parent, Directory *subdir) {

//   if (parent->num_subdirs >= MAX_DIRS) {
//     return 1;
//   }
//   parent->subdirs[parent->num_subdirs] = subdir;
//   parent->num_subdirs++;
//   return 0;
// }

// File *create_file(int size, const char *name) {

//   File *new_file = (File *)malloc(sizeof(File));
//   new_file->size = size;
//   strcpy(new_file->name, name);
//   return new_file;
// }

// int add_file_to_dir(Directory *dir, File *file) {
//   int num_files = dir->num_files;

//   if (num_files >= MAX_FILES) {
//     return 1;
//   }

//   dir->files[dir->num_files] = file;
//   dir->num_files++;
//   dir->directory_size += file->size;
//   update_parent_dir_size(dir->parent, file->size);

//   return 0;
// }

// void remove_subdirs(Directory *parent) {
//   for (int i = 0; i < parent->num_subdirs; i++) {
//     remove_subdirs(parent->subdirs[i]);
//     free(parent->subdirs[i]);
//   }
// }

// Command parse_command(const char *command) {
//   if (strncmp(command, "$ cd", 4) == 0) {
//     return CHANGE_DIR;
//   }

//   if (strncmp(command, "$ ls", 4) == 0) {
//     return LIST_FILES;
//   }

//   return CMD_PROCESSING;
// }

// char *parse_args(char *command) {
//   char *token = strtok(command, " ");

//   while (strcmp(token, "cd")) {
//     token = strtok(NULL, " ");
//   }

//   token = strtok(NULL, " ");
//   trim(token);

//   return token;
// }

// Cursor *change_directory(Cursor *cur_dir, char *directory) {
//   Cursor *new_dir = (Cursor *)malloc(sizeof(Cursor));
//   Directory *current_directory;
//   current_directory = cur_dir->cur_dir;

//   if (strcmp(directory, "..") == 0) {
//     // Go up 1 director
//     new_dir->cur_dir = cur_dir->cur_dir->parent;
//   } else if (strcmp(directory, "/") == 0) {
//     // Go to root directory
//     while (cur_dir->cur_dir->parent != NULL) {
//       cur_dir->cur_dir = cur_dir->cur_dir->parent;
//     }
//     new_dir->cur_dir = cur_dir->cur_dir;
//   } else if (strcmp(directory, ".") == 0) {
//     // Go to same directory
//     return cur_dir;
//   } else {
//     // Go to sub directory
//     for (int i = 0; i < current_directory->num_subdirs; i++) {
//       if (strcmp(current_directory->subdirs[i]->name, directory) == 0) {
//         new_dir->cur_dir = current_directory->subdirs[i];
//       }
//     }
//   }
//   return new_dir;
// }

// Type parse_file(const char *info, char *name, int *size) {

//   char *token = strtok(info, " ");

//   if (token[0] == 'd') {
//     token = strtok(NULL, " ");
//     trim(token);
//     strcpy(name, token);
//     return DIRECTORY_TYPE;
//   } else {
//     *size = atoi(token);
//     token = strtok(NULL, " ");
//     trim(token);
//     strcpy(name, token);
//     return FILE_TYPE;
//   }
// }

// int create_file_in_dir(Directory *dir, const char *name, int size) {
//   File *new_file = create_file(size, name);
//   add_file_to_dir(dir, new_file);

//   return 0;
// }
// void trim(char *string) { string[strlen(string) - 1] = '\0'; }

// void update_parent_dir_size(Directory *cursor, int size) {
//   if (cursor == NULL) {
//     return;
//   }
//   cursor->directory_size += size;
//   update_parent_dir_size(cursor->parent, size);
// }

// void find_dirs_by_size_lt(Directory *cursor, int size, Directory *matches[],
//                           int *num_matches) {

//   if (cursor->num_subdirs != 0) {
//     for (int i = 0; i < cursor->num_subdirs; i++) {
//       find_dirs_by_size_lt(cursor->subdirs[i], size, matches, num_matches);
//     }
//   }
//   if (cursor->directory_size < size) {
//     matches[*num_matches] = cursor;
//     *num_matches += 1;
//   }
// }

// void find_dirs_by_size_gte(Directory *cursor, int size, Directory *matches[],
//                            int *num_matches) {

//   if (cursor->num_subdirs != 0) {
//     for (int i = 0; i < cursor->num_subdirs; i++) {
//       find_dirs_by_size_gte(cursor->subdirs[i], size, matches, num_matches);
//     }
//   }
//   if (cursor->directory_size >= size) {
//     matches[*num_matches] = cursor;
//     *num_matches += 1;
//   }
// }

// int main() {

//   FILE *fp;

//   char *cmd_line = (char *)malloc(MAX_LINE_SIZE * sizeof(char));

//   fp = fopen("C:\\input.txt", "r");
//   Directory *root = create_directory(NULL, "root");
//   Cursor *current_dir = (Cursor *)malloc(sizeof(Cursor));
//   current_dir->cur_dir = root;
//   Command current_command;

//   // Build directory structure
//   while (fgets(cmd_line, MAX_LINE_SIZE, fp)) {

//     Command next_cmd = parse_command(cmd_line);
//     char *args;
//     char *name = (char *)malloc(MAX_LINE_SIZE * sizeof(char));
//     int size = 0;
//     if (next_cmd == CHANGE_DIR) {
//       // Process change dir
//       args = parse_args(cmd_line);
//       current_command = CHANGE_DIR;
//       current_dir = change_directory(current_dir, args);
//     } else if (next_cmd == LIST_FILES) {
//       // Process List Files
//       current_command = LIST_FILES;
//       continue;
//     }

//     if (current_command == LIST_FILES) {
//       Type artifact = parse_file(cmd_line, name, &size);
//       switch (artifact) {
//       case DIRECTORY_TYPE:
//         create_directory(current_dir->cur_dir, name);
//         break;
//       case FILE_TYPE:
//         // create_file_in_dir(current_dir->cur_dir,name,size);
//         create_file_in_dir(current_dir->cur_dir, name, size);
//         break;
//       default:
//         break;
//       }
//     }
//   }

//   printf("Finding matches...\n");
//   Directory *matches[50];
//   int num_matches = 0;
//   int total_size = 0;

//   find_dirs_by_size_lt(root, 100000, matches, &num_matches);

//   for (int i = 0; i < num_matches; i++) {
//     total_size += matches[i]->directory_size;
//     printf("Found directory: %s with size %d\n", matches[i]->name,
//            matches[i]->directory_size);
//   }

//   printf("Total size is: %d\n", total_size);

//   // Part 2
//   int target_size = SYSTEM_FILE_SIZE - root->directory_size;
//   target_size = UPDATE_SIZE - target_size;
//   num_matches = 0;
//   int min_size = SYSTEM_FILE_SIZE;

//   find_dirs_by_size_gte(root, target_size, matches, &num_matches);

//   for (int i = 0; i < num_matches; i++) {
//     printf("Found directory %s with size %d\n", matches[i]->name,
//            matches[i]->directory_size);

//     if (matches[i]->directory_size < min_size) {
//       min_size = matches[i]->directory_size;
//     }
//   }

//   printf("Smallest dir has size: %d\n", min_size);

//   // Clean up
//   remove_subdirs(root);
//   free(root);
//   free(current_dir);
//   fclose(fp);
//   return 0;
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// day 6
// int find_n_unique_set(char *str, int len, int n) {
//   int i = 0;
//   int j = 0;
//   int k = 0;
//   int found = 0;
//   for (i = 0; i < len - n; i++) {
//     found = 0;
//     for (j = 0; j < n; j++) {
//       for (k = 0; k < n; k++) {
//         if (str[i + j] == str[i + k]) {
//           found++;
//         }
//       }
//     }
//     if (found == n) {
//       return i;
//     }
//   }
//   return -1;
// }

// int main() {
//   FILE *fptr;
//   char chars[4096];
//   int answer;

//   if ((fptr = fopen("C:\\input.txt", "r")) == NULL) {
//     printf("Error! opening file");
//     return 0;
//   }
//   while (fgets(chars, 4096, fptr) != NULL) {
//     printf("%s", chars);
//   }
//   // answer = 4 + find_n_unique_set(chars, 4096, 4);//part 1
//   answer = 14 + find_n_unique_set(chars, 4096, 14); // part 2
//   printf("%d", answer);
//   fclose(fptr);
//   return 0;
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
// struct move_s {
//   int amount;
//   int from;
//   int to;
// };
// int string_length(char *str) {
//   int len = 0;
//   while (*str != '\0') {
//     len++;
//     str++;
//   }
//   return len;
// }

// void add_char(char *str, char c) { // not safe, don't care
//   int len = string_length(str);
//   str[len] = c;
//   str[len + 1] = '\0';
// }

// char remove_char(char *str) { // not safe, don't care
//   int len = string_length(str);
//   char c = str[len - 1];
//   str[len - 1] = '\0';
//   return c;
// }

// void add_string(char *str, char *str2) { // not safe, don't care
//   int len = string_length(str);
//   int len2 = string_length(str2);
//   int i = 0;
//   for (i = 0; i < len2; i++) {
//     str[len + i] = str2[i];
//   }
//   str[len + len2] = '\0';
// }

// int main() {
//   FILE *fptr;
//   struct move_s move;

//   char stacks[9][1000] = {"FCJPHTW", "GRVFZJBH", "HPTR", "ZSNPHT",
//   "NVFZHJCD",
//                           "PMGFWDZ", "MVZWSJDP", "NDS",  "DZSFM"};

//   char str[60];
//   int i = 0;
//   char *token;

//   if ((fptr = fopen("C:\\input.txt", "r")) == NULL) {
//     printf("Error! opening file");
//     return 0;
//   }
//   while (fgets(str, 60, fptr) != NULL) { // put data in array

//     // printf("%s", str);
//     token = strtok(str, "move");
//     move.amount = atoi(token);
//     // printf("start: %d \n", move.start);
//     token = strtok(NULL, "from");
//     move.from = atoi(token);
//     token = strtok(NULL, "to");
//     move.to = atoi(token);
//     printf("amount: %d from: %d to: %d \n", move.amount, move.from, move.to);
//     // for (i = 0; i < move.amount; i++) {//part 1
//     //   add_char(stacks[move.to - 1], remove_char(stacks[move.from - 1]));
//     // }
//     add_string(stacks[move.to - 1],
//                &stacks[move.from - 1][string_length(stacks[move.from - 1]) -
//                                       move.amount]); // part 2
//     stacks[move.from - 1][string_length(stacks[move.from - 1]) - move.amount]
//     =
//         '\0'; // part 2
//   }
//   for (i = 0; i < 9; i++) {
//     printf("%s \n", stacks[i]);
//   }
//   fclose(fptr);
//   return 0;
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// day 4

// int range_contains_other_range(int min, int max, int min2, int max2) { //
// part 1
//   return (min >= min2 && min <= max2) || (max >= min2 && max <= max2);
// }

// int range_overlaps_other_range(int min, int max, int min2, int max2) { //
// part 2
//   return (min >= min2 && min <= max2) || (max >= min2 && max <= max2) ||
//          (min2 >= min && min2 <= max) || (max2 >= min && max2 <= max);
// }

// struct range {
//   int min;
//   int max;
// };

// struct range ranges[1000][2];

// // part 1
// int main() {
//   FILE *fptr;
//   char str[60];
//   int i = 0;
//   int j = 0;
//   int answer = 0;
//   char *token;

//   if ((fptr = fopen("C:\\input.txt", "r")) == NULL) {
//     printf("Error! opening file");
//     return 0;
//   }
//   while (fgets(str, 60, fptr) != NULL) { // put data in array
//     printf("%s", str);
//     token = strtok(str, ",-");
//     printf("%s\n", token);
//     ranges[i][0].min = atoi(token);
//     token = strtok(NULL, ",-");
//     printf("%s\n", token);
//     ranges[i][0].max = atoi(token);
//     token = strtok(NULL, ",-");
//     printf("%s\n", token);
//     ranges[i][1].min = atoi(token);
//     token = strtok(NULL, ",-");
//     printf("%s\n", token);
//     ranges[i][1].max = atoi(token);
//     i++;
//     printf("%d\n",
//            range_overlaps_other_range(ranges[i][1].min, ranges[i][1].max,
//                                       ranges[i][0].min, ranges[i][0].max));
//   }
//   for (j = 0; j < 1000; j++) {
//     answer += range_overlaps_other_range(ranges[j][1].min,
//     ranges[j][1].max,
//                                          ranges[j][0].min,
//                                          ranges[j][0].max);
//   }
//   printf("%d", answer);
//   fclose(fptr);
//   return 0;
// }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// // day 3
// int find_common_char(char *arr1, char *arr2, int len) {
//   int i = 0, j = 0;
//   for (i = 0; i < len; i++) {
//     for (j = 0; j < len; j++) {
//       if (arr1[i] == arr2[j]) {
//         if (arr1[i] < 91) {
//           printf("Common char: %c Value: %d\n", arr1[i],
//                  (int)(arr1[i] - 38)); // use some ascii magic to get the
//                  value
//           return (int)(arr1[i] - 38);
//         } else {
//           printf("Common char: %c Value: %d\n", arr1[i], (int)(arr1[i] -
//           96)); return (int)(arr1[i] - 96);
//         }
//       }
//     }
//   }
//   return 1;
// }

// int find_common_char_3_arrays(char *arr1, char *arr2, char *arr3, int len1,
//                               int len2, int len3) {
//   int i = 0, j = 0, k = 0;
//   for (i = 0; i < len1; i++) {
//     for (j = 0; j < len2; j++) {
//       for (k = 0; k < len3; k++) {
//         if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
//           if (arr1[i] < 91) {
//             // printf("Common char: %c Value: %d\n", arr1[i], (int)(arr1[i]
//             -
//             // 38));
//             return (int)(arr1[i] - 38); // use some ascii magic to get the
//             value
//           } else {
//             // printf("Common char: %c Value: %d\n", arr1[i], (int)(arr1[i]
//             -
//             // 96));
//             return (int)(arr1[i] - 96);
//           }
//         }
//       }
//     }
//   }
//   return 1;
// }
// // part 2
// int main() {
//   FILE *fptr;
//   int answer = 0;
//   char str[60];
//   char lines[300][100];
//   int line_lenghts[300];
//   int i = 0;
//   int j = 0;

//   if ((fptr = fopen("C:\\input.txt", "r")) == NULL) {
//     printf("Error! opening file");
//     return 0;
//   }

//   while (fgets(str, 60, fptr) != NULL) { // put data in array
//     while (str[j] != '\0') {
//       lines[i][j] = str[j];
//       j++;
//     }
//     if (str[j] == '\0') {
//       lines[i][j - 1] = '\0';
//       line_lenghts[i] = j - 1;
//     }
//     j = 0;
//     i++;
//   }
//   for (int k = 0; k < 300; k += 3) {
//     answer += find_common_char_3_arrays(lines[k], lines[k + 1], lines[k +
//     2],
//                                         line_lenghts[k], line_lenghts[k +
//                                         1], line_lenghts[k + 2]);
//     // answer +=
//   }
//   printf("Answer: %d", answer);
//   fclose(fptr);
//   return 0;
// }

// part 1
//  int main() {
//    FILE *fptr;
//    int answer = 0;
//    char str[60];
//    char lines[300][100];
//    int line_lenghts[300];
//    int i = 0;
//    int j = 0;

//   if ((fptr = fopen("C:\\input.txt", "r")) == NULL) {
//     printf("Error! opening file");
//     return 0;
//   }

//   while (fgets(str, 60, fptr) != NULL) { // put data in array
//     while (str[j] != '\0') {
//       lines[i][j] = str[j];
//       j++;
//     }
//     if (str[j] == '\0') {
//       lines[i][j - 1] = '\0';
//       line_lenghts[i] = j - 1;
//     }
//     j = 0;
//     i++;
//   }
//   for (int k = 0; k < 300; k++) {
//     answer += find_common_char(lines[k], &lines[k][line_lenghts[k] / 2],
//                                line_lenghts[k] / 2);
//   }
//   printf("Answer: %d", answer);
//   fclose(fptr);
//   return 0;
// }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// day 2
//  int win_lose_draw(char player1, char player2) {
//    int score = 0;
//    // if ((player1 - player2) == -23) {
//    //   score = 3;
//    //   return score;
//    // }
//    switch (player1) {
//    case 'A':               // rock
//      if (player2 == 'Y') { // paper
//        score = 1;
//      } else if (player2 == 'Z') { // scissors
//        score = 2;
//      } else {
//        score = 3;
//      }
//      break;
//    case 'B':               // paper
//      if (player2 == 'X') { // rock
//        score = 1;
//      } else if (player2 == 'Z') { // scissors
//        score = 3;
//      } else {
//        score = 2;
//      }
//      break;
//    case 'C':               // scissors
//      if (player2 == 'X') { // rock
//        score = 2;
//      } else if (player2 == 'Y') { // paper
//        score = 3;
//      } else {
//        score = 1;
//      }
//      break;
//    default:
//      break;
//    }
//    return score;
//  }

// int main() {
//   char input_pairs[2500][2];
//   int i = 0;
//   FILE *fptr;
//   char str[5];
//   int total_score = 0;
//   if ((fptr = fopen("C:\\input.txt", "r")) == NULL) {
//     printf("Error! opening file");
//     return 0;
//   }

//   while (fgets(str, 60, fptr) != NULL) {
//     input_pairs[i][0] = str[0];
//     input_pairs[i][1] = str[2];
//     i++;
//   }
//   for (i = 0; i < 2500; i++) {
//     // printf("%c %c %d", input_pairs[i][0], input_pairs[i][1], i);
//     switch (input_pairs[i][1]) { // sorting the choices
//       {
//       case 'X': // rock
//         // printf(" 1");
//         total_score += 0;
//         break;
//       case 'Y': // paper
//         // printf(" 2");
//         total_score += 3;
//         break;
//       case 'Z': // scissors
//         // printf(" 6");
//         total_score += 6;
//         break;
//       default:
//         break;
//       }
//     }
//     total_score += win_lose_draw(input_pairs[i][0], input_pairs[i][1]);
//     // printf(" %d\n", win_lose_draw(input_pairs[i][0],
//     input_pairs[i][1]));
//   }
//   printf("%d", total_score);
//   fclose(fptr);
//   return 0;
// }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// day 1
//  int main() {
//    int num;
//    char str[60];
//    FILE *fptr;
//    int current_elf_index = 0;
//    int sum = 0;
//    int vals[10000] = {0};

//   if ((fptr = fopen("C:\\input.txt", "r")) == NULL) {
//     printf("Error! opening file");
//     return 0;
//   }

//   while (fgets(str, 60, fptr) != NULL) {
//     if (str[0] == '\n') {
//       vals[current_elf_index] = sum;
//       current_elf_index++;
//       sum = 0;
//     } else {
//       sscanf(str, "%d", &num);
//       sum += num;
//     }
//   }

//   qsort(vals, 10000, sizeof(int), compare_function);
//   printf("%d", sum_integer_array(vals, 3));
//   fclose(fptr);
//   return 0;
// }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
