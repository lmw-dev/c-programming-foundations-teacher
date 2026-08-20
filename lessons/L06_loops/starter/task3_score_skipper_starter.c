/*
 * 任务 3 起步模板：教务成绩质检系统 (break 与 continue 实战)
 * 对应课件: 第06讲 PPT 第11~15页【及格成绩过滤器】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 输入 -1 时执行 break 退出录入
 * 2. 输入异常成绩 (<0 或 >100) 时执行 continue 跳过并重新输入
 * 3. 统计有效录入总人数和及格人数 (>= 60)
 */

#include <stdio.h>

int main(void)
{
    float score = 0.0f;
    float sum = 0.0f;
    int count = 0;
    int pass = 0;

    printf("请输入成绩 (输入 -1 结束):\n");

    while (1) {
        if (scanf("%f", &score) != 1) break;

        // TODO 1: 输入 -1 时 break 退出
        if (score == -1.0f) {
            break;
        }

        // TODO 2: 异常成绩时 continue 跳过本次
        if (score < 0.0f || score > 100.0f) {
            printf("异常成绩已跳过！\n");
            continue;
        }

        // TODO 3: 累加有效成绩
        sum += score;
        count++;
        if (score >= 60.0f) pass++;
    }

    printf("有效人数: %d, 及格人数: %d\n", count, pass);
    return 0;
}
