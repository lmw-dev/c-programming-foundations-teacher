/*
 * 任务 2 起步模板：行指针与列指针遍历二维数组
 * 对应课件: 第13讲 PPT 第10, 11, 12页【二维行/列指针】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 使用列指针 int *p 扁平化遍历输出 2x3 数组
 * 2. 使用行指针 int (*rp)[3] 按行输出
 */

#include <stdio.h>

int main(void)
{
    int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // TODO 1: 列指针扁平遍历
    printf("列指针遍历: ");
    int *col_p = &mat[0][0];
    for (int i = 0; i < 6; i++) {
        printf("%d ", *(col_p + i));
    }
    printf("\n");

    // TODO 2: 行指针按行访问
    printf("行指针访问 mat[1][2]: %d (预期 6)\n", *(*(mat + 1) + 2));

    return 0;
}
