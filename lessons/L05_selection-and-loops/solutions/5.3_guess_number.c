/*
 * 文件名: 5.3_guess_number.c
 * 对应课件: 第05讲 PPT 第19页【课后作业与挑战：do-while 猜数字趣味游戏】
 * 对应教材: 谭浩强版《C程序设计》第5章 + 何钦铭版《C语言程序设计》第4章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 深刻领会 do-while 循环“先执行一次再进行条件判断”的物理特征
 * 2. 掌握伪随机数函数 rand() 与种子生成器 srand(time(NULL)) 的标准使用
 * 3. 掌握取模限制区间算法：rand() % 100 得到 0~99，加 1 映射为 1~100
 */

#include <stdio.h>
#include <stdlib.h>  // 引入 rand() 和 srand()
#include <time.h>    // 引入 time() 获取系统时钟秒数作为随机种子

int main(void)
{
    printf("====================================================\n");
    printf("     🎮 趣味人机互动游戏 —— do-while 猜数字挑战     \n");
    printf("====================================================\n\n");

    // 1. 初始化系统时钟随机种子
    // 物理原理解析:
    // rand() 产生的其实是“伪随机数序列”，如果不设置种子，每次运行生成的数字序列完全相同！
    // time(NULL) 返回自 1970年1月1日以来的当前总秒数，保证每次运行游戏时种子都是崭新的。
    srand((unsigned int)time(NULL));

    // 2. 生成 1 到 100 之间的神秘目标数字
    // 数学映射机理: rand() % 100 将任意大随机数约束在 0 ~ 99 之间，加 1 后平移为 1 ~ 100
    int secret_number = rand() % 100 + 1;
    int user_guess = 0;
    int attempt_count = 0;

    printf("🤖 系统已经悄悄生成了一个 1 到 100 之间的神秘数字，请开始猜测！\n\n");

    // =========================================================================
    // 【do-while 循环黄金应用场景】
    // 
    // 为什么选型 do-while 而不是 while？
    // 因为在人机交互游戏中，“用户必须至少先猜一次并输入”，程序才拥有数据去和神秘数字进行比较！
    // 先执行输入（do），再判断是否猜对（while），逻辑严丝合缝、最为优雅！
    // =========================================================================
    do
    {
        printf("👉 请输入您猜测的数字 (1-100): ");
        if (scanf("%d", &user_guess) != 1) {
            printf("⚠️ 输入无效，游戏提前结束。\n");
            break;
        }

        // 尝试次数累加
        attempt_count++;

        // 判定大小并给出智能提示
        if (user_guess > secret_number) {
            printf("📈 [提示] 猜大啦！往小了再试一次。\n\n");
        } else if (user_guess < secret_number) {
            printf("📉 [提示] 猜小啦！往大了再试一次。\n\n");
        } else {
            printf("\n🎉 恭喜你！神枪手，猜对啦！神秘数字就是 %d！\n", secret_number);
            printf("🏆 您一共尝试了 %d 次成功通关！\n", attempt_count);
        }

    // 循环条件: 只要用户没猜对 (user_guess != secret_number)，就继续循环
    // ⚠️ 语法天条: do-while 的 while 判定后必须紧跟一个英文分号 ';'！
    } while (user_guess != secret_number);

    printf("\n====================================================\n");
    return 0;
}
