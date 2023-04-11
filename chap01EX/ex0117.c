#include <stdio.h>

void spira(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++)
            putchar(' ');
        for (int j = 1; j <= (i - 1) * 2 + 1; j++)
            putchar('*');
        putchar('\n');
    }
}

int main(void)
{
    int n;

    do {
        printf("段数は：");
        scanf("%d", &n);
    } while (n <= 0);

    spira(n);

    return 0;
}
