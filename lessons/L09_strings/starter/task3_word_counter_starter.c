/*
 * 任务 3 起步模板：有限状态机 (FSM) 统计单词个数
 * 对应课件: 第09讲 PPT 第11, 17页【案例工坊】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 使用 fgets 安全读取包含空格的一整行句子
 * 2. 声明状态标志 in_word (0=空白, 1=单词内部)
 * 3. 遇到非空格且 in_word==0 时，word_count++ 并将 in_word 设为 1
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[200];
    printf("请输入句子: ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;

    // 去除换行符
    str[strcspn(str, "\r\n")] = '\0';

    int in_word = 0;
    int count = 0;

    // TODO: 状态机循环扫描
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            in_word = 0;
        } else {
            if (in_word == 0) {
                in_word = 1;
                count++;
            }
        }
    }

    printf("单词总数: %d\n", count);
    return 0;
}
