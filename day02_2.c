// #include <stdbool.h>
#include <stdio.h>
#include <math.h>

int dec_len(long x) {
    int n = 0;
    while (x > 0) {
        x /= 10;
        n++;
    }
    return n;
}

long shift_and_mask(long x, int n, long* last_dec) {
    long res = 0;
    for (int i = 0; i < n; i++) {
        res += (x % 10) * powl(10, i);
        x /= 10;
    }
    *last_dec = res;
    return x;
}

int is_invalid_n(long x, int n) {
    long prev = 0;
    long cur = 0;
    long v = shift_and_mask(x, n, &prev);
    while (true) {
        v = shift_and_mask(v, n, &cur);
        if (prev != cur) {
            return false;
        }
        prev = cur;
        if (v == 0) break;
    }
    return true;
}


/**
 * 1188511885 is invalide because 11885 repeats
 */
bool is_invalid(long x) {
    int len = dec_len(x);
    
    for (int i = 1; i <= len / 2; i++) {
        if (len % i != 0) continue;
        if (is_invalid_n(x, i)) return true;
    }
    return false;
}

int main(void) {
    long start;
    long finish;

    long sums = 0;
    while(scanf("%ld-%ld,", &start, &finish) > 0) {
        printf("[%ld %ld]\n", start, finish);
        for (long i = start; i <= finish; i++) {
            if (is_invalid(i)) {
                printf("invalid: %ld\n", i);
                sums += i;
            }
        }
    }
    printf("RESULT: %ld\n", sums);

    return 0;
}
