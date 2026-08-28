/*
 * 任务 1 起步模板：使用 sizeof 测量电脑上的“收纳盒规格”
 * 对应课件: 第02讲 PPT 第19页【实操工坊·探究一：寻找你电脑上的收纳盒规格】
 * 适用环境: Visual Studio 2022 / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 补全下方 TODO 区域的代码，使用 sizeof 测量具体变量与核心类型字节数
 * 2. 编译并运行，在实验探究报告中记录你电脑上的实际物理尺寸
 * 3. 观察思考：你电脑上的 int 和 long 分别占几个字节？它们是什么关系？
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    printf("====================================================\n");
    printf("  【探究一】寻找你电脑上的“收纳盒规格” (sizeof 量地尺)\n");
    printf("====================================================\n\n");

    // 1. 声明具体变量
    char my_char = 'A';
    int my_int = 100;
    double my_double = 9.9;

    printf("[Part 1] 测量具体变量实例的物理空间 (sizeof 变量名):\n");
    // TODO 1: 测量 char 型变量 my_char 的字节数
    printf("  -> char   变量 my_char   占用: %zu 字节\n", sizeof(my_char));

    // TODO 2: 测量 int 型变量 my_int 的字节数
    printf("  -> int    变量 my_int    占用: %zu 字节\n", sizeof(my_int));

    // TODO 3: 测量 double 型变量 my_double 的字节数
    printf("  -> double 变量 my_double 占用: %zu 字节\n\n", sizeof(my_double));

    printf("[Part 2] 测量核心数据类型收纳盒规格 (sizeof(类型名)):\n");
    // TODO 4: 依次使用 sizeof(类型名) 测量各个核心类型
    printf("  char        大小: %zu 字节\n", sizeof(char));
    printf("  short       大小: %zu 字节\n", sizeof(short));
    printf("  int         大小: %zu 字节\n", sizeof(int));
    printf("  long        大小: %zu 字节\n", sizeof(long));
    printf("  long long   大小: %zu 字节\n", sizeof(long long));
    printf("  float       大小: %zu 字节\n", sizeof(float));
    printf("  double      大小: %zu 字节\n", sizeof(double));

    printf("\n====================================================\n");

    return 0;
}
