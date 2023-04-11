#include <stdio.h>
#include <stdlib.h>

int search(int a[], int n, int key)
{
    int i;

    a[n] = key;

    for (i = 0; 1; i++) {
        if (a[i] == key)
            break;
    }

    return i == n ? -1 : i;
}

int main(void)
{
    int nx, ky;

    puts("線形探索（番兵法）");
    printf("要素数 : ");
    scanf("%d", &nx);
    int *x = calloc(nx + 1, sizeof(int));

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
