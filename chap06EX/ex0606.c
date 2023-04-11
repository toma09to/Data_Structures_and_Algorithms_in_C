#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

void shaker(int a[], int n)
{
    int j = 0;
    int k = n - 1;
    int idx;

    while (1) {
        idx = j;
        for (int i = j; i < k; i++)
            if (a[i] > a[i + 1]) {
                swap(int, a[i], a[i + 1]);
                idx = i;
            }
        k = idx;
        if (j == k) break;

        idx = k;
        for (int i = k; i > j; i--)
            if (a[i] < a[i - 1]) {
                swap(int, a[i], a[i - 1]);
                idx = i;
            }
        j = idx;
        if (j == k) break;
    }
}

int main(void)
{
    int nx;

    puts("シェーカーソート");
    printf("要素数：");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    shaker(x, nx);

    puts("昇順にソートしました。");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}
