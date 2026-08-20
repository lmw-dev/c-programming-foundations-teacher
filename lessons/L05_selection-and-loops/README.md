# 第05讲 — 智能菜单与无限套娃的秘密：switch-case 多分支与 while / do-while 循环结构

> **对应章节**：第4章(下) switch 语句 + 第5章 循环结构程序设计(起步)  
> **对应课件**：《C语言程序设计》第05讲 PPT逐页文稿与教学设计（共19页·双书融合深度优化版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（整型表达式限定、case 穿透机理、循环三大基石与内存打表追踪）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（常驻菜单计算器、阶乘累加、do-while 猜数字趣味游戏）
> - 湖南大学《程序设计》课件（循环控制变量物理更新、大数溢出爆仓防御、防御性除零拦截）  
> **课时设置**：4课时（180分钟）理实一体化课堂  
> **核心指标**：达成**“能写菜单（用 switch）、能控穿透（防漏 break）、能写循环（懂三要素）、能辨异同（while vs do-while）”**的四维能力指标。

---

## 📂 代码资产与目录结构

```
lessons/L05_selection-and-loops/
├── README.md                                # 本讲教学说明与全景导学指南（本文件）
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与演示）
│   ├── 5.1_menu_calculator.c                # 常驻菜单计算器：while(is_running) + switch-case + 除零防御拦截 (PPT 第14~15页)
│   └── 5.2_factorial_sum.c                  # 阶乘累加和 1!+...+10!：单层 while 循环、循环三要素、long long 防爆仓 (PPT 第17页)
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_menu_calculator_starter.c      # 任务1：常驻菜单计算器模板 (PPT 第14~15页)
│   ├── task2_factorial_sum_starter.c        # 任务2：while 循环阶乘累加和模板 (PPT 第17页)
│   └── task3_guess_number_starter.c         # 任务3：do-while 猜数字趣味游戏模板 (PPT 第19页)
├── exercises/                               # 当堂练习与评测
│   ├── exercises_05.md                      # 多分支找茬、CPU 累加时序打表、同伴极限黑盒破坏性测试单、离堂小测 (PPT 第6, 10, 13, 18, 19页)
│   └── exercise_fix_loop_errors.c           # 专升本经典改错：switch漏break穿透、循环变量未更新死循环、while后误加分号 (PPT 第16页)
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── 5.3_guess_number.c                   # 任务3/作业2参考答案：do-while 猜数字游戏与 rand() 随机数 (PPT 第19页)
    └── exercises_05_answers.md              # 评测标准答案与专升本深度考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| 1 | [`5.1_menu_calculator.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L05_selection-and-loops/lecture-demo/5.1_menu_calculator.c) | 第14~15页 | 课上精讲：常驻交互架构 | `while(is_running)` 状态哨兵维持终端生命周期、`switch-case` 多路派发、`break` 刹车片、除零防御 |
| 2 | [`5.2_factorial_sum.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L05_selection-and-loops/lecture-demo/5.2_factorial_sum.c) | 第17页 | 实践工坊：循环三大基石 | 循环初始化/判定/步长三位一体、单层 while 同步累乘累加、`long long` (%lld) 大数防爆仓 |
| 3 | [`5.3_guess_number.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L05_selection-and-loops/solutions/5.3_guess_number.c) | 第19页 | 课后挑战：游戏化实战 | `do-while`“至少执行一次”先斩后奏特性、`srand(time(NULL))` 随机数种子、`rand()%100+1` 区间映射 |
| 4 | [`exercise_fix_loop_errors.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L05_selection-and-loops/exercises/exercise_fix_loop_errors.c) | 第16页 | 质检排雷：常见错误盘点 | `case` 漏 `break` 穿透、`while ();` 空语句死循环、漏写 `i++` 计数器未更新 |

---

## 🏫 教学实施精细化指引

### 1. switch-case 语法硬锁与 case 穿透（PPT 第4~5页）
- **控制表达式类型限制**：必须是**整型（`int`、`short`、`char` 等）**，绝对不能是浮点数（`float/double`）！
- **case 标签要求**：必须是**常量表达式**（如 `case 1:` 或 `case 'A':`），绝不能带变量！
- **case 穿透物理流向**：`switch` 只是入场定位锚点，若缺少 `break;` 刹车，程序将无视条件顺流直下执行后续所有 `case` 直到遇到 `break` 或结束。

### 2. 循环控制三大基石（PPT 第8页）
```text
  [ 基石一：初始化 (i = 1) ] ──> [ 基石二：条件判定 (i <= 100) ] ──(真)──> [ 循环体 ] ──> [ 基石三：步长更新 (i++) ]
                                         │ (假)
                                         └──> [ 退出循环 ]
```
- **警示**：若遗漏“基石三（变量更新）”，计数器永远无法逼近终点，系统将坠入**死循环（Infinite Loop）**！

### 3. while vs do-while 核心物理差异（PPT 第12页）
- **`while`（当型循环）**：先判后做。若初始条件为假，**可能 0 次执行**。
- **`do-while`（直到型循环）**：先斩后奏。无论初始条件真假，**至少执行 1 次**（注意末尾必须有分号 `;`）。

### 4. 阶乘大数防爆仓机制（PPT 第17页）
- $10! = 3,628,800$，16 位整型（最大 32767）在 $8!$ 时即溢出爆仓成负数；
- 必须使用 64 位有符号大整数 **`long long`** 配合占位符 **`%lld`** 确保数据物理安全。

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | switch 多分支直达电梯 | PPT 第1~6页：复习导入、switch 语法硬锁、case 穿透与 break 刹车、多分支找茬 PK |
| **第2课时** | 45 min | 循环诞生与三大基石 | PPT 第7~10页：循环需求、三大基石（起点/终点/步长）、while 当型循环、CPU 累加打表追踪 |
| **第3课时** | 45 min | do-while 异同与常驻计算器 | PPT 第11~15页：do-while 先斩后奏、时序打表对比、`5.1_menu_calculator.c` 演示精讲 |
| **第4课时** | 45 min | 阶乘实践、同伴互评与小测 | PPT 第16~20页：上机 `5.2_factorial_sum`、同伴黑盒测试、离堂小测、布置作业 `5.3` |

---

## 📊 代码资产状态

| 资产类别 | 包含文件 | 当前状态 | 备注 |
|:---|:---|:---:|:---|
| **课堂演示代码** | `5.1_menu_calculator.c`, `5.2_factorial_sum.c` | **已定稿** | 2 份演示源文件全量通过编译测试 |
| **起步模板** | `task1_menu_calculator_starter.c`, `task2_factorial_sum_starter.c`, `task3_guess_number_starter.c` | **已定稿** | 3 份上机任务骨架 |
| **当堂练习** | `exercises_05.md`, `exercise_fix_loop_errors.c` | **已定稿** | 1 份测评题单 + 1 份改错实操 |
| **参考答案** | `5.3_guess_number.c`, `exercises_05_answers.md` | **已定稿** | 1 份代码答案 + 1 份题目解析 |
