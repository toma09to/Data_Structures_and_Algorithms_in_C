#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

void insertion(int a[], int n)
{
    for (int i = 1; i < n; i++) {
        int tmp = a[i];
        int j;
        for (int k = 0; k < n; k++)
            printf("%3d ", a[k]);
        putchar('\n');
        for (j = i; j > 0 && a[j - 1] > tmp; j--)
            a[j] = a[j - 1];
        for (int k = 0; k < n; k++) {
            if (k == i && k == j)
                printf("  + ");
            else if (k == j)
                printf("^---");
            else if (k == i)
                printf("--+ ");
            else if (k > j && k < i)
                printf("----");
            else
                printf("    ");
        }
        putchar('\n');
        a[j] = tmp;
    }
    for (int i = 0; i < n; i++)
        printf("%3d ", a[i]);
    putchar('\n');
}

int main(void)
{
    int nx;

    puts("単純挿入ソート");
    printf("要素数：");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    insertion(x, nx);

    puts("昇順にソートしました。");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}
