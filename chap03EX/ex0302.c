#include <stdio.h>
#include <stdlib.h>

int search(const int a[], int n, int key)
{
    printf("   |");
    for (int i = 0; i < n; i++)
        printf("%4d", i);
    putchar('\n');
    printf("---+");
    for (int i = 0; i < n * 4; i++)
        putchar('-');
    putchar('\n');

    for (int i = 0; i < n; i++) {
        printf("   |");
        for (int j = 0; j < i * 4 + 3; j++)
            putchar(' ');
        printf("*\n");
        printf("%3d|", i);
        for (int j = 0; j < n; j++)
            printf("%4d", a[j]);
        putchar('\n');
        if (a[i] == key)
            return i;
    }

    return -1;
}

int main(void)
{
    int nx, ky;

    puts("線形探索");
    printf("要素数 : ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("探す値 : ");
    scanf("%d", &ky);

    int idx = search(x, nx, ky);

    if (idx == -1)
        puts("探索に失敗しました。");
    else
        printf("%dはx[%d]にあります。\n", ky, idx);
    free(x);

    return 0;
}
