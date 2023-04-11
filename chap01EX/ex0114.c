#include <stdio.h>

int main(void)
{
    int n;

    printf("正方形を表示します。\n");

    do {
        printf("段数は：");
        scanf("%d", &n);
    } while (n <= 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            putchar('*');
        putchar('\n');
    }

    return 0;
}
