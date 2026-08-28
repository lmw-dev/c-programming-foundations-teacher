/*
 * 任务 5 起步模板：爱心小超市符号常量智能收银结算单
 * 对应课件: 第02讲 PPT 第23页【实操工坊·探究五：符号常量小超市收银结算单】
 * 适用环境: Visual Studio 2022 / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 使用 #define 定义苹果单价 APPLE_PRICE 为 5.5，香蕉单价 BANANA_PRICE 为 3.2
 * 2. 声明整型变量 apple_weight 和 banana_weight 并初始化为 0
 * 3. 从键盘读取购买斤数，计算 double 类型的应付总额
 * 4. 补全 \t 与 %%.2f 控制台排版对齐代码，打印出规范的小票
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// TODO 1: 使用 #define 定义苹果单价 APPLE_PRICE (5.5) 与香蕉单价 BANANA_PRICE (3.2)
#define APPLE_PRICE 5.5
#define BANANA_PRICE 3.2

int main(void)
{
    printf("====================================================\n");
    printf("    【探究五】爱心小超市智能收银结算单实战工坊     \n");
    printf("====================================================\n\n");

    // TODO 2: 声明整型变量并初始化
    int apple_weight = 0;
    int banana_weight = 0;

    printf("请输入购买苹果的斤数: ");
    if (scanf("%d", &apple_weight) != 1) return 1;

    printf("请输入购买香蕉的斤数: ");
    if (scanf("%d", &banana_weight) != 1) return 1;

    // TODO 3: 计算小计与总额 (double 类型)
    double apple_total = apple_weight * APPLE_PRICE;
    double banana_total = banana_weight * BANANA_PRICE;
    double grand_total = apple_total + banana_total;

    // TODO 4: 补全结账小票打印
    printf("\n====== 欢迎光临爱心小超市收银系统 ======\n");
    printf("商品\t单价(元)\t数量(斤)\t小计(元)\n");
    printf("------------------------------------------\n");
    printf("苹果\t%-8.1f\t%-8d\t%6.2f 元\n", APPLE_PRICE, apple_weight, apple_total);
    printf("香蕉\t%-8.1f\t%-8d\t%6.2f 元\n", BANANA_PRICE, banana_weight, banana_total);
    printf("------------------------------------------\n");
    printf("应付总额:                  %6.2f 元\n", grand_total);
    printf("==========================================\n\n");

    return 0;
}
