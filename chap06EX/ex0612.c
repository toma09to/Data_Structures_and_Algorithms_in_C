#include <stdio.h>
#include <stdlib.h>

void shell(int a[], int n)
{
    int h;
    int mcnt = 0;

    for (h = 1; h < n; h = h * 3 + 1)
        ;

    for ( ; h > 0; h /= 3)
        for (int i = h; i < n; i++) {
            int tmp = a[i];
            int j;
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
                mcnt++;
                a[j + h] = a[j];
            }
            mcnt++;
            a[j + h] = tmp;
        }
    printf("要素の移動回数は%d回です。\n", mcnt);
}

int main(void)
{
    int nx;

    puts("シェルソート");
    printf("要素数：");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    shell(x, nx);

    puts("昇順にソートしました。");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}
