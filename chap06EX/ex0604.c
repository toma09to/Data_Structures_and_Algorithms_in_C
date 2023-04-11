#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

void bubble(int a[], int n)
{
    int ccnt = 0;
    int scnt = 0;
    char op[3];
    for (int i = 0; i < n - 1; i++) {
        printf("パス%d:\n", i + 1);
        int exchg = 0;
        for (int j = n - 1; j > i; j--) {
            printf("%2d", a[0]);
            for (int k = 1; k < n; k++) {
                if (k != j)
                    strcpy(op, "  ");
                else if (a[j - 1] > a[j])
                    strcpy(op, " +");
                else
                    strcpy(op, " -");
                printf("%s%2d", op, a[k]);
            }
            putchar('\n');

            ccnt++;
            if (a[j - 1] > a[j]) {
                scnt++;
                swap(int, a[j - 1], a[j]);
                exchg++;
            }
        }
        printf("%2d", a[0]);
        for (int j = 1; j < n; j++)
            printf("  %2d", a[j]);
        putchar('\n');
        if (exchg == 0) break;
    }
    printf("比較は%d回でした。\n交換は%d回でした。\n", ccnt, scnt);
}

int main(void)
{
    int nx;

    puts("単純交換ソート");
    printf("要素数：");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    bubble(x, nx);

    puts("昇順にソートしました。");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}
