#include <stdio.h>
#include "IntStack.h"

void move(int no, int x, int y)
{
    int sw;
    IntStack nstk, xstk, ystk, sstk;
    Initialize(&nstk, 100);
    Initialize(&xstk, 100);
    Initialize(&ystk, 100);
    Initialize(&sstk, 100);

First:
    printf("%d %d %d\n", no, x, y);
    sw = 0;
    if (no > 1) {
        Push(&nstk, no);
        Push(&xstk, x);
        Push(&ystk, y);
        Push(&sstk, sw);
        no = no - 1;
        y = 6 - x - y;
        goto First;
    }
Second:
    printf("円盤[%d]を%d軸から%d軸へ移動\n", no, x, y);

    if (no > 1) {
        sw = 1;
        Push(&nstk, no);
        Push(&xstk, x);
        Push(&ystk, y);
        Push(&sstk, sw);
        no = no - 1;
        x = 6 - x - y;
        goto First;
    }
    do {
        Pop(&nstk, &no);
        Pop(&xstk, &x);
        Pop(&ystk, &y);
        Pop(&sstk, &sw);
        if (!IsEmpty(&nstk))
            goto Second;
        else
            goto End;
    } while (sw == 1);
    // if (!IsEmpty(&nstk)) {
    //     Pop(&nstk, &no);
    //     Pop(&xstk, &x);
    //     Pop(&ystk, &y);
    //     Pop(&sstk, &sw);
    //     if (sw == 0)
    //         goto Second;
    // }
End:

    Terminate(&nstk);
    Terminate(&xstk);
    Terminate(&ystk);
    Terminate(&sstk);
}

int main(void)
{
    int n;

    printf("ハノイの塔\n円盤の枚数：");
    scanf("%d", &n);

    move(n, 1, 3);

    return 0;
}
