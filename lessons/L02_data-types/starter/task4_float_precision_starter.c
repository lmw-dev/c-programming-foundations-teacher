/*
 * 任务 4 起步模板：浮点数的“近视眼”精度显微镜
 * 对应课件: 第02讲 PPT 第22页【实操工坊·探究四：浮点数的近视眼精度显微镜】
 * 适用环境: Visual Studio 2022 / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 补全 TODO 区域，分别声明单精度 float 和双精度 double 并存入 16 位小数 1.234567890123456
 * 2. 使用 %%.16f 格式控制符强制输出 16 位小数
 * 3. 观察记录：float 从第几位开始失真？double 能精确保真到第几位？
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    printf("====================================================\n");
    printf("      【探究四】浮点数的“近视眼”精度显微镜实验      \n");
    printf("====================================================\n\n");

    printf("原始高精输入: 1.234567890123456 (16位有效数字)\n\n");

    // TODO 1: 声明 float 变量 my_float 并赋值（注意添加 f 后缀）
    float my_float = 1.234567890123456f;

    // TODO 2: 声明 double 变量 my_double 并赋值
    double my_double = 1.234567890123456;

    // TODO 3: 使用 %%.16f 打印 my_float 与 my_double 的实际存储值
    printf("float  实际存储 (%%.16f): %.16f\n", my_float);
    printf("double 实际存储 (%%.16f): %.16f\n\n", my_double);

    printf("====================================================\n");

    return 0;
}
