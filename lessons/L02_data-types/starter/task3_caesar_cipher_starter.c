/*
 * 任务 3 起步模板：凯撒密码单字偏移与 ASCII 解密
 * 对应课件: 第02讲 PPT 第21页【实操工坊·探究三：凯撒密码单字偏移与 ASCII 解密】
 * 适用环境: Visual Studio 2022 / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 运行 Part 1，观察八进制 '\101' 与十六进制 '\x41' 密电还原出的字符
 * 2. 补全 Part 2，使用 scanf 读取用户输入的大写字母，通过 secret_char = raw_char + 3 进行凯撒偏移
 * 3. 验证输入字母 'C' 时，加密输出是否为 'F' (ASCII 70)
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    printf("====================================================\n");
    printf("  【探究三】凯撒密码单字偏移与 ASCII 进制密电还原   \n");
    printf("====================================================\n\n");

    // Part 1: 转义字符进制密电还原
    char c1 = '\101'; // 八进制形式
    char c2 = '\x41'; // 十六进制形式
    printf("[Part 1] 密电还原结果: c1 = '%c', c2 = '%c'\n\n", c1, c2);

    // Part 2: 凯撒密码单字偏移器
    char raw_char = 'A';
    char secret_char = 'A';

    printf("[Part 2] 极简凯撒密码偏移器:\n");
    printf("  请输入一个大写英文字母 (A-W): ");
    
    // TODO 1: 使用 scanf 读取一个字符放入 raw_char 中
    if (scanf(" %c", &raw_char) == 1) {
        // TODO 2: 将 raw_char 加上偏移量 3 赋值给 secret_char
        secret_char = raw_char + 3;

        printf("  -> 原始字符: '%c' (ASCII值: %d)\n", raw_char, raw_char);
        printf("  -> 加密字符: '%c' (ASCII值: %d)\n", secret_char, secret_char);
    }

    printf("\n====================================================\n");

    return 0;
}
