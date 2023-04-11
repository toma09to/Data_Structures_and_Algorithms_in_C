#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

void insertion(int a[], int n)
{
    for (int i = 2; i <= n; i++) {
        int tmp = a[i];
        int j;
        a[0] = tmp;
        for (j = i; a[j - 1] > tmp; j--)
            a[j] = a[j - 1];
        a[j] = tmp;
    }
}

int main(void)
{
    int nx;

    puts("単純挿入ソート");
    printf("要素数：");
    scanf("%d", &nx);
    int *x = calloc(nx + 1, sizeof(int));

    for (int i = 1; i <= nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    insertion(x, nx);

    puts("昇順にソートしました。");
    for (int i = 1; i <= nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}
