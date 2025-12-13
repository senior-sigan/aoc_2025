#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

#define MAX_LINE_WIDTH 4000
#define MAX_N_LINES 10
char line[MAX_N_LINES][MAX_LINE_WIDTH] = {0};
int n_lines = 0;

typedef struct {
  char* items;
  int size;
  int capacity;
} Line;

bool read_column(int col, int* value) {
  *value = 0;
  bool any_num = false;
  for (int i = 0; i < n_lines; i++) {
    char ch = line[i][col];
    if (ch >= '0' && ch <= '9') {
      *value = *value * 10 + (ch - '0');
      any_num = true;
    }
  }
  return any_num;
}

int main(void) {
  for (int i = 0; i < MAX_N_LINES; i++) {
    while (fgets(line[n_lines], MAX_LINE_WIDTH, stdin) != NULL) {
      printf("%s", line[n_lines]);
      n_lines++;
    }
  }
  printf("Read lines: %d\n", n_lines);
  // first (n_lines - 1) are numbers, last line is operations

  char lastop = {0};
  long agg = 0;
  long res = 0;
  for (int col = 0; line[n_lines-1][col] != '\0'; col++) {
    char ch = line[n_lines-1][col];
    if (ch == '*') {
      printf("agg = %ld\n", agg);
      res += agg;
      lastop = '*';
      agg = 1;
    } else if (ch == '+') {
      printf("agg = %ld\n", agg);
      res += agg;
      lastop = '+';
      agg = 0;
    }
    
    int val = 0;
    if (read_column(col, &val)) {
      printf("%c %d\n", lastop, val);
      if (lastop == '*') agg *= val;
      if (lastop == '+') agg += val;
    }
  }
  printf("agg = %ld\n", agg);
  // flush last operation
  res += agg;

  printf("RESULT: %ld\n", res);
  return 0;
}
