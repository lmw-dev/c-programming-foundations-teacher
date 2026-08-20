/*
 * 文件名: 11.3_static_tracker.c
 * 对应课件: 第11讲 PPT 第10, 11, 19页【实操任务二：基于 static 变量的状态追踪器与安全监控】
 * 对应教材: 谭浩强版《C程序设计》第7章 7.8, 7.9 + 湖南大学《C语言程序设计》第4章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 掌握 static 静态局部变量与 auto 自动变量在物理存储区（静态区 vs 动态栈区）的根本差异
 * 2. 领会 static 变量的“单次初始化与状态持久化”机制在工业安全监控中的典型应用
 * 3. 掌握以 static 局部变量代替易受污染的全局变量的软件工程高内聚设计思想
 */

#include <stdio.h>

// 业务监控函数声明
void record_login_attempt(const char *username, int is_success);

int main(void)
{
    printf("======================================================================\n");
    printf("     服务器安全网关实战 —— 基于 static 变量的登录异常监控系统          \n");
    printf("======================================================================\n\n");

    printf("1. 【模拟场景 1: 用户 admin 连续 3 次密码错误尝试】:\n");
    record_login_attempt("admin", 0); // 第 1 次失败
    record_login_attempt("admin", 0); // 第 2 次失败
    record_login_attempt("admin", 0); // 第 3 次失败 (触发暴力破解安全警报)

    printf("\n2. 【模拟场景 2: 正常用户 guest 登录成功】:\n");
    record_login_attempt("guest", 1); // 成功登录

    printf("\n======================================================================\n");
    return 0;
}

// 模拟服务器安全审计函数
void record_login_attempt(const char *username, int is_success)
{
    // 1. 普通自动局部变量 (分配在栈区，每次进入函数重新开辟并初始化为 0，出大括号立即销毁)
    int auto_fail_count = 0;

    // 2. 静态局部变量 (分配在静态存储区，整个生命期只初始化一次，出大括号空间不释放，保留历史值)
    static int static_fail_count = 0;
    static int total_system_calls = 0; // 记录系统总审计次数

    total_system_calls++;

    if (!is_success)
    {
        auto_fail_count++;
        static_fail_count++;

        printf("   [日志 #%d] ⚠️ 用户 [%s] 登录失败！\n", total_system_calls, username);
        printf("      -> 普通变量 auto_fail_count   : %d 次 (每次调用重新归零，无法累计！)\n", auto_fail_count);
        printf("      -> 静态变量 static_fail_count : %d 次 (静态区持久化保存，成功累计！)\n", static_fail_count);

        // 触发安全防御规则
        if (static_fail_count >= 3)
        {
            printf("      🚨 【SECURITY ALERT】检测到用户 [%s] 累计失败已达 %d 次，触发暴力破解风控封禁！\n",
                   username, static_fail_count);
        }
    }
    else
    {
        printf("   [日志 #%d] ✅ 用户 [%s] 登录成功！系统状态正常。\n", total_system_calls, username);
    }
}
