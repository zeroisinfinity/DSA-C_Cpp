
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

// Forward declaration from your uploaded file
typedef int (*IntArrayPtr)[];
IntArrayPtr bubblesort(int size, int *arr, IntArrayPtr ret_ptr);

// Standard qsort comparator
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

bool arrays_equal(int *a, int *b, int size) {
    for (int i = 0; i < size; i++)
        if (a[i] != b[i]) return false;
    return true;
}

int main() {
    int total_tests = 0, passed = 0;

    int vals[] = {-1, 0, 1, 2};
    int len = sizeof(vals) / sizeof(vals[0]);

    for (int i0 = 0; i0 < len; i0++)
    for (int i1 = 0; i1 < len; i1++)
    for (int i2 = 0; i2 < len; i2++)
    for (int i3 = 0; i3 < len; i3++)
    for (int i4 = 0; i4 < len; i4++) {
        int original[5] = {
            vals[i0], vals[i1], vals[i2], vals[i3], vals[i4]
        };
        int test[5], ref[5];
        memcpy(test, original, sizeof(test));
        memcpy(ref, original, sizeof(ref));

        IntArrayPtr sorted = bubblesort(5, test, (IntArrayPtr)test);
        qsort(ref, 5, sizeof(int), cmp);

        total_tests++;
        if (arrays_equal(*sorted, ref, 5)) {
            passed++;
        } else {
            printf("❌ Mismatch in test #%d\n", total_tests);
            printf("Input:   [%d, %d, %d, %d, %d]\n", original[0], original[1], original[2], original[3], original[4]);
            printf("Output:  [%d, %d, %d, %d, %d]\n", (*sorted)[0], (*sorted)[1], (*sorted)[2], (*sorted)[3], (*sorted)[4]);
            printf("Expected:[%d, %d, %d, %d, %d]\n\n", ref[0], ref[1], ref[2], ref[3], ref[4]);
        }
    }

    printf("\n✅ Passed %d / %d test cases.\n", passed, total_tests);
    return 0;
}
