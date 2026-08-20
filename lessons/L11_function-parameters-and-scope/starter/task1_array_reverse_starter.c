/*
 * 任务 1 起步模板：数组传参与原地逆序
 * 对应课件: 第11讲 PPT 第4, 18页【数组参数与逆序】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 声明并实现 reverse_array(int arr[], int size)
 * 2. 在函数内使用双指针进行首尾元素原地交换
 * 3. 在 main 中验证原数组已被原地修改
 */

#include <stdio.h>

void reverse_array(int arr[], int size);

int main(void)
{
    int a[5] = {10, 20, 30, 40, 50};

    // TODO 1: 传递数组名和长度进行逆序
    reverse_array(a, 5);

    // TODO 2: 打印逆序后的数组验证结果
    printf("Reversed: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void reverse_array(int arr[], int size)
{
    int left = 0;
    int right = size - 1;

    // TODO: 双指针向心对碰交换
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}
