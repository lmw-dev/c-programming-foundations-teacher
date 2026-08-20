/*
 * 任务 2 起步模板：while 循环阶乘累加和 (1! + 2! + ... + 10!)
 * 对应课件: 第05讲 PPT 第17页【实践工坊】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 使用 while 循环实现 1! 到 10! 的累乘与累加
 * 2. 使用 long long 防止大数爆仓溢出
 * 3. 运行测试：1! 到 10! 的累加总和应为 4037913
 */

#include <stdio.h>

int main(void)
{
    // TODO 1: 循环三要素之一：起点初始化
    int i = 1;
    long long fact = 1;
    long long sum = 0;

    // TODO 2: 循环三要素之二：终点判定
    while (i <= 10) {
        fact = fact * i;   // 累乘
        sum = sum + fact;  // 累加

        // TODO 3: 循环三要素之三：步长更新 (切勿漏写!)
        i++;
    }

    printf("1! + 2! + ... + 10! = %lld\n", sum);
    return 0;
}
