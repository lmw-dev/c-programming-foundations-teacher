/*
 * 练习题：函数定义、声明与作用域排雷改错实战
 * 对应课件: 第10讲 PPT 第6, 11, 16页【代码诊所：函数四大经典翻车漏洞】
 * 
 * 题目要求:
 * 观察并修复下方代码中的 4 处经典函数与作用域漏洞：
 * 漏洞 1: 函数原型声明漏写分号，或函数定义首部误加分号
 * 漏洞 2: 形参列表缺少明确的数据类型标注
 * 漏洞 3: 非 void 函数在 else 分支漏写 return 导致返回未定义垃圾值
 * 漏洞 4: 函数定义返回值类型与实际计算精度不匹配导致精度被截断
 */

#include <stdio.h>

// 修复点 1: 函数原型声明末尾必须加分号
double compute_average(double a, double b);

// 修复点 2: 每个形参都必须明确写出数据类型 int
int multiply(int x, int y);

int main(void)
{
    printf("=== 函数模块化排雷与修复 ===\n");

    double avg = compute_average(10.5, 20.0);
    printf("修复1: compute_average 结果: %.2f\n", avg);

    int prod = multiply(6, 7);
    printf("修复2: multiply 结果: %d\n", prod);

    return 0;
}

// 修复点 3: 函数定义首部末尾绝不能有分号，大括号内所有分支都必须有明确 return
double compute_average(double a, double b)
{
    return (a + b) / 2.0;
}

// 修复点 4: 修复形参类型与完整返回值
int multiply(int x, int y)
{
    return x * y;
}
