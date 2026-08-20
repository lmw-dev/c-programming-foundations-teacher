/*
 * 任务 2 起步模板：凯撒密码环形加密与解密
 * 对应课件: 第09讲 PPT 第18页【凯撒密码加密】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 遍历字符串中的每一个字符
 * 2. 对小写字母执行 (c - 'a' + 3) % 26 + 'a' 环形回绕
 * 3. 对大写字母执行 (c - 'A' + 3) % 26 + 'A' 环形回绕
 * 4. 非字母字符原样保留
 */

#include <stdio.h>

int main(void)
{
    char text[] = "Attack at Dawn! zZ";
    char cipher[100];

    int i = 0;
    while (text[i] != '\0') {
        char c = text[i];
        // TODO 1: 小写字母环形偏移
        if (c >= 'a' && c <= 'z') {
            cipher[i] = (char)((c - 'a' + 3) % 26 + 'a');
        }
        // TODO 2: 大写字母环形偏移
        else if (c >= 'A' && c <= 'Z') {
            cipher[i] = (char)((c - 'A' + 3) % 26 + 'A');
        }
        // TODO 3: 其他字符原样保留
        else {
            cipher[i] = c;
        }
        i++;
    }
    cipher[i] = '\0';

    printf("明文: %s\n", text);
    printf("密文: %s\n", cipher);

    return 0;
}
