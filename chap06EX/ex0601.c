#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

void bubble(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++)
            if (a[j - 1] > a[j])
                swap(int, a[j - 1], a[j]);
    }
}

int main(void)
{
    int nx;

    puts("単純交換ソート");
    printf("要素数：");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    bubble(x, nx);

    puts("昇順にソートしました。");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}
