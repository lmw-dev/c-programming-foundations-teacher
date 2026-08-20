/*
 * 练习题：专升本四大经典真题纠错与安全加固
 * 对应课件: 第16讲 PPT 第4, 8, 10, 15, 17页【代码诊所与升本排雷】
 * 
 * 题目要求:
 * 观察并修复下方代码中的 4 处经典考场翻车地雷：
 * 地雷 1: 带参宏定义无括号导致优先级错乱
 * 地雷 2: 试图通过字符指针修改只读常量区数据导致崩溃
 * 地雷 3: 结构体排序时只交换成绩字段导致姓名与成绩错位
 * 地雷 4: 动态内存分配后未做 NULL 检查与未释放内存泄漏
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 修复点 1: 必须给每个参数和整体套上完整括号
#define CUBE_SAFE(x) ((x) * (x) * (x))

struct Student {
    int id;
    char name[20];
    float score;
};

void safe_string_modify(void);
void safe_struct_sort(struct Student arr[], int n);

int main(void)
{
    printf("=== 专升本经典四大真题排雷修复 ===\n");

    // 1. 宏替换修复验证
    int res = CUBE_SAFE(1 + 2); // 展开为 ((1+2)*(1+2)*(1+2)) = 27
    printf("修复1: 宏计算 CUBE(1+2) = %d\n", res);

    // 2. 字符串栈区安全修改
    safe_string_modify();
    printf("修复2: 字符数组栈区安全改写成功\n");

    // 3. 结构体整包置换排序
    struct Student list[3] = {
        {101, "张三", 75.0f},
        {102, "李四", 95.0f},
        {103, "王五", 85.0f}
    };
    safe_struct_sort(list, 3);
    printf("修复3: 结构体整包置换排序完成，榜首: %s (%.1f分)\n", list[0].name, list[0].score);

    return 0;
}

void safe_string_modify(void)
{
    // 修复：使用字符数组分配在栈区，可随意修改
    char str[] = "Hello";
    str[0] = 'Y'; // "Yello"
}

void safe_struct_sort(struct Student arr[], int n)
{
    // 修复：排序时必须声明同类型的结构体变量 temp 进行【整包置换】
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].score < arr[j+1].score) {
                struct Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
