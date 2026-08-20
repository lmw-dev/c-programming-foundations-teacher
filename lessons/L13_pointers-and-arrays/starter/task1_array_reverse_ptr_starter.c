/*
 * 任务 1 起步模板：双指针向心原地逆序
 * 对应课件: 第13讲 PPT 第16页【双指针对碰逆序】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 编写 void reverse_array_ptr(int *arr, int size)
 * 2. 使用 left 和 right 两个指针在 while(left < right) 条件下对调元素
 */

#include <stdio.h>

void reverse_array_ptr(int *arr, int size);

int main(void)
{
    int data[6] = {10, 20, 30, 40, 50, 60};

    // TODO 1: 调用纯指针逆序函数
    reverse_array_ptr(data, 6);

    printf("逆序结果: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}

void reverse_array_ptr(int *arr, int size)
{
    if (arr == NULL || size <= 0) return;

    int *left = arr;
    int *right = arr + size - 1;

    // TODO 2: 双指针向心对碰交换
    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}
