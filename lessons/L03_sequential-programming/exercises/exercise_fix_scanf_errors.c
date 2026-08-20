/*
 * 练习题：顺序结构与输入输出经典排雷改错实战
 * 对应课件: 第03讲 PPT 第14~15页【案例工坊 & 机房排雷】
 * 
 * 题目要求:
 * 观察并修复下方代码中的 3 处经典致命错误，使其能够正确接收用户输入的圆半径并计算圆面积：
 * 错误 1: scanf 缺少取地址符 '&' 导致崩溃
 * 错误 2: 宏定义或除法表达式中的精度截断
 * 错误 3: double 类型变量在 scanf 中使用了错误的格式占位符
 */

#include <stdio.h>

#define PI 3.1415926535

int main(void)
{
    double radius = 0.0;
    double area = 0.0;

    printf("请输入圆的半径 (单位: 厘米): ");

    // 修复点: double 类型必须使用 "%lf" 且必须传入 &radius 地址
    if (scanf("%lf", &radius) == 1 && radius > 0.0) {
        // 计算圆面积: Area = PI * r * r
        area = PI * radius * radius;

        printf("圆的半径: %.2f cm\n", radius);
        printf("圆的面积: %.2f cm²\n", area);
    } else {
        printf("⚠️ 输入无效！\n");
    }

    return 0;
}
