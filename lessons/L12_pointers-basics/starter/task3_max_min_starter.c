/*
 * 任务 3 起步模板：利用指针突破 return 实现多值带回
 * 对应课件: 第12讲 PPT 第16, 17页【多值带回】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 编写 void get_extremes(int a, int b, int *max_val, int *min_val)
 * 2. 在函数内部通过 *max_val 和 *min_val 将最大最小值带回给 main
 */

#include <stdio.h>

void get_extremes(int a, int b, int *max_val, int *min_val);

int main(void)
{
    int num1 = 45, num2 = 88;
    int high, low;

    // TODO 1: 传入 num1, num2 以及 &high, &low
    get_extremes(num1, num2, &high, &low);

    printf("数字 (%d, %d) 中: 最大值 = %d, 最小值 = %d\n", num1, num2, high, low);
    return 0;
}

void get_extremes(int a, int b, int *max_val, int *min_val)
{
    // TODO 2: 比较并写入指针所指的变量
    if (a >= b) {
        *max_val = a;
        *min_val = b;
    } else {
        *max_val = b;
        *min_val = a;
    }
}
