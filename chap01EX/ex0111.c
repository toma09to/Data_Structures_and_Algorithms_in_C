#include <stdio.h>

int main(void)
{
    int n;

    do {
        printf("正の整数：");
        scanf("%d", &n);
    } while (n <= 0);

    int digits = 0;
    while (n > 0) {
        digits++;
        n /= 10;
    }

    printf("その数は%d桁です。\n", digits);

    return 0;
}
