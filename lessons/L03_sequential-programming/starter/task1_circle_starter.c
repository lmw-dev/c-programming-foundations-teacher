/*
 * 任务 1 起步模板：圆之几何学计算器 (谭版 3.7 改编)
 * 对应课件: 第03讲 PPT 第22页【实操大满贯·任务一：圆之几何学计算器】
 * 适用环境: Visual Studio 2022 / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 使用 #define 定义圆周率符号常量 PI 为 3.1415926
 * 2. 从键盘输入圆半径 r 和圆柱高 h (float 类型)
 * 3. 补全 TODO 区域，计算圆周长 L、圆面积 S、圆球表面积 S_ball、圆球体积 V_ball 和圆柱体积 V_cyl
 * 4. 🚨 防坑警告: 计算圆球体积时公式为 (4.0/3) * PI * r * r * r，切勿写成 4/3 整除截断！
 * 5. 使用 %.2f 格式化输出所有几何指标
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// TODO 1: 使用 #define 定义 PI 为 3.1415926
#define PI 3.1415926

int main(void)
{
    printf("====================================================\n");
    printf("     【任务一】圆之几何学计算器 (PPT 第22页)        \n");
    printf("====================================================\n\n");

    float r = 0.0f; // 圆半径
    float h = 0.0f; // 圆柱高

    printf("请输入圆半径 r 和圆柱高 h (空格隔开，例如 1.5 3.0): ");
    if (scanf("%f %f", &r, &h) != 2 || r <= 0.0f || h <= 0.0f) {
        printf("⚠️ 输入错误: 半径与高必须为正数！\n");
        return 1;
    }

    // TODO 2: 计算圆周长 L = 2 * PI * r
    float L = 2.0f * (float)PI * r;

    // TODO 3: 计算圆面积 S = PI * r * r
    float S = (float)PI * r * r;

    // TODO 4: 计算圆球表面积 S_ball = 4 * PI * r * r
    float S_ball = 4.0f * (float)PI * r * r;

    // TODO 5: 计算圆球体积 V_ball = (4.0 / 3) * PI * r * r * r (切记 4.0/3 避开整除截断!)
    float V_ball = (4.0f / 3.0f) * (float)PI * r * r * r;

    // TODO 6: 计算圆柱体积 V_cyl = S * h
    float V_cyl = S * h;

    // 格式化输出账单
    printf("\n---------------- 圆与圆柱几何指标报告 ----------------\n");
    printf("  * 输入半径 r      : %8.2f\n", r);
    printf("  * 输入柱高 h      : %8.2f\n", h);
    printf("  ----------------------------------------------------\n");
    printf("  * 圆周长 (L)      : %8.2f\n", L);
    printf("  * 圆面积 (S)      : %8.2f\n", S);
    printf("  * 圆球表面积      : %8.2f\n", S_ball);
    printf("  * 圆球体积        : %8.2f\n", V_ball);
    printf("  * 圆柱体积        : %8.2f\n", V_cyl);
    printf("------------------------------------------------------\n\n");

    return 0;
}
