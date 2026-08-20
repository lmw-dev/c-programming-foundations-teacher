/*
 * 任务 1 起步模板：字符串长度与安全复制
 * 对应课件: 第09讲 PPT 第13~14页【strlen vs sizeof & 复制】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 比较 strlen 与 sizeof 的输出差异
 * 2. 手写循环实现字符复制到目标数组
 * 3. 复制完成后必须在目标数组末尾显式添加 '\0'
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[30] = "Data_Structures";
    char dest[30];

    // TODO 1: 打印 strlen(src) 和 sizeof(src)
    printf("strlen: %lu, sizeof: %lu\n", strlen(src), sizeof(src));

    // TODO 2: 手写循环复制字符
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    // TODO 3: 显式添加字符串结束标志 '\0'
    dest[i] = '\0';

    printf("dest 内容: \"%s\"\n", dest);
    return 0;
}
