/*
 * 任务 1 起步模板：指针重写 swap 函数
 * 对应课件: 第12讲 PPT 第14, 18页【指针 swap】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 声明并实现 void swap(int *p1, int *p2)
 * 2. 在 main 中传递 &a 和 &b
 * 3. 验证 a 和 b 成功完成物理对换
 */

#include <stdio.h>

void swap(int *p1, int *p2);

int main(void)
{
    int a = 5, b = 10;
    printf("交换前: a = %d, b = %d\n", a, b);

    // TODO 1: 传入 a 和 b 的地址
    swap(&a, &b);

    printf("交换后: a = %d, b = %d\n", a, b);
    return 0;
}

void swap(int *p1, int *p2)
{
    // TODO 2: 通过 * 解引用完成值交换
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
