/*
 * 任务 3 起步模板：学生总分计算与降序起泡排序
 * 对应课件: 第14讲 PPT 第17, 18页【结构体数组排序】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 编写 calc_sum 计算学生总分
 * 2. 编写 sort_students 进行降序起泡排序（整包置换）
 */

#include <stdio.h>

struct Student {
    int id;
    char name[20];
    float grades[3];
    float sum;
};

void calc_sum(struct Student arr[], int size);
void sort_students(struct Student arr[], int size);

int main(void)
{
    struct Student data[3] = {
        {101, "张三", {80.0f, 85.0f, 90.0f}, 0.0f},
        {102, "李四", {95.0f, 90.0f, 92.0f}, 0.0f},
        {103, "王五", {70.0f, 75.0f, 80.0f}, 0.0f}
    };

    calc_sum(data, 3);
    sort_students(data, 3);

    printf("排序后总榜:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d %s %.1f\n", data[i].id, data[i].name, data[i].sum);
    }
    return 0;
}

void calc_sum(struct Student arr[], int size)
{
    if (arr == NULL || size <= 0) return;
    for (int i = 0; i < size; i++) {
        arr[i].sum = arr[i].grades[0] + arr[i].grades[1] + arr[i].grades[2];
    }
}

void sort_students(struct Student arr[], int size)
{
    if (arr == NULL || size <= 0) return;
    // TODO: 降序起泡排序与整包置换
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j].sum < arr[j + 1].sum) {
                struct Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
