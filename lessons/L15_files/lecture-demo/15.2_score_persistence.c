/*
 * 文件名: 15.2_score_persistence.c
 * 对应课件: 第15讲 PPT 第12, 13, 17, 18页【格式化成绩单持久化读写与EOF安全边界】
 * 对应教材: 谭浩强版《C程序设计》第10章 10.3 + 何钦铭版《C语言程序设计》第12章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 掌握结构体数据与纯文本文件之间的格式化持久化：fprintf 与 fscanf
 * 2. 领会序列化 (Serialization: 内存->磁盘) 与反序列化 (Deserialization: 磁盘->内存) 的闭环
 * 3. 攻克 fscanf 循环读取末尾边界控制：
 *    为什么判断 fscanf(...) == 3 比盲目依赖 feof() 更加安全？
 *    因为文件末尾常留有多余的换行符或空格，fscanf == 3 能严格确保字段完整读入，杜绝重复打印最后一行
 */

#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "students.txt"
#define MAX_RECORDS 5

// 定义学生结构体
struct Student {
    int id;        // 学号
    char name[20]; // 姓名
    float score;   // 成绩
};

int main(void)
{
    printf("======================================================================\n");
    printf("    数据持久化封印与还原 —— 结构体数据 fprintf/fscanf 磁盘序列化实战   \n");
    printf("======================================================================\n\n");

    // =========================================================================
    // 【阶段 A：序列化 (Serialization: 内存数据 -> 磁盘文本)】
    // =========================================================================
    struct Student initial_students[3] = {
        {1001, "张三", 88.50f},
        {1002, "李四", 95.00f},
        {1003, "王五", 76.50f}
    };

    printf("1. 【阶段 A：正在将内存中的结构体数据序列化保存到 %s】...\n", FILE_PATH);
    FILE *fp_write = fopen(FILE_PATH, "w");
    if (fp_write == NULL)
    {
        perror("🚨 打开写文件失败");
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        // 格式化输出到磁盘文件（各字段以制表符 \t 分隔）
        fprintf(fp_write, "%d\t%s\t%.2f\n", 
                initial_students[i].id, 
                initial_students[i].name, 
                initial_students[i].score);
    }
    fclose(fp_write); // 结账落盘
    printf("   ✅ 成功持久化 3 条学生记录到磁盘文件中！\n\n");

    // =========================================================================
    // 【阶段 B：反序列化 (Deserialization: 磁盘文本 -> 内存结构体)】
    // =========================================================================
    printf("2. 【阶段 B：正在从磁盘 %s 重新反序列化装载数据回内存】...\n", FILE_PATH);
    struct Student loaded_students[MAX_RECORDS];
    int loaded_count = 0;

    FILE *fp_read = fopen(FILE_PATH, "r");
    if (fp_read == NULL)
    {
        perror("🚨 打开读文件失败");
        return 1;
    }

    // 💡 工业级防御性读取：判断 fscanf 的实际匹配返回值
    //    当且仅当成功匹配并填充了全部 3 个字段时，才算作有效读取
    while (loaded_count < MAX_RECORDS &&
           fscanf(fp_read, "%d%s%f", 
                  &loaded_students[loaded_count].id, 
                  loaded_students[loaded_count].name, 
                  &loaded_students[loaded_count].score) == 3)
    {
        loaded_count++;
    }
    fclose(fp_read);
    printf("   ✅ 成功从磁盘读回 %d 条完整有效记录！\n\n", loaded_count);

    // =========================================================================
    // 【阶段 C：验证与制表展示】
    // =========================================================================
    printf("3. 【阶段 C：验证控制台打印反序列化再现的成绩单】:\n");
    printf("==================================================\n");
    printf("学号\t\t姓名\t\t成绩\n");
    printf("==================================================\n");
    for (int i = 0; i < loaded_count; i++)
    {
        printf("%d\t\t%-8s\t%.2f\n", 
               loaded_students[i].id, 
               loaded_students[i].name, 
               loaded_students[i].score);
    }
    printf("==================================================\n");

    printf("\n============================ 教学原理解析 ============================\n");
    printf("💡 为什么 fscanf(...) == 3 比 while(!feof(fp)) 更加严谨？\n");
    printf("   在文本文件末尾常留有空行或空格，feof() 在读取到换行符时依然返回 0 (未结束)，\n");
    printf("   会导致多进入一次循环并重复打印最后一行！判断匹配个数为 3 可彻底根除此 Bug！\n");
    printf("======================================================================\n");

    return 0;
}
