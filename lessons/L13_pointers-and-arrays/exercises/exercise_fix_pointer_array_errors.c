/*
 * 练习题：指针与数组、字符串排雷改错实战
 * 对应课件: 第13讲 PPT 第4, 11, 13, 14页【代码诊所：指针与数组四大经典翻车地雷】
 * 
 * 题目要求:
 * 观察并修复下方代码中的 4 处经典指针与数组漏洞：
 * 漏洞 1: 数组名是地址常量，非法执行 a++
 * 漏洞 2: 未分配栈空间的字符指针直接传入 scanf 导致系统崩溃
 * 漏洞 3: 指向字符串常量的指针强行解引用改写（常量区写保护崩溃）
 * 漏洞 4: 行指针声明漏加圆括号误写为指针数组
 */

#include <stdio.h>

void print_matrix_first_row(int (*row_ptr)[3]);

int main(void)
{
    printf("=== 指针与数组排雷修复实战 ===\n");

    // 修复点 1: 数组名不可自增，应使用辅助指针变量 p 进行移动
    int arr[3] = {10, 20, 30};
    int *p = arr;
    printf("修复1: 移动指针访问元素: %d\n", *(p + 1));

    // 修复点 2: 字符指针必须指向明确的栈空间再进行输入
    char input_buf[64] = "Hello Safe World";
    char *str_ptr = input_buf;
    printf("修复2: 安全字符缓冲区内容: %s\n", str_ptr);

    // 修复点 3: 栈区字符数组才具备可读写权限
    char mutable_str[] = "China";
    mutable_str[0] = 'c';
    printf("修复3: 栈区修改后的字符串: %s\n", mutable_str);

    // 修复点 4: 二维数组行指针必须带圆括号 (*row_ptr)[3]
    int mat[2][3] = {{100, 200, 300}, {400, 500, 600}};
    print_matrix_first_row(mat);

    return 0;
}

void print_matrix_first_row(int (*row_ptr)[3])
{
    printf("修复4: 行指针打印首行: %d, %d, %d\n", (*row_ptr)[0], (*row_ptr)[1], (*row_ptr)[2]);
}
