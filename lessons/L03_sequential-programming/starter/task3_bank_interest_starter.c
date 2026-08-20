/*
 * 任务 3 起步模板：银行复利与利息计算器
 * 对应课件: 第03讲 PPT 第19页【课后作业与挑战】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 引入 <math.h>，使用 pow(1.0 + r, n) 计算复利本息和
 * 2. 金融数据使用 double 声明，格式化保留 2 位小数
 * 3. 运行测试：本金 10000 元，年利率 0.03 (3%)，存期 3 年，到期本息和应为 10927.27 元
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double principal = 0.0;
    double rate = 0.0;
    int years = 0;

    printf("请输入本金、年利率(小数)、年限 (空格隔开，如 10000 0.03 3): ");
    
    // TODO 1: 使用 scanf 读取 double 类型变量 (注意用 %lf)
    if (scanf("%lf %lf %d", &principal, &rate, &years) == 3) {
        // TODO 2: 运用公式 total_sum = principal * pow(1.0 + rate, years) 计算本息和
        double total_sum = principal * pow(1.0 + rate, years);
        double interest = total_sum - principal;

        printf("\n========== 存单核算 ==========\n");
        printf("  本金   : %.2f 元\n", principal);
        printf("  利息   : %.2f 元\n", interest);
        printf("  本息和 : %.2f 元\n", total_sum);
        printf("==============================\n");
    }

    return 0;
}
