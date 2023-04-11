#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

void shuffle(int a[], int n)
{
    int itr;
    for (int i = 0; i < n; i++) {
        itr = rand() % (n - i) + i;
        swap(int, a[i], a[itr]);
    }
}

int main(void)
{
    int n;

    printf("要素数：");
    scanf("%d", &n);

    int *a = calloc(n, sizeof(int));

    printf("%d個の整数を入力してください。\n", n);
    for (int i = 0; i < n; i++) {
        printf("a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    shuffle(a, n);

    printf("配列aの全要素の並びをシャッフルしました。\n");
    for (int i = 0; i < n; i++)
        printf("a[%d] = %d\n", i, a[i]);

    free(a);

    return 0;
}
