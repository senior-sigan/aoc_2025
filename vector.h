// Simple implementation of a vector (dynamic array)
#include <stdlib.h>

/**
 * @brief append an element to array
 * User must specify the struct:
 * typedef struct {
 *   int* items; // any type supported
 *   int size;
 *   int capacity;
 * } MyElements; // use defined name of the array
 * MyElements arr;
 * arr_append(arr, 42);
 */

#define arr_append(arr, el)                                              \
  do {                                                                   \
    if (arr.size >= arr.capacity) {                                      \
      if (arr.capacity == 0) {                                           \
        arr.capacity = 128;                                              \
      } else {                                                           \
        arr.capacity *= 2;                                               \
      }                                                                  \
      arr.items = realloc(arr.items, arr.capacity * sizeof(*arr.items)); \
    }                                                                    \
    arr.items[arr.size++] = el;                                          \
  } while ((void)0, 0)
