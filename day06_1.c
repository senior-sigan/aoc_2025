#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

#define MAX_LINE_WIDTH 4000
#define MAX_N_LINES 10
char line[MAX_N_LINES][MAX_LINE_WIDTH] = {0};

typedef struct {
  long* items;
  int size;
  int capacity;
} Numbers;

int main(void) {
  // it could be a bit improved by reading and parsing on-fly
  int n_lines = 0;
  for (int i = 0; i < MAX_N_LINES; i++) {
    if (scanf("%[^\n]\n", line[n_lines]) > 0) {
      printf("[%s]\n", line[n_lines]);
      n_lines++;
    }
  }
  printf("Read lines: %d\n", n_lines);
  // first (n_lines - 1) are numbers, last line is operations

  Numbers* number_lines = calloc(n_lines - 1, sizeof(Numbers));

  for (int i = 0; i < n_lines - 1; i++) {
    char* token = strtok(line[i], " ");
    while (token) {
      printf("%s ", token);
      long num = atol(token);
      arr_append(number_lines[i], num);

      token = strtok(NULL, " ");
    }

    printf("\n====\n");
  }

  long total = 0;
  int col = 0;
  char* token = strtok(line[n_lines - 1], " ");
  while (token) {
    printf("%s ", token);
    switch (token[0]) {
      case '*': {
        long agg = 1;
        for (int i = 0; i < n_lines - 1; i++) {
          agg *= number_lines[i].items[col];
        }
        total += agg;
        break;
      }
      case '+': {
        long agg = 0;
        for (int i = 0; i < n_lines - 1; i++) {
          agg += number_lines[i].items[col];
        }
        total += agg;
        break;
      }
      default:
        printf("Unknown operation: '%s'\n", token);
        break;
    }
    token = strtok(NULL, " ");
    col++;
  }
  printf("\n====\n");
  printf("RESULT: %ld\n", total);

  return 0;
}
