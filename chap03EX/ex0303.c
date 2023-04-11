#include <stdio.h>
#include <stdlib.h>

int search_idx(const int a[], int n, int key, int idx[])
{
    int ptr = 0;

    for (int i = 0; i < n; i++)
        if (a[i] == key)
            idx[ptr++] = i;

    return ptr;
}

int main(void)
{
    int nx, ky;

    printf("要素数 : ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));
    int *idx = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    printf("探す値 : ");
    scanf("%d", &ky);

    int no = search_idx(x, nx, ky, idx);

    if (no == 0)
        puts("探索に失敗しました。");
    else {
        printf("%dは以下の場所にあります : ", ky);
        for (int i = 0; i < no; i++)
            printf("x[%d] ", idx[i]);
        putchar('\n');
    }
    free(x);
    free(idx);

    return 0;
}
