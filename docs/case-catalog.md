# 案例目录 — 16讲教学案例卡

> 本目录为每讲建立案例卡模板。当前所有案例状态均为「待补代码」，信息来源为授课计划 v0.8 和 PPT逐页文稿。标注「待案例定稿」的字段表示材料中有方向但未确认具体实现。

---

## L01 — 认识C程序：概述、程序结构、开发流程与屏幕输出

### 案例 1-1：Hello World 程序
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L01-01 Hello World |
| 教学目标 | 识别C程序基本结构（头文件、main函数、语句、注释） |
| 输入 | 无 |
| 核心处理 | printf 输出固定文本 |
| 输出 | `Hello World!` 或类似问候语 |
| 关键知识点 | #include、main函数、printf、return 0、分号 |
| 测试正常值 | 输出内容正确，格式无多余字符 |
| 测试边界值 | 空输出、多行输出、含转义字符输出 |
| 测试特殊值/错误输入 | 漏写分号（编译错误）、漏写花括号（编译错误） |
| 常见错误 | 忘记 `#include <stdio.h>`、main 写成 `mian`、语句末尾无分号 |
| 对应源文件 | 待补：`lessons/L01_intro/lecture-demo/hello_world.c` |
| 对应PPT页码 | 待确认 |
| 当前状态 | 待补代码 |

### 案例 1-2：多行文本输出
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L01-02 多行文本输出 |
| 教学目标 | 理解 `\n` 换行符和 printf 顺序执行 |
| 输入 | 无 |
| 核心处理 | 多个 printf 语句或含 `\n` 的单个 printf |
| 输出 | 多行文本（三行以上） |
| 关键知识点 | `\n` 换行符、printf 顺序执行 |
| 测试正常值 | 输出行数正确、内容正确 |
| 测试边界值 | 单行输出、末尾无换行 |
| 测试特殊值/错误输入 | 转义字符误用（如 `\a`） |
| 常见错误 | 忘记 `\n` 导致输出连在一行 |
| 对应源文件 | 待补：`lessons/L01_intro/lecture-demo/multi_line.c` |
| 对应PPT页码 | 待确认 |
| 当前状态 | 待补代码 |

### 案例 1-3：规范格式个人信息名卡
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L01-03 规范格式个人信息名卡 |
| 教学目标 | 综合运用多个 printf 输出带边框结构化个人名卡并体验控制台排版对齐 |
| 输入 | 无（静态输出） |
| 核心处理 | 多行 printf 组合输出，利用空格与等宽字符特性对齐右侧边框 |
| 输出 | 带 `===` 与 `*` 边框对齐的姓名、班级、学号、座右铭卡片 |
| 关键知识点 | printf、\n 换行符、控制台字符宽度对齐、程序结构 |
| 测试正常值 | 边框对齐整齐、信息完整无乱码 |
| 测试边界值 | 中英文字符混排宽度对齐（中文占2列，英文占1列） |
| 测试特殊值/错误输入 | 漏分号、双引号不匹配、中文标点误用 |
| 常见错误 | 字符数未算准导致右侧边框错位、换行符漏写 |
| 对应源文件 | [`lessons/L01_intro/lecture-demo/1.3_student_card.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L01_intro/lecture-demo/1.3_student_card.c) |
| 对应PPT页码 | 第12~15页 |
| 当前状态 | **已定稿** |

---

## L02 — 标识符、常量和变量；基本数据类型初识

### 案例 2-1：合法与非法标识符辨析
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L02-01 标识符合法性判断与命名天条 |
| 教学目标 | 掌握标识符命名规则与四大天条（字母数字下划线、首字符非数字、区分大小写、非关键字） |
| 输入 | 程序内嵌标识符列表（`score_1`, `2score`, `_temp`, `char`, `my$price`, `018`, `0xg`） |
| 核心处理 | 对每个标识符判断是否合法并分析违反规则 |
| 输出 | 合法/非法标识符及深层原因剖析 |
| 关键知识点 | 标识符命名规则、保留关键字、八/十六进制常量陷阱、蛇形命名法 |
| 测试正常值 | 典型合法标识符（`score_1`, `_temp`, `student_age`） |
| 测试边界值 | 单下划线 `_`、长标识符 |
| 测试特殊值/错误输入 | 数字开头(`2score`)、含非法符号(`my$price`)、关键字(`char`)、八进制非法数字(`018`) |
| 常见错误 | 混淆关键字与合法标识符、大小写拼写混淆 |
| 对应源文件 | [`lessons/L02_data-types/exercises/exercise_identifier_check.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L02_data-types/exercises/exercise_identifier_check.c) |
| 对应PPT页码 | 第5~7页 |
| 当前状态 | **已定稿** |

