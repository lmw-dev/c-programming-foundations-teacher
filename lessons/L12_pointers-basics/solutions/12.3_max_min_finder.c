/*
 * 文件名: 12.3_max_min_finder.c
 * 对应课件: 第12讲 PPT 第16, 17页【指针多值带回黄金三步法 & 班级极值统计器】
 * 对应教材: 谭浩强版《C程序设计》第8章 8.2 + 何钦铭版《C语言程序设计》第8章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 突破 C 语言函数 return 只能返回单个数据的语法限制，掌握利用指针参数“多值带回”的设计模式
 * 2. 掌握工业级防御性编程：入参空指针检查 (scores, out_max, out_min) 与数组越界保护
 * 3. 深刻领会指针多值带回“黄金三步法则”：
 *    - 第 1 步：主调函数将接收变量的地址 (&max, &min) 传给函数
 *    - 第 2 步：子函数使用对应类型的指针形参 (int *out_max, int *out_min) 接收地址
 *    - 第 3 步：子函数通过 * 解引用将计算结果直接写回主调函数中的变量
 */

#include <stdio.h>

#define CLASS_SIZE 10

// 核心函数原型声明
void find_max_min(const int scores[], int size, int *out_max, int *out_min);

int main(void)
{
    printf("======================================================================\n");
    printf("     教务分析系统实战 —— 利用指针突破 return 限制实现多值带回           \n");
    printf("======================================================================\n\n");

    int class_grades[CLASS_SIZE] = {89, 92, 76, 54, 98, 45, 88, 100, 67, 83};

    // 声明用于接收多值返回结果的局部变量（无需赋予初值，由子函数负责写回）
    int max_score = 0;
    int min_score = 0;

    printf("1. 【原始班级成绩序列】: ");
    for (int i = 0; i < CLASS_SIZE; i++)
    {
        printf("%d%s", class_grades[i], (i == CLASS_SIZE - 1) ? "" : ", ");
    }
    printf("\n\n");

    // 【黄金第 1 步】：传递数组与待接收变量的地址 (&max_score, &min_score)
    printf("2. 【调用 find_max_min，传递 &max_score 和 &min_score 钥匙】...\n");
    find_max_min(class_grades, CLASS_SIZE, &max_score, &min_score);

    // 3. 验证主函数变量是否已成功接收子函数写回的数据
    printf("3. 【多值带回分析报告】:\n");
    printf("   🏆 全班最高分: %d 分 (通过 *out_max 成功带回)\n", max_score);
    printf("   📉 全班最低分: %d 分 (通过 *out_min 成功带回)\n", min_score);

    printf("\n======================================================================\n");
    return 0;
}

// =============================================================================
// 【核心函数：同时统计最大值与最小值】
// 【黄金第 2 步】：形参使用指针 int *out_max 和 int *out_min 接收钥匙
// =============================================================================
void find_max_min(const int scores[], int size, int *out_max, int *out_min)
{
    // 🛡️ 工业级防御性安全检查：拦截空指针与非法尺寸，杜绝野针与段错误
    if (scores == NULL || out_max == NULL || out_min == NULL || size <= 0)
    {
        printf("⚠️ [错误拦截] 检测到非法参数或空指针 (NULL)，中止计算！\n");
        return;
    }

    int current_max = scores[0];
    int current_min = scores[0];

    // 打擂台算法：线性遍历 O(N) 搜寻最高分与最低分
    for (int i = 1; i < size; i++)
    {
        if (scores[i] > current_max)
        {
            current_max = scores[i];
        }
        if (scores[i] < current_min)
        {
            current_min = scores[i];
        }
    }

    // 【黄金第 3 步】：通过 * 解引用将计算结果隔空写回主调函数
    *out_max = current_max;
    *out_min = current_min;
}
