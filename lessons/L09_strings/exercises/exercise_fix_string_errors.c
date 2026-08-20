/*
 * 练习题：字符串常见陷阱与标准库函数排雷改错实战
 * 对应课件: 第09讲 PPT 第8, 11, 12, 15页【避坑指南：字符串四大核心雷区】
 * 
 * 题目要求:
 * 观察并修复下方代码中的 4 处经典逻辑与内存漏洞：
 * 漏洞 1: 字符数组定义长度刚好等于字符数，导致丢失字符串结束符 '\0' 引发乱码
 * 漏洞 2: 试图使用 s2 = s1 进行数组直接赋值（数组名是地址常量）
 * 漏洞 3: 试图使用 s1 == "China" 比较字符串内容（双等号比的是内存地址）
 * 漏洞 4: strcat 拼接时目的数组容量不足引发栈内存溢出崩溃
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("=== 字符串与文本处理专项排雷 ===\n");

    // 修复点 1: 容纳 5 个字符的 "China" 必须分配至少 6 字节空间，留给 '\0' 哨兵
    char s1[10] = "China";
    printf("修复1: s1 安全输出: %s (strlen=%lu, sizeof=%lu)\n", s1, strlen(s1), sizeof(s1));

    // 修复点 2: 不能使用 s2 = s1，必须使用 strcpy(s2, s1) 复制
    char s2[20];
    strcpy(s2, s1);
    printf("修复2: strcpy 复制后 s2: %s\n", s2);

    // 修复点 3: 不能使用 s1 == "China"，必须使用 strcmp(s1, "China") == 0 进行内容比对
    if (strcmp(s1, "China") == 0)
    {
        printf("修复3: 字符串内容比对成功 (strcmp 返回 0)！\n");
    }

    // 修复点 4: 拼接前确保目的数组有足够的空间 (至少容纳 5 + 6 + 1 = 12 字节)
    char buffer[30] = "Hello ";
    strcat(buffer, "World!");
    printf("修复4: 安全拼接后 buffer: %s (总长=%lu)\n", buffer, strlen(buffer));

    return 0;
}
