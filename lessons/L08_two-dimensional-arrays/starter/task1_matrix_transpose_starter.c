/*
 * 任务 1 起步模板：矩阵转置算法
 * 对应课件: 第08讲 PPT 第8页【经典算法实战一】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 将 2x3 的矩阵 a 转置为 3x2 的矩阵 b
 * 2. 核心公式: b[j][i] = a[i][j]
 * 3. 打印转置后的矩阵网格
 */

#include <stdio.h>

int main(void)
{
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int b[3][2];

    // TODO 1: 双重循环完成矩阵转置 (外层遍历 a 的行 0~1，内层遍历 a 的列 0~2)
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            b[j][i] = a[i][j];
        }
    }

    // TODO 2: 网格输出转置后的 3x2 矩阵 b
    printf("转置后的 3x2 矩阵 b:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%4d ", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
