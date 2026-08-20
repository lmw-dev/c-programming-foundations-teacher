/*
 * 任务 3 起步模板：智能四则运算计算器与除零拦截
 * 对应课件: 第04讲 PPT 第16~17页【小时四：实践工坊】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 使用 scanf("%f %c %f", ...) 读取表达式（注意 %c 前面的空格）
 * 2. 使用 if-else if-else 多分支结构分别实现 +, -, *, /
 * 3. 在除法中进行防御性编程：使用 fabs(num2) < 1e-6 拦截除零错误
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    float num1 = 0.0f, num2 = 0.0f;
    char op = '\0';

    printf("请输入表达式 (如 10.5 / 2.0): ");

    // TODO 1: 读取输入，注意 %c 前必须留有空格
    if (scanf("%f %c %f", &num1, &op, &num2) == 3) {
        if (op == '+') {
            printf("结果: %.2f\n", num1 + num2);
        } else if (op == '-') {
            printf("结果: %.2f\n", num1 - num2);
        } else if (op == '*') {
            printf("结果: %.2f\n", num1 * num2);
        } else if (op == '/') {
            // TODO 2: 防御性拦截除数为 0 的异常
            if (fabs(num2) < 1e-6) {
                printf("⚠️ [错误] 除数不能为零！\n");
            } else {
                printf("结果: %.2f\n", num1 / num2);
            }
        } else {
            printf("⚠️ [错误] 未知运算符 '%c'！\n", op);
        }
    }

    return 0;
}
