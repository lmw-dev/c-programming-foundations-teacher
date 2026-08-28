/*
 * 任务 3 教师参考答案：三位整数的“剥洋葱”逆序器 (何版经典)
 * 对应课件: 第03讲 PPT 第24页【实操大满贯·任务三：三位整数剥洋葱逆序器】
 * 适用环境: Visual Studio 2022 / Dev-C++ / VS Code
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    printf("====================================================\n");
    printf("  【任务三 参考答案】三位整数剥洋葱逆序器 (PPT 第24页)\n");
    printf("====================================================\n\n");

    int num = 0;
    printf("请输入一个三位正整数 (100~999): ");
    if (scanf("%d", &num) != 1 || num < 100 || num > 999) {
        printf("⚠️ 输入无效！\n");
        return 1;
    }

    // 1. 拆解数码
    int hundred = num / 100;
    int single = num % 10;
    int ten = (num / 10) % 10;

    // 2. 计算求和与逆序拼接
    int digit_sum = hundred + ten + single;
    int reversed_num = single * 100 + ten * 10 + hundred;

    printf("\n>>> 数字 %d 拆解报告 <<<\n", num);
    printf("  * 百位数字 (Hundred) : %d\n", hundred);
    printf("  * 十位数字 (Ten)     : %d\n", ten);
    printf("  * 个位数字 (Single)  : %d\n", single);
    printf("  --------------------------------\n");
    printf("  * 数码总和 (DigitSum): %d\n", digit_sum);
    printf("  * 逆序拼接 (Reverse) : %d\n", reversed_num);
    printf("========================================\n\n");

    printf("【考点剖析】: 熟练运用 / 100、%% 10 与 (/ 10) %% 10 提取整数各个数位。\n");
    printf("====================================================\n");

    return 0;
}