### 案例 2-2：变量声明、初始化与 sizeof 内存量地尺
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L02-02 内存收纳盒物理映像与 sizeof 测量 |
| 教学目标 | 理解变量物理内存模型（先声明后使用、补码存储、幽灵垃圾值）及掌握 sizeof 运算符 |
| 输入 | 变量声明与基本数据类型关键字 |
| 核心处理 | 声明 `int/float/double/char` 变量，使用 `sizeof` 运算符测量物理字节长度 |
| 输出 | 各变量实例及核心数据类型的字节数表格输出 |
| 关键知识点 | `sizeof` 运算符、基本数据类型（`char/short/int/long/float/double`）、未初始化幽灵垃圾值 |
| 测试正常值 | `char=1`, `short=2`, `int=4`, `float=4`, `double=8` |
| 测试边界值 | 浮点数带 `f` 后缀避免双精度截断警告、大写字母加 32 偏移转换 |
| 测试特殊值/错误输入 | 局部变量未初始化直接使用产生随机垃圾值 |
| 常见错误 | `sizeof` 误当成函数、连等声明错误、字符单双引号混淆 |
| 对应源文件 | [`lessons/L02_data-types/lecture-demo/2.1_ghost_value.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L02_data-types/lecture-demo/2.1_ghost_value.c)<br>[`lessons/L02_data-types/solutions/2.3_sizeof_ruler.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L02_data-types/solutions/2.3_sizeof_ruler.c) |
| 对应PPT页码 | 第9~18页 |
| 当前状态 | **已定稿** |

---

## L03 — 运算符、表达式；顺序结构与基础输入输出

### 案例 3-1：华氏度转摄氏度与整除截断排雷
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L03-01 华氏转摄氏与 5/9 整除截断排雷 |
| 教学目标 | 掌握除法截断天条、隐式类型提升与 scanf 地址符 & 的物理内存机理 |
| 输入 | 华氏温度 fahrenheit (float) |
| 核心处理 | `celsius_wrong = (5 / 9) * (f - 32.0f);` vs `celsius_correct = (5.0f / 9.0f) * (f - 32.0f);` |
| 输出 | 错误计算(0.00°C)与正确计算对照输出 |
| 关键知识点 | 整除截断、浮点隐式提升、scanf 取地址符 &、%.2f 格式化 |
| 测试正常值 | f=100.0 → celsius=37.78 |
| 测试边界值 | f=32.0 → celsius=0.00；f=212.0 → celsius=100.00 |
| 测试特殊值/错误输入 | 非法字符输入、负温度值 |
| 常见错误 | 5/9 截断为 0 导致温度被冻结、scanf 漏写 & 产生段错误闪退 |
| 对应源文件 | [`lessons/L03_sequential-programming/lecture-demo/3.1_temp_convert.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L03_sequential-programming/lecture-demo/3.1_temp_convert.c) |
| 对应PPT页码 | 第14~15页 |
| 当前状态 | **已定稿** |

### 案例 3-2：两数多功能计算器与精确商强转
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L03-02 两数多功能计算器与精确商 |
| 教学目标 | 掌握五大算术运算、(double) 强制类型转换求精确商与带符号取模天条 |
| 输入 | 两个非零整数 A 和 B |
| 核心处理 | 和差积、整除商 `A/B`、精确商 `(double)A/B`、取模 `A%B` |
| 输出 | 格式化计算清单表格 |
| 关键知识点 | 算术运算符、强制类型转换、取模符号判定规则 |
| 测试正常值 | A=15, B=4 → 商:3, 精确商:3.75, 余数:3 |
| 测试边界值 | A=20, B=-3 → 商:-6, 精确商:-6.67, 余数:2；A=-15, B=-4 → 商:3, 精确商:3.75, 余数:-3 |
| 测试特殊值/错误输入 | B=0 除零错误校验 |
| 常见错误 | 取模操作数混入浮点数、余数正负号判断混淆 |
| 对应源文件 | [`lessons/L03_sequential-programming/lecture-demo/3.2_calculator.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L03_sequential-programming/lecture-demo/3.2_calculator.c) |
| 对应PPT页码 | 第16~17页 |
| 当前状态 | **已定稿** |

