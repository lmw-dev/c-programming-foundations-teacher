/*
 * 任务 1 起步模板：华氏温度转摄氏温度与整除避坑
 * 对应课件: 第03讲 PPT 第14~15页【案例工坊】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 补全下方的 TODO 区域，通过 scanf 读入华氏温度
 * 2. 运用公式: C = 5.0 / 9.0 * (F - 32) 计算摄氏度（避免 5/9 截断为 0）
 * 3. 编译并运行，测试输入 100°F 时输出是否为 37.78°C
 */

#include <stdio.h>

int main(void)
{
    float fahrenheit = 0.0f;
    float celsius = 0.0f;

    printf("请输入华氏温度值 (°F): ");

    // TODO 1: 使用 scanf 读取浮点数并存入 fahrenheit 的地址中 (注意加 '&')
    if (scanf("%f", &fahrenheit) == 1) {
        // TODO 2: 使用 5.0f / 9.0f 计算摄氏温度
        celsius = (5.0f / 9.0f) * (fahrenheit - 32.0f);

        // TODO 3: 格式化输出摄氏温度，保留 2 位小数
        printf("对应的摄氏温度为: %.2f °C\n", celsius);
    }

    return 0;
}
