/*
 * 任务 3 起步模板：升序起泡排序 (Bubble Sort)
 * 对应课件: 第07讲 PPT 第11~12页【起泡排序】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 掌握起泡排序的双重循环控制：外层控制趟数 (n-1)，内层控制相邻比对 (n-1-i)
 * 2. 实现相邻两两比较与三步易位交换
 * 3. 打印升序排序后的结果
 */

#include <stdio.h>

int main(void)
{
    int a[10] = {87, 45, 99, 62, 73, 55, 90, 81, 68, 77};

    printf("排序前数组:\n");
    for (int i = 0; i < 10; i++) printf("%d ", a[i]);
    printf("\n");

    // TODO 1: 外层循环控制趟数 (共 9 趟)
    for (int i = 0; i < 9; i++) {
        // TODO 2: 内层循环控制相邻比对 (范围随趟数递减)
        for (int j = 0; j < 9 - i; j++) {
            // TODO 3: 相邻比对与三步交换
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("升序排序后数组:\n");
    for (int i = 0; i < 10; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