---

## L04 — if 与关系/逻辑表达式

### 案例 4-1：公元年份闰年判定（双书对比）
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L04-01 闰年判定算法与短路求值 |
| 教学目标 | 掌握何版嵌套逻辑树 vs 谭版复合逻辑表达式对比，理解 && 和 \|\| 短路求值物理机制 |
| 输入 | 公元年份 year (int) |
| 核心处理 | 何版层层嵌套判断 vs 谭版 `(year%4==0 && year%100!=0) \|\| (year%400==0)` |
| 输出 | 两种方法判定是否为闰年的对比结果 |
| 关键知识点 | 关系运算符、逻辑运算符优先级、短路求值、嵌套 if |
| 测试正常值 | 2024 (普通闰年), 2000 (世纪闰年), 1900 (世纪平年), 2023 (普通平年) |
| 测试边界值 | year <= 0 防御性拦截 |
| 测试特殊值/错误输入 | 非数字输入、负数年份 |
| 常见错误 | 混淆世纪闰年规则、逻辑与/或优先级混淆 |
| 对应源文件 | [`lessons/L04_selection/lecture-demo/4.1_leap_year.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L04_selection/lecture-demo/4.1_leap_year.c) |
| 对应PPT页码 | 第12页 |
| 当前状态 | **已定稿** |

### 案例 4-2：三数夺魁与“打擂台”算法
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L04-02 三数求最大值与打擂台算法 |
| 教学目标 | 掌握从嵌套两两比较飞跃到“打擂台（Arena）”算法，理解 O(N) 线性可扩展性 |
| 输入 | 三个整数 a, b, c |
| 核心处理 | `max = a; if (b > max) max = b; if (c > max) max = c;` |
| 输出 | 三个数中的最大值 max |
| 关键知识点 | 打擂台算法思想、分支结构、算法可扩展性 |
| 测试正常值 | 18, 95, 42 → max=95 |
| 测试边界值 | 三个相同值 (5, 5, 5)、负数比较 (-5, -10, -2 → max=-2) |
| 测试特殊值/错误输入 | 极大/极小整数 |
| 常见错误 | 嵌套层次过深导致 else 配对错位、打擂台初始擂主未赋值 |
| 对应源文件 | [`lessons/L04_selection/lecture-demo/4.2_three_max.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L04_selection/lecture-demo/4.2_three_max.c) |
| 对应PPT页码 | 第15页 |
| 当前状态 | **已定稿** |

---

## L05 — 多分支选择、循环结构入门

