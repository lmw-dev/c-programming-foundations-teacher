/*
 * 练习题：数组参数、带参宏与 static 变量排雷改错实战
 * 对应课件: 第11讲 PPT 第6, 10, 14页【避坑指南：数组参数与预处理三大雷区】
 * 
 * 题目要求:
 * 观察并修复下方代码中的 4 处经典语法与逻辑漏洞：
 * 漏洞 1: 二维数组作为形参时非法省略了第二维（列数）
 * 漏洞 2: 宏定义末尾误加分号导致展开语法报错
 * 漏洞 3: 带参宏未对参数和整体加括号导致优先级被破坏
 * 漏洞 4: 跨函数调用计数误用普通局部变量（每次调用重新归零）
 */

#include <stdio.h>

// 修复点 1: 宏定义末尾绝对不能加分号！
#define PI 3.14159265

// 修复点 2: 带参宏必须对形参及整体添加严格的双重括号
#define SQUARE(x) ((x) * (x))

// 修复点 3: 二维数组形参必须指定第二维列数 (如 [3][4] 或 [][4])
int get_matrix_sum(int matrix[][4], int rows);

// 修复点 4: 使用 static 修饰局部变量，使其保留调用历史
int get_unique_id(void);

int main(void)
{
    printf("=== 数组参数与宏定义排雷修复 ===\n");

    int a = 2, b = 3;
    printf("修复1: SQUARE(a + b) 正确计算结果: %d (预期 25)\n", SQUARE(a + b));

    int m[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    printf("修复2: 二维矩阵求和: %d\n", get_matrix_sum(m, 2));

    printf("修复3: ID 生成器: %d, %d, %d\n", get_unique_id(), get_unique_id(), get_unique_id());

    return 0;
}

int get_matrix_sum(int matrix[][4], int rows)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int get_unique_id(void)
{
    static int current_id = 1000;
    current_id++;
    return current_id;
}
