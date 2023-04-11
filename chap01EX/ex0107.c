// 1, 2, …, nの総和を求める（for文）

#include <stdio.h>

int main(void)
{
    int n;

    puts("1からnまでの総和を求めます。");

    printf("nの値：");
    scanf("%d", &n);

    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += i;
        if (i != n)
            printf("%d + ", i);
    }

    printf("%d = %d\n", n, sum);

    return 0;
}
