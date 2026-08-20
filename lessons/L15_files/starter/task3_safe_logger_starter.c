/*
 * 任务 3 起步模板：安全系统日志追加器
 * 对应课件: 第15讲 PPT 第8, 16页【追加模式与安全防护】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 编写 void append_log(const char *msg)
 * 2. 使用 "a" 模式打开并写入，防止抹除历史记录
 */

#include <stdio.h>

void append_log(const char *msg)
{
    if (msg == NULL) return;

    // TODO 1: "a" 追加模式打开
    FILE *fp = fopen("app.log", "a");
    if (fp == NULL) return;

    // TODO 2: 写入日志并检查
    fprintf(fp, "[LOG] %s\n", msg);

    // TODO 3: 必须安全关闭
    fclose(fp);
}

int main(void)
{
    append_log("系统启动中...");
    append_log("数据库初始化成功。");

    // 回显读取
    FILE *fp = fopen("app.log", "r");
    if (fp != NULL) {
        char buf[128];
        printf("读取日志文件:\n");
        while (fgets(buf, sizeof(buf), fp) != NULL) {
            printf("%s", buf);
        }
        fclose(fp);
    }
    return 0;
}
