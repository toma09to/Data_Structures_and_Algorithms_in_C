#include <stdio.h>
#include <stdlib.h>

void ary_copy(int a[], const int b[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[i];
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

    ary_copy(y, x, n);

    printf("配列xの全要素を配列yにコピーしました。\n");
    for (int i = 0; i < n; i++)
        printf("y[%d] = %d\n", i, y[i]);

    free(x);
    free(y);
    
    return 0;
}
