// int[5]型の配列（要素型がint型で要素数が5の配列）の要素に値を読み込んで表示

#include <stdio.h>

#define N   5

int main(void)
{
    int a[N];

    for (int i = 0; i < N; i++) {
        printf("a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    puts("各要素の値");
    for (int i = 0; i < N; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
