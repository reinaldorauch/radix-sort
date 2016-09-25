#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int *radix (int *input, int length) {
  return input;
}


int main (int argc, char **argv) {
 int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
 int *sorted;

 sorted = radix(arr, 10);

 assert(sorted[0] == arr[9]);

 return 0;
}
