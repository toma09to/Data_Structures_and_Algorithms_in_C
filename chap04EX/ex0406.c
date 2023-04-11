#include <stdio.h>
#include "IntDeque.h"

int main(void)
{
    IntDeque que;

    if (Initialize(&que, 64) == -1) {
        puts("キューの生成に失敗しました。");
        return 1;
    }

    while (1) {
        int m, x, idx;

        printf("現在のデータ数：%d / %d\n", Size(&que), Capacity(&que));
        printf("(1)先頭に要素を追加　(2)末尾に要素を追加　(3)先頭の要素を取出す　(4)末尾の要素を取出す\n"
                "(5)先頭の要素を調べる　(6)末尾の要素を調べる　(7)表示　(8)全削除　(9)状態確認　(10)探索(物理)　(11)探索(論理)　(0)終了：");
        scanf("%d", &m);

        if (m == 0) break;

        switch (m) {
            case 1:
                    printf("データ：");   scanf("%d", &x);
                    if (EnqueFront(&que, x) == -1)
                        puts("\aエラー：エンキューに失敗しました。");
                    break;

            case 2:
                    printf("データ：");   scanf("%d", &x);
                    if (EnqueRear(&que, x) == -1)
                        puts("\aエラー：エンキューに失敗しました。");
                    break;
            case 3:
                    if (DequeFront(&que, &x) == -1)
                        puts("\aエラー：デキューに失敗しました。");
                    else
                        printf("デキューしたデータは%dです。\n", x);
                    break;

            case 4:
                    if (DequeRear(&que, &x) == -1)
                        puts("\aエラー：デキューに失敗しました。");
                    else
                        printf("デキューしたデータは%dです。\n", x);
                    break;

            case 5:
                    if (PeekFront(&que, &x) == -1)
                        puts("\aエラー：ピークに失敗しました。");
                    else
                        printf("ピークしたデータは%dです。\n", x);
                    break;

            case 6:
                    if (PeekRear(&que, &x) == -1)
                        puts("\aエラー：ピークに失敗しました。");
                    else
                        printf("ピークしたデータは%dです。\n", x);
                    break;

            case 7:
                    Print(&que);
                    break;

            case 8:
                    Clear(&que);
                    break;

            case 9:
                    if (IsEmpty(&que))
                        puts("キューは空です。");
                    else if (IsFull(&que))
                        puts("キューは満杯です。");
                    else
                        puts("キューは空でも満杯でもありません。");
                    break;

            case 10:
                    printf("探す値：");
                    scanf("%d", &x);
                    idx = Search(&que, x);
                    if (idx == -1)
                        puts("探索に失敗しました。");
                    else
                        printf("%dはque[%d]にあります。\n", x, idx);
                    break;

            case 11:
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
