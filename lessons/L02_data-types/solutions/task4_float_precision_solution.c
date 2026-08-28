/*
 * 任务 4 教师参考答案：浮点数的“近视眼”精度显微镜
 * 对应课件: 第02讲 PPT 第22页【实操工坊·探究四：浮点数的近视眼精度显微镜】
 * 适用环境: Visual Studio 2022 / Dev-C++ / VS Code
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    printf("====================================================\n");
    printf("  【探究四 参考答案】浮点精度显微镜与物理误差分析   \n");
    printf("====================================================\n\n");

    printf("原始高精基准输入: 1.234567890123456\n\n");

    float my_float = 1.234567890123456f;
    double my_double = 1.234567890123456;

    printf("float  实际存储 (%%.16f): %.16f\n", my_float);
    printf("double 实际存储 (%%.16f): %.16f\n\n", my_double);

    printf("【实验探究结论】:\n");
    printf("  1. float 占 4 字节，有效位数仅 7 位，从第 8 位开始发生精度截断失真；\n");
    printf("  2. double 占 8 字节，有效位数达 15~16 位，15 位以内完全精确；\n");
    printf("  3. 涉及财务与高精计算时，必须选用 double。\n");
    printf("====================================================\n");

    return 0;
}
