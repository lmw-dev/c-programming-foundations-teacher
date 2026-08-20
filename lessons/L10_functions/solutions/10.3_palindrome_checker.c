/*
 * 文件名: 10.3_palindrome_checker.c
 * 对应课件: 第10讲 PPT 第17~19页【当堂实践与防错性编程：回文数检测器 & 单一职责原则】
 * 对应教材: 谭浩强版《C程序设计》第7章 + 何钦铭版《C语言程序设计》第6章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 掌握工业级单一职责原则 (Single Responsibility) 与关注点分离 (Separation of Concerns)
 * 2. 掌握纯数学逆序构建回文数算法: rev = rev * 10 + (n % 10), n /= 10
 * 3. 掌握防御性输入清洗机制 (Defensive Input Cleansing): 拦截负数、非法非数字字符与输入流死循环防御
 */

#include <stdio.h>

// 函数原型声明
int is_palindrome(int num);
int read_valid_integer(const char *prompt);

int main(void)
{
    printf("======================================================================\n");
    printf("     工业级防御性编程 —— 回文数检测器与单一职责函数架构               \n");
    printf("======================================================================\n\n");

    // 1. 调用输入清洗专业函数获取干净的整数
    int number = read_valid_integer("👉 请输入你要检测的整数 (如 121, 12321, 0, -121)");

    // 2. 调用核心业务逻辑函数进行回文判定
    if (is_palindrome(number))
    {
        printf("\n🎉 判定报告: 数字 【%d】 是标准的【回文数】！(正读反读完全相同)\n", number);
    }
    else
    {
        printf("\n❌ 判定报告: 数字 【%d】 不是回文数。\n", number);
    }

    printf("======================================================================\n");
    return 0;
}

// =========================================================================
// 【业务专家函数：纯数学回文数算法 (is_palindrome)】
// 职责: 仅负责回文逻辑判定，不负责任何打印和用户输入，高内聚低耦合
// 
// 算法机理:
// 1. 防御性安检: 负数 (如 -121) 带有负号，逆序为 121-，绝对不可能为回文，直接 return 0！
// 2. 逆序组装: 循环提取个位数拼接到 rev 变量中
// =========================================================================
int is_palindrome(int num)
{
    // 安检口 1: 负数直接一票否决
    if (num < 0)
    {
        return 0;
    }

    int original = num;
    long long reversed_num = 0; // 使用 long long 防止 32位整型逆序时高位溢出 (Overflow)

    while (num > 0)
    {
        int digit = num % 10;
        reversed_num = reversed_num * 10 + digit;
        num /= 10;
    }

    // 比对逆序值与原始值
    return (reversed_num == original) ? 1 : 0;
}

// =========================================================================
// 【输入清洗专家函数：read_valid_integer】
// 职责: 处理一切肮脏的键盘输入，拦截字母、符号、回车，直到获得合法的 int
// =========================================================================
int read_valid_integer(const char *prompt)
{
    int value = 0;
    while (1)
    {
        printf("%s: ", prompt);
        if (scanf("%d", &value) == 1)
        {
            return value; // 读入成功且格式正确，安全返回
        }

        // 🚨 缓冲区冲刷保护: 拦截非法字母输入导致的 scanf 死循环
        printf("⚠️ 错误: 检测到非数字输入！已拦截恶意输入，请重新输入整数！\n");
        while (getchar() != '\n'); // 排空输入流缓冲区
    }
}
