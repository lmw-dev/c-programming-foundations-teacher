/*
 * 任务 3 起步模板：static 变量状态追踪
 * 对应课件: 第11讲 PPT 第10, 19页【static 状态保留】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 在 monitor_step() 中声明 static int step = 0
 * 2. 连续调用时 step 成功累加保留
 */

#include <stdio.h>

void monitor_step(const char *action)
{
    // TODO: 使用 static 修饰 step 变量
    static int step = 0;
    step++;
    printf("步骤 #%d: 执行操作 [%s]\n", step, action);
}

int main(void)
{
    monitor_step("初始化硬件");
    monitor_step("加载配置");
    monitor_step("启动监听服务");
    return 0;
}
