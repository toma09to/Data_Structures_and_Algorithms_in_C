#include <stdio.h>

int mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int isleap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int dayof_year(int y, int m, int d)
{
    while (--m)
        d += mdays[isleap(y)][m - 1];
    return d;
}

int main(void)
{
    int retry;

    do {
        int year, month, day;
        printf("年：");   scanf("%d", &year);
        printf("月：");   scanf("%d", &month);
        printf("日：");   scanf("%d", &day);

        printf("年内で%d日目です。\n", dayof_year(year, month, day));

        printf("もう一度しますか（1…はい／0…いいえ）：");
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}
