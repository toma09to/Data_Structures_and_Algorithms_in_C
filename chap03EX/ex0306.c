#include <stdio.h>
#include <stdlib.h>

int long_cmpr(const long *a, const long *b)
{
    if (*a < *b)
        return 1;
    else if (*a > *b)
        return -1;
    else
        return 0;
}

int main(void)
{
    int nx;
    long ky;

    puts("bsearch関数によるlong型の配列からの探索");
    printf("要素数 : ");
    scanf("%d", &nx);
    long *x = calloc(nx, sizeof(long));

    printf("降順に入力してください。\n");

    printf("x[0] : ");
    scanf("%ld", &x[0]);

    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%ld", &x[i]);
        } while (x[i] > x[i - 1]);
    }

    printf("探す値 : ");
    scanf("%ld", &ky);

    long *p = bsearch(
                &ky,
                x,
                nx,
                sizeof(long),
                (int (*)(const void *, const void *))long_cmpr
            );

    if (p == NULL)
        puts("探索に失敗しました。");
    else
        printf("%ldはx[%d]にあります。\n", ky, (int)(p - x));
    free(x);

    return 0;
}
