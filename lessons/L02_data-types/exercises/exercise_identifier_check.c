/*
 * 练习题：标识符命名规范与变量声明排雷实战
 * 对应课件: 第02讲 PPT 第6、12、15页
 * 
 * 题目要求:
 * 观察并修复下方代码中的语法错误，使其能顺利编译并正常输出
 */

#include <stdio.h>

int main(void)
{
    // 提示 1: 标识符不能以数字开头，将 1st_score 修改为合法的规范变量名
    int first_score = 95;

    // 提示 2: 浮点型单精度常量建议加上 f 后缀，避免 double 截断警告
    float product_price = 19.9f;

    // 提示 3: 字符常量必须使用单引号，双引号代表字符串
    char user_level = 'A';

    // 打印输出结果
    printf("学员成绩: %d\n", first_score);
    printf("商品单价: %.2f\n", product_price);
    printf("用户等级: %c\n", user_level);

    return 0;
}
