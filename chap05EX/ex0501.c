#include <stdio.h>

int factorial(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans *= i;
    return ans;
}

int main(void)
{
    int x;

    printf("整数を入力せよ：");
    scanf("%d", &x);

    printf("%dの階乗は%dです。\n", x, factorial(x));

    return 0;
}
