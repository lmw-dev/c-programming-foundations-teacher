/*
 * 任务 1 起步模板：结构体定义、嵌套与赋值
 * 对应课件: 第14讲 PPT 第4, 5, 6, 7页【结构体基础与嵌套】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 定义 struct Date 和 struct Student
 * 2. 实例化并用 strcpy 赋值姓名
 */

#include <stdio.h>
#include <string.h>

struct Date {
    int year;
    int month;
    int day;
};

struct Student {
    int id;
    char name[20];
    struct Date birthday;
    float score;
};

int main(void)
{
    // TODO 1: 实例化结构体变量
    struct Student stu1;
    stu1.id = 101;
    strcpy(stu1.name, "张三");
    stu1.birthday.year = 2006;
    stu1.birthday.month = 5;
    stu1.birthday.day = 12;
    stu1.score = 88.5f;

    // TODO 2: 打印输出验证
    printf("学号: %d, 姓名: %s, 成绩: %.1f, 出生年份: %d\n",
           stu1.id, stu1.name, stu1.score, stu1.birthday.year);

    return 0;
}
