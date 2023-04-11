#include <stdio.h>
#include <stdlib.h>

double aveof(const int a[], int n)
{
    double sum = 0.0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum / n;
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

    printf("平均値は%fです。\n", aveof(height, number));

    free(height);

    return 0;
}
