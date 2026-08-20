/*
 * 文件名: 10.2_scope_and_static.c
 * 对应课件: 第10讲 PPT 第12, 13, 14页【空间大战：作用域、局部遮蔽全局与 static 静态局部变量】
 * 对应教材: 谭浩强版《C程序设计》第7章 7.8, 7.9 + 湖南大学《C语言程序设计》第4章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 理解局部变量（栈区随生随死）与全局变量（静态区寿与天齐）的作用域与生命期差异
 * 2. 掌握局部变量“遮蔽”同名全局变量的强龙压地头蛇机制
 * 3. 掌握 static 静态局部变量的核心特性：只在首次调用时初始化一次，空间不释放，保留历史痕迹
 */

#include <stdio.h>

// 全局变量定义：不属于任何函数，整个源文件生命期贯穿始终
int tracker = 100;

// 函数原型声明
void demonstrate_auto_variable(void);
void demonstrate_static_variable(void);
void demonstrate_scope_shadowing(void);

int main(void)
{
    printf("======================================================================\n");
    printf("    作用域与生命期解密 —— 局部 vs 全局 vs static 静态局部变量          \n");
    printf("======================================================================\n\n");

    // =========================================================================
    // 【实验一：普通局部变量 vs 静态局部变量连续调用对比】
    // =========================================================================
    printf("1. 【普通局部变量 (auto) 连续调用 3 次测试】:\n   输出: ");
    for (int i = 0; i < 3; i++)
    {
        demonstrate_auto_variable();
    }
    printf("\n   💡 结论: 普通局部变量在函数退出时空间立即被回收销毁，每次调用都重新初始化为 0！\n\n");

    printf("2. 【静态局部变量 (static) 连续调用 3 次测试】:\n   输出: ");
    for (int i = 0; i < 3; i++)
    {
        demonstrate_static_variable();
    }
    printf("\n   💡 结论: static 变量在静态存储区分配，仅首次初始化一次，函数退出不销毁，保留历史状态！\n\n");

    // =========================================================================
    // 【实验二：同名局部变量遮蔽全局变量 (局部优先原则)】
    // =========================================================================
    printf("3. 【同名变量作用域遮蔽效应 (Scope Shadowing)】:\n");
    printf("   [main 中访问全局变量] tracker = %d (初始值 100)\n", tracker);
    demonstrate_scope_shadowing();
    printf("   [main 再次访问全局变量] tracker = %d (全局变量毫发无损)\n", tracker);

    printf("\n======================================================================\n");
    return 0;
}

// 普通局部变量：每次调用重新分配，count 初始为 0，加 1 后为 1
void demonstrate_auto_variable(void)
{
    int count = 0;  // 普通自动变量（分配在栈区）
    count++;
    printf("%d ", count);
}

// 静态局部变量：首次调用分配在静态存储区并初始化为 0，后续调用跳过初始化继续累加
void demonstrate_static_variable(void)
{
    static int count = 0;  // 静态局部变量（分配在静态存储区）
    count++;
    printf("%d ", count);
}

// 演示同名遮蔽原则
void demonstrate_scope_shadowing(void)
{
    int tracker = 5;  // 局部变量 tracker，名字与全局变量完全一致！
    printf("   [函数内部局部作用域] tracker = %d (局部强龙压过地头蛇，遮蔽了全局变量 100)\n", tracker);
}
