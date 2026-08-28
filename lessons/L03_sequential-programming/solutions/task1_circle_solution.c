/*
 * 任务 1 教师参考答案：圆之几何学计算器 (谭版 3.7 改编)
 * 对应课件: 第03讲 PPT 第22页【实操大满贯·任务一：圆之几何学计算器】
 * 适用环境: Visual Studio 2022 / Dev-C++ / VS Code
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define PI 3.1415926

int main(void)
{
    printf("====================================================\n");
    printf("  【任务一 参考答案】圆之几何学计算器 (PPT 第22页)  \n");
    printf("====================================================\n\n");

    float r = 0.0f;
    float h = 0.0f;

    printf("请输入圆半径 r 和圆柱高 h (例如 1.5 3.0): ");
    if (scanf("%f %f", &r, &h) != 2 || r <= 0.0f || h <= 0.0f) {
        printf("⚠️ 输入错误！\n");
        return 1;
    }

    float L = 2.0f * (float)PI * r;
    float S = (float)PI * r * r;
    float S_ball = 4.0f * (float)PI * r * r;
    float V_ball = (4.0f / 3.0f) * (float)PI * r * r * r; // 避开 4/3 整除截断
    float V_cyl = S * h;

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

    printf("【考点剖析】: 计算球体积时必须使用 4.0/3.0，若写成 4/3 则截断为 1，导致结果严重失真。\n");
    printf("====================================================\n");

    return 0;
}
