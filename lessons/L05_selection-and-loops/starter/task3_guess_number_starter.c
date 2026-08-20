/*
 * 任务 3 起步模板：do-while 猜数字趣味游戏
 * 对应课件: 第05讲 PPT 第19页【课后作业与挑战】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 使用 rand() % 100 + 1 生成 1 到 100 的随机数
 * 2. 使用 do-while 循环让玩家至少猜一次，直到猜中为止
 * 3. 统计并输出玩家尝试的总次数
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand((unsigned int)time(NULL));
    int secret = rand() % 100 + 1;
    int guess = 0;
    int count = 0;

    printf("=== 猜数字游戏 (1-100) ===\n");

    // TODO 1: 编写 do-while 循环结构
    do {
        printf("请输入你的猜测: ");
        if (scanf("%d", &guess) != 1) break;
        count++;

        // TODO 2: 大小比较与提示
        if (guess > secret) {
            printf("猜大啦！\n");
        } else if (guess < secret) {
            printf("猜小啦！\n");
        } else {
            printf("🎉 恭喜猜中！共尝试了 %d 次！\n", count);
        }
    // TODO 3: 循环条件 (注意末尾分号)
    } while (guess != secret);

    return 0;
}
