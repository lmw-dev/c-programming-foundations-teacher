/*
 * 任务 1 起步模板：公元年份闰年判定
 * 对应课件: 第04讲 PPT 第12页【课堂案例】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 补全下方的 TODO 区域，通过 scanf 读入年份
 * 2. 运用闰年复合逻辑表达式: (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)
 * 3. 运行测试：2000年输出闰年，1900年输出平年，2024年输出闰年
 */

#include <stdio.h>

int main(void)
{
    int year = 0;

    printf("请输入年份 (如 2024): ");

    // TODO 1: 使用 scanf 读取年份并做防御性检查 (年份必须 > 0)
    if (scanf("%d", &year) == 1 && year > 0) {
        // TODO 2: 补全复合逻辑表达式判断是否为闰年
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            printf("%d 年是 🎉 闰年！\n", year);
        } else {
            printf("%d 年是 平年。\n", year);
        }
    } else {
        printf("⚠️ 输入无效！\n");
    }

    return 0;
}
