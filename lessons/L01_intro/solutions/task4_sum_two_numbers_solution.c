/*
 * 任务 4 参考答案：两数之和与改写三数之和/乘积
 * 对应课件: 第01讲 PPT 第3页【模仿、改写、编写】& 第16页【求两数之和】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 */

#include <stdio.h>

int main(void)
{
    // 1. 基础两数之和
    int a = 20;
    int b = 30;
    int sum = a + b;

    printf("【基础任务】两数之和: %d + %d = %d\n", a, b, sum);

    // 2. 拓展改写任务：三数之和与乘积
    int c = 50;
    int sum3 = a + b + c;
    int product = a * b;

    printf("【改写任务 1】三数之和: %d + %d + %d = %d\n", a, b, c, sum3);
    printf("【改写任务 2】两数之积: %d * %d = %d\n", a, b, product);

    return 0;
}
