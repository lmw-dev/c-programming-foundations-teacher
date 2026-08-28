/*
 * 任务 4 教师参考答案：神秘的凯撒谍报密码机 (谭版 3.6)
 * 对应课件: 第03讲 PPT 第25页【实操大满贯·任务四：神秘的凯撒谍报密码机】
 * 适用环境: Visual Studio 2022 / Dev-C++ / VS Code
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    printf("====================================================\n");
    printf("  【任务四 参考答案】神秘凯撒谍报密码机 (PPT 第25页) \n");
    printf("====================================================\n\n");

    // 1. 初始化
    char c1 = 'C';
    char c2 = 'h';
    char c3 = 'i';
    char c4 = 'n';
    char c5 = 'a';

    printf("【原始明文】: %c%c%c%c%c\n", c1, c2, c3, c4, c5);

    // 2. 物理平移加密 +4
    c1 = c1 + 4;
    c2 = c2 + 4;
    c3 = c3 + 4;
    c4 = c4 + 4;
    c5 = c5 + 4;

    // 3. 双管道同台输出
    printf("【加密密文】: ");
    putchar(c1);
    putchar(c2);
    putchar(c3);
    printf("%c%c\n\n", c4, c5);

    printf("【考点剖析】: char 型在底层为 1 字节整数，支持算术加减运算；掌握 putchar 与 printf 输出。\n");
    printf("====================================================\n");

    return 0;
}
