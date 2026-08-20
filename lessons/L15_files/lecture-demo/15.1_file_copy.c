/*
 * 文件名: 15.1_file_copy.c
 * 对应课件: 第15讲 PPT 第5, 6, 7, 8, 10, 11页【文件字符拷贝、EOF哨兵与缓冲区机制解密】
 * 对应教材: 谭浩强版《C程序设计》第10章 10.2 + 何钦铭版《C语言程序设计》第12章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 掌握字符级文件流式读写：fgetc 与 fputc
 * 2. 深刻理解 EOF (-1) 哨兵控制与为什么接收变量 ch 必须定义为 int 类型：
 *    char 无法在所有系统上区分有效字符 (如 0xFF) 与文件结束标志 EOF (-1)
 * 3. 揭秘缓冲文件系统（512字节中转仓库）：
 *    为什么不执行 fclose() 会丢失末尾未满 512 字节的数据？因为 fclose 会触发强制物理落盘 (Flush)
 */

#include <stdio.h>
#include <stdlib.h>

#define SOURCE_FILE "source.txt"
#define DEST_FILE   "copy.txt"

int main(void)
{
    printf("======================================================================\n");
    printf("    字符级文件 I/O 与缓冲区解密 —— fgetc/fputc 流式文件拷贝实战         \n");
    printf("======================================================================\n\n");

    // =========================================================================
    // 【第一步：自动生成测试源数据文件 source.txt】
    // =========================================================================
    printf("1. 【正在自动创建源文件 %s】...\n", SOURCE_FILE);
    FILE *fp_init = fopen(SOURCE_FILE, "w");
    if (fp_init == NULL)
    {
        perror("⚠️ 创建源文件失败");
        return 1;
    }
    fputs("Hello C Programming Language!\n", fp_init);
    fputs("Data Persistence in Storage Device.\n", fp_init);
    fputs("Happy Coding with Antigravity AI!\n", fp_init);
    fclose(fp_init); // 结账冲刷，数据物理写入磁盘
    printf("   ✅ 源文件 %s 创建并写入成功！\n\n", SOURCE_FILE);

    // =========================================================================
    // 【第二步：建立双向通道，执行流式字符拷贝】
    // =========================================================================
    printf("2. 【正在建立管道：从 %s 拷贝至 %s】...\n", SOURCE_FILE, DEST_FILE);

    // 🛡️ 工业安全防线一：以 "r" 只读模式打开源文件并进行 NULL 拦截
    FILE *fp_src = fopen(SOURCE_FILE, "r");
    if (fp_src == NULL)
    {
        printf("🚨 【系统拦截】源文件 %s 打开失败，阻止空指针崩溃！\n", SOURCE_FILE);
        return 1;
    }

    // 🛡️ 工业安全防线二：以 "w" 只写模式打开目标文件并进行 NULL 拦截
    FILE *fp_dest = fopen(DEST_FILE, "w");
    if (fp_dest == NULL)
    {
        printf("🚨 【系统拦截】目标文件 %s 打开失败！\n", DEST_FILE);
        fclose(fp_src); // 安全释放已占用的资源
        return 1;
    }

    // 💡 核心知识点：为什么 ch 必须声明为 int 而不是 char？
    //    fgetc 返回的是 int。在遇到文件末尾时，它会返回一个负数常量 EOF (通常为 -1)。
    //    若定义为 unsigned char，-1 会被截断为 255 (0xFF)，导致循环永远无法终止！
    int ch;
    long char_count = 0;

    // 字符级流式读取：只要未遇到文件结束哨兵 EOF，就持续搬运写入
    while ((ch = fgetc(fp_src)) != EOF)
    {
        fputc(ch, fp_dest);
        char_count++;
    }

    printf("   ✅ 字符流拷贝完成！共传输字节数: %ld 字节\n", char_count);

    // =========================================================================
    // 【第三步：安全结账与缓冲区强制冲刷 (Flush)】
    // =========================================================================
    // 💡 物理真相：调用 fclose() 时，操作系统会自动触发冲刷动作，
    //    把停留在内存 512 字节中转仓库中尚未满载的末尾数据，强制倾倒进磁盘扇区！
    fclose(fp_src);
    fclose(fp_dest);
    printf("   🔒 双文件管道安全关闭，缓冲区数据已强制物理落盘。\n");

    printf("\n============================ 教学原理解析 ============================\n");
    printf("💡 为什么在企业级开发中严禁遗漏 fclose()？\n");
    printf("   如果程序意外退出且未调用 fclose()，最后留在内存缓冲区未满 512 字节的数据，\n");
    printf("   将在内存销毁时直接蒸发，导致拷贝出的目标文件内容残缺不全！\n");
    printf("======================================================================\n");

    return 0;
}
