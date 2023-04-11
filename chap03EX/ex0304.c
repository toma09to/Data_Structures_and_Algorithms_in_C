#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key)
{
    int pl = 0;
    int pr = n - 1;

    printf("   |");
    for (int i = 0; i < n; i++)
        printf("%4d", i);
    putchar('\n');
    printf("---+");
    for (int i = 0; i < n; i++)
        printf("----");
    printf("--\n");

    do {
        int pc = (pl + pr) / 2;

        printf("   |");
        for (int i = 0; i < n; i++) {
            if (i == pl)
                printf(" <- ");
            else if (i == pr)
                printf("  ->");
            else if (i == pc)
                printf("   +");
            else
                printf("    ");
        }
        putchar('\n');
        printf("%3d|", pc);
        for (int i = 0; i < n; i++)
            printf("%4d", a[i]);
        putchar('\n');

        if (a[pc] == key)
            return pc;
        else if (a[pc] < key)
            pl = pc + 1;
        else
            pr = pc - 1;
    } while (pl <= pr);

    return -1;
}

int main(void)
{
    int nx, ky;

    puts("２分探索");
    printf("要素数 : ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    printf("昇順に入力してください。\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);

    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);
    }
    printf("探す値 : ");
    scanf("%d", &ky);

    int idx = bin_search(x, nx, ky);

    if (idx == -1)
        puts("探索に失敗しました。");
    else
        printf("%dはx[%d]にあります。\n", ky, idx);
    free(x);

    return 0;
}
