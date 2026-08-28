/*
 * 任务 4 起步模板：神秘的凯撒谍报密码机 (谭版 3.6)
 * 对应课件: 第03讲 PPT 第25页【实操大满贯·任务四：神秘的凯撒谍报密码机】
 * 适用环境: Visual Studio 2022 / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 声明 5 个字符变量 c1, c2, c3, c4, c5 并初始化为 'C', 'h', 'i', 'n', 'a'
 * 2. 根据凯撒密码规律，各字符向后平移 4 个位置进行加密 (例如 c1 = c1 + 4)
 * 3. 前 3 个字符使用 putchar() 管道输出，后 2 个字符使用 printf() 的 %c 控制符输出
 * 4. 验证最终打印的密文是否为 "Glmre"
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    printf("====================================================\n");
    printf("     【任务四】神秘的凯撒谍报密码机 (PPT 第25页)    \n");
    printf("====================================================\n\n");

    // 1. 初始化明文字符
    char c1 = 'C';
    char c2 = 'h';
    char c3 = 'i';
    char c4 = 'n';
    char c5 = 'a';

    printf("【原始明文】: %c%c%c%c%c\n", c1, c2, c3, c4, c5);

    // TODO 1: 对 5 个字符执行 +4 物理平移加密
    c1 = c1 + 4;
    c2 = c2 + 4;
    c3 = c3 + 4;
    c4 = c4 + 4;
    c5 = c5 + 4;

    // TODO 2: 分别使用 putchar 与 printf 进行双管道输出验证
    printf("【加密密文】: ");
    
    // 前 3 个使用 putchar() 输出
    putchar(c1);
    putchar(c2);
    putchar(c3);

    // 后 2 个使用 printf("%c") 输出
    printf("%c%c\n\n", c4, c5);

    printf("【自查指标】: 观察屏幕输出是否为 \"Glmre\"！\n");
    printf("====================================================\n");

    return 0;
}
