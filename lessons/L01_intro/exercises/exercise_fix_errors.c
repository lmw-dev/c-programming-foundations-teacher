/*
 * 练习题：找出并修改以下程序中的 3 处语法错误
 * 对应课件: 第01讲 PPT 第11页【常见错误初步辨析】 & 专升本改错题型训练
 * 
 * 题目要求:
 * 请找出并修复下面程序中的 3 处错误，使其能够顺利编译并通过屏幕输出两行内容：
 * 第一行：Hello, C Programming!
 * 第二行：Welcome to our class!
 */

// 提示：检查此处引入库的拼写
#include <stdio.h>

// 提示：检查主函数名称拼写
int main(void)
{
    // 错误 1 提示：检查字符串右侧是否缺少分号，或存在中文字符
    printf("Hello, C Programming!\n");

    // 错误 2 提示：检查转义换行符斜杠方向是否正确
    printf("Welcome to our class!\n");

    return 0;
}
