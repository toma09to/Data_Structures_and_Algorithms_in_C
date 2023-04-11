#include <stdio.h>

void nrpira(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++)
            putchar(' ');
        for (int j = 1; j <= (n - i) * 2 + 1; j++)
            putchar(i % 10 + '0');
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

    nrpira(n);

    return 0;
}
