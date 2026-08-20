/*
 * 任务 2 起步模板：三数升序排序器 sort3
 * 对应课件: 第12讲 PPT 第18页【三数指针排序】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 编写 void sort3(int *p1, int *p2, int *p3)
 * 2. 依次比较并交换 (*p1, *p2), (*p1, *p3), (*p2, *p3)，使 *p1 <= *p2 <= *p3
 */

#include <stdio.h>

void swap(int *p1, int *p2);
void sort3(int *p1, int *p2, int *p3);

int main(void)
{
    int x = 15, y = 5, z = 8;
    printf("排序前: %d, %d, %d\n", x, y, z);

    // TODO 1: 传入三个变量的地址进行升序排序
    sort3(&x, &y, &z);

    printf("排序后: %d, %d, %d (升序)\n", x, y, z);
    return 0;
}

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sort3(int *p1, int *p2, int *p3)
{
    // TODO 2: 顺序比较并对调
    if (*p1 > *p2) swap(p1, p2);
    if (*p1 > *p3) swap(p1, p3);
    if (*p2 > *p3) swap(p2, p3);
}
