/*
 * 任务 1 起步模板：常驻菜单计算器系统
 * 对应课件: 第05讲 PPT 第14~15页【综合项目】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 补全下方的 switch-case 多分支结构
 * 2. 在每个 case 结束时切记加上 break 刹车
 * 3. 在除法分支中，防御性拦截除数为 0 的情况
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    int choice = -1;
    double a = 0.0, b = 0.0;
    int is_running = 1;

    while (is_running) {
        printf("\n=== 简易计算器菜单 ===\n");
        printf(" 1. 加法\n 2. 减法\n 3. 乘法\n 4. 除法\n 0. 退出\n");
        printf("请选择 (0-4): ");

        if (scanf("%d", &choice) != 1) break;

        // TODO 1: 编写 switch-case 分支
        switch (choice) {
            case 1:
                printf("输入两数: "); scanf("%lf %lf", &a, &b);
                printf("结果: %.2f\n", a + b);
                break;
            case 2:
                printf("输入两数: "); scanf("%lf %lf", &a, &b);
                printf("结果: %.2f\n", a - b);
                break;
            case 3:
                printf("输入两数: "); scanf("%lf %lf", &a, &b);
                printf("结果: %.2f\n", a * b);
                break;
            case 4:
                printf("输入两数: "); scanf("%lf %lf", &a, &b);
                // TODO 2: 除零防御性拦截
                if (fabs(b) < 1e-6) {
                    printf("⚠️ 除数不能为 0！\n");
                } else {
                    printf("结果: %.2f\n", a / b);
                }
                break;
            case 0:
                is_running = 0;
                printf("退出系统。\n");
                break;
            default:
                printf("无效选项，请重新输入！\n");
                break;
        }
    }

    return 0;
}
