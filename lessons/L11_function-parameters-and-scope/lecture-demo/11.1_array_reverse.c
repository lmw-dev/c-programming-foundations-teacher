/*
 * 文件名: 11.1_array_reverse.c
 * 对应课件: 第11讲 PPT 第4, 5, 18页【数组作为函数参数的物理真相 & 原地逆序算法】
 * 对应教材: 谭浩强版《C程序设计》第7章 7.7 + 何钦铭版《C语言程序设计》第7章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 掌握数组作为函数参数的物理本质：数组名自动退化为指向首元素的指针 (Decay to Pointer)
 * 2. 领会“共享内存与原地改值”：形参数组与实参数组共享同一段物理内存，函数内修改直接影响原数组
 * 3. 揭秘 sizeof 陷阱：子函数中 sizeof(arr) 测量的是指针本身的字节数 (8B/4B)，而非整个数组大小
 * 4. 深刻理解“成对法则”：为什么向函数传递数组时，必须显式传入一个表示长度的参数 int size
 */

#include <stdio.h>

#define ARRAY_SIZE 10

// 函数原型声明
void reverse_array(int arr[], int size);
void print_array(const int arr[], int size, const char *label);

int main(void)
{
    printf("======================================================================\n");
    printf("    数组参数底层解密 —— 首地址传递、sizeof 退化与原地逆序换血实战       \n");
    printf("======================================================================\n\n");

    int numbers[ARRAY_SIZE] = {12, 45, 8, 99, 34, 56, 78, 90, 23, 11};

    // =========================================================================
    // 【物理维度一：主函数中的 sizeof(numbers) 测量】
    // 在 main() 作用域内，numbers 是一个真正的数组，包含 10 个 int 元素
    // =========================================================================
    printf("1. 【main 函数内物理尺寸检测】:\n");
    printf("   numbers 数组在 main 中的 sizeof: %lu 字节 (10 个 int * 4B = 40 字节)\n", sizeof(numbers));
    printf("   numbers 首元素起始物理内存地址 : %p\n\n", (void*)numbers);

    // 打印逆序前的原始数组
    print_array(numbers, ARRAY_SIZE, "逆序前 (Original)");

    // =========================================================================
    // 【物理维度二：传递数组首地址并调用函数】
    // =========================================================================
    printf("\n2. 【进入被调函数 reverse_array 进行原地对调】:\n");
    reverse_array(numbers, ARRAY_SIZE);

    // =========================================================================
    // 【物理维度三：验证主函数原数组是否被直接篡改 (原地换血)】
    // =========================================================================
    printf("\n3. 【退回 main 函数后原数组状态巡检】:\n");
    print_array(numbers, ARRAY_SIZE, "逆序后 (Reversed) ");

    printf("\n============================ 教学原理解析 ============================\n");
    printf("💡 为什么在子函数中不能用 sizeof(arr)/sizeof(arr[0]) 计算数组长度？\n");
    printf("   因为 C 语言中，形参数组 int arr[] 只是一个伪装者，它在底层已退化为指针变量 (int*)，\n");
    printf("   系统并不为形参开辟新的数组空间，只传递了 8 字节的物理首地址。\n");
    printf("   因此子函数根本无法感知原数组有多长，必须遵从【成对法则】显式传入 int size！\n");
    printf("======================================================================\n");

    return 0;
}

// 核心函数：双指针向心对碰实现数组原地逆序 (In-place Reverse)
void reverse_array(int arr[], int size)
{
    // 🚨 现场抓包：在子函数中测量 sizeof(arr)
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsizeof-array-argument"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsizeof-array-argument"
#endif
    printf("   🔍 [子函数内现场] sizeof(arr) = %lu 字节 (已退化为指针变量的物理大小！)\n", (unsigned long)sizeof(arr));
#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
    printf("   🔍 [子函数内现场] arr 接收到的首地址: %p (与 main 中的地址完全一致！)\n", (void*)arr);

    int left = 0;
    int right = size - 1;

    // 双指针向中间聚拢，两两对调元素
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

// 辅助打印数组工具函数
void print_array(const int arr[], int size, const char *label)
{
    printf("   %s: [ ", label);
    for (int i = 0; i < size; i++)
    {
        printf("%d%s", arr[i], (i == size - 1) ? "" : ", ");
    }
    printf(" ]\n");
}
