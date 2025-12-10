#include <stdio.h>
#include <stdlib.h>

int find_max_pair(char* arr, int size) {
    char a = arr[0];
    char b = arr[1];

    for (int i = 1; i < size - 1; i++) {
        if (arr[i] > a) {
            a = arr[i];
            b = arr[i+1];
        } else if (arr[i] > b) {
            b = arr[i];
        }
    }
    if (arr[size-1] > b) {
        b = arr[size-1];
    }

    return a*10 + b;
}

#define LINE_LEN 100

int main(void) {
    char* line = malloc(sizeof(char) * (LINE_LEN+1));
    
    int sum = 0;
    while(scanf("%s", line) > 0) {
        printf("in: ");
        for (int i = 0; i < LINE_LEN; i++) {
            line[i] = line[i] - '0'; // ascii to int
            printf("%d", line[i]);
        }
        printf("\n");

        int joltage = find_max_pair(line, LINE_LEN);
        printf("%d\n", joltage);
        sum += joltage;
    }
    printf("RESULT: %d\n", sum);

    return 0;
}
