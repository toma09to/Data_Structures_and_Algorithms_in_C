#include <stdio.h>
#include "IntStack.h"

int main(void)
{
    IntStack s;

    if (Initialize(&s, 64) == -1) {
        puts("スタックの生成に失敗しました。");
        return 1;
    }

    while (1) {
        int menu, x;

        printf("現在のデータ数：%d / %d\n", Size(&s), Capacity(&s));
        printf("(1)プッシュ　(2)ポップ　(3)ピーク　(4)表示　(5)全削除　(6)状態確認　(7)探索　(0)終了：");
        scanf("%d", &menu);

        if (menu == 0) break;

        switch (menu) {
            case 1:
                    printf("データ：");
                    scanf("%d", &x);
                    if (Push(&s, x) == -1)
                        puts("\aエラー：プッシュに失敗しました。");
                    break;

            case 2:
                    if (Pop(&s, &x) == -1)
                        puts("\aエラー：ポップに失敗しました。");
                    else
                        printf("ポップしたデータは%dです。\n", x);
                    break;

            case 3:
                    if (Peek(&s, &x) == -1)
                        puts("\aエラー：ピークに失敗しました。");
                    else
                        printf("ピークしたデータは%dです。\n", x);
                    break;

            case 4:
                    Print(&s);
                    break;

            case 5:
                    Clear(&s);
                    break;

            case 6:
                    if (IsEmpty(&s))
                        puts("スタックは空です。");
                    else if (IsFull(&s))
                        puts("スタックは満杯です。");
                    else
                        puts("スタックは空でも満杯でもありません。");
                    break;

            case 7:
                    printf("探す値：");
                    scanf("%d", &x);
                    int idx = Search(&s, x);
                    if (idx == -1)
                        puts("探索に失敗しました。");
                    else
                        printf("%dは%d番目にあります。\n", x, idx);
                    break;
        }
    }

    Terminate(&s);

    return 0;
}
