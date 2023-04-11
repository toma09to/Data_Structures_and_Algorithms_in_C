// 1, 2, …, nの総和を求める（for文）

#include <stdio.h>

int main(void)
{
    int n;

    puts("1からnまでの総和を求めます。");

    do {
        printf("nの値：");
        scanf("%d", &n);
    } while (n <= 0);

    int sum = 0;

    for (int i = 1; i <= n; i++)
        sum += i;

    printf("1から%dまでの総和は%dです。\n", n, sum);

    return 0;
}
