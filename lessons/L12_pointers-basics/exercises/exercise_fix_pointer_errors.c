/*
 * 练习题：指针定义、多函数协作与解引用排雷改错实战
 * 对应课件: 第12讲 PPT 第9, 14, 15页【代码诊所：指针三大致命翻车地雷】
 * 
 * 题目要求:
 * 观察并修复下方代码中的 4 处经典指针漏洞：
 * 漏洞 1: 指针未初始化即强行解引用写值（野指针非法越界）
 * 漏洞 2: 调用指针传参函数时实参漏写取地址符 &
 * 漏洞 3: 子函数中仅交换了形参指针自身的地址值，未曾进行 * 解引用操作
 * 漏洞 4: 自增运算符优先级混淆导致指针发生意外偏移
 */

#include <stdio.h>

// 修复点 1: 正确声明指针函数
void correct_swap(int *p1, int *p2);
void double_value(int *p);

int main(void)
{
    printf("=== 指针基础与多函数协作排雷修复 ===\n");

    // 修复点 2: 保证指针先指向合法变量再解引用
    int value = 10;
    int *ptr = &value;
    *ptr = 20;
    printf("修复1: 目标变量合法赋值: %d (预期 20)\n", value);

    // 修复点 3: 实参必须加 & 传递地址
    int num = 50;
    double_value(&num);
    printf("修复2: double_value 翻倍结果: %d (预期 100)\n", num);

    // 修复点 4: 正确调用 swap 交换
    int a = 3, b = 7;
    correct_swap(&a, &b);
    printf("修复3: correct_swap 交换结果: a = %d, b = %d (预期 a=7, b=3)\n", a, b);

    return 0;
}

void double_value(int *p)
{
    if (p != NULL)
    {
        // 修复点 5: 使用 (*p) *= 2 避免优先级歧义
        (*p) *= 2;
    }
}

void correct_swap(int *p1, int *p2)
{
    if (p1 != NULL && p2 != NULL)
    {
        // 必须通过 * 解引用交换主函数中的变量内容
        int temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }
}
