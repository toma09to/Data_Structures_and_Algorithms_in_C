#include <stdio.h>
#include <stdlib.h>

void ary_rcopy(int a[], const int b[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[n - i - 1];
}

int main(void)
{
    int n;

    printf("要素数：");
    scanf("%d", &n);

    int *x = calloc(n, sizeof(int));
    int *y = calloc(n, sizeof(int));

    printf("%d個の整数を入力してください。\n", n);
    for (int i = 0; i < n; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    ary_rcopy(y, x, n);

    printf("配列xの全要素を配列yに逆順にコピーしました。\n");
    for (int i = 0; i < n; i++)
        printf("y[%d] = %d\n", i, y[i]);

    free(x);
    free(y);
    
    return 0;
}
