/*
 * 文件名: homework_02_solution.c
 * 对应课件: 第02讲 PPT 第24页【课后作业一：黑客字母转换彩蛋】
 * 适用环境: Visual Studio 2022 / Dev-C++ / VS Code
 * 
 * 任务描述:
 * 1. 已知大写字母 'A' 的 ASCII 码是 65，小写字母 'a' 是 97。
 * 2. 声明字符变量 c = 'A'，通过数学算术运算将其转换为小写字母并输出。
 * 3. 严禁直接写 c = 'a'，必须通过 c = c + 32 实现物理转换。
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    printf("====================================================\n");
    printf("     第02讲 课后作业：黑客大写转小写字母转换彩蛋    \n");
    printf("====================================================\n\n");

    // 1. 声明大写字符变量
    char c = 'A';

    printf("【转换前】:\n");
    printf("  字符形态 (%%c): '%c'\n", c);
    printf("  ASCII 码 (%%d): %d\n\n", c);

    // 2. 通过数学运算转换 ('A'(65) + 32 = 'a'(97))
    char lower_c = c + 32;

    printf("【转换后】(执行 c + 32 运算):\n");
    printf("  字符形态 (%%c): '%c'\n", lower_c);
    printf("  ASCII 码 (%%d): %d\n\n", lower_c);

    printf("【底层本质总结】:\n");
    printf("  C 语言中 char 本质就是 1 字节整数，大写与小写字母之间相差固定数值 32！\n");
    printf("====================================================\n");

    return 0;
}
