// 1, 2, …, nの総和を求める（while文）

#include <stdio.h>

int main(void)
{
    int n;

    puts("1からnまでの総和を求めます。");

    printf("nの値：");
    scanf("%d", &n);

    int sum = 0;
    int i = 1;

    while (i <= n) {
        sum += i;
        i++;
    }
    printf("1から%dまでの総和は%dです。\n", n, sum);
    printf("i = %d\n", i);

    return 0;
}
