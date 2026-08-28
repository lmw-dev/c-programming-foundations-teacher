/*
 * 任务 3 起步模板：三位整数的“剥洋葱”逆序器 (何版经典)
 * 对应课件: 第03讲 PPT 第24页【实操大满贯·任务三：三位整数剥洋葱逆序器】
 * 适用环境: Visual Studio 2022 / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 从键盘读入一个任意的三位正整数 (例如 382)
 * 2. 补全 TODO 区域，利用除法天条与取模天条拆解各位数码：
 *    - 百位数 hundred = N / 100
 *    - 个位数 single  = N % 10
 *    - 十位数 ten     = (N / 10) % 10
 * 3. 计算各位数码之和，并按 single * 100 + ten * 10 + hundred 拼接逆序三位数
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    printf("====================================================\n");
    printf("     【任务三】三位整数“剥洋葱”逆序器 (PPT 第24页)  \n");
    printf("====================================================\n\n");

    int num = 0;
    printf("请输入一个三位正整数 (100~999，如 382): ");
    if (scanf("%d", &num) != 1 || num < 100 || num > 999) {
        printf("⚠️ 输入错误: 请输入有效的三位正整数！\n");
        return 1;
    }

    // TODO 1: 提取百位数字 (整除砍掉十位个位)
    int hundred = num / 100;

    // TODO 2: 提取个位数字 (取余切下个位)
    int single = num % 10;

    // TODO 3: 提取十位数字 (先整除10，再取余10)
    int ten = (num / 10) % 10;

    // TODO 4: 计算数码总和
    int digit_sum = hundred + ten + single;

    // TODO 5: 拼接逆序三位数
    int reversed_num = single * 100 + ten * 10 + hundred;

    printf("\n>>> 数字 %d 拆解报告 <<<\n", num);
    printf("  * 百位数字 (Hundred) : %d\n", hundred);
    printf("  * 十位数字 (Ten)     : %d\n", ten);
    printf("  * 个位数字 (Single)  : %d\n", single);
    printf("  --------------------------------\n");
    printf("  * 数码总和 (DigitSum): %d\n", digit_sum);
    printf("  * 逆序拼接 (Reverse) : %d\n", reversed_num);
    printf("========================================\n\n");

    return 0;
}
