# 第01讲 — 从计算机指令到你的第一个C程序

> **对应章节**：第1章 C语言概述 + 第3章 顺序程序设计(起步)  
> **对应课件**：《C语言程序设计基础》第01讲 PPT逐页文稿（v4全新对齐版，共26页）  
> **课时设置**：4课时（180分钟）理实一体化大课  
> **教学目标**：让专升本/职校零基础学生达成**“玩转指令、看懂结构、走通流程、独立编写”**的四维学习指标。

---

## 📂 代码资产与目录结构

```
lessons/L01_intro/
├── README.md                                # 本讲教学说明与全景导学指南（本文件）
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与演示）
│   ├── menu_runner.c                        # ⭐ Visual Studio 专属一键式全案交互运行器（零冲突，强烈推荐）
│   ├── 1.0_instruction_simulator.c         # ⭐ PPT 第10~12页：虚拟7条指令虚拟机与 A+B+C / A*B 模拟器
│   ├── 1.1_hello_world.c                    # PPT 第14~15页：最简标准C结构逐行剖析与四大基石
│   ├── 1.2_multi_line_output.c              # PPT 第17页：多行输出与 \n 换行符机制对比
│   ├── 1.3_student_card.c                   # PPT 第23页：标准程序员电子名卡案例
│   ├── 1.4_error_examples.md                # PPT 第18页：找茬大作战三选段与常见报错排雷指南
│   ├── 1.4_error_fixed.c                    # PPT 第18&22页：找茬修复与语法/逻辑错误对比标准版
│   └── 1.5_sum_two_numbers.c                # ⭐ PPT 第16页：两数之和（例1.2）、变量初识与 %d 占位符
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_hello_starter.c                # 任务1：运行 Hello, C!
│   ├── task2_student_card_starter.c         # 任务2：个人名片骨架填空
│   ├── task3_goal_card_starter.c            # 任务3：个性化学习目标名卡与格式对齐
│   └── task4_sum_two_numbers_starter.c      # ⭐ 任务4：两数之和与改写三数之和实操
├── exercises/                               # 当堂练习与评测
│   ├── exercises_01.md                      # 快速判断、找茬对决、互评标准卡与离堂小测
│   └── exercise_fix_errors.c                # 升本常考题型：经典语法改错练习
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── task1_hello_solution.c               # 任务1参考答案
    ├── task2_student_card_solution.c        # 任务2参考答案
    ├── task3_goal_card_solution.c           # 任务3参考答案
    ├── task4_sum_two_numbers_solution.c      # ⭐ 任务4参考答案（两数和 + 三数和 + 乘积改写）
    ├── homework_01_solution.c               # PPT 第26页课后作业：自我介绍 + 爱心字符画拼图
    └── exercises_01_answers.md              # 评测标准答案与详细考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 源文件名 / 资产名 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| ⭐ | [`menu_runner.c`](lecture-demo/menu_runner.c) | 全讲综合 | VS 一键式全案交互运行器 | 单项目零冲突，数字菜单随意调度 6 大演示案例 |
| 1 | [`1.0_instruction_simulator.c`](lecture-demo/1.0_instruction_simulator.c) | 第10~12页 | 启蒙导入：虚拟指令系统与程序本质 | 7条极简指令集、顺序累加 $A+B+C$、循环累加 $A \times B$ 底层模拟 |
| 2 | [`1.1_hello_world.c`](lecture-demo/1.1_hello_world.c) | 第14~15页 | 课上精讲：最简标准C程序结构与四大基石 | 预处理指令、`main(void)` 入口、`printf`、`return 0`、分号 `;` |
| 3 | [`1.5_sum_two_numbers.c`](lecture-demo/1.5_sum_two_numbers.c) | 第16页 | 进阶精讲：求两数之和（例1.2） | 变量定义（先定义后使用）、赋值运算符 `=`、`%d` 整型占位符 |
| 4 | [`1.2_multi_line_output.c`](lecture-demo/1.2_multi_line_output.c) | 第17页 | 课上精讲：多行输出与转义换行 | 顺序执行逻辑、`\n` 换行符机制、`/n` 错误辨析 |
| 5 | [`1.4_error_examples.md`](lecture-demo/1.4_error_examples.md)<br>[`1.4_error_fixed.c`](lecture-demo/1.4_error_fixed.c) | 第18、22页 | 现场对决：找茬大作战与错误辨析 | 找茬三选段（漏分号/中文标点/`mian`拼写/未闭合引号）与语法错误 vs 逻辑错误对比 |
| 6 | [`1.3_student_card.c`](lecture-demo/1.3_student_card.c) | 第23页 | 实践工坊：程序员电子名卡 | 多语句排版、边框对齐、格式化输出、学习目标设定 |
| 7 | [`homework_01_solution.c`](solutions/homework_01_solution.c) | 第26页 | 课后挑战：名卡升级与字符画拼图 | 4行以上自我介绍档案 + `printf` 字符爱心图案精密控制 |

---

## 🏫 教学实施精细化指引

### 1. 案例精析：极简虚拟 CPU 指令系统（PPT 第10~12页）
- **核心源码**：[`1.0_instruction_simulator.c`](lecture-demo/1.0_instruction_simulator.c)
- **底层揭秘**：计算机硬件由 CPU 和内存构成，只能听懂极简指令（`Input`, `Output`, `Add`, `Sub`, `Set`, `BranchEq`, `Jump`）。
- **算法演进**：
  - **顺序结构**：$A+B+C$ 通过两次两两加法顺序完成；
  - **循环结构**：无乘法指令时，利用 `BranchEq` 条件判断与 `Jump` 无条件跳转，通过 $B$ 次累加 $A$ 模拟实现 $A \times B$。

### 2. 案例精析：最简标准 C 结构与四大基石（PPT 第14~15页）
- **核心源码**：[`1.1_hello_world.c`](lecture-demo/1.1_hello_world.c)
- **四大基石板书模型**：
  - `#include <stdio.h>` $\rightarrow$ **“拉外援 / 引入工具箱”**（标准输入输出库）；
  - `int main(void)` $\rightarrow$ **“进大门”**（程序的唯一入口）；
  - `{ ... }` $\rightarrow$ **“砌围墙”**（函数体复合语句边界）；
  - `printf("...\n");` $\rightarrow$ **“大喇叭”**（控制台输出与换行）；
  - `;` $\rightarrow$ **“打句号”**（C 语句法定结束符）；
  - `return 0;` $\rightarrow$ **“安全到家”**（返回操作系统正常状态码）。

