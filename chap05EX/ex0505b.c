#include <stdio.h>
#include <string.h>

static char memo[128][1024];
static int cnt;

void recur(int n)
{
    cnt++;
    if (memo[n + 1][0] != '\0')
        printf("%s", memo[n + 1]);
    else {
        if (n > 0) {
            recur(n - 1);
            printf("%d\n", n);
            recur(n - 2);
            sprintf(memo[n + 1], "%s%d\n%s", memo[n], n, memo[n - 1]);
        } else {
            strcpy(memo[n + 1], "");
        }
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
