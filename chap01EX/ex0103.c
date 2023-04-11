#include <stdio.h>

int min4(int a, int b, int c, int d)
{
    int min = a;

    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;

    return min;
}

int main(void)
{
    int a, b, c, d;

    printf("四つの整数の最小値を求めます。\n");
    printf("aの値：");   scanf("%d", &a);
    printf("bの値：");   scanf("%d", &b);
    printf("cの値：");   scanf("%d", &c);
    printf("dの値：");   scanf("%d", &d);

    printf("最小値は%dです。\n", min4(a, b, c, d));

    return 0;
}
