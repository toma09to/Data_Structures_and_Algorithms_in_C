// 線形探索

#include <stdio.h>
#include <stdlib.h>

/*--- 要素数nの配列aからkeyと一致する要素を線形探索 ---*/
int search(const int a[], int n, int key)
{
    int i = 0;

    while (1) {
        if (i == n)
            return -1;      // 探索失敗
        if (a[i] == key)
            return i;       // 探索成功
        i++;
    }
}

int main(void)
{
    int nx, ky;

    puts("線形探索");
    printf("要素数 : ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 要素数nxのint型配列xを生成

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("探す値 : ");
    scanf("%d", &ky);

    int idx = search(x, nx, ky);        // 配列xから値がkyの要素を線形探索

    if (idx == -1)
        puts("探索に失敗しました。");
    else
        printf("%dはx[%d]にあります。\n", ky, idx);
    free(x);                            // 配列xを破棄

    return 0;
}
