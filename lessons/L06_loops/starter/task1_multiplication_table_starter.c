/*
 * 任务 1 起步模板：九九乘法表
 * 对应课件: 第06讲 PPT 第9~10页【何版经典案例】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 使用双重 for 循环输出九九乘法表
 * 2. 外层 i 控制行 (1~9)，内层 j 控制列 (1~i)
 * 3. 每一项使用 printf("%d*%d=%-2d\t", j, i, j*i) 保持对齐
 */

#include <stdio.h>

int main(void)
{
    // TODO 1: 外层循环控制行号 i (从 1 到 9)
    for (int i = 1; i <= 9; i++) {
        // TODO 2: 内层循环控制列号 j (从 1 到 i)
        for (int j = 1; j <= i; j++) {
            printf("%d*%d=%-2d\t", j, i, j * i);
        }
        // TODO 3: 每行结束后换行
        printf("\n");
    }

    return 0;
}
