/*
 * 任务 2 起步模板：三数求最大值（打擂台算法）
 * 对应课件: 第04讲 PPT 第15页【机房实战一】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 补全下方的 TODO 区域，通过 scanf 读入三个整数 a, b, c
 * 2. 运用“打擂台”算法，先让 a 当擂主 (max = a)，随后依次用 b 和 c 挑战并更新擂主
 * 3. 运行测试：输入 12 99 45，输出最大值 99
 */

#include <stdio.h>

int main(void)
{
    int a = 0, b = 0, c = 0;
    int max = 0;

    printf("请输入三个整数 (空格隔开): ");
    if (scanf("%d %d %d", &a, &b, &c) == 3) {
        // TODO 1: 让 a 成为初始擂主
        max = a;

        // TODO 2: b 上台挑战，若 b > max 则更新 max
        if (b > max) {
            max = b;
        }

        // TODO 3: c 上台挑战，若 c > max 则更新 max
        if (c > max) {
            max = c;
        }

        printf("三个数中的最大值是: %d\n", max);
    }

    return 0;
}
