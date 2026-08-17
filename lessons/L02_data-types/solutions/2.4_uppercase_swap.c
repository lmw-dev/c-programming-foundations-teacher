/*
 * 文件名: 2.4_uppercase_swap.c
 * 对应课件: 第02讲 PPT 第8、16、19页【随堂实战作业：字母转换与符号常量计算器】
 * 对应教材: 谭浩强版《C程序设计》第2章 + 何钦铭版《C语言程序设计》第2章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 掌握利用 ASCII 码差值（32）实现大小写字母转换的算术逻辑
 * 2. 掌握符号常量 #define 与常变量 const 的定义与使用方式
 * 3. 掌握 float 浮点数的基本输入 (scanf) 与格式化保留两位小数输出 (%.2f)
 */

#include <stdio.h>

// 定义符号常量：苹果的单价为每公斤（或每斤）2.5 元
// 优点: 预处理指令，若价格变动只需改动这一处宏定义，实现“一改全改”
#define APPLE_PRICE 2.5f

int main(void)
{
    printf("====================================================\n");
    printf("   第02讲 课后挑战：字符转换与符号常量计算器       \n");
    printf("====================================================\n\n");

    // =========================================================
    // Part 1: 黑客字母转换彩蛋 (Uppercase-to-Lowercase Swap)
    // 物理原理:
    // 大写字母 'A'~'Z' (ASCII 65~90) 与小写字母 'a'~'z' (ASCII 97~122)
    // 每一个对应的字母之间均相差固定数值 32 ('a' - 'A' = 32)。
    // =========================================================
    printf("[Part 1] 黑客大写转小写字母转换实验:\n");
    char upper_letter = 'A';
    char lower_letter = upper_letter + 32;

    printf("  -> 原始大写字母: '%c' (ASCII码值: %d)\n", upper_letter, upper_letter);
    printf("  -> 加上偏移量32: '%c' + 32\n", upper_letter);
    printf("  -> 转换后小写字母: '%c' (ASCII码值: %d)\n\n", lower_letter, lower_letter);

    // =========================================================
    // Part 2: 符号常量苹果价格计算器 (Constant Price Calculator)
    // =========================================================
    printf("[Part 2] 符号常量苹果价格结账台:\n");
    printf("  -> 当前苹果单价 (APPLE_PRICE): %.2f 元/公斤\n", APPLE_PRICE);

    float weight = 0.0f;
    printf("  请输入您购买的苹果重量 (公斤): ");
    
    // 安全输入浮点数（注意取地址符 &）
    if (scanf("%f", &weight) == 1) {
        float total_cost = weight * APPLE_PRICE;
        printf("\n  ----------- 结账小票 -----------\n");
        printf("  购买单价 : %6.2f 元/公斤\n", APPLE_PRICE);
        printf("  购买重量 : %6.2f 公斤\n", weight);
        printf("  应付总额 : %6.2f 元\n", total_cost);
        printf("  --------------------------------\n");
    } else {
        printf("\n  ⚠️ 输入错误: 请输入有效的数字！\n");
    }

    printf("\n====================================================\n");

    return 0;
}
