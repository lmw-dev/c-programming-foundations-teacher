/*
 * 文件名: 14.3_student_sorter.c
 * 对应课件: 第14讲 PPT 第9, 10, 17, 18页【结构体数组、降序起泡排序与整包置换铁律】
 * 对应教材: 谭浩强版《C程序设计》第9章 9.2.2 + 何钦铭版《C语言程序设计》第7章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 熟练掌握结构体数组批量管理多条记录：struct Student stud[5]
 * 2. 牢记结构体数组排序的【整包置换铁律】：
 *    必须进行 struct Student temp = arr[j]; 整包置换，绝对不可只单独对调 sum 数值，
 *    彻底杜绝“张三的名字配上李四的成绩”之张冠李戴系统灾难！
 * 3. 掌握结构体数组作为函数参数进行模块化处理（总分累加计算与起泡排序）
 */

#include <stdio.h>

#define STUDENT_COUNT 5
#define SUBJECT_COUNT 3

// 定义学生完整档案结构体
struct Student {
    int id;                      // 学号
    char name[20];               // 姓名
    float grades[SUBJECT_COUNT]; // 三科成绩：[0]数学, [1]英语, [2]C语言
    float sum;                   // 总分
};

// 函数原型声明
void calc_sum(struct Student arr[], int size);
void sort_students(struct Student arr[], int size);
void print_leaderboard(const struct Student arr[], int size);

int main(void)
{
    printf("======================================================================\n");
    printf("    极客班级成绩管理系统 —— 结构体数组批量降序起泡排序与整包置换        \n");
    printf("======================================================================\n\n");

    // 初始化 5 名学生的多科成绩档案
    struct Student students[STUDENT_COUNT] = {
        {101, "张三", {85.0f, 78.0f, 92.0f}, 0.0f},
        {102, "李四", {90.0f, 95.0f, 92.0f}, 0.0f},
        {103, "王五", {76.0f, 65.0f, 80.0f}, 0.0f},
        {104, "赵六", {88.0f, 92.0f, 96.0f}, 0.0f},
        {105, "孙七", {60.0f, 70.0f, 68.0f}, 0.0f}
    };

    // 1. 计算每位学生的总分
    calc_sum(students, STUDENT_COUNT);

    // 2. 使用起泡排序按总分进行降序排序 (从高到低)
    sort_students(students, STUDENT_COUNT);

    // 3. 规范打印成绩总榜
    print_leaderboard(students, STUDENT_COUNT);

    printf("\n============================ 教学原理解析 ============================\n");
    printf("💡 为什么结构体排序能够确保“人分一致”？\n");
    printf("   因为在起泡排序做对调时，我们执行了 struct Student temp = arr[j]; \n");
    printf("   整只结构体收纳盒一并移动，学号、姓名、各科成绩在物理上同生共死，永不错位！\n");
    printf("======================================================================\n");

    return 0;
}

// 模块 1：计算每位学生的三科总分
void calc_sum(struct Student arr[], int size)
{
    if (arr == NULL || size <= 0) return;

    for (int i = 0; i < size; i++)
    {
        arr[i].sum = 0.0f;
        for (int j = 0; j < SUBJECT_COUNT; j++)
        {
            arr[i].sum += arr[i].grades[j];
        }
    }
}

// 模块 2：起泡排序（按总分从高到低降序排列）
void sort_students(struct Student arr[], int size)
{
    if (arr == NULL || size <= 0) return;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            // 若前一个学生的总分小于后一个学生，则进行整包置换（降序）
            if (arr[j].sum < arr[j + 1].sum)
            {
                // 🚨 黄金安全铁律：必须整包置换结构体变量！
                struct Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 模块 3：格式化打印成绩排行榜
void print_leaderboard(const struct Student arr[], int size)
{
    if (arr == NULL || size <= 0) return;

    printf("======================================================================\n");
    printf("名次\t学号\t姓名\t数学\t英语\tC语言\t总分\n");
    printf("======================================================================\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.2f\n",
               i + 1,
               arr[i].id,
               arr[i].name,
               arr[i].grades[0],
               arr[i].grades[1],
               arr[i].grades[2],
               arr[i].sum);
    }
    printf("======================================================================\n");
}
