// 1, 2, …, nの総和を求める（for文）

#include <stdio.h>

int main(void)
{
    int n;

    puts("1からnまでの総和を求めます。");

    printf("nの値：");
    scanf("%d", &n);

    int sum = (1 + n) * n / 2;

    printf("1から%dまでの総和は%dです。\n", n, sum);

    return 0;
}
