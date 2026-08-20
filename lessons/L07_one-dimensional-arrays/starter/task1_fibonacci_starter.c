/*
 * 任务 1 起步模板：斐波那契数列生成器 (数组递推)
 * 对应课件: 第07讲 PPT 第9页【经典算法一】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 声明长度为 20 的整型数组 f
 * 2. 初始化 f[0]=1, f[1]=1
 * 3. 递推计算：f[i] = f[i-1] + f[i-2]
 * 4. 格式化输出：每 5 个数一行
 */

#include <stdio.h>

int main(void)
{
    // TODO 1: 声明数组并初始化前两项
    int f[20] = {1, 1};

    // TODO 2: 递推计算第 3 项到第 20 项 (下标 2 到 19)
    for (int i = 2; i < 20; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    // TODO 3: 格式化输出 (每行 5 个)
    printf("斐波那契数列前 20 项:\n");
    for (int i = 0; i < 20; i++) {
        printf("%10d\t", f[i]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }

    return 0;
}
