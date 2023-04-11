#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

void insertion(int a[], int n)
{
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int pl = 0;
        int pr = i - 1;
        int pc;

        do {
            pc = (pl + pr) / 2;
            if (a[pc] == key)
                break;
            else if (a[pc] < key)
                pl = pc + 1;
            else
                pr = pc - 1;
        } while (pl <= pr);
        int pd = (pl <= pr) ? pc + 1 : pr + 1;

        for (int j = i; j > pd; j--)
            a[j] = a[j - 1];
        a[pd] = key;
    }
}

int main(void)
{
    int nx;

    puts("２分挿入ソート");
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
