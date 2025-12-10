#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

typedef struct Pair_t {
    long a;
    long b;
} Pair;

int cmp(const void* lhs, const void* rhs) {
    const Pair* p1 = lhs;
    const Pair* p2 = rhs;

    if (p1->a < p2->a) return -1;
    if (p1->a > p2->a) return 1;
    return 0;
}

#define N 187

Pair pairs[N] = {0};

int main(void) {
    for (int i = 0; i < N; i++) {
        scanf("%ld-%ld ", &pairs[i].a, &pairs[i].b);
    }

    qsort(pairs, N, sizeof(Pair), cmp);

    long counter = 0;
    long last = 0;
    for (int i = 0; i < N; i++) {
        long a = MAX(pairs[i].a, last+1);
        long b = pairs[i].b;

        if (a>b) continue;
        
        long delta = b - a + 1;
        last = b;
        counter += delta;
    }
    printf("%ld\n", counter);

    return 0;
}
