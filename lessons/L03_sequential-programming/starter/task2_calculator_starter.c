/*
 * 任务 2 起步模板：两数多功能计算器
 * 对应课件: 第03讲 PPT 第16~17页【当堂任务】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 补全下方代码，接收用户输入的两个非零整数 A 和 B
 * 2. 依次计算和、差、积、整除商、精确商与余数
 * 3. 运行测试：输入 15 4 时，精确商应输出 3.75，余数应输出 3
 */

#include <stdio.h>

int main(void)
{
    int a = 0, b = 0;

    printf("请输入两个整数 (空格隔开): ");
    if (scanf("%d %d", &a, &b) == 2 && b != 0) {
        // TODO 1: 计算和、差、积、整除商、余数
        int sum = a + b;
        int diff = a - b;
        int prod = a * b;
        int quot = a / b;
        int rem = a % b;

        // TODO 2: 利用强制类型转换 (double)a 计算精确商
        double real_quot = (double)a / b;

        printf("\n========== 计算清单 ==========\n");
        printf("  和   : %d\n", sum);
        printf("  差   : %d\n", diff);
        printf("  积   : %d\n", prod);
        printf("  整商 : %d\n", quot);
        printf("  精商 : %.2f\n", real_quot);
        printf("  余数 : %d\n", rem);
        printf("==============================\n");
    }

    return 0;
}