### 案例 5-1：常驻交互式智能计算器系统
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L05-01 常驻菜单计算器与 switch 分支 |
| 教学目标 | 掌握 while(is_running) 状态哨兵架构、switch-case 直达电梯与除零防御拦截 |
| 输入 | 菜单选择 choice (0-4)，以及两操作数 (double) |
| 核心处理 | switch(choice) 分流执行 +、-、*、/，除法时 `fabs(num2)<1e-6` 拦截除零 |
| 输出 | 运算结果或退出提示，循环常驻直到输入 0 |
| 关键知识点 | switch-case、break 刹车片、case 穿透、while 状态哨兵、除零防御性编程 |
| 测试正常值 | 选 1 输入 12.5 3.5 → 输出 16.00；选 0 → 安全退出 |
| 测试边界值 | 选 4 输入 10.0 0 → 拦截除零并重新回到菜单 |
| 测试特殊值/错误输入 | 选 5 越界输入 → 提示无效选项 |
| 常见错误 | case 缺少 break 导致坠落穿透、switch 括号内误用浮点数 |
| 对应源文件 | [`lessons/L05_selection-and-loops/lecture-demo/5.1_menu_calculator.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L05_selection-and-loops/lecture-demo/5.1_menu_calculator.c) |
| 对应PPT页码 | 第14~15页 |
| 当前状态 | **已定稿** |

### 案例 5-2：while 循环阶乘累加和与防爆仓
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L05-02 while 阶乘累加和 (1!+...+10!) |
| 教学目标 | 掌握循环控制三大基石（起点/终点/步长）与 long long 大数防爆仓 |
| 输入 | 无（程序内置 1 到 10 计算） |
| 核心处理 | 单层 while 循环同步计算 `fact = fact * i` 与 `sum = sum + fact`，步长 `i++` |
| 输出 | 每一轮的阶乘项与累计总和表格，最终总和 4037913 |
| 关键知识点 | while 循环三要素、累乘累加双重流动、long long (%lld) 防大数溢出 |
| 测试正常值 | i 从 1 累加到 10，输出总和 4037913 |
| 测试边界值 | 1! 到 5! 累加和为 153 |
| 测试特殊值/错误输入 | 漏写 `i++` 引发死循环测试 |
| 常见错误 | 漏写循环控制变量更新导致死循环、使用 16 位 int 导致溢出为负数 |
| 对应源文件 | [`lessons/L05_selection-and-loops/lecture-demo/5.2_factorial_sum.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L05_selection-and-loops/lecture-demo/5.2_factorial_sum.c) |
| 对应PPT页码 | 第17页 |
| 当前状态 | **已定稿** |

---

## L06 — 三类循环、循环嵌套、break/continue

### 案例 6-1：九九乘法表与控制台制表符对齐
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L06-01 九九乘法表与时钟模型 |
| 教学目标 | 掌握双重 for 循环嵌套（分针秒针时钟模型）与 `\t` 硬件级对齐工程 |
| 输入 | 无（内置 1 到 9 矩阵） |
| 核心处理 | 外层 `i` 控制行 (1~9)，内层 `j` 控制列 (`j <= i`)，输出 `j*i=乘积` |
| 输出 | 格式规整的左下直角三角形九九乘法表 |
| 关键知识点 | 双重 for 嵌套、时钟模型、`j <= i` 几何约束、`\t` 横向制表符 |
| 测试正常值 | 打印 9 行左下三角，每行末尾换行 |
| 测试边界值 | 1*1=1 (起点), 9*9=81 (终点) |
| 测试特殊值/错误输入 | 无 |
| 常见错误 | 混淆 `i` 与 `j` 导致打印矩形、换行语句误写在内层循环 |
| 对应源文件 | [`lessons/L06_loops/lecture-demo/6.1_multiplication_table.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L06_loops/lecture-demo/6.1_multiplication_table.c) |
| 对应PPT页码 | 第9~10页 |
| 当前状态 | **已定稿** |

### 案例 6-2：100 以内素数过滤器与 sqrt 数学优化
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L06-02 素数过滤器与 sqrt 优化 |
| 教学目标 | 掌握循环嵌套、break 一票否决制提前跳出与 sqrt(n) 算力优化 |
| 输入 | 无（遍历 2 到 100） |
| 核心处理 | 外层遍历候选数 num，内层试除 2 到 sqrt(num)，遇整除立即 break |
| 输出 | 100 以内的全部 25 个素数，每行 5 个规整排版 |
| 关键知识点 | 素数数学判定、break 剪枝、sqrt() 数学优化（$O(N) \to O(\sqrt{N})$） |
| 测试正常值 | 2, 3, 5, 7, 11, ..., 97 (共25个) |
| 测试边界值 | 2 是最小素数，4 是最小合数，9 是奇合数 |
| 测试特殊值/错误输入 | 非法负数拦截 |
| 常见错误 | break 误以为能跳出外层循环、未试除到 sqrt(n) 边界漏判 |
| 对应源文件 | [`lessons/L06_loops/lecture-demo/6.2_prime_filter.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L06_loops/lecture-demo/6.2_prime_filter.c) |
| 对应PPT页码 | 第16~17页 |
| 当前状态 | **已定稿** |

