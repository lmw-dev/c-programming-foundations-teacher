/*
 * 练习题：文件打开模式、NULL拦截与安全关闭排雷改错实战
 * 对应课件: 第15讲 PPT 第7, 8, 9, 10, 11页【代码诊所：文件操作四大经典翻车地雷】
 * 
 * 题目要求:
 * 观察并修复下方代码中的 4 处经典文件 I/O 漏洞：
 * 漏洞 1: fopen 打开文件后未做 NULL 检查直接读写
 * 漏洞 2: 日志文件记录误用 "w" 模式覆盖历史数据
 * 漏洞 3: 使用 char 变量接收 fgetc 的返回值判断 EOF
 * 漏洞 4: 写入完毕后未调用 fclose() 导致数据残留缓冲区丢失
 */

#include <stdio.h>
#include <stdlib.h>

void safe_append_log(const char *filename, const char *msg);
void safe_copy_file(const char *src, const char *dest);

int main(void)
{
    printf("=== 文件 I/O 与安全异常排雷修复实战 ===\n");

    const char *log_name = "test_run.log";

    // 修复点 1 & 2: 使用 "a" 模式安全追加日志，并进行 NULL 拦截
    safe_append_log(log_name, "事件 1: 服务正常启动");
    safe_append_log(log_name, "事件 2: 数据库连接就绪");
    printf("修复1&2: 日志追加与 NULL 拦截执行完毕\n");

    // 修复点 3 & 4: 正确使用 int 接收 fgetc 并确保 fclose 强制落盘
    safe_copy_file(log_name, "test_run_backup.log");
    printf("修复3&4: 文件流式备份与缓冲区冲刷完成\n");

    return 0;
}

void safe_append_log(const char *filename, const char *msg)
{
    if (filename == NULL || msg == NULL) return;

    // 修复：必须使用 "a" 模式，并且必须进行 NULL 拦截
    FILE *fp = fopen(filename, "a");
    if (fp == NULL)
    {
        perror("打开日志文件失败");
        return;
    }

    fprintf(fp, "%s\n", msg);

    // 修复：必须调用 fclose 确保缓冲区数据冲刷落盘
    fclose(fp);
}

void safe_copy_file(const char *src, const char *dest)
{
    if (src == NULL || dest == NULL) return;

    FILE *in = fopen(src, "r");
    if (in == NULL)
    {
        perror("打开源文件失败");
        return;
    }

    FILE *out = fopen(dest, "w");
    if (out == NULL)
    {
        perror("打开目标文件失败");
        fclose(in);
        return;
    }

    // 修复：接收变量必须为 int 类型以准确容纳 EOF (-1)
    int ch;
    while ((ch = fgetc(in)) != EOF)
    {
        fputc(ch, out);
    }

    fclose(in);
    fclose(out);
}
