/*
 * 任务 2 起步模板：回文数判定函数
 * 对应课件: 第10讲 PPT 第17~18页【回文数检测】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 声明并实现 int is_palindrome(int n)
 * 2. 负数返回 0
 * 3. 循环逆序构造 rev，比较 rev == n
 */

#include <stdio.h>

int is_palindrome(int n);

int main(void)
{
    int num;
    printf("请输入整数: ");
    if (scanf("%d", &num) != 1) return 1;

    if (is_palindrome(num)) {
        printf("%d 是回文数！\n", num);
    } else {
        printf("%d 不是回文数。\n", num);
    }
    return 0;
}

int is_palindrome(int n)
{
    if (n < 0) return 0;

    int original = n;
    long long rev = 0;

    // TODO: 逆序重新组装数字
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }

    return (rev == original);
}
