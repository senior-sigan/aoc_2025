#include <stdio.h>
#include <stdlib.h>

#define LINE_LEN 100
#define MAX_N 12

long aslong(char* str) {
    long res = 0;
    // printf("str: ");
    for (int i = 0; i < MAX_N; i++) {
        // printf("%d", str[i]);
        res = res*10 + str[i];
    }
    // printf("\n");
    return res;
}

long find_max_n(char* arr) {
    char maxs[MAX_N];

    int left = 0;
    for (int i = 0; i < MAX_N; i++) {
        // printf("i: %d, left: %d, value: %d\n", i, left, arr[left]);
        maxs[i] = arr[left++];
        for (int j = left; j < LINE_LEN - (MAX_N - i - 1); j++) {
            if (arr[j] > maxs[i]) {
                maxs[i] = arr[j];
                left = j + 1;
            }
        }
    }

    return aslong(maxs);
}

int main(void) {
    char line[LINE_LEN + 1] = {0};
    
    long sum = 0;
    while(scanf("%s", line) > 0) {
        printf("in:  ");
        for (int i = 0; i < LINE_LEN; i++) {
            line[i] = line[i] - '0'; // ascii to int
            printf("%d", line[i]);
        }
        printf("\n");

        long joltage = find_max_n(line);
        printf("out: %ld\n", joltage);
        sum += joltage;
    }
    printf("RESULT: %ld\n", sum);

    return 0;
}
