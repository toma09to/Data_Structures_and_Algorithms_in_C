#include <stdio.h>
#include "IntStack.h"

void recur3(int n)
{
    int sw = 0;
    IntStack nstk, sstk;

    Initialize(&nstk, 100);
    Initialize(&sstk, 100);

    while (1) {
        if (n > 0) {
            Push(&nstk, n);
            Push(&sstk, sw);

            if (sw == 0)
                n = n - 1;
            else if (sw == 1) {
                n = n - 2;
                sw = 0;
            }
            continue;
        }

        do {
            Pop(&nstk, &n);
            Pop(&sstk, &sw);
            sw++;

            if (sw == 2) {
                printf("%d\n", n);
                if (IsEmpty(&nstk))
                    return;
            }
        } while (sw == 2);
    }   

    Terminate(&nstk);
    Terminate(&sstk);
}

int main(void)
{
    int n;

    printf("整数を入力せよ：");
    scanf("%d", &n);

    recur3(n);

    return 0;
}
