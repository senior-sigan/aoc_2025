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
    int start = 50;
    while(scanf("%c%d ", &dir, &count) > 0) {
        if (dir == 'L') {
            start = mod(start - count, N);
        } else {
            start = mod(start + count, N);   
        }
        if (start == 0) {
            pwd += 1;
        }
        // printf("INPUT: %c %d %d\n", dir, count, start);
    }

    printf("%d\n", pwd);

    return 0;
}
