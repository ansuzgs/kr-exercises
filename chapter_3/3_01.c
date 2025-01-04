#include <stdio.h>
#include <time.h>

#define MAXLEN 1000000
#define ITERATIONS 1000000

void init_vector(int v[], int n);

int binarysearch_kr(int x, int v[], int n);
int binarysearch(int x, int v[], int n);

void test_binarysearch(int bs(int x, int v[], int n), int x, int v[], int n);

int main(void) {
    int v[MAXLEN];

    init_vector(v, MAXLEN);
    // printVector(v, MAXLEN);

    int x = -1;

    // Test binsearch_kr()
    test_binarysearch(binarysearch_kr, x, v, MAXLEN);

    // Test binsearch()
    test_binarysearch(binarysearch, x, v, MAXLEN);

    return 0;
}

void init_vector(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = i;
    }
}

int binarysearch_kr(int x, int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;

        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int binarysearch(int x, int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;

        if (x < v[mid]) {
            high = mid - 1;
        } else if (x >= v[mid]) {
            low = mid + 1;
        }
    }
    if (x == v[mid]) {
        return low - 1;
    }
    return -1;
}

void test_binarysearch(int bs(int x, int v[], int n), int x, int v[], int n) {
    static int test_nr = 0;
    long clocks = clock();

    for (int i = 0; i < ITERATIONS; i++) {
        bs(x, v, n);
    }

    clocks = clock() - clocks;
    printf("test_%d: %lu clocks (%.4f seconds)\n", test_nr, clocks,
           (double)clocks / CLOCKS_PER_SEC);
    test_nr++;
}
