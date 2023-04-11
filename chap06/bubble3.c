// 単純交換ソート（第３版）

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 単純交換ソート（第３版：走査範囲を限定） ---*/
void bubble(int a[], int n)
{
    int k = 0;                              // a[k]より前はソートずみ

    while (k < n - 1) {
        int last = n - 1;                   // 最後に交換した位置

        for (int j = n - 1; j > k; j--)
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                last = j;
            }
        k = last;
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

    bubble(x, nx);                      // 配列xを単純交換ソート

    puts("昇順にソートしました。");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 配列xを破棄

    return 0;
}
