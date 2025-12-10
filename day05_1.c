#include <stdio.h>
#include <stdlib.h>

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

// supposing pairs is sorted
// Sorry, I'm too lazy to implement **binary search**
bool find(long x) {
    for (int i = 0; i < N; i++) {
        Pair p = pairs[i];
        if (p.a > x) {
            return false;
        }
        if (p.a <= x && p.b >= x) {
            return true;
        }
    }

    return false;
}

int main(void) {
    for (int i = 0; i < N; i++) {
        scanf("%ld-%ld ", &pairs[i].a, &pairs[i].b);
    }

    qsort(pairs, N, sizeof(Pair), cmp);

    int counter = 0;
    long x;
    while(scanf("%ld ", &x) > 0) {
        if (find(x)) {
            counter++;
        }
    }
    printf("RESULT: %d\n", counter);

    return 0;
}