### 3. 进阶精析：求两数之和与变量初识（PPT 第16页）
- **核心源码**：[`1.5_sum_two_numbers.c`](lecture-demo/1.5_sum_two_numbers.c)
- **变量三步法**：
  - `int a, b, sum;` $\rightarrow$ 向内存申请整型收纳盒；
  - `a = 123; b = 456;` $\rightarrow$ 赋值号 `=` 将数据放入盒中；
  - `printf("sum is %d\n", sum);` $\rightarrow$ `%d` 作为数据定位锚点，动态替换变量值。

### 4. 现场对决：找茬大作战与错误辨析（PPT 第18、22页）
- **核心文档与源码**：[`1.4_error_examples.md`](lecture-demo/1.4_error_examples.md) / [`1.4_error_fixed.c`](lecture-demo/1.4_error_fixed.c)
- **语法错误 vs 逻辑错误黄金法则**：
  - **语法错误**：编译器直接抓包报错，顺着行号定位排错；
  - **逻辑错误**：编译器不报错，但结果荒谬（如 $3+5$ 误写为 $3-5$），必须依靠**单步调试（Debug）**排查！

### 5. 机房实操与 Code Review（PPT 第23~24页）
- **核心源码**：[`1.3_student_card.c`](lecture-demo/1.3_student_card.c) & [`task2_student_card_starter.c`](starter/task2_student_card_starter.c)
- **Review 互评三步走**：① 读得通（脑内模拟排版） $\rightarrow$ ② 找隐患（检查 `.c` 后缀、分号、`\n`） $\rightarrow$ ③ 点个赞（夸奖精妙排版）。

---

## 🛠️ Visual Studio 专属避坑：同一个项目多个 `.c` 文件（多 main 函数）如何丝滑切换运行？

在 Visual Studio 中，初学者最常遇到的一个“特大拦路虎”是：**把多个课堂案例（如 `1.1_hello_world.c` 和 `1.2_multi_line_output.c`）同时放进同一个项目，一按运行直接报错 `LNK2005: _main 已经在 xxx.obj 中定义`**！

### 1. 物理机理剖析
- 一个控制台应用程序（`.exe`）有且仅能有一个 `main` 函数作为入口；
- VS 默认会将项目“源文件”目录下的**所有 `.c` 文件同时送入编译并打包链接**，导致多个 `main` 函数产生名字冲突。

### 2. 极简解决方案（推荐学生必须掌握）

#### 方案 A：【从生成中排除（Excluded From Build）】⭐⭐⭐⭐⭐（首选，零侵入代码）
1. 在 VS 右侧 **解决方案资源管理器** 中，找到当前**不打算运行的 `.c` 文件**（例如暂不跑 `1.1_hello_world.c`）；
2. **右键点击该文件** $\rightarrow$ 选择 **属性（Properties）**；
3. 在左侧选中 **配置属性 $\rightarrow$ 常规**，将右侧的 **【从生成中排除】（Excluded From Build）** 改为 **【是 (Yes)】** $\rightarrow$ 点击确定；
4. 此时该文件图标会出现标记，不再参与本次编译。直接按 **`Ctrl + F5`** 即可完美运行你想跑的另一个 `.c` 文件！
5. 下次想换回来时，只需将该属性改回 **【否 (No)】** 即可。

#### 方案 B：【从项目中排除（Exclude From Project）】⭐⭐⭐⭐（轻量快捷）
- 右键点击不想运行的文件 $\rightarrow$ 选择 **从项目中排除**（文件依然保存在本地硬盘中，只是从当前编译列表移除）；
- 想再次使用时，点击解决方案顶部的“显示所有文件”，右键点击该文件选择“包含在项目中”。

#### 方案 C：【多项目独立管理（设为启动项目）】⭐⭐⭐⭐（工程化结构）
- 在同一个解决方案下，为每个独立案例新建一个项目（如 `L01_01_Hello`、`L01_02_MultiLine`）；
- 想运行哪个案例，只需**右键点击对应项目 $\rightarrow$ 选择【设为启动项目（Set as Startup Project）】**（项目名变为粗体），按 `Ctrl + F5` 即可直接运行。

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | **概念破冰与指令游戏** | 课程通关路线图（PPT 1~6） + 虚拟 7 条指令游戏实战（PPT 7~12） |
| **第2课时** | 45 min | **C 程序解剖与案例精讲** | C 语言历史（PPT 13） + Hello World 与四大基石（PPT 14~15） + 两数之和与 printf 转义（PPT 16~17） |
| **第3课时** | 45 min | **找茬对决与开发全流程** | 找茬大作战（PPT 18~19） + 算法偶数和（PPT 20） + 编辑/编译/连接/运行四步走与错误辨析（PPT 21~22） |
| **第4课时** | 45 min | **机房实训与结课测评** | 上机定制程序员名卡（PPT 23） + 同伴 Code Review（PPT 24） + 离堂小测与作业布置（PPT 25~26） |
