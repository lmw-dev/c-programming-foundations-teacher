/*
 * 任务 1 教师参考答案：使用 sizeof 测量电脑上的“收纳盒规格”
 * 对应课件: 第02讲 PPT 第19页【实操工坊·探究一：寻找你电脑上的收纳盒规格】
 * 适用环境: Visual Studio 2022 / Dev-C++ / VS Code
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    printf("====================================================\n");
    printf("  【探究一 参考答案】电脑 Memory 收纳盒规格测量    \n");
    printf("====================================================\n\n");

    char my_char = 'A';
    int my_int = 100;
    double my_double = 9.9;

    printf("[Part 1] 测量具体变量实例的物理空间:\n");
    printf("  -> char   变量 my_char   占用: %zu 字节 (Byte)\n", sizeof(my_char));
    printf("  -> int    变量 my_int    占用: %zu 字节 (Byte)\n", sizeof(my_int));
    printf("  -> double 变量 my_double 占用: %zu 字节 (Byte)\n\n", sizeof(my_double));

    printf("[Part 2] 测量核心数据类型收纳盒规格 (sizeof(类型名)):\n");
    printf("  --------------------------------------------------\n");
    printf("  | 类型关键字          | 占用字节数 | 典型位宽 (Bit) |\n");
    printf("  --------------------------------------------------\n");
    printf("  | char                | %4zu 字节  |  8 位          |\n", sizeof(char));
    printf("  | short               | %4zu 字节  | 16 位          |\n", sizeof(short));
    printf("  | int                 | %4zu 字节  | 32 位          |\n", sizeof(int));
    printf("  | long                | %4zu 字节  | 32/64 位       |\n", sizeof(long));
    printf("  | long long           | %4zu 字节  | 64 位          |\n", sizeof(long long));
    printf("  | float               | %4zu 字节  | 32 位 (单精度) |\n", sizeof(float));
    printf("  | double              | %4zu 字节  | 64 位 (双精度) |\n", sizeof(double));
    printf("  | long double         | %4zu 字节  | 80/128 位      |\n", sizeof(long double));
    printf("  --------------------------------------------------\n\n");

    printf("====================================================\n");

    return 0;
}
