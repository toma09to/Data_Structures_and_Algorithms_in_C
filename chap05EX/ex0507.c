#include <stdio.h>
#include "IntStack.h"

void move(int no, int x, int y)
{
    char *name[] = {"Ａ軸", "Ｂ軸", "Ｃ軸"};
    if (no > 1)
        move(no - 1, x, 6 - x - y);

    printf("円盤[%d]を%sから%sへ移動\n", no, name[x - 1], name[y - 1]);

    if (no > 1)
        move(no - 1, 6 - x - y, y);
}

int main(void)
{
    int n;

    printf("ハノイの塔\n円盤の枚数：");
    scanf("%d", &n);

    move(n, 1, 3);

    return 0;
}
