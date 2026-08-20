/*
 * 文件名: 5.1_menu_calculator.c
 * 对应课件: 第05讲 PPT 第14~15页【综合项目：智能菜单计算器系统】
 * 对应教材: 谭浩强版《C程序设计》第4、5章 + 何钦铭版《C语言程序设计》第3、4章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 掌握基于 while(is_running) 状态哨兵的终端常驻交互系统架构
 * 2. 掌握 switch-case 多分支直达电梯的工程应用与 break 刹车机制
 * 3. 掌握防御性编程：除零异常精密拦截 (fabs(num2) < 1e-6) 与 default 保底分支
 */

#include <stdio.h>
#include <math.h>  // 引入 fabs() 浮点数绝对值函数

int main(void)
{
    double num1 = 0.0;
    double num2 = 0.0;
    double result = 0.0;
    int choice = -1;
    int is_running = 1;  // 状态标志变量（哨兵）：1代表持续运行，0代表安全退出

    // while(is_running) 保持程序生命周期，杜绝控制台“一闪即退”
    while (is_running)
    {
        // 1. 打印整洁的 ASCII 终端主菜单
        printf("\n====================================\n");
        printf("       === 智能四则运算计算器 ===       \n");
        printf("  1. 加法运算 (+)\n");
        printf("  2. 减法运算 (-)\n");
        printf("  3. 乘法运算 (*)\n");
        printf("  4. 除法运算 (/)\n");
        printf("  0. 退出程序\n");
        printf("====================================\n");
        printf("请输入您的选择 (0-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("⚠️ [错误] 输入格式无效，退出系统！\n");
            break;
        }

        // 2. switch-case 多路分支调度
        switch (choice)
        {
            case 1:  // 加法
                printf("请输入两个运算数 (空格隔开, 如 12.5 3.5): ");
                if (scanf("%lf %lf", &num1, &num2) == 2) {
                    result = num1 + num2;
                    printf("✅ 计算结果: %.2f + %.2f = %.2f\n", num1, num2, result);
                }
                break;  // 关键刹车片: 跳出 switch，防止坠落进入 case 2

            case 2:  // 减法
                printf("请输入两个运算数 (空格隔开): ");
                if (scanf("%lf %lf", &num1, &num2) == 2) {
                    result = num1 - num2;
                    printf("✅ 计算结果: %.2f - %.2f = %.2f\n", num1, num2, result);
                }
                break;

            case 3:  // 乘法
                printf("请输入两个运算数 (空格隔开): ");
                if (scanf("%lf %lf", &num1, &num2) == 2) {
                    result = num1 * num2;
                    printf("✅ 计算结果: %.2f * %.2f = %.2f\n", num1, num2, result);
                }
                break;

            case 4:  // 除法 (含防御性除零拦截)
                printf("请输入被除数和除数 (空格隔开): ");
                if (scanf("%lf %lf", &num1, &num2) == 2) {
                    // 防御性除零检测: 浮点数零判定使用绝对值误差阈值 1e-6
                    if (fabs(num2) < 1e-6) {
                        printf("❌ [错误] 物理拦截：除数不能为零！请重新选择菜单。\n");
                    } else {
                        result = num1 / num2;
                        printf("✅ 计算结果: %.2f / %.2f = %.2f\n", num1, num2, result);
                    }
                }
                break;

            case 0:  // 退出系统
                is_running = 0;  // 熄灭哨兵指示灯，下一次 while 条件判定为假，自然退出
                printf("👋 感谢使用，智能计算器程序安全退出！\n");
                break;

            default: // 保底备胎分支
                printf("⚠️ [警告] 无效的菜单选项 '%d'！请输入 0-4 之间的数字。\n", choice);
                break;
        }
    }

    return 0;
}
