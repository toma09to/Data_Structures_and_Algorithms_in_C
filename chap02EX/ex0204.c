#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int maxof(const int a[], int n)
{
    int max = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > max) max = a[i];

    return max;
}

int main(void)
{
    srand(time(NULL));

    int number = 5 + rand() % 16;

    printf("人数 : %d\n", number);

    int *height = calloc(number, sizeof(int));

    for (int i = 0; i < number; i++) {
        height[i] = 100 + rand() % 90;
        printf("height[%d] = %d\n", i, height[i]);
    }

    printf("最大値は%dです。\n", maxof(height, number));

    free(height);

    return 0;
}
