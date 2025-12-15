#include <stdio.h>

#define MAX_LINE_WIDTH 200

int main(void) {
    char line[MAX_LINE_WIDTH] = {0};
    bool set[MAX_LINE_WIDTH] = {0};

    int splits = 0;
    while (scanf("%s", line) > 0) {
        printf("%s\n", line);
        int i = 0; // count line length. We need it later
        for (i = 0; line[i] != 0; i++) {
            if (line[i] == 'S') {
                set[i] = true;
            } else if (line[i] == '^' && set[i] == true) {
                set[i] = false;
                set[i-1] = true;
                set[i+1] = true;
                splits ++;
            }
        }

        for (int j = 0; j < i; j++) {
            printf("%d", set[j]);
        }
        printf(" %d\n", splits);
    }

    printf("RESULT: %d\n", splits);
    
    return 0;
}
