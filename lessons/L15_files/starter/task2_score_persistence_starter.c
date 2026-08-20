/*
 * 任务 2 起步模板：结构体成绩数据持久化读写
 * 对应课件: 第15讲 PPT 第12, 13, 17页【fprintf 与 fscanf】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 使用 fprintf 将学生数据写入 score.txt
 * 2. 使用 fscanf 将数据重新读入并在屏幕输出
 */

#include <stdio.h>

struct Student {
    int id;
    char name[20];
    float score;
};

int main(void)
{
    struct Student list[2] = {
        {101, "张三", 89.5f},
        {102, "李四", 93.0f}
    };

    // TODO 1: 写入文件
    FILE *fp_w = fopen("score.txt", "w");
    if (fp_w != NULL) {
        for (int i = 0; i < 2; i++) {
            fprintf(fp_w, "%d %s %.1f\n", list[i].id, list[i].name, list[i].score);
        }
        fclose(fp_w);
    }

    // TODO 2: 读取并打印
    FILE *fp_r = fopen("score.txt", "r");
    if (fp_r != NULL) {
        struct Student stu;
        printf("从文件读回数据:\n");
        while (fscanf(fp_r, "%d %s %f", &stu.id, stu.name, &stu.score) == 3) {
            printf("学号: %d, 姓名: %s, 成绩: %.1f\n", stu.id, stu.name, stu.score);
        }
        fclose(fp_r);
    }
    return 0;
}
