#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

long long maxAlternatingSum(int* nums, int numsSize) {
    long long total = 0;
    int squares[100000];

    for (int i = 0; i < numsSize; i++) {
        squares[i] = nums[i] * nums[i];
        total += squares[i];
    }

    qsort(squares, numsSize, sizeof(int), cmp);

    long long smallest = 0;
    for (int i = 0; i < numsSize / 2; i++) {
        smallest += squares[i];
    }

    return total - 2 * smallest;
}