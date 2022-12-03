#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            // printf("Common char: %c Value: %d\n", arr1[i], (int)(arr1[i] -
            // 38));
            return (int)(arr1[i] - 38); // use some ascii magic to get the value
          } else {
            // printf("Common char: %c Value: %d\n", arr1[i], (int)(arr1[i] -
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

  if ((fptr = fopen("C:\\input.txt", "r")) == NULL) {
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
    // answer +=
  }
  printf("Answer: %d", answer);
  fclose(fptr);
  return 0;
}

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
