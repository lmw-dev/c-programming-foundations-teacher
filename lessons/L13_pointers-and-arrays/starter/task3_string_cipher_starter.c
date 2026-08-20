/*
 * 任务 3 起步模板：基于字符指针的电码加密器
 * 对应课件: 第13讲 PPT 第17, 18页【字符指针扫描】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 编写 void encrypt(char *s)
 * 2. 使用 while(*s != '\0') 扫描，遇到 'z' 变 'a'，'Z' 变 'A'，其他字母 ASCII+1
 */

#include <stdio.h>

void encrypt(char *s)
{
    if (s == NULL) return;

    // TODO: 使用纯字符指针扫描
    while (*s != '\0') {
        if (*s == 'z') *s = 'a';
        else if (*s == 'Z') *s = 'A';
        else if ((*s >= 'a' && *s < 'z') || (*s >= 'A' && *s < 'Z')) {
            *s = *s + 1;
        }
        s++;
    }
}

int main(void)
{
    char msg[50] = "Hello World zZ!";
    printf("加密前: %s\n", msg);
    encrypt(msg);
    printf("加密后: %s\n", msg);
    return 0;
}
