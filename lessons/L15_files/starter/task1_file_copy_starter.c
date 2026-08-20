/*
 * 任务 1 起步模板：字符级文件读写与拷贝
 * 对应课件: 第15讲 PPT 第11页【fgetc 与 fputc】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 从 "src.txt" 读入字符并写入 "dst.txt"
 * 2. 使用 while ((ch = fgetc(in)) != EOF)
 */

#include <stdio.h>

int main(void)
{
    // 初始化源文件
    FILE *init = fopen("src.txt", "w");
    if (init != NULL) {
        fputs("Hello C File I/O Starter!", init);
        fclose(init);
    }

    FILE *in = fopen("src.txt", "r");
    FILE *out = fopen("dst.txt", "w");

    // TODO 1: 检查空指针
    if (in == NULL || out == NULL) {
        printf("打开文件失败！\n");
        if (in) fclose(in);
        if (out) fclose(out);
        return 1;
    }

    // TODO 2: 循环流式拷贝
    int ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch, out);
    }

    // TODO 3: 必须安全关闭文件
    fclose(in);
    fclose(out);
    printf("拷贝完成！\n");
    return 0;
}
