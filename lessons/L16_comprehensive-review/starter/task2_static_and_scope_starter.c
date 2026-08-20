/*
 * 任务 2 起步模板：作用域与 static 变量生命期
 * 对应课件: 第16讲 PPT 第11, 13页【static 局部变量】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 */

#include <stdio.h>

int x = 50; // 全局变量

void demo(void)
{
    // TODO 1: 声明同名局部变量
    int x = 10;

    // TODO 2: 声明静态局部变量
    static int count = 0;
    count++;

    printf("局部 x = %d, static count = %d\n", x, count);
}

int main(void)
{
    for (int i = 0; i < 3; i++) {
        demo();
    }
    printf("全局 x = %d\n", x);
    return 0;
}
