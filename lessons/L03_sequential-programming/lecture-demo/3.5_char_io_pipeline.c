/*
 * 文件名: 3.5_char_io_pipeline.c
 * 对应课件: 第03讲 PPT 第17页【putchar 与 getchar 字符流管道 & 何版大写转小写】
 * 对应教材: 何钦铭版《C语言程序设计》第2章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 掌握轻量级字符输入函数 getchar() 与输出函数 putchar() 的极简机制
 * 2. 掌握 putchar() 既能接收字符变量又能接收 ASCII 整数 (putchar(66) -> 'B')
 * 3. 掌握大写转小写的算术逻辑: c2 = c1 + 32
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    printf("====================================================\n");
    printf("       putchar 与 getchar 字符流管道实验            \n");
    printf("====================================================\n\n");

    // 1. putchar 多种形式输出 (字符变量、转义字符、ASCII 整数)
    char ch = 'B';
    printf("[实验 1] putchar 字符与整型输出对比:\n");
    printf("  -> putchar(ch): ");
    putchar(ch);
    putchar('\n');

    printf("  -> putchar(66): ");
    putchar(66); // 字符底层就是整数，66 直接打印为 'B'
    putchar('\n');
    printf("  -> 结论: char 具有双重身份，直接喂给 putchar 整数即可输出字符！\n\n");

    // 2. 何版经典案例：getchar 读入大写转小写
    printf("[实验 2] 大写字母转小写字符流管道 (何版经典案例):\n");
    printf("  请输入一个大写英文字母 (如 A/B/C) 并按回车: ");

    char c1, c2;
    c1 = (char)getchar(); // 从键盘读入单个字符

    if (c1 >= 'A' && c1 <= 'Z') {
        c2 = c1 + 32; // ASCII 码值加 32 转换为小写
        printf("  -> 成功转码: 大写 '%c' (ASCII: %d) --> 小写 '%c' (ASCII: %d)\n", 
               c1, c1, c2, c2);
    } else {
        printf("  ⚠️ 您输入的 '%c' 不是大写字母！\n", c1);
    }

    printf("\n====================================================\n");

    return 0;
}
