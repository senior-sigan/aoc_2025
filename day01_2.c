// https://adventofcode.com/2025/day/1

#include <stdio.h>

#define N 100

int mod(int a, int n) {
    if (a >= 0) {
        return a % n;
    } else {
        while (a < 0) {
            a += n;
        }
        return a % n;
    }
}

int main(void) {
    char dir;
    int count;

    int pwd = 0;
    int value = 50;
    while(scanf("%c%d ", &dir, &count) > 0) {
        int d = 1;
        if (dir == 'L') {
            d = -1;
        }

        // HAHA, emulate rotation LIKE IN REAL LIFE
        for (int i = 0; i < count; i++) {
            value = mod(value + d, N);
            if (value == 0) pwd++;
        }

        // printf("INPUT: %c%d\t%d\t%d\n", dir, count, value, pwd);
    }

    printf("%d\n", pwd);

    return 0;
}
