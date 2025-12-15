#include <stdio.h>

#define MAX_LINE_WIDTH 200

int main(void) {
    char line[MAX_LINE_WIDTH] = {0};
    long set[MAX_LINE_WIDTH] = {0};

    long splits = 0;
    while (scanf("%s", line) > 0) {
        printf("%s\n", line);
        int i = 0; // count line length. We need it later
        for (i = 0; line[i] != 0; i++) {
            if (line[i] == 'S') {
                set[i] = 1;
            } else if (line[i] == '^' && set[i] != 0) {
                set[i-1] += set[i];
                set[i+1] += set[i];
                set[i] = 0;
            }
        }

        splits = 0;
        for (int j = 0; j < i; j++) {
            splits += set[j];
        }
        printf(" %ld\n", splits);
    }

    printf("RESULT: %ld\n", splits);
    
    return 0;
}
