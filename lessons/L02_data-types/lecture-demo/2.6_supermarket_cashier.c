/*
 * 文件名: 2.6_supermarket_cashier.c
 * 对应课件: 第02讲 PPT 第23页【符号常量小超市收银结算单】
 * 对应教材: 谭浩强版《C程序设计》第2章 + 何钦铭版《C语言程序设计》第2章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 熟练运用 #define 声明符号常量（苹果 5.5元/斤，香蕉 3.2元/斤），体会“一改全改”的高维护性
 * 2. 掌握整型变量声明、初始化与从键盘 scanf 动态读入商品数量
 * 3. 掌握 double 双精度总金额计算与制表符 \t、%.2f 控制台精美对齐排版
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 1. 使用符号常量锁死固定商品单价（一改全改，只读保护）
#define APPLE_PRICE 5.5
#define BANANA_PRICE 3.2

int main(void)
{
    printf("====================================================\n");
    printf("       爱心小超市智能收银结算系统 (PPT 第23页)      \n");
    printf("====================================================\n\n");

    // 2. 声明整型变量并初始化为 0（防幽灵垃圾值）
    int apple_weight = 0;
    int banana_weight = 0;

    printf("请输入购买苹果的斤数: ");
    if (scanf("%d", &apple_weight) != 1 || apple_weight < 0) {
        printf("⚠️ 输入错误，斤数必须为非负整数！\n");
        return 1;
    }

    printf("请输入购买香蕉的斤数: ");
    if (scanf("%d", &banana_weight) != 1 || banana_weight < 0) {
        printf("⚠️ 输入错误，斤数必须为非负整数！\n");
        return 1;
    }

    // 3. 计算小计金额与应付总额 (使用 double 保证财务精度)
    double apple_total = apple_weight * APPLE_PRICE;
    double banana_total = banana_weight * BANANA_PRICE;
    double grand_total = apple_total + banana_total;

    // 4. 利用 \t 制表符与 %.2f 格式化打印精美结账小票
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
