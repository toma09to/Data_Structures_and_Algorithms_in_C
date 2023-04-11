// 読み込んだ整数値の符号（正／負／０）を判定

#include <stdio.h>

int main(void)
{
    int n;

    printf("整数：");
    scanf("%d", &n);

    if (n == 1)
        puts("A");
    else if (n == 2)
        puts("B");
    else if (n == 3)
        puts("C");

    return 0;
}
