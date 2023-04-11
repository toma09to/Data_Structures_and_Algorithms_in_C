#include <stdio.h>
#include "IntStack.h"

int flag_a[8];
int flag_b[15];
int flag_c[15];
int pos[8];

void print(void)
{
    for (int i = 0; i < 8; i++)
        printf("%2d", pos[i]);
    putchar('\n');
}

void set(int i)
{
    int j;
    IntStack stk;
    Initialize(&stk, 8);

Start:
    for (j = 0; j < 8; j++) {
        if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7]) {
            pos[i] = j;
            if (i == 7)
                print();
            else {
                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
                Push(&stk, j);
                i++;
                goto Start;
Return:
                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
            }
        }
    }
    if (!IsEmpty(&stk)) {
        i--;
        Pop(&stk, &j);
        goto Return;
    }

    Terminate(&stk);
}

int main(void)
{
    for (int i = 0; i < 8; i++)
        flag_a[i] = 0;
    for (int i = 0; i < 15; i++)
        flag_b[i] = flag_c[i] = 0;

    set(0);

    return 0;
}
