#include "sort_a_unstable.h"

void sort_a_unstable_ascending(size_t input_count, int *input) {
  int input_capture;
  size_t gap = input_count;
  size_t i;
  size_t j;

  while (gap > 15) {
    gap = (gap >> 5) + (gap >> 3);
    i = gap;

    while (i < input_count) {
      input_capture = input[i];
      j = i;

      while (
        j >= gap &&
        input[j - gap] > input_capture
      ) {
        input[j] = input[j - gap];
        j -= gap;
      }

      input[j] = input_capture;
      i++;
    }
  }

  i = 1;
  gap = 0;

  while (i < input_count) {
    input_capture = input[i];
    j = i;

    while (
      j > 0 &&
      input[gap] > input_capture
    ) {
      input[j] = input[gap];
      j = gap;
      gap--;
    }

    input[j] = input_capture;
    gap = i;
    i++;
  }
}

void sort_a_unstable_descending(size_t input_count, int *input) {
  int input_capture;
  size_t gap = input_count;
  size_t i;
  size_t j;

  while (gap > 15) {
    gap = (gap >> 5) + (gap >> 3);
    i = gap;

    while (i < input_count) {
      input_capture = input[i];
      j = i;

      while (
        j >= gap &&
        input[j - gap] < input_capture
      ) {
        input[j] = input[j - gap];
        j -= gap;
      }

      input[j] = input_capture;
      i++;
    }
  }

  i = 1;
  gap = 0;

  while (i < input_count) {
    input_capture = input[i];
    j = i;

    while (
      j > 0 &&
      input[gap] < input_capture
    ) {
      input[j] = input[gap];
      j = gap;
      gap--;
    }

    input[j] = input_capture;
    gap = i;
    i++;
  }
}
