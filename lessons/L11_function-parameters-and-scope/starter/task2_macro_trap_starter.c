/*
 * 任务 2 起步模板：带参宏定义的括号防错防御
 * 对应课件: 第11讲 PPT 第14页【宏双重括号法则】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 观察未加括号的宏与加上双重括号的宏的展开结果差异
 * 2. 牢记宏每个形参和整体都必须加括号
 */

#include <stdio.h>

// ❌ 未加括号的危险宏
#define CUBE_BAD(x) x * x * x

// TODO: 定义带严格双重括号保护的规范宏
#define CUBE_GOOD(x) ((x) * (x) * (x))

int main(void)
{
    int a = 1, b = 2;

    // 期望计算 (1+2)^3 = 27
    printf("CUBE_BAD(a + b) : %d (展开为 1+2*1+2*1+2 = 7)\n", CUBE_BAD(a + b));
    printf("CUBE_GOOD(a + b): %d (正确展开为 ((1+2)*(1+2)*(1+2)) = 27)\n", CUBE_GOOD(a + b));

    return 0;
}
