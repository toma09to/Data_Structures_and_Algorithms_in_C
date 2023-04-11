#include <stdio.h>
#include "IntQueue.h"

int main(void)
{
    IntQueue que;

    if (Initialize(&que, 64) == -1) {
        puts("キューの生成に失敗しました。");
        return 1;
    }

    while (1) {
        int m, x, idx;

        printf("現在のデータ数：%d / %d\n", Size(&que), Capacity(&que));
        printf("(1)エンキュー　(2)デキュー　(3)ピーク　(4)表示　(5)全削除　(6)状態確認　(7)探索(物理)　(8)探索(論理)　(0)終了：");
        scanf("%d", &m);

        if (m == 0) break;

        switch (m) {
            case 1:
                    printf("データ：");   scanf("%d", &x);
                    if (Enque(&que, x) == -1)
                        puts("\aエラー：エンキューに失敗しました。");
                    break;

            case 2:
                    if (Deque(&que, &x) == -1)
                        puts("\aエラー：デキューに失敗しました。");
                    else
                        printf("デキューしたデータは%dです。\n", x);
                    break;

            case 3:
                    if (Peek(&que, &x) == -1)
                        puts("\aエラー：ピークに失敗しました。");
                    else
                        printf("ピークしたデータは%dです。\n", x);
                    break;

            case 4:
                    Print(&que);
                    break;

            case 5:
                    Clear(&que);
                    break;

            case 6:
                    if (IsEmpty(&que))
                        puts("キューは空です。");
                    else if (IsFull(&que))
                        puts("キューは満杯です。");
                    else
                        puts("キューは空でも満杯でもありません。");
                    break;

            case 7:
                    printf("探す値：");
                    scanf("%d", &x);
                    idx = Search(&que, x);
                    if (idx == -1)
                        puts("探索に失敗しました。");
                    else
                        printf("%dはque[%d]にあります。\n", x, idx);
                    break;

            case 8:
                    printf("探す値：");
                    scanf("%d", &x);
                    idx = Search2(&que, x);
                    if (idx == -1)
                        puts("探索に失敗しました。");
                    else
                        printf("%dは%d番目にあります。\n", x, idx);
                    break;
        }
    }

    Terminate(&que);

    return 0;
}
