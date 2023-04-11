#include <stdio.h>
#include <stdlib.h>

int is_sorted(const int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return 0;
    return 1;
}

int main(void)
{
    int nx;

    printf("要素数：");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    if (is_sorted(x, nx))
        puts("配列xはソートずみです。");
    else
        puts("配列xはソートずみではありません。");

    free(x);

    return 0;
}
