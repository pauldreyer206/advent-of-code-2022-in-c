#include "helpers.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// day 11 joh! very very hacky solution... but it works!
#define NUMBER_OF_ROUNDS 10000

uint64_t monkey_0_test_operation(uint64_t test_value, uint64_t operation_input,
                                 uint64_t do_operation) {
  // check if test_value is divisible by 23
  if (!do_operation) {
    if (test_value % 7 == 0) {
      return 1;
    }
    return 0;
  } else {
    return operation_input * 3;
  }
}

uint64_t monkey_1_test_operation(uint64_t test_value, uint64_t operation_input,
                                 uint64_t do_operation) {
  // check if test_value is divisible by 19
  if (!do_operation) {
    if (test_value % 19 == 0) {
      return 1;
    }
    return 0;
  } else {
    return operation_input * 17;
  }
}

uint64_t monkey_2_test_operation(uint64_t test_value, uint64_t operation_input,
                                 uint64_t do_operation) {
  // check if test_value is divisible by 23
  if (!do_operation) {
    if (test_value % 13 == 0) {
      return 1;
    }
    return 0;
  } else {
    return operation_input + 1;
  }
}

uint64_t monkey_3_test_operation(uint64_t test_value, uint64_t operation_input,
                                 uint64_t do_operation) {
  // check if test_value is divisible by 23
  if (!do_operation) {
    if (test_value % 3 == 0) {
      return 1;
    }
    return 0;
  } else {
    return operation_input + 2;
  }
}

uint64_t monkey_4_test_operation(uint64_t test_value, uint64_t operation_input,
                                 uint64_t do_operation) {
  // check if test_value is divisible by 23
  if (!do_operation) {
    if (test_value % 2 == 0) {
      return 1;
    }
    return 0;
  } else {
    return operation_input * operation_input;
  }
}

uint64_t monkey_5_test_operation(uint64_t test_value, uint64_t operation_input,
                                 uint64_t do_operation) {
  // check if test_value is divisible by 19
  if (!do_operation) {
    if (test_value % 11 == 0) {
      return 1;
    }

    return 0;
  } else {
    return operation_input + 8;
  }
}

uint64_t monkey_6_test_operation(uint64_t test_value, uint64_t operation_input,
                                 uint64_t do_operation) {
  // check if test_value is divisible by 19
  if (!do_operation) {
    if (test_value % 17 == 0) {
      return 1;
    }

    return 0;
  } else {
    return operation_input + 6;
  }
}

uint64_t monkey_7_test_operation(uint64_t test_value, uint64_t operation_input,
                                 uint64_t do_operation) {
  // check if test_value is divisible by 19
  if (!do_operation) {
    if (test_value % 5 == 0) {
      return 1;
    }

    return 0;
  } else {
    return operation_input + 7;
  }
}

typedef struct monkey_s {
  uint64_t items[100];
  uint64_t number_of_items;
  uint64_t inspected;
  uint64_t monkey_to_throw_to_if_true;
  uint64_t monkey_to_throw_to_if_false;
};

struct monkey_s monkeys[8] = {0};

void append(uint64_t *array, uint64_t size, uint64_t value) {
  array[size] = value;
}

uint64_t remove_from_front(uint64_t *array, uint64_t size) {
  uint64_t value = array[0];
  for (uint64_t i = 0; i < size - 1; i++) {
    array[i] = array[i + 1];
  }
  return value;
}

void init_monkey(uint64_t monkey_number, uint64_t monkey_to_throw_to_if_true,
                 uint64_t monkey_to_throw_to_if_false, uint64_t *items,
                 uint64_t number_of_items) {
  monkeys[monkey_number].monkey_to_throw_to_if_true =
      monkey_to_throw_to_if_true;
  monkeys[monkey_number].monkey_to_throw_to_if_false =
      monkey_to_throw_to_if_false;
  monkeys[monkey_number].number_of_items = number_of_items;
  for (uint64_t i = 0; i < number_of_items; i++) {
    monkeys[monkey_number].items[i] = items[i];
  }
}

void print_times_inspected() {
  for (uint64_t i = 0; i < 8; i++) {
    printf("Monkey %lld was inspected %lld times\n", i, monkeys[i].inspected);
  }
}

