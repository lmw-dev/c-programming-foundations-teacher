/*
 * 任务 3 起步模板：单链表按成绩降序动态构建与落盘
 * 对应课件: 第16讲 PPT 第15, 16, 18, 19, 20页【升本压轴大题模板】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[20];
    float score;
    struct Student *next;
};

// TODO 1: 实现降序有序插入
struct Student* insert_sorted(struct Student *head, int id, const char *name, float score)
{
    struct Student *node = (struct Student*)malloc(sizeof(struct Student));
    if (!node) return head;

    node->id = id;
    strcpy(node->name, name);
    node->score = score;
    node->next = NULL;

    if (head == NULL || node->score > head->score) {
        node->next = head;
        return node;
    }

    struct Student *p = head;
    while (p->next != NULL && p->next->score >= node->score) {
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    return head;
}

// TODO 2: 遍历打印
void print_list(const struct Student *head)
{
    printf("学号\t姓名\t成绩\n");
    while (head) {
        printf("%d\t%s\t%.2f\n", head->id, head->name, head->score);
        head = head->next;
    }
}

// TODO 3: 释放内存
void free_list(struct Student *head)
{
    while (head) {
        struct Student *tmp = head->next;
        free(head);
        head = tmp;
    }
}

int main(void)
{
    struct Student *head = NULL;
    head = insert_sorted(head, 101, "张三", 85.5f);
    head = insert_sorted(head, 102, "李四", 92.0f);
    head = insert_sorted(head, 103, "王五", 76.5f);

    print_list(head);
    free_list(head);
    return 0;
}
