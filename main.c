#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
int sumsTo(uint32_t x[], uint32_t n, uint32_t k, uint32_t v) {

    if (v == 0 && k == 0)
        return 1;
    if (v != 0 && k == 0)
        return 0;
    if (n == 0)
        return 0;
    int res1 = 0;
    if (v >= x[0])
        res1 = sumsTo(x + 1, n-1, k-1, v-x[0]);
    int res2 = sumsTo(x + 1, n-1, k, v);
    return (res1 + res2 > 0);
}

void printArray(uint32_t x[], int size)
{

    for (int i = 0; i < size; i++)
        printf("%d, ", x[i]);
        printf("\n");
}
int main() {
    uint32_t x[10] = {1,3,5,7,9,11,13};
    printf("0 = false and 1 = true\n");
    printf("array #1 = ...\n");
    printArray(x, 7);
    printf("n = 7, k = 3, v = 33 -----> result should be 1\n");
    printf("result = %d\n", sumsTo(x, 7, 3, 33));
    printf("n = 7, k = 4, v = 33 -----> result should be 0\n");
    printf("result = %d\n", sumsTo(x, 7, 4, 33));
    printf("n = 7, k =1, v = 3 -----> result should be 1\n");
    printf("result = %d\n", sumsTo(x, 7, 1, 3));
    return 0;
}