void transfer_single_item_from_monkey_to_another(uint64_t monkey_number,
                                                 uint64_t monkey_to_throw_to) {
  uint64_t item = remove_from_front(monkeys[monkey_number].items,
                                    monkeys[monkey_number].number_of_items);
  monkeys[monkey_number].number_of_items--;
  append(monkeys[monkey_to_throw_to].items,
         monkeys[monkey_to_throw_to].number_of_items, item);
  monkeys[monkey_to_throw_to].number_of_items++;
}
// 16180387602 too low
// 16184981659 too low
// 16152451678 too low
int main() {
  // init monkeys
  uint64_t number_of_items = 0;
  uint64_t supermod = 7 * 19 * 13 * 3 * 2 * 11 * 17 *
                      5; // mod by this without losing information
  init_monkey(0, 7, 1, (uint64_t[]){93, 54, 69, 66, 71}, 5);
  init_monkey(1, 5, 7, (uint64_t[]){89, 51, 80, 66}, 4);
  init_monkey(2, 4, 3, (uint64_t[]){90, 92, 63, 91, 96, 63, 64}, 7);
  init_monkey(3, 4, 6, (uint64_t[]){65, 77}, 2);
  init_monkey(4, 0, 6, (uint64_t[]){76, 68, 94}, 3);
  init_monkey(5, 2, 3, (uint64_t[]){86, 65, 66, 97, 73, 83}, 6);
  init_monkey(6, 0, 1, (uint64_t[]){78}, 1);
  init_monkey(7, 2, 5, (uint64_t[]){89, 57, 59, 61, 87, 55, 55, 88}, 8);
  for (uint64_t i = 0; i < NUMBER_OF_ROUNDS; i++) {
    for (uint64_t j = 0; j < 8; j++) {
      number_of_items = monkeys[j].number_of_items;
      for (uint64_t k = 0; k < number_of_items; k++) {
        // increase worry level using operation
        monkeys[j].items[0] =
            monkeys[j].items[0] % supermod; // mod by supermod to prevent
        // overflow
        switch (j) {
        case 0:
          // mod by 7 to prevent overflow
          monkeys[j].items[0] = monkey_0_test_operation(monkeys[j].items[0],
                                                        monkeys[j].items[0], 1);
          break;
        case 1:
          monkeys[j].items[0] = monkey_1_test_operation(monkeys[j].items[0],
                                                        monkeys[j].items[0], 1);
          break;
        case 2:
          monkeys[j].items[0] = monkey_2_test_operation(monkeys[j].items[0],
                                                        monkeys[j].items[0], 1);
          break;
        case 3:
          monkeys[j].items[0] = monkey_3_test_operation(monkeys[j].items[0],
                                                        monkeys[j].items[0], 1);
          break;
        case 4:
          monkeys[j].items[0] = monkey_4_test_operation(monkeys[j].items[0],
                                                        monkeys[j].items[0], 1);
          break;
        case 5:
          monkeys[j].items[0] = monkey_5_test_operation(monkeys[j].items[0],
                                                        monkeys[j].items[0], 1);
          break;
        case 6:
          monkeys[j].items[0] = monkey_6_test_operation(monkeys[j].items[0],
                                                        monkeys[j].items[0], 1);
          break;
        case 7:
          monkeys[j].items[0] = monkey_7_test_operation(monkeys[j].items[0],
                                                        monkeys[j].items[0], 1);
          break;
        }
        // divide by 3
        // monkeys[j].items[0] = monkeys[j].items[0] / 3;
        if (monkeys[j].items[0] > 9223372036854775807) {
          printf("Overflow detected\n"); // why is this happening?
        }
        switch (j) {
        case 0:
          if (monkey_0_test_operation(monkeys[j].items[0], 0, 0)) {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_true);
          } else {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_false);
          }
          break;
        case 1:
          if (monkey_1_test_operation(monkeys[j].items[0], 0, 0)) {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_true);
          } else {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_false);
          }
          break;
        case 2:
          if (monkey_2_test_operation(monkeys[j].items[0], 0, 0)) {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_true);
          } else {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_false);
          }
          break;
        case 3:
          if (monkey_3_test_operation(monkeys[j].items[0], 0, 0)) {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_true);
          } else {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_false);
          }
          break;
        case 4:
          if (monkey_4_test_operation(monkeys[j].items[0], 0, 0)) {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_true);
          } else {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_false);
          }
          break;
        case 5:
          if (monkey_5_test_operation(monkeys[j].items[0], 0, 0)) {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_true);
          } else {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_false);
          }
          break;
        case 6:
          if (monkey_6_test_operation(monkeys[j].items[0], 0, 0)) {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_true);
          } else {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_false);
          }
          break;
        case 7:
          if (monkey_7_test_operation(monkeys[j].items[0], 0, 0)) {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_true);
          } else {
            monkeys[j].inspected++;
            transfer_single_item_from_monkey_to_another(
                j, monkeys[j].monkey_to_throw_to_if_false);
          }
          break;
        }
      }
    }
  }
  print_times_inspected();
  return 0;
}
