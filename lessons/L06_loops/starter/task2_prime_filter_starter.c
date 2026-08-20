/*
 * 任务 2 起步模板：100 以内素数过滤器 (含 sqrt 优化)
 * 对应课件: 第06讲 PPT 第16~17页【当堂任务】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 遍历 2 到 100 的所有整数
 * 2. 引入 <math.h>，内层试除到 sqrt(num) 即可
 * 3. 遇到整除时，标志位设 0 并立刻 break
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("100 以内的素数有:\n");

    // TODO 1: 外层遍历 2 到 100
    for (int num = 2; num <= 100; num++) {
        int is_prime = 1;
        int limit = (int)sqrt(num);

        // TODO 2: 内层试除 2 到 limit
        for (int i = 2; i <= limit; i++) {
            if (num % i == 0) {
                is_prime = 0;
                break; // 提前刹车
            }
        }

        // TODO 3: 检查标志位并输出
        if (is_prime) {
            printf("%d ", num);
        }
    }

    printf("\n");
    return 0;
}
