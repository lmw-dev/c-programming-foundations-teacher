/*
 * 任务 2 起步模板：成绩大满贯与打擂台求最值
 * 对应课件: 第07讲 PPT 第10, 16页【打擂台算法】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 录入 10 位学生的成绩并求总分和平均分
 * 2. 使用打擂台算法找出最高分、最低分及其学号下标
 * 3. 打印详细的统计报告
 */

#include <stdio.h>

int main(void)
{
    int score[10];
    int sum = 0;

    printf("请输入 10 位同学的成绩:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &score[i]);
        sum += score[i];
    }

    float avg = (float)sum / 10.0f;

    // TODO 1: 擂台变量初始化 (先请 0 号学生当擂主)
    int max = score[0], min = score[0];
    int max_idx = 0, min_idx = 0;

    // TODO 2: 循环挑战与同步更新下标
    for (int i = 1; i < 10; i++) {
        if (score[i] > max) {
            max = score[i];
            max_idx = i;
        }
        if (score[i] < min) {
            min = score[i];
            min_idx = i;
        }
    }

    printf("平均分: %.2f\n", avg);
    printf("最高分: %d (下标 %d)\n", max, max_idx);
    printf("最低分: %d (下标 %d)\n", min, min_idx);

    return 0;
}
