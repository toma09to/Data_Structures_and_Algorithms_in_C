#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

void selection(int a[], int n)
{
    char op;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        for (int j = 0; j < n; j++) {
            if (j == i) op = '*';
            else if (j == min) op = '+';
            else op = ' ';
            printf("  %c ", op);
        }
        putchar('\n');
        for (int j = 0; j < n; j++)
            printf("%3d ", a[j]);
        putchar('\n');
        swap(int, a[i], a[min]);
    }
    putchar('\n');
    for (int i = 0; i < n; i++)
        printf("%3d ", a[i]);
    putchar('\n');
}

int main(void)
{
    int nx;

    puts("単純選択ソート");
    printf("要素数：");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    selection(x, nx);

    puts("昇順にソートしました。");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}
