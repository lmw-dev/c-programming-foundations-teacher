/*
 * 文件名: 2.3_sizeof_ruler.c
 * 对应课件: 第02讲 PPT 第17~18页【sizeof：探秘内存的物理“量地尺”】
 * 对应教材: 谭浩强版《C程序设计》第2章 + 何钦铭版《C语言程序设计》第2章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 掌握 sizeof 运算符的使用方法：sizeof(类型名) 与 sizeof 变量名
 * 2. 探究并在本地计算机上实测各基础数据类型的物理内存字节数
 * 3. 理解 C 语言标准并未死规定各类型的具体大小，具体长度由操作系统与编译器决定
 */

#include <stdio.h>

int main(void)
{
    printf("====================================================\n");
    printf("    === Your Computer's Memory收纳盒 Ruler ===     \n");
    printf("====================================================\n\n");

    // 1. 声明不同类型的具体变量
    char my_char = 'A';
    int my_int = 100;
    double my_double = 9.9;

    printf("[Part 1] 测量具体变量实例的物理空间 (sizeof 变量名):\n");
    printf("  -> char   变量 my_char   占用: %zu 字节 (Byte)\n", sizeof(my_char));
    printf("  -> int    变量 my_int    占用: %zu 字节 (Byte)\n", sizeof(my_int));
    printf("  -> double 变量 my_double 占用: %zu 字节 (Byte)\n\n", sizeof(my_double));

    // 2. 测量核心 C 语言基本数据类型 (sizeof(类型名))
    // 提示: 在 64 位现代系统与编译器中，sizeof 返回类型为 size_t，推荐使用 %zu 或 %lu 格式符
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
