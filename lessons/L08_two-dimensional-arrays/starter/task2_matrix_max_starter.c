/*
 * 任务 2 起步模板：二维矩阵打擂台求最值与坐标锁定
 * 对应课件: 第08讲 PPT 第9~10页【经典算法实战二】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 遍历 3x4 矩阵求最大值
 * 2. 初始擂主设为 a[0][0]
 * 3. 挑战成功时同步记录 row 与 col 下标
 */

#include <stdio.h>

int main(void)
{
    int a[3][4] = {
        { 5, 12, 23, 56},
        {19, 28, 37, 46},
        {-12, -34, 6,  8}
    };

    // TODO 1: 擂主初始化
    int max = a[0][0];
    int max_row = 0;
    int max_col = 0;

    // TODO 2: 双重循环遍历挑战
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    printf("最大值: %d, 位于 matrix[%d][%d] (第 %d 行, 第 %d 列)\n",
           max, max_row, max_col, max_row + 1, max_col + 1);

    return 0;
}
