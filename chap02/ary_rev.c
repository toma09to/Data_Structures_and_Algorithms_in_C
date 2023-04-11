// 配列の要素の並びを反転する

#include <stdio.h>
#include <stdlib.h>

/*--- type型のxとyの値を交換 ---*/
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- 要素数nの配列aの要素の並びを反転 ---*/
void ary_reverse(int a[], int n)
{
    for (int i = 0; i < n / 2; i++)
        swap(int, a[i], a[n - i - 1]);
}

int main(void)
{
    int nx;     // 配列xの要素数

    printf("要素数：");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    ary_reverse(x, nx);                 // 配列xの要素の並びを反転

    printf("要素の並びを反転しました。\n");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);                            // 配列xを破棄

    return 0;
}
