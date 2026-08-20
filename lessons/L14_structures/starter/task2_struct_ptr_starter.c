/*
 * 任务 2 起步模板：结构体指针与指向运算符 ->
 * 对应课件: 第14讲 PPT 第11, 12, 13页【结构体指针】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 使用 struct Student *p 指向结构变量
 * 2. 使用 p->name 和 p->score 输出成员
 */

#include <stdio.h>

struct Student {
    int id;
    char name[20];
    float score;
};

void show_student(const struct Student *p);

int main(void)
{
    struct Student stu = {102, "李四", 95.0f};

    // TODO 1: 传入结构体地址调用函数
    show_student(&stu);

    return 0;
}

void show_student(const struct Student *p)
{
    if (p == NULL) return;

    // TODO 2: 使用指向符 -> 访问成员
    printf("学号: %d, 姓名: %s, 成绩: %.1f\n", p->id, p->name, p->score);
}
