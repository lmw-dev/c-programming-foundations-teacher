/*
 * 文件名: 3.3_bank_interest.c
 * 对应课件: 第03讲 PPT 第19页【课后作业与挑战：银行复利与利息计算器】
 * 对应教材: 谭浩强版《C程序设计》第3章 + 何钦铭版《C语言程序设计》第2章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 掌握标准数学函数库 <math.h> 的引入与 pow(x, n) 幂函数计算
 * 2. 掌握金融高精度实数 double 的声明、scanf("%lf") 输入与 printf("%.2f") 输出
 * 3. 掌握实际工程常识：Linux/GCC 环境下编译数学库必须手动添加 -lm 链接参数
 */

#include <stdio.h>
#include <math.h>  // 引入数学库，提供 pow()、sqrt()、fabs() 等数学函数

int main(void)
{
    printf("====================================================\n");
    printf("        金融存单模拟 —— 银行复利本息计算器         \n");
    printf("====================================================\n\n");

    // 1. 变量声明 (高精度金融计算统一使用 double 类型，占 8 字节，避免精度损失)
    double principal = 0.0;       // 存款本金 (元)
    double interest_rate = 0.0;    // 年利率 (如 0.0225 代表 2.25%)
    int years = 0;                 // 存款期限 (年)
    double total_sum = 0.0;        // 最终本息和 (元)
    double net_interest = 0.0;     // 纯利息收入 (元)

    // 2. 交互式数据输入 (IPO 中的 Input)
    // 关键细节: scanf 读取 double 类型变量时，格式符必须是 "%lf" (long float)，严禁写成 "%f"！
    printf("请输入存款本金 (元, 例如 10000.0): ");
    if (scanf("%lf", &principal) != 1 || principal <= 0.0) {
        printf("⚠️ 错误: 本金必须为大于 0 的数字！\n");
        return 1;
    }

    printf("请输入年利率 (小数形式, 例如 2.25%% 请输入 0.0225): ");
    if (scanf("%lf", &interest_rate) != 1 || interest_rate < 0.0) {
        printf("⚠️ 错误: 年利率输入无效！\n");
        return 1;
    }

    printf("请输入存款年限 (整数年, 例如 3): ");
    if (scanf("%d", &years) != 1 || years <= 0) {
        printf("⚠️ 错误: 存款年限必须为正整数！\n");
        return 1;
    }

    // 3. 核心复利计算 (IPO 中的 Process)
    // 复利公式: 本息和 = 本金 * (1 + 利率)^年限
    // math.h 中的 pow(base, exponent) 函数: 第一个参数是底数，第二个参数是指数
    total_sum = principal * pow(1.0 + interest_rate, years);
    net_interest = total_sum - principal;

    // 4. 格式化存单模拟票据输出 (IPO 中的 Output)
    printf("\n================ 🏦 电子银行存单凭证 ================\n");
    printf("  存款本金 (Principal)    : %12.2f 元\n", principal);
    printf("  执行年利率 (Annual Rate): %11.2f %%\n", interest_rate * 100.0);
    printf("  存期年限 (Years)        : %12d 年\n", years);
    printf("  --------------------------------------------------\n");
    printf("  💰 累计纯利息 (Interest): %12.2f 元\n", net_interest);
    printf("  🎉 到期本息和 (Total)   : %12.2f 元\n", total_sum);
    printf("====================================================\n\n");

    // 编译与工程常识说明:
    // 在 Linux / GCC 命令行环境下编译包含 math.h 的程序时，必须在末尾追加 -lm 显式链接数学库:
    // gcc 3.3_bank_interest.c -o bank_interest -lm
    // -l 代表链接库 (link library)，m 代表数学库 (math)
    return 0;
}
