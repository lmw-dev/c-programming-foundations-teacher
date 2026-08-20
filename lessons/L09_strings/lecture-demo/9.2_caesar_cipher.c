/*
 * 文件名: 9.2_caesar_cipher.c
 * 对应课件: 第09讲 PPT 第18页【实践工坊：凯撒密码环形加密器与字符遍历】
 * 对应教材: 谭浩强版《C程序设计》第5章 例5.11 + 何钦铭版《C语言程序设计》第5章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 掌握字符数组逐字符扫描与判断机制（扫描直到遇到 '\0' 哨兵）
 * 2. 掌握基于 ASCII 相对位移的模运算环形回绕算法: (c - 'a' + offset) % 26 + 'a'
 * 3. 掌握密码学对称加密与解密还原的工程实现
 */

#include <stdio.h>
#include <string.h>

#define SHIFT_OFFSET 3  // 凯撒密码经典偏移量：每个字母向后移动 3 位

int main(void)
{
    printf("======================================================================\n");
    printf("       密码学算法实战 —— 凯撒密码环形加密与解密还原系统                \n");
    printf("======================================================================\n\n");

    // 1. 定义包含大小写字母、空格、标点符号的待加密明文字符串
    char original_text[] = "Hello, C Programming World! zZ-2026";
    char cipher_text[100];
    char decrypted_text[100];

    // =========================================================================
    // 【核心算法一：凯撒加密循环 (模运算环形回绕)】
    // 
    // 数学映射机理:
    // 1. (c - 'a') 将字母映射为 0 ~ 25 的相对索引 ('a'->0, 'z'->25)；
    // 2. + 3 向后偏移；
    // 3. % 26 取模运算实现环形闭环！例如: 'z'(25) + 3 = 28, 28 % 26 = 2 ('c')！
    // 4. + 'a' 重新平移回 ASCII 字符码。
    // =========================================================================
    int i = 0;
    while (original_text[i] != '\0')
    {
        char c = original_text[i];

        if (c >= 'a' && c <= 'z')
        {
            // 小写字母环形加密
            cipher_text[i] = (char)((c - 'a' + SHIFT_OFFSET) % 26 + 'a');
        }
        else if (c >= 'A' && c <= 'Z')
        {
            // 大写字母环形加密
            cipher_text[i] = (char)((c - 'A' + SHIFT_OFFSET) % 26 + 'A');
        }
        else
        {
            // 非字母字符（空格、逗号、感叹号、数字）原样保留
            cipher_text[i] = c;
        }
        i++;
    }
    cipher_text[i] = '\0';  // 🚨 显式加上字符串结束符 '\0'！

    // =========================================================================
    // 【核心算法二：凯撒解密循环 (逆向还原)】
    // 逆向平移: (c - 'a' - 3 + 26) % 26 + 'a' (+26 防止负数取模异常)
    // =========================================================================
    int j = 0;
    while (cipher_text[j] != '\0')
    {
        char c = cipher_text[j];

        if (c >= 'a' && c <= 'z')
        {
            decrypted_text[j] = (char)((c - 'a' - SHIFT_OFFSET + 26) % 26 + 'a');
        }
        else if (c >= 'A' && c <= 'Z')
        {
            decrypted_text[j] = (char)((c - 'A' - SHIFT_OFFSET + 26) % 26 + 'A');
        }
        else
        {
            decrypted_text[j] = c;
        }
        j++;
    }
    decrypted_text[j] = '\0';

    // 2. 打印加密与解密对比报告
    printf("1. 【原始明文 (Original)】:\n   \"%s\"\n\n", original_text);
    printf("2. 【加密密文 (Ciphertext, 偏移量 +%d)】:\n   \"%s\"\n\n", SHIFT_OFFSET, cipher_text);
    printf("3. 【解密还原 (Decrypted)】:\n   \"%s\"\n\n", decrypted_text);

    // 3. 校验正确性
    if (strcmp(original_text, decrypted_text) == 0)
    {
        printf("✅ 密码学校验: 解密文本与原始明文完全一致，算法验证 100%% 通过！\n");
    }
    else
    {
        printf("❌ 密码学校验: 解密失败！\n");
    }
    printf("======================================================================\n");

    return 0;
}
