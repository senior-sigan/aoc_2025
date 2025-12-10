#include <stdio.h>
#include <stdlib.h>

#define WIDTH  140
#define HEIGHT 140

char matrix[HEIGHT][WIDTH + 1] = {0};

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int count(int x, int y) {
    int c = 0;
    for (int i = max(x - 1, 0); i <= min(x + 1, WIDTH-1); i++) {
        for (int j = max(y - 1, 0); j <= min(y + 1, HEIGHT-1); j++) {
            if (matrix[j][i] == '@') {
                c++;
            }
        }
    }
    return c;
}

int main(void) {
    for (int j = 0; j < HEIGHT; j++) {
        scanf("%s", matrix[j]);
    }

    int counter = 0;
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            char ch = matrix[j][i];
            if (ch == '@') {
                int c = count(i, j);
                if (c <= 4) {
                    printf("x");
                    counter++;
                    continue;
                }
            }
            printf("%c", ch);
        }
        printf("\n");
    }

    printf("RESULT: %d\n", counter);

    return 0;
}
