#include <stdio.h>

typedef struct {
    int y;
    int m;
    int d;
} Date;

int mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int isleap(int y)
{
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

Date DateOf(int y, int m, int d)
{
    Date ret = {y, m, d};
    return ret;
}

Date After(Date x, int n)
{
    x.d += n;

    while (x.d > mdays[isleap(x.y)][x.m - 1]) {
        x.d -= mdays[isleap(x.y)][x.m - 1];
        x.m++;
        if (x.m > 12) {
            x.m -= 12;
            x.y++;
        }
    }

    return x;
}

Date Before(Date x, int n)
{
    x.d -= n;

    while (x.d < 1) {
        x.m--;
        if (x.m < 1) {
            x.m += 12;
            x.y--;
        }
        x.d += mdays[isleap(x.y)][x.m - 1];
    }

    return x;
}

void Print(Date x)
{
    printf("%4d年%2d月%2d日", x.y, x.m, x.d);
}

int main(void)
{
    int y, m, d;
    printf("年：");   scanf("%d", &y);
    printf("月：");   scanf("%d", &m);
    printf("日：");   scanf("%d", &d);

    Date x = DateOf(y, m, d);

    int n;

    printf("n日前・n日後の日付を表示します。\n");
    printf("nの値：");   scanf("%d", &n);

    printf("n日前：\n");   Print(Before(x, n));   putchar('\n');
    printf("n日後：\n");   Print(After(x, n));    putchar('\n');

    return 0;
}
