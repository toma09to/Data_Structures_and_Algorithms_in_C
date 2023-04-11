#include <stdio.h>

static int cnt;

void recur(int n)
{
    cnt++;
    if (n > 0) {
        recur(n - 1);
        printf("%d\n", n);
        recur(n - 2);
    }
}

int main(void)
{
    int x;

    printf("整数を入力せよ：");
    scanf("%d", &x);

    recur(x);
    printf("関数呼び出し回数：%d回\n", cnt);

    return 0;
}