---

## L07 — 一维数组与批量数据处理

### 案例 7-1：斐波那契数列生成器与连续内存
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L07-01 斐波那契数列数组递推 |
| 教学目标 | 掌握一维数组连续内存物理模型与递推递加空间换时间优化 |
| 输入 | 无（内置递推计算前 20 项） |
| 核心处理 | `fib[0]=1, fib[1]=1;` 单循环 `fib[i] = fib[i-1] + fib[i-2]` 计算前 20 项 |
| 输出 | 格式化输出前 20 项数列，每行 5 个制表符规整排版 |
| 关键知识点 | 数组定义/初始化、O(1) 快速随机访问、`(i+1)%5==0` 换行控制 |
| 测试正常值 | 前 20 项精准计算输出（第 20 项为 6765） |
| 测试边界值 | fib[0]=1, fib[1]=1, fib[19]=6765 |
| 测试特殊值/错误输入 | 无 |
| 常见错误 | 下标误写为 `fib[20]` 越界、递推初始两项未赋初值 |
| 对应源文件 | [`lessons/L07_one-dimensional-arrays/lecture-demo/7.1_fibonacci.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L07_one-dimensional-arrays/lecture-demo/7.1_fibonacci.c) |
| 对应PPT页码 | 第9页 |
| 当前状态 | **已定稿** |

### 案例 7-2：班级成绩大满贯与起泡排序
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L07-02 成绩大满贯与起泡排序 |
| 教学目标 | 掌握打擂台算法最值与学号下标同步定位，以及升序起泡排序 |
| 输入 | 10 个学生成绩 (0~100) |
| 核心处理 | 循环求和/平均分，打擂台同步记录 `max_index`/`min_index`，双重循环升序起泡 |
| 输出 | 总分、平均分、最高/最低分及学号，以及升序排序后的序列 |
| 关键知识点 | 打擂台算法、下标同步更新、起泡排序双重循环、三步易位交换 |
| 测试正常值 | 10 个典型成绩（如 85, 92, 78...）正常统计与排序 |
| 测试边界值 | 全部相同成绩、含 0 分与 100 分边界 |
| 测试特殊值/错误输入 | 超出 0~100 范围的成绩防御性重试 |
| 常见错误 | 遍历边界用 `<=10` 越界、更新擂主时忘记同步更新下标 |
| 对应源文件 | [`lessons/L07_one-dimensional-arrays/lecture-demo/7.2_grade_master.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L07_one-dimensional-arrays/lecture-demo/7.2_grade_master.c) |
| 对应PPT页码 | 第10~12, 16页 |
| 当前状态 | **已定稿** |

---

## L08 — 二维数组、查找/最值/累加/统计 ⭐阶段回收1

