/*
 * 任务 1 起步模板：圆形体体积计算器（模块化拆解）
 * 对应课件: 第10讲 PPT 第5, 6, 7页【3层架构】
 * 适用环境: Visual Studio / Dev-C++ / VS Code
 * 
 * 任务说明:
 * 1. 声明并实现 get_circle_area(r) 计算圆面积
 * 2. 声明并实现 calculate_cylinder_volume(r, h) 计算圆柱体积
 * 3. 声明并实现 calculate_cone_volume(r, h) 计算圆锥体积
 */

#include <stdio.h>

#define PI 3.141592653589793

// TODO 1: 函数原型声明
double get_circle_area(double radius);
double calculate_cylinder_volume(double radius, double height);
double calculate_cone_volume(double radius, double height);

int main(void)
{
    double r = 3.0, h = 5.0;

    printf("圆底面积: %.4f\n", get_circle_area(r));
    printf("圆柱体积: %.4f\n", calculate_cylinder_volume(r, h));
    printf("圆锥体积: %.4f\n", calculate_cone_volume(r, h));

    return 0;
}

// TODO 2: 实现底面积计算
double get_circle_area(double radius)
{
    return PI * radius * radius;
}

// TODO 3: 实现圆柱体积计算
double calculate_cylinder_volume(double radius, double height)
{
    return get_circle_area(radius) * height;
}

// TODO 4: 实现圆锥体积计算
double calculate_cone_volume(double radius, double height)
{
    return get_circle_area(radius) * height / 3.0;
}
