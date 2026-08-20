/*
 * 文件名: 16.3_bachelor_rush.c
 * 对应课件: 第16讲 PPT 第15, 16, 18, 19, 20页【专升本压轴大题：单链表按成绩降序动态构建与持久化落盘】
 * 对应教材: 谭浩强版《C程序设计》第9, 10章 + 全国专升本统考编程压轴大题标准模板
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 掌握动态内存分配 malloc / free 与 NULL 指针安全检测
 * 2. 掌握单向链表结构（套娃指针 next）与指针“穿针引线”逻辑
 * 3. 掌握无需依赖数组下标的【链表原地降序有序插入算法】(insert_sorted)
 * 4. 掌握链表数据的遍历与文件流持久化落盘 (save_list_to_file)
 * 5. 掌握堆区动态内存的完整安全物理回收 (free_list)，彻底根除内存泄漏
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUTPUT_FILE "sorted_result.txt"

// 1. 定义学生链表数据节点结构体
struct Student {
    int id;                // 学号
    char name[20];         // 姓名
    float score;           // 期末总分
    struct Student *next;  // 指向下一个节点的物理指针（套娃指针）
};

// 函数原型声明
struct Student* insert_sorted(struct Student *head, int id, const char *name, float score);
void display_list(const struct Student *head);
void save_list_to_file(const struct Student *head, const char *filename);
void free_list(struct Student *head);

int main(void)
{
    printf("======================================================\n");
    printf("         C语言程序设计期末冲刺：单链表降序排行榜       \n");
    printf("======================================================\n");

    struct Student *head = NULL; // 初始化空链表头指针

    // 动态模拟插入 5 位学生的成绩数据（无序输入 -> 链表内部自动降序排序）
    head = insert_sorted(head, 101, "张三", 85.50f);
    head = insert_sorted(head, 102, "李四", 92.00f);
    head = insert_sorted(head, 103, "王五", 76.50f);
    head = insert_sorted(head, 104, "赵六", 98.00f);
    head = insert_sorted(head, 105, "孙七", 88.00f);

    // 1. 控制台制表打印排序后的排行榜
    display_list(head);

    // 2. 将降序结果持久化写入磁盘文件
    save_list_to_file(head, OUTPUT_FILE);

    // 3. 安全回收动态堆内存
    free_list(head);
    head = NULL; // 规避野指针

    return 0;
}

// 核心模块 1：单链表按成绩降序有序插入节点
struct Student* insert_sorted(struct Student *head, int id, const char *name, float score)
{
    // 🛡️ 工业防线一：为新节点动态申请堆内存并进行 NULL 检查
    struct Student *new_node = (struct Student*)malloc(sizeof(struct Student));
    if (new_node == NULL)
    {
        fprintf(stderr, "🚨 【内存告警】malloc 堆内存分配失败！\n");
        return head;
    }

    // 填充节点数据
    new_node->id = id;
    strncpy(new_node->name, name, sizeof(new_node->name) - 1);
    new_node->name[sizeof(new_node->name) - 1] = '\0';
    new_node->score = score;
    new_node->next = NULL;

    // 💡 降序插入场景 A：链表为空，或新节点成绩高于当前头节点 -> 成为新的头节点
    if (head == NULL || new_node->score > head->score)
    {
        new_node->next = head;
        return new_node; // 新节点荣升为链表新表头
    }

    // 💡 降序插入场景 B：遍历链表，寻找插入缝隙
    //    找到第一个满足 temp->next 为空 或 new_node->score > temp->next->score 的位置
    struct Student *current = head;
    while (current->next != NULL && current->next->score >= new_node->score)
    {
        current = current->next;
    }

    // 指针穿针引线：先连后断
    new_node->next = current->next;
    current->next = new_node;

    return head;
}

// 核心模块 2：遍历打印链表
void display_list(const struct Student *head)
{
    printf("名次\t学号\t姓名\t期末总分\n");
    printf("======================================================\n");
    const struct Student *curr = head;
    int rank = 1;
    while (curr != NULL)
    {
        printf("%d\t%d\t%-8s%.2f\n", rank, curr->id, curr->name, curr->score);
        curr = curr->next;
        rank++;
    }
    printf("======================================================\n");
}

// 核心模块 3：将链表数据持久化落盘至文本文件
void save_list_to_file(const struct Student *head, const char *filename)
{
    if (filename == NULL) return;

    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("🚨 打开落盘文件失败");
        return;
    }

    const struct Student *curr = head;
    int rank = 1;
    fprintf(fp, "名次\t学号\t姓名\t期末总分\n");
    fprintf(fp, "------------------------------------\n");
    while (curr != NULL)
    {
        fprintf(fp, "%d\t%d\t%s\t%.2f\n", rank, curr->id, curr->name, curr->score);
        curr = curr->next;
        rank++;
    }
    fclose(fp); // 强制冲刷缓冲区落盘
    printf("【落盘成功】排行榜数据已安全写入: %s\n", filename);
}

// 核心模块 4：逐个节点释放堆内存，杜绝内存泄漏
void free_list(struct Student *head)
{
    struct Student *curr = head;
    while (curr != NULL)
    {
        struct Student *next_node = curr->next; // 先记录下一个节点地址
        free(curr);                             // 释放当前节点
        curr = next_node;                       // 指针前进
    }
    printf("【内存回收】单链表动态空间已物理释放完毕，程序安全退出。\n");
}
