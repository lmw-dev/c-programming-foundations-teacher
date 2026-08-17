/*
 * 任务 2 起步模板：字母大小写转换与符号常量价格计算器
 * 对应课件: 第02讲 PPT 第8、16、19页【随堂实战作业】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 补全 Part 1 中的字母转换逻辑：将大写字符 'A' 加上 32 转换为小写 'a' 并输出
 * 2. 补全 Part 2 中的价格计算逻辑：定义符号常量 APPLE_PRICE 为 2.5，使用 scanf 输入购买重量，计算并输出总额
 * 3. 编译并运行，测试输入 3.5 公斤时的输出总价是否为 8.75 元
 */

#include <stdio.h>

// TODO 1: 定义符号常量 APPLE_PRICE 为 2.5f
#define APPLE_PRICE 2.5f

int main(void)
{
    printf("=== 任务 2: 字母转换与符号常量计算器 ===\n\n");

    // Part 1: 大写转小写
    char upper_letter = 'A';
    // TODO 2: 将 upper_letter 加上 32 赋值给 lower_letter
    char lower_letter = upper_letter + 32;

    printf("[Part 1] 大写转小写:\n");
    printf("  '%c' -> '%c'\n\n", upper_letter, lower_letter);

    // Part 2: 苹果总价计算
    printf("[Part 2] 苹果总价计算:\n");
    float weight = 0.0f;
    printf("  请输入苹果重量(公斤): ");
    
    // TODO 3: 使用 scanf 读取用户输入的浮点数 weight (注意加 &)
    if (scanf("%f", &weight) == 1) {
        // TODO 4: 计算总价 total_cost = weight * APPLE_PRICE
        float total_cost = weight * APPLE_PRICE;
        printf("  应付总额: %.2f 元\n", total_cost);
    }

    return 0;
}
