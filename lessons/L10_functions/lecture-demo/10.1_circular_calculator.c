/*
 * 文件名: 10.1_circular_calculator.c
 * 对应课件: 第10讲 PPT 第5, 6, 7, 11页【结构化程序设计：3层5函数架构 & 单向值传递】
 * 对应教材: 谭浩强版《C程序设计》第7章 + 北京石油化工学院《C语言程序设计》第10章
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 核心教学目标:
 * 1. 掌握结构化程序设计（自顶向下，逐步细化）的“3层架构”解耦模型
 * 2. 掌握函数原型声明（Prototype Declaration）与具体实现的物理分离（先声明、后使用）
 * 3. 深刻理解形参实参在栈帧中的“单向值传递（Pass by Value）”与副本隔离机制
 * 4. 理解函数返回值类型转换规则：函数返回类型拥有最高决定权
 */

#include <stdio.h>

#define PI 3.141592653589793

// =========================================================================
// 【函数原型声明区 (Function Prototypes)】
// 
// 💡 为什么需要在此声明？
// 编译器自顶向下编译代码，若 main() 中调用的函数定义在 main() 之后，
// 必须通过原型声明提前向编译器“备案”，明确函数的返回值类型与形参列表！
// ⚠️ 注意: 函数原型声明是一条完整的 C 语句，末尾必须加英文分号 ';' ！
// =========================================================================

// 第 2 层：计算控制器函数
double calculate_sphere_volume(double radius);
double calculate_cylinder_volume(double radius, double height);
double calculate_cone_volume(double radius, double height);

// 第 3 层：基础专业工具函数
double get_circle_area(double radius);
double get_positive_double(const char *prompt);

// =========================================================================
// 【第 1 层：调度总指挥 (The Director)】
// main() 函数不负责具体几何计算，仅协调交互菜单与流程调度
// =========================================================================
int main(void)
{
    printf("======================================================================\n");
    printf("    模块化架构实战 —— 圆形体几何体积计算器 (3层结构解耦模型)           \n");
    printf("======================================================================\n\n");

    int choice = 0;
    int is_running = 1;

    while (is_running)
    {
        printf("\n------------- 功能菜单 (Menu) -------------\n");
        printf("  [1] 计算球体体积 (Sphere Volume)\n");
        printf("  [2] 计算圆柱体体积 (Cylinder Volume)\n");
        printf("  [3] 计算圆锥体体积 (Cone Volume)\n");
        printf("  [0] 退出系统 (Exit)\n");
        printf("-------------------------------------------\n");
        printf("👉 请输入功能选项 (0~3): ");

        if (scanf("%d", &choice) != 1)
        {
            printf("⚠️ 输入无效，请输入数字选项！\n");
            while (getchar() != '\n'); // 清理缓冲区
            continue;
        }

        switch (choice)
        {
            case 1: {
                double r = get_positive_double("请输入球体半径 r");
                double vol = calculate_sphere_volume(r);
                printf("🎯 计算结果: 半径 r=%.2f 的球体体积为: %.4f\n", r, vol);
                break;
            }
            case 2: {
                double r = get_positive_double("请输入圆柱底面半径 r");
                double h = get_positive_double("请输入圆柱高度 h");
                double vol = calculate_cylinder_volume(r, h);
                printf("🎯 计算结果: 底半径 r=%.2f, 高 h=%.2f 的圆柱体积为: %.4f\n", r, h, vol);
                break;
            }
            case 3: {
                double r = get_positive_double("请输入圆锥底面半径 r");
                double h = get_positive_double("请输入圆锥高度 h");
                double vol = calculate_cone_volume(r, h);
                printf("🎯 计算结果: 底半径 r=%.2f, 高 h=%.2f 的圆锥体积为: %.4f\n", r, h, vol);
                break;
            }
            case 0:
                printf("👋 感谢使用，系统安全退出！\n");
                is_running = 0;
                break;
            default:
                printf("❌ 选项超出范围，请重新输入 0~3！\n");
                break;
        }
    }

    return 0;
}

// =========================================================================
// 【第 2 层：计算控制层实现 (The Calculators)】
// 业务控制器调用第 3 层几何专家 get_circle_area 完成复合计算
// =========================================================================

// 计算球体体积: V = 4/3 * PI * r^3
double calculate_sphere_volume(double radius)
{
    return (4.0 / 3.0) * PI * radius * radius * radius;
}

// 计算圆柱体体积: V = 底面积 * 高
double calculate_cylinder_volume(double radius, double height)
{
    // 调用第 3 层专家获取底面积
    double base_area = get_circle_area(radius);
    return base_area * height;
}

// 计算圆锥体体积: V = 底面积 * 高 / 3.0
double calculate_cone_volume(double radius, double height)
{
    double base_area = get_circle_area(radius);
    return (base_area * height) / 3.0;
}

// =========================================================================
// 【第 3 层：基础专业工具实现 (The Specialists)】
// 底层单一职责模块，提供高复用率的纯计算与防御性输入
// =========================================================================

// 计算圆面积: S = PI * r^2
double get_circle_area(double radius)
{
    // 💡 物理单向值传递说明:
    // radius 是函数内部的局部形参，它的修改绝不会影响到 main() 中的原始变量 r
    return PI * radius * radius;
}

// 防御性安全读取正浮点数（负数或非法输入拦截）
double get_positive_double(const char *prompt)
{
    double value = 0.0;
    while (1)
    {
        printf("👉 %s: ", prompt);
        if (scanf("%lf", &value) == 1)
        {
            if (value >= 0.0)
            {
                return value; // 校验成功，返回合法值
            }
            printf("⚠️ 错误: 几何尺寸不能为负数，请重新输入！\n");
        }
        else
        {
            printf("⚠️ 错误: 输入格式非法，请输入有效的浮点数！\n");
            while (getchar() != '\n'); // 清空输入流残留字符
        }
    }
}