### 案例 8-1：二维数组行优先连续存储与矩阵转置
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L08-01 矩阵转置与物理内存连续性 |
| 教学目标 | 掌握二维数组行优先连续线性存储（Row-Major Order）与矩阵转置算法 |
| 输入 | 2x3 矩阵（6个整数） |
| 核心处理 | 打印 %p 物理内存地址验证连续性，双重循环执行 `b[j][i] = a[i][j]` 转置 |
| 输出 | 原始 2x3 矩阵与转置后 3x2 矩阵网格视图 |
| 关键知识点 | 二维数组定义/初始化、行优先线性内存、列数不可省略、矩阵转置 |
| 测试正常值 | 2x3 矩阵 {{1,2,3},{4,5,6}} 转置为 3x2 矩阵 |
| 测试边界值 | 全零矩阵、对称方阵 |
| 测试特殊值/错误输入 | 无 |
| 常见错误 | 行列边界张冠李戴、声明时省略第二维（列数） |
| 对应源文件 | [`lessons/L08_two-dimensional-arrays/lecture-demo/8.1_matrix_transpose.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L08_two-dimensional-arrays/lecture-demo/8.1_matrix_transpose.c) |
| 对应PPT页码 | 第5, 8页 |
| 当前状态 | **已定稿** |

---

## L09 — 字符数组、字符串与基础处理

### 案例 9-1：凯撒密码环形加密与字符串安全处理
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L09-01 凯撒密码环形加密器 |
| 教学目标 | 掌握字符数组逐位扫描、'\0'哨兵、ASCII模运算环形回绕与对称解密 |
| 输入 | 待加密英文字符串（含字母、空格、标点） |
| 核心处理 | 小写 `(c-'a'+3)%26+'a'`，大写 `(c-'A'+3)%26+'A'`，其他字符保留，对称还原 |
| 输出 | 明文、密文与解密还原对比报告 |
| 关键知识点 | 字符数组遍历、'\0'结束符、模运算环形回绕、对称解密 |
| 测试正常值 | "Hello, C Programming World! zZ-2026" 正常加密与还原 |
| 测试边界值 | 'z'/'Z' 回绕为 'c'/'C'、全特殊符号 |
| 测试特殊值/错误输入 | 无 |
| 常见错误 | 忘记添加末尾 '\0'、越界字符未取模回绕 |
| 对应源文件 | [`lessons/L09_strings/lecture-demo/9.2_caesar_cipher.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L09_strings/lecture-demo/9.2_caesar_cipher.c) |
| 对应PPT页码 | 第18页 |
| 当前状态 | **已定稿** |

---

## L10 — 函数定义、调用、参数与返回值

### 案例 10-1：回文数判断函数与防御性架构
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L10-01 回文数判定函数与单一职责 |
| 教学目标 | 掌握函数原型声明、定义、单向值传递、纯数学逆序与防御性编程 |
| 输入 | 一个整数（支持正数、负数、0 与非法字符测试） |
| 核心处理 | `read_valid_integer` 过滤非法字符，`is_palindrome` 逆序数学组装判定 |
| 输出 | 回文数判定报告 |
| 关键知识点 | 单一职责原则、原型声明、值传递隔离、scanf 输入流排空防御 |
| 测试正常值 | 121→是, 123→否, 12321→是 |
| 测试边界值 | 0→是, 9→是, -121→否 (负数拦截) |
| 测试特殊值/错误输入 | 非法字母 "abc" (安全拦截提示重试) |
| 常见错误 | 负数未做拦截、函数定义在 main 之后且无原型声明 |
| 对应源文件 | [`lessons/L10_functions/solutions/10.3_palindrome_checker.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L10_functions/solutions/10.3_palindrome_checker.c) |
| 对应PPT页码 | 第17~19页 |
| 当前状态 | **已定稿** |

---

## L11 — 数组作函数参数、作用域、存储类别、预处理

### 案例 11-1：数组作为函数参数与原地逆序换血
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L11-01 数组传参物理退化与原地逆序 |
| 教学目标 | 掌握数组名作为参数传递时退化为首地址指针的本质、sizeof差异与原地逆序 |
| 输入 | 包含 10 个整数的一维数组 |
| 核心处理 | 双指针两极对碰向心逼近原地对调元素，验证 sizeof(arr) 指针退化 |
| 输出 | 逆序前后的数组序列 |
| 关键知识点 | 数组名退化为指针、共享内存物理单元、成对法则传size、sizeof陷阱 |
| 测试正常值 | {12, 45, 8, 99, 34, 56, 78, 90, 23, 11} 原地逆序 |
| 测试边界值 | 单元素数组、偶数/奇数个元素 |
| 测试特殊值/错误输入 | 无 |
| 常见错误 | 子函数中误用 sizeof(arr) 测长、形参二维数组漏写列数 |
| 对应源文件 | [`lessons/L11_function-parameters-and-scope/lecture-demo/11.1_array_reverse.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L11_function-parameters-and-scope/lecture-demo/11.1_array_reverse.c) |
| 对应PPT页码 | 第4, 5, 18页 |
| 当前状态 | **已定稿** |

