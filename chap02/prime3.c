// 1,000以下の素数を列挙（第３版）

#include <stdio.h>

int main(void)
{
    int prime[500];                         // 素数を格納する配列
    int ptr = 0;                            // 既に得られた素数の個数
    unsigned long counter = 0;              // 乗除の回数

    prime[ptr++] = 2;                       // ２は素数である
    prime[ptr++] = 3;                       // ３は素数である

    for (int n = 5; n <= 1000; n += 2) {    // 奇数のみを対象とする
        int i;
        int flag = 0;
        for (i = 1; counter++, prime[i] * prime[i] <= n; i++) {
            counter++;
            if (n % prime[i] == 0) {        // 割り切れると素数ではない
                flag = 1;
                break;                      // それ以上の繰返しは不要
            }
        }
        if (!flag)                          // 最後まで割り切れなかった
            prime[ptr++] = n;               // 配列に登録
    }

    for (int i = 0; i < ptr; i++)
        printf("%d\n", prime[i]);

    printf("乗除算を行った回数：%lu\n", counter);

    return 0;
}
