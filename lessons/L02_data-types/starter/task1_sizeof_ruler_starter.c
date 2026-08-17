/*
 * 任务 1 起步模板：使用 sizeof 测量电脑上的“收纳盒规格”
 * 对应课件: 第02讲 PPT 第17~18页【上机实操探究】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 补全下方 TODO 区域的代码，使用 sizeof 运算符测量变量与类型大小
 * 2. 编译并运行，记录下你电脑上各个数据类型占用的实际物理字节数
 * 3. 观察并思考：你电脑上的 int 和 long 分别占几个字节？
 */

#include <stdio.h>

int main(void)
{
    printf("====================================================\n");
    printf("    === Your Computer's Memory收纳盒 Ruler ===     \n");
    printf("====================================================\n\n");

    // 1. 声明具体变量
    char my_char = 'A';
    int my_int = 100;
    double my_double = 9.9;

    printf("[Part 1] 测量具体变量实例的物理空间:\n");
    // TODO 1: 使用 sizeof 测量变量 my_char 的字节数并打印
    printf("  -> char   变量 my_char   占用: %zu 字节\n", sizeof(my_char));

    // TODO 2: 使用 sizeof 测量变量 my_int 的字节数并打印
    printf("  -> int    变量 my_int    占用: %zu 字节\n", sizeof(my_int));

    // TODO 3: 使用 sizeof 测量变量 my_double 的字节数并打印
    printf("  -> double 变量 my_double 占用: %zu 字节\n\n", sizeof(my_double));

    printf("[Part 2] 测量核心数据类型收纳盒规格 (sizeof(类型名)):\n");
    // TODO 4: 使用 sizeof(类型名) 依次测量 char, short, int, long, float, double
    printf("  char        大小: %zu 字节\n", sizeof(char));
    printf("  short       大小: %zu 字节\n", sizeof(short));
    printf("  int         大小: %zu 字节\n", sizeof(int));
    printf("  long        大小: %zu 字节\n", sizeof(long));
    printf("  float       大小: %zu 字节\n", sizeof(float));
    printf("  double      大小: %zu 字节\n", sizeof(double));

    printf("\n====================================================\n");

    return 0;
}
