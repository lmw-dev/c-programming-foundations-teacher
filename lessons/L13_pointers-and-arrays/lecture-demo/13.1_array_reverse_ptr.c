/*
 * 文件名: 13.1_array_reverse_ptr.c
 * 对应课件: 第13讲 PPT 第4, 5, 6, 16页【指针算术自适应步长 & 双指针向心原地逆序】
 * 对应教材: 谭浩强版《C程序设计》第8章 8.3 + 何钦铭版《C语言程序设计》第8章 例8-13
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 深刻理解指针算术自适应步长（Pointer Arithmetic）：
 *    p + 1 物理上并非加 1 个字节，而是自动向前跨越 1 * sizeof(基类型) 字节 (int 为 4 字节)
 * 2. 掌握工业级“双指针向心对碰 (Two-Pointer Converging)”原地逆序算法
 * 3. 掌握丢掉方括号下标 [i]、完全使用纯指针操作实现高性能数组读写的资深开发者思维
 */

#include <stdio.h>

#define SIZE 9

// 函数原型声明
void reverse_array_ptr(int *arr, int size);
void print_array_ptr(const int *arr, int size, const char *label);

int main(void)
{
    printf("======================================================================\n");
    printf("    指针算术与向心扫描 —— 双指针原地逆序换血算法实战                     \n");
    printf("======================================================================\n\n");

    int numbers[SIZE] = {11, 22, 33, 44, 55, 66, 77, 88, 99};

    // 1. 打印逆序前的原始数组
    print_array_ptr(numbers, SIZE, "逆序前 (Original)");

    // 2. 调用纯指针逆序函数
    printf("\n👉 正在执行双指针向心原地逆序操作 (left++ 与 right-- 相向聚拢)...\n");
    reverse_array_ptr(numbers, SIZE);

    // 3. 验证逆序后的数组状态
    printf("\n");
    print_array_ptr(numbers, SIZE, "逆序后 (Reversed) ");

    printf("\n============================ 教学原理解析 ============================\n");
    printf("💡 为什么 right = arr + size - 1 能够准确踩中尾元素？\n");
    printf("   因为 C 语言的指针加法是【步长自适应】的！\n");
    printf("   表达式 arr + (size - 1) 在物理内存中自动执行了: 首地址 + 8 * sizeof(int) (即 +32字节)，\n");
    printf("   无需程序员手动做乘法，编译器自动保证指针永远对齐在整型格子的边界上！\n");
    printf("======================================================================\n");

    return 0;
}

// 核心函数：双指针向心对碰实现数组原地逆序
void reverse_array_ptr(int *arr, int size)
{
    // 🛡️ 防御性检查：拦截空指针与非法尺寸
    if (arr == NULL || size <= 0)
    {
        return;
    }

    // 初始化左哨兵（指向首元素）与右哨兵（指向末尾元素）
    int *left = arr;
    int *right = arr + size - 1;

    // 两端指针对向聚拢，直到碰头交汇
    while (left < right)
    {
        // 1. 原地互换指针所指向的物理内存值
        int temp = *left;
        *left = *right;
        *right = temp;

        // 2. 步长自适应滑动：左指针向右移 1 个 int (4字节)，右指针向左移 1 个 int (4字节)
        left++;
        right--;
    }
}

// 辅助打印函数：演示纯指针移动遍历
void print_array_ptr(const int *arr, int size, const char *label)
{
    printf("   %s: [ ", label);
    // 使用指针变量 p 自增进行高效遍历（无需每次通过下标做乘法偏移）
    for (const int *p = arr; p < arr + size; p++)
    {
        printf("%d%s", *p, (p == arr + size - 1) ? "" : ", ");
    }
    printf(" ]\n");
}
