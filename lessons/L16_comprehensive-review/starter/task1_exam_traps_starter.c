/*
 * 任务 1 起步模板：五大高频考点排雷大找茬
 * 对应课件: 第16讲 PPT 第3, 4, 8, 14, 17页【考点排雷】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 */

#include <stdio.h>

#define SQUARE(x) ((x) * (x))

int main(void)
{
    // TODO 1: 补码溢出测试
    short a = 32767;
    short a_next = a + 1;
    printf("short 32767 + 1 = %d\n", a_next);

    // TODO 2: 逻辑短路测试
    int i = 0, j = 0, k = 0;
    int res = (i++ || ++j) && ++k;
    printf("i=%d, j=%d, k=%d, res=%d\n", i, j, k, res);

    // TODO 3: 指针自增时序
    int arr[] = {10, 20, 30};
    int *p = arr;
    printf("*p++ = %d\n", *p++);
    printf("(*p)++ = %d\n", (*p)++);

    // TODO 4: 宏展开
    printf("SQUARE(2+3) = %d\n", SQUARE(2 + 3));

    return 0;
}
