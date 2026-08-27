/*
 * 任务 4 起步模板：两数之和与改写三数之和实操
 * 对应课件: 第01讲 PPT 第3页【三步走阶梯】& 第16页【求两数之和】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 模仿课件范例，完成两数之和计算 (a = 20, b = 30)
 * 2. 【改写挑战】：引入第三个变量 c = 50，计算并输出三数之和 sum3
 */

#include <stdio.h>

int main(void)
{
    // TODO 1: 声明整型变量 a, b, sum
    int a = 20;
    int b = 30;
    int sum;

    // TODO 2: 计算 a + b 并赋值给 sum
    sum = a + b;

    // TODO 3: 使用 printf 与 %d 打印两数之和
    printf("两数之和: %d + %d = %d\n", a, b, sum);

    // TODO 4: 【改写演练】声明变量 c，计算并打印 a + b + c 的总和
    int c = 50;
    int sum3 = a + b + c;
    printf("三数之和: %d + %d + %d = %d\n", a, b, c, sum3);

    return 0;
}
