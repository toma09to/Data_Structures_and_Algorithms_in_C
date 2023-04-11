#include <stdio.h>

void triangleLB(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            putchar('*');
        putchar('\n');
    }
}

void triangleLU(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++)
            putchar('*');
        putchar('\n');
    }
}

void triangleRU(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++)
            putchar(' ');
        for (int j = 1; j <= n - i + 1; j++)
            putchar('*');
        putchar('\n');
    }
}

void triangleRB(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++)
            putchar(' ');
        for (int j = 1; j <= i; j++)
            putchar('*');
        putchar('\n');
    }
}

int main(void)
{
    int n;

    do {
        printf("nの値：");
        scanf("%d", &n);
    } while (n <= 0);

    printf("\n左下側が直角の二等辺三角形\n");   triangleLB(n);
    printf("\n左上側が直角の二等辺三角形\n");   triangleLU(n);
    printf("\n右上側が直角の二等辺三角形\n");   triangleRU(n);
    printf("\n右下側が直角の二等辺三角形\n");   triangleRB(n);

    return 0;
}
