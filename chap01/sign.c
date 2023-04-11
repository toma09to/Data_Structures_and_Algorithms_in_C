// 読み込んだ整数値の符号（正／負／０）を判定

#include <stdio.h>

int main(void)
{
    int n;

    printf("整数：");
    scanf("%d", &n);

    if (n > 0)
        printf("正です。\n");
    else if (n < 0)
        printf("負です。\n");
    else
        printf("０です。\n");

    return 0;
}
