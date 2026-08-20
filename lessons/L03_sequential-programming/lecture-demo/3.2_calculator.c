/*
 * 文件名: 3.2_calculator.c
 * 对应课件: 第03讲 PPT 第16~17页【当堂任务：两数多功能计算器 & 强制类型转换】
 * 对应教材: 谭浩强版《C程序设计》第3章 + 何钦铭版《C语言程序设计》第2章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 熟练掌握 C 语言五大算术运算符：+、-、*、/、%
 * 2. 掌握使用 (double) 或 (float) 强制类型转换求取“精确商”
 * 3. 验证取模天条：% 两侧必为整，余数符号始终与被除数（前操作数）保持一致
 */

#include <stdio.h>

int main(void)
{
    printf("====================================================\n");
    printf("      两数多功能计算器 (支持带符号取模与精确商)      \n");
    printf("====================================================\n\n");

    int num_a = 0;
    int num_b = 0;

    printf("请输入两个整数 (非零，空格隔开，如 15 4 或 -15 -4): ");
    if (scanf("%d %d", &num_a, &num_b) != 2) {
        printf("⚠️ 输入错误: 请输入两个有效的整数！\n");
        return 1;
    }

    if (num_b == 0) {
        printf("⚠️ 数学错误: 除数不能为 0！\n");
        return 1;
    }

    // 1. 基本运算
    int sum = num_a + num_b;
    int diff = num_a - num_b;
    int prod = num_a * num_b;
    int quot_int = num_a / num_b;      // 整除商 (砍掉小数)
    int mod_rem = num_a % num_b;       // 余数 (符号跟 num_a 一致)

    // 2. 强制类型转换求精确商
    // 物理原理解析: (double)num_a 生成临时双精度马甲，触发除法自动提升为双精度浮点除
    double quot_real = (double)num_a / num_b;

    // 3. 规范格式化打印清单
    printf("\n========== %d 与 %d 的计算清单 ==========\n", num_a, num_b);
    printf("  *  和 (Sum)        : %d + %d = %d\n", num_a, num_b, sum);
    printf("  *  差 (Diff)       : %d - %d = %d\n", num_a, num_b, diff);
    printf("  *  积 (Prod)       : %d * %d = %d\n", num_a, num_b, prod);
    printf("  *  整除商 (Quot)   : %d / %d = %d (丢弃小数)\n", num_a, num_b, quot_int);
    printf("  *  精确商 (Real)   : %d / %d = %.2f (保留2位小数)\n", num_a, num_b, quot_real);
    printf("  *  余数 (Mod)      : %d %% %d = %d (符号看前数)\n", num_a, num_b, mod_rem);
    printf("========================================\n\n");

    return 0;
}
