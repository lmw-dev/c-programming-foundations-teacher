/*
 * 文件名: 7.2_grade_master.c
 * 对应课件: 第07讲 PPT 第10~12, 16页【实践工坊：班级期末成绩大满贯 & 起泡排序】
 * 对应教材: 谭浩强版《C程序设计》第6章 例6.3 + 何钦铭版《C语言程序设计》第5章 例5.3
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 掌握一维数组批量数据录入与防御性输入过滤
 * 2. 掌握打擂台算法：在遍历中同步更新最高分/最低分及其对应的学号门牌号 (max_index/min_index)
 * 3. 掌握升序起泡排序（Bubble Sort）双重循环物理时序与相邻两两三步易位交换
 */

#include <stdio.h>

#define STUDENT_COUNT 10  // 符号常量：班级学生总人数

int main(void)
{
    printf("====================================================\n");
    printf("     教务成绩大满贯 —— 统计、打擂台与起泡排序实战     \n");
    printf("====================================================\n\n");

    int score[STUDENT_COUNT];
    int sum = 0;

    // 1. 批量输入 10 位学生的期末考试成绩 (含防御性校验)
    printf("👉 请依次输入 %d 位同学的期末成绩 (0-100分):\n", STUDENT_COUNT);
    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        while (1)
        {
            printf("  学生 [%2d 号]: ", i + 1);
            if (scanf("%d", &score[i]) != 1) {
                // 清理输入流
                while (getchar() != '\n');
                printf("  ⚠️ [错误] 请输入有效整数成绩！\n");
                continue;
            }

            // 防御性拦截: 成绩必须在 0 到 100 之间
            if (score[i] >= 0 && score[i] <= 100)
            {
                break;  // 输入有效，退出重试循环
            }
            printf("  ⚠️ [警告] 成绩超出 0~100 范围，请重新输入！\n");
        }
        sum += score[i];
    }

    // 2. 计算平均分 (强制类型转换保证浮点精度)
    float average = (float)sum / (float)STUDENT_COUNT;

    // =========================================================================
    // 【核心算法一：打擂台求最值与学号下标同步更新】
    // 
    // 物理思想:
    // 1. 先请 0 号学生当擂主 (max_score = score[0], min_score = score[0])；
    // 2. 其余学生 (1 ~ 9 号) 依次上台挑战；
    // 3. ⚠️ 关键操作: 一旦发生擂主易主，必须同步更新学号下标 (max_index = i)！
    //    这是数据库主键定位与多属性数据关联的底层核心思维。
    // =========================================================================
    int max_score = score[0];
    int min_score = score[0];
    int max_index = 0;  // 记录最高分学生的数组下标
    int min_index = 0;  // 记录最低分学生的数组下标

    for (int i = 1; i < STUDENT_COUNT; i++)
    {
        if (score[i] > max_score)
        {
            max_score = score[i];
            max_index = i;  // 同步记录新黑马的门牌号
        }

        if (score[i] < min_score)
        {
            min_score = score[i];
            min_index = i;  // 同步记录最低分的门牌号
        }
    }

    printf("\n==================== 统计分析报告 ====================\n");
    printf("  班级总分 (Sum)       : %d 分\n", sum);
    printf("  班级平均分 (Average) : %.2f 分\n", average);
    printf("  全班最高分 (Max)     : %d 分 (由 %d 号同学斩获, 数组下标 [%d])\n", 
           max_score, max_index + 1, max_index);
    printf("  全班最低分 (Min)     : %d 分 (由 %d 号同学获得, 数组下标 [%d])\n", 
           min_score, min_index + 1, min_index);

    // =========================================================================
    // 【核心算法二：升序起泡排序 (Bubble Sort)】
    // 
    // 物理重力模型解析:
    // 1. 外层循环 i 控制“趟数”：n 个数最多只需排 n-1 趟 (i 从 0 到 n-2)；
    // 2. 内层循环 j 控制“相邻两两比对与调换”：
    //    每走完一趟，数组最右端就有一个“大泡泡”安全着陆，因此比较边界递减为 0 ~ n-1-i；
    // 3. 三步易位交换: temp = a; a = b; b = temp;
    // =========================================================================
    for (int i = 0; i < STUDENT_COUNT - 1; i++)  // 外层控制 9 趟
    {
        for (int j = 0; j < STUDENT_COUNT - 1 - i; j++)  // 内层随趟数收缩比对范围
        {
            // 若左边元素大于右边相邻元素，则发生对调（大数下沉）
            if (score[j] > score[j + 1])
            {
                int temp = score[j];
                score[j] = score[j + 1];
                score[j + 1] = temp;
            }
        }
    }

    printf("\n------------------------------------------------------\n");
    printf("📊 升序起泡排序完成 (由低到高成绩排名):\n  ");
    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        printf("%d", score[i]);
        if (i < STUDENT_COUNT - 1)
        {
            printf(" <= ");
        }
    }
    printf("\n====================================================\n");

    return 0;
}
