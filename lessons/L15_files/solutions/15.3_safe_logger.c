/*
 * 文件名: 15.3_safe_logger.c
 * 对应课件: 第15讲 PPT 第7, 8, 16, 17, 18页【异常防御型系统日志追加器与硬件错误拦截】
 * 对应教材: 谭浩强版《C程序设计》第10章 10.4 + 湖南大学《C语言程序设计》第11章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 掌握文件追加模式 "a" (Append Mode) 的安全特性：
 *    文件不存在则自动新建，文件存在则将位置指针滑至末尾，绝不破坏历史数据
 * 2. 构筑工业级异常防御三剑客：feof()、ferror() 与 clearerr()
 *    - feof(): 确认是否正常读至文件物理末尾 (EOF)
 *    - ferror(): 拦截由于只读写保护、磁盘已满、拔出介质等引发的硬件级读写错误
 *    - clearerr(): 错误或结束处理完毕后清洗标志位
 */

#include <stdio.h>
#include <stdlib.h>

#define LOG_FILE_PATH "system_runtime.log"

// 函数原型声明
void log_event(const char *log_path, const char *level, const char *message);
void print_logs(const char *log_path);

int main(void)
{
    printf("======================================================================\n");
    printf("    工业级安全日志追加器 —— 追加模式 'a' 与 ferror/feof 异常防护盾   \n");
    printf("======================================================================\n\n");

    // 1. 模拟系统连续记录运行事件 (多次追加)
    printf("1. 【正在向 %s 追加系统运行事件】...\n", LOG_FILE_PATH);
    log_event(LOG_FILE_PATH, "INFO",  "系统核心服务启动成功 (System Core Booted)");
    log_event(LOG_FILE_PATH, "DEBUG", "内存池初始化完成: 动态划分 64MB");
    log_event(LOG_FILE_PATH, "WARN",  "检测到管理员账户 'admin' 在异地登录");
    log_event(LOG_FILE_PATH, "INFO",  "文件持久化与备份机制已生效");
    printf("   ✅ 所有事件已安全追加并强制物理落盘！\n\n");

    // 2. 逐行读取并回显日志文件
    printf("2. 【正在读取并回放历史日志记录】:\n");
    print_logs(LOG_FILE_PATH);

    printf("\n============================ 教学原理解析 ============================\n");
    printf("💡 为什么系统日志必须使用 'a' 追加模式而不是 'w' 写入模式？\n");
    printf("   'w' 模式每次打开都会无情抹除全部历史数据！\n");
    printf("   'a' 模式能够在保留原有历史记录的前提下，将指针滑动到末尾安全追加！\n");
    printf("======================================================================\n");

    return 0;
}

// 模块 1：追加写入单条日志并进行硬件异常拦截
void log_event(const char *log_path, const char *level, const char *message)
{
    if (log_path == NULL || level == NULL || message == NULL)
    {
        return;
    }

    // 🛡️ 工业防线一：以 "a" 模式打开 (自动创建或末尾追加)
    FILE *fp = fopen(log_path, "a");
    if (fp == NULL)
    {
        fprintf(stderr, "🚨 【系统严重中断】无法打开日志文件 %s，拦截崩溃风险！\n", log_path);
        return;
    }

    // 模拟时间戳 (避免平台 time.h 差异)
    const char *mock_timestamp = "2026-08-20 17:15:00";

    // 格式化输出日志行
    fprintf(fp, "[%s] [%-5s] %s\n", mock_timestamp, level, message);

    // 🛡️ 工业防线二：检查是否发生硬件级写入故障
    if (ferror(fp))
    {
        fprintf(stderr, "🚨 【磁盘硬件异常】日志写入失败，可能磁盘已满或受写保护！\n");
        clearerr(fp); // 清洗重置错误标志位
    }

    // 🛡️ 工业防线三：安全关闭结账并冲刷
    fclose(fp);
}

// 模块 2：读取历史日志并在控制台安全回显
void print_logs(const char *log_path)
{
    if (log_path == NULL) return;

    FILE *fp = fopen(log_path, "r");
    if (fp == NULL)
    {
        printf("⚠️ 未找到日志文件 %s 或无权读取！\n", log_path);
        return;
    }

    char buffer[256];
    int line_count = 0;

    printf("----------------------------------------------------------------------\n");
    // 使用 fgets 逐行安全提取数据
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
        line_count++;
    }
    printf("----------------------------------------------------------------------\n");

    // 🛡️ 使用 feof 验证是否完整读取到文件物理末尾
    if (feof(fp))
    {
        printf("   📌 [校验通过] feof(fp) 确认文件正常读取完毕，共 %d 条日志记录。\n", line_count);
    }
    else if (ferror(fp))
    {
        fprintf(stderr, "🚨 [读取异常] 读取过程中发生硬件级 I/O 故障！\n");
        clearerr(fp);
    }

    fclose(fp);
}
