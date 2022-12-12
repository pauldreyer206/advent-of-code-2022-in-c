
// for ordering integers, swap signs for reverse order
int compare_function(const void *a, const void *b) {
  int *x = (int *)a;
  int *y = (int *)b;
  return *y - *x;
}

// int compare_function(const void *a,
//                      const void *b) { // for ordering strings, swop sign of
//                                       // strcmp for reverse order
//   return (strcmp((char *)a, (char *)b));
// }

// int compare_function(const void *a, const void *b) {// for ordering floats,
//   double *x = (double *)a;
//   double *y = (double *)b;
//   if (*x < *y)
//     return -1;
//   else if (*x > *y)
//     return 1;
//   return 0;
// }

// qsort(<arrayname>, <size>, sizeof(<elementsize>), compare_function);

int sum_integer_array(int *array, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum;
}

int array_max(int *array, int size) {
  int max = array[0];
  for (int i = 0; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

int array_min(int *array, int size) {
  int min = array[0];
  for (int i = 0; i < size; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}