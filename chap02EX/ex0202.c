#include <stdio.h>
#include <stdlib.h>

int sumof(const int a[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

int main(void)
{
    int number;

    printf("人数 : ");
    scanf("%d", &number);

    int *height = calloc(number, sizeof(int));

    printf("%d人の身長を入力してください。\n", number);
    for (int i = 0; i < number; i++) {
        printf("height[%d] : ", i);
        scanf("%d", &height[i]);
    }

    printf("合計値は%dです。\n", sumof(height, number));

    free(height);

    return 0;
}
