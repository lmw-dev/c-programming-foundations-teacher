/*
 * 任务 5 教师参考答案：爱心小超市符号常量智能收银结算单
 * 对应课件: 第02讲 PPT 第23页【实操工坊·探究五：符号常量小超市收银结算单】
 * 适用环境: Visual Studio 2022 / Dev-C++ / VS Code
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 1. 符号常量锁死固定价格
#define APPLE_PRICE 5.5
#define BANANA_PRICE 3.2

int main(void)
{
    printf("====================================================\n");
    printf("  【探究五 参考答案】爱心小超市智能收银结算单       \n");
    printf("====================================================\n\n");

    int apple_weight = 0;
    int banana_weight = 0;

    printf("请输入购买苹果的斤数: ");
    if (scanf("%d", &apple_weight) != 1 || apple_weight < 0) {
        printf("⚠️ 输入错误！\n");
        return 1;
    }

    printf("请输入购买香蕉的斤数: ");
    if (scanf("%d", &banana_weight) != 1 || banana_weight < 0) {
        printf("⚠️ 输入错误！\n");
        return 1;
    }

    // 2. double 保证计算精度
    double apple_total = apple_weight * APPLE_PRICE;
    double banana_total = banana_weight * BANANA_PRICE;
    double grand_total = apple_total + banana_total;

    // 3. 控制台排版输出
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
