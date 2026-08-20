/*
 * 任务 3 起步模板：双指针向心逼近回文判定
 * 对应课件: 第08讲 PPT 第17~18页【阶段综合案例】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 读入字符串并计算长度
 * 2. 使用首尾双指针 left 和 right 向中间逼近
 * 3. 若全流程对齐则为回文，若遇不符则立即 break
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];
    printf("请输入单词: ");
    if (scanf("%99s", str) != 1) return 1;

    int len = strlen(str);
    int is_pal = 1;

    // TODO 1: 首尾双指针初始化
    int left = 0;
    int right = len - 1;

    // TODO 2: 向心逼近比较
    while (left < right) {
        if (str[left] != str[right]) {
            is_pal = 0;
            break;
        }
        left++;
        right--;
    }

    if (is_pal) {
        printf("\"%s\" 是回文字符串！\n", str);
    } else {
        printf("\"%s\" 不是回文字符串。\n", str);
    }

    return 0;
}
