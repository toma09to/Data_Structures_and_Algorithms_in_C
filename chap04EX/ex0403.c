#include <stdio.h>
#include "ArrayIntQueue.h"

int main(void)
{
    ArrayIntQueue q;

    if (Initialize(&q, 64) == -1) {
        puts("キューの生成に失敗しました。");
        return 1;
    }

    while (1) {
        int menu, x;

        printf("現在のデータ数：%d / %d\n", Size(&q), Capacity(&q));
        printf("(1)エンキュー (2)デキュー (3)ピーク (4)表示 (5)全削除 (6)状態確認 (7)探索 (0)終了：");
        scanf("%d", &menu);

        if (menu == 0) break;

        switch (menu) {
            case 1:
                    printf("データ：");
                    scanf("%d", &x);
                    if (Enque(&q, x) == -1)
                        puts("\aエラー：エンキューに失敗しました。");
                    break;

            case 2:
                    if (Deque(&q, &x) == -1)
                        puts("\aエラー：デキューに失敗しました。");
                    else
                        printf("デキューしたデータは%dです。\n", x);
                    break;

            case 3:
                    if (Peek(&q, &x) == -1)
                        puts("\aエラー：ピークに失敗しました。");
                    else
                        printf("ピークしたデータは%dです。\n", x);
                    break;

            case 4:
                    Print(&q);
                    break;

            case 5:
                    Clear(&q);
                    break;

            case 6:
                    if (IsEmpty(&q))
                        puts("キューは空です。");
                    else if (IsFull(&q))
                        puts("キューは満杯です。");
                    else
                        puts("キューは空でも満杯でもありません。");
                    break;

            case 7:
                    printf("探す値：");
                    scanf("%d", &x);
                    int idx = Search(&q, x);
                    if (idx == -1)
                        puts("探索に失敗しました。");
                    else
                        printf("%dは%d番目にあります。\n", x, idx);
                    break;
        }
    }

    Terminate(&q);

    return 0;
}
