// クイックソート（改良版）

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- x[a], x[b], x[c]をソート（中央値の添字を返却） ---*/
int sort3elem(int x[], int a, int b, int c)
{
    if (x[b] < x[a]) swap(int, x[b], x[a]);
    if (x[c] < x[b]) swap(int, x[c], x[b]);
    if (x[b] < x[a]) swap(int, x[b], x[a]);
    return b;
}

/*--- クイックソート ---*/
void quick(int a[], int left, int right)
{
    int pl = left;                                  // 左カーソル
    int pr = right;                                 // 右カーソル
    int m = sort3elem(a, pl, (pl + pr) / 2, pr);    // 先頭・末尾・中央をソート
    int x = a[m];                                   // 枢軸

    swap(int, a[m], a[right - 1]);          // 中央と末尾から２番目を交換
    pl++;                                   // 左カーソルを１個右へ
    pr -= 2;                                // 右カーソルを２個左へ

    do {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }
    } while (pl <= pr);

    if (left < pr)  quick(a, left, pr);
    if (pl < right) quick(a, pl, right);
}

int main(void)
{
    int nx;

    puts("クイックソート");
    printf("要素数：");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    quick(x, 0, nx - 1);                // 配列xをクイックソート

    puts("昇順にソートしました。");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 配列xを廃棄

    return 0;
}
