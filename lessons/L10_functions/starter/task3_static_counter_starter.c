/*
 * 任务 3 起步模板：static 静态局部变量计数器
 * 对应课件: 第10讲 PPT 第14页【静态局部变量】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 在 count_invocations() 中使用 static int count = 0
 * 2. 观察多次调用时 count 的保留累加行为
 */

#include <stdio.h>

void count_invocations(void)
{
    // TODO: 声明 static 变量，使其保留调用历史
    static int count = 0;
    count++;
    printf("函数被调用第 %d 次\n", count);
}

int main(void)
{
    for (int i = 0; i < 3; i++) {
        count_invocations();
    }
    return 0;
}
