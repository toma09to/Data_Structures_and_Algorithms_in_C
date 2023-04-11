#include <stdio.h>

int main(void)
{
    int h, w;

    printf("長方形を表示します。\n");

    do {
        printf("高さは：");
        scanf("%d", &h);
    } while (h <= 0);

    do {
        printf("横幅は：");
        scanf("%d", &w);
    } while (w <= 0);

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++)
            putchar('*');
        putchar('\n');
    }

    return 0;
}
