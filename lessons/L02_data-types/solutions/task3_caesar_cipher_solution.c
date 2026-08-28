/*
 * 任务 3 教师参考答案：凯撒密码单字偏移与 ASCII 解密
 * 对应课件: 第02讲 PPT 第21页【实操工坊·探究三：凯撒密码单字偏移与 ASCII 解密】
 * 适用环境: Visual Studio 2022 / Dev-C++ / VS Code
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    printf("====================================================\n");
    printf("  【探究三 参考答案】凯撒密码与 ASCII 密电还原     \n");
    printf("====================================================\n\n");

    // Part 1: 转义字符进制密电还原
    char c1 = '\101'; // 八进制 101 -> 十进制 65 -> 'A'
    char c2 = '\x41'; // 十六进制 41 -> 十进制 65 -> 'A'
    printf("[Part 1] 密电还原结果:\n");
    printf("  -> c1 ('\\101') = '%c' (十进制ASCII: %d)\n", c1, c1);
    printf("  -> c2 ('\\x41') = '%c' (十进制ASCII: %d)\n\n", c2, c2);

    // Part 2: 凯撒密码单字偏移器
    char raw_char = 'A';
    char secret_char = 'A';

    printf("[Part 2] 极简凯撒密码偏移器:\n");
    printf("  请输入一个大写英文字母 (A-W): ");
    
    if (scanf(" %c", &raw_char) == 1) {
        secret_char = raw_char + 3; // 物理 ASCII 码直接加 3

        printf("\n  ----------- 加密结果 -----------\n");
        printf("  原始明文字符 : '%c' (ASCII: %d)\n", raw_char, raw_char);
        printf("  加密密文字符 : '%c' (ASCII: %d)\n", secret_char, secret_char);
        printf("  --------------------------------\n");
    } else {
        printf("  ⚠️ 输入无效！\n");
    }

    printf("\n====================================================\n");

    return 0;
}
