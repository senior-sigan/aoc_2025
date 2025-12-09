// #include <stdbool.h>
#include <stdio.h>

int dec_len(long x) {
    int n = 0;
    while (x > 0) {
        x /= 10;
        n++;
    }
    return n;
}

/**
 * 1188511885 is invalide because 11885 repeats
 */
bool is_invalid(long x) {
    int len = dec_len(x);
    if (len % 2 != 0) return false;

    long right = 0;
    for (int i = 0; i < len/2; i++) {
        right = right * 10 + x % 10;
        x /= 10;
    }

    long left = 0;
    for (int i = 0; i < len/2; i++) {
        left = left * 10 + x % 10;
        x /= 10;
    }

    return right == left;
}

int main(void) {
    long start;
    long finish;

    long sums = 0;
    while(scanf("%ld-%ld,", &start, &finish) > 0) {
        printf("[%ld %ld]\n", start, finish);
        for (long i = start; i <= finish; i++) {
            if (is_invalid(i)) {
                printf("%ld\n", i);
                sums += i;
            }
        }
    }
    printf("RESULT: %ld\n", sums);

    return 0;
}
