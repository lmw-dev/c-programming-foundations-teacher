/*
 * 练习题：结构体定义、成员访问与指针排雷改错实战
 * 对应课件: 第14讲 PPT 第4, 12, 16, 17页【代码诊所：结构体四大经典翻车地雷】
 * 
 * 题目要求:
 * 观察并修复下方代码中的 4 处经典结构体漏洞：
 * 漏洞 1: 结构体定义末尾漏写分号 ;
 * 漏洞 2: 结构体数组成员非法使用 = 赋值
 * 漏洞 3: 结构体普通变量与指针变量的运算符混用
 * 漏洞 4: 未初始化的结构体指针空中解引用
 */

#include <stdio.h>
#include <string.h>

// 修复点 1: 结构体模板定义末尾必须加英文分号 ;
struct Student {
    int id;
    char name[20];
    float score;
};

void show_student(const struct Student *p);

int main(void)
{
    printf("=== 结构体排雷修复实战 ===\n");

    // 修复点 2: 字符数组必须使用 strcpy 进行赋值
    struct Student stu1;
    stu1.id = 101;
    strcpy(stu1.name, "张三");
    stu1.score = 89.5f;
    printf("修复1: 学生姓名合法赋值: %s\n", stu1.name);

    // 修复点 3: 普通变量使用点运算符 .，指针变量使用箭头 ->
    struct Student *ptr = &stu1;
    printf("修复2: 通过指针箭头访问成员: 学号 %d, 分数 %.1f\n", ptr->id, ptr->score);

    // 修复点 4: 指针必须先指向合法内存再使用
    struct Student stu2 = {102, "李四", 95.0f};
    show_student(&stu2);

    return 0;
}

void show_student(const struct Student *p)
{
    if (p != NULL)
    {
        printf("修复3: 指针函数安全打印: %d %s %.1f\n", p->id, p->name, p->score);
    }
}