---

## L12 — 函数综合训练；指针概念与基础使用 ⭐阶段回收2

### 案例 12-1：swap 三国演义对决与指针多值带回
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L12-01 swap 三国演义与指针基础 |
| 教学目标 | 理解指针物理本质、&取地址与*解引用、多函数协作黄金三步法则与多值带回 |
| 输入 | 两个待对换的整数，以及待分析的成绩数组 |
| 核心处理 | 对比值传递失效、偷梁换柱失效与地址传递成功；通过指针突破 return 实现多值带回 |
| 输出 | 交换前后的变量值，以及全班最高分与最低分分析报告 |
| 关键知识点 | 变量三要素、&取地址、*解引用、栈帧物理隔离、狸猫换太子、NULL安全防线 |
| 测试正常值 | a=10, b=20 → a=20, b=10；成绩数组求极值 |
| 测试边界值 | a=b 的情况、单元素数组 |
| 测试特殊值/错误输入 | NULL 空指针防御拦截 |
| 常见错误 | 指针未初始化即强行解引用写值（野指针）、调用时漏写&、子函数仅交换局部指针变量 |
| 对应源文件 | [`lessons/L12_pointers-basics/lecture-demo/12.2_swap_comparison.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L12_pointers-basics/lecture-demo/12.2_swap_comparison.c) |
| 对应PPT页码 | 第2, 12~15, 18页 |
| 当前状态 | **已定稿** |

---

## L13 — 指针与数组、通过指针访问数组元素

### 案例 13-1：指针算术与双指针向心原地逆序
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L13-01 双指针向心原地逆序与指针算术 |
| 教学目标 | 掌握指针算术自适应步长、丢弃下标[i]、双指针向心扫描算法 |
| 输入 | 包含 9 个整数的一维数组 |
| 核心处理 | left 与 right 双指针相向滑动，在 while(left < right) 条件下原地对调元素 |
| 输出 | 逆序前后的数组序列 |
| 关键知识点 | 指针自适应步长、双指针向心对碰、四大剑客等价矩阵、指针移动遍历 |
| 测试正常值 | {11, 22, 33, 44, 55, 66, 77, 88, 99} 原地逆序 |
| 测试边界值 | 偶数/奇数个元素、单元素数组 |
| 测试特殊值/错误输入 | NULL 空指针防御拦截 |
| 常见错误 | 对常量数组名执行 a++ 自增、指针步长误解为仅加 1 字节 |
| 对应源文件 | [`lessons/L13_pointers-and-arrays/lecture-demo/13.1_array_reverse_ptr.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L13_pointers-and-arrays/lecture-demo/13.1_array_reverse_ptr.c) |
| 对应PPT页码 | 第4, 5, 6, 16页 |
| 当前状态 | **已定稿** |

---

## L14 — 结构体、结构体数组及信息管理

### 案例 14-1：学生多科成绩降序排序器与信息管理
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L14-01 学生多科成绩管理与整包置换排序 |
| 教学目标 | 掌握结构体定义、嵌套结构、结构体数组、起泡排序整包置换与指针传参 |
| 输入 | 5 名学生的多科成绩记录（学号、姓名、三科成绩） |
| 核心处理 | 计算三科总分，使用降序起泡排序进行结构体整包置换（杜绝人分错位灾难） |
| 输出 | 格式化成绩排行榜单（名次、学号、姓名、数学、英语、C语言、总分） |
| 关键知识点 | struct定义、strcpy赋值排雷、.与->运算符、块复制、起泡排序整包置换 |
| 测试正常值 | 5 名学生完整记录降序排序 |
| 测试边界值 | 并列相同总分学生、单科目满分/及格临界值 |
| 测试特殊值/错误输入 | NULL 空指针防御拦截 |
| 常见错误 | 结构体末尾漏分号、字符数组成员直接用等号赋值、排序时仅交换分数字段 |
| 对应源文件 | [`lessons/L14_structures/solutions/14.3_student_sorter.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L14_structures/solutions/14.3_student_sorter.c) |
| 对应PPT页码 | 第9, 10, 17, 18页 |
| 当前状态 | **已定稿** |

---

## L15 — 文件、FILE指针、fopen/fclose、fprintf/fscanf

### 案例 15-1：学生成绩格式化持久化与安全日志管理
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L15-01 文件读写与数据持久化 |
| 教学目标 | 掌握文件打开/关闭完整控制流、格式化持久化读写与异常防御盾体系 |
| 输入 | 学生结构体记录或系统运行事件字符串 |
| 核心处理 | fprintf 格式化输出至文本文件 → fscanf 精准反序列化读回内存（或追加模式 "a" 记录日志） |
| 输出 | 磁盘文件内容以及屏幕验证输出 |
| 关键知识点 | FILE*、fopen("w"/"r"/"a")、fprintf/fscanf、fclose冲刷落盘、feof/ferror异常检测 |
| 测试正常值 | 写入后读回内容与格式完全一致 |
| 测试边界值 | 文件不存在（"r"模式报错NULL，"a"模式自动创建） |
| 测试特殊值/错误输入 | 文件末尾空行（fscanf==3过滤拦截） |
| 常见错误 | fopen漏做NULL检查、日志误用"w"模式抹除历史、未fclose丢数据 |
| 对应源文件 | [`lessons/L15_files/lecture-demo/15.2_score_persistence.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L15_files/lecture-demo/15.2_score_persistence.c) |
| 对应PPT页码 | 第7, 8, 12, 13, 17, 18页 |
| 当前状态 | **已定稿** |

---

## L16 — 十章串联复习、读程序/改错/编程综合训练 ⭐阶段回收3

### 案例 16-1：升本模拟综合练习
| 字段 | 内容 |
|------|------|
| 讲次与案例名称 | L16-01 升本模拟 |
| 教学目标 | 十章知识串联、四题型综合训练 |
| 输入 | 综合练习题目 |
| 核心处理 | 选择题(10) + 读程序(3) + 改错(2) + 编程(2) |
| 输出 | 练习答案与解析 |
| 关键知识点 | 全课程十章核心知识 |
| 测试正常值 | 覆盖各章核心考点 |
| 测试边界值 | 跨章节综合题 |
| 测试特殊值/错误输入 | 改错题中的常见错误模式 |
| 常见错误 | 待根据阶段回收数据汇总 |
| 对应源文件 | 待补：`lessons/L16_comprehensive-review/exercises/` |
| 对应PPT页码 | 待确认 |
| 当前状态 | 待补代码 |
