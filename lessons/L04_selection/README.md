# 第04讲 — 程序的“分流岔路口”：if 选择结构、条件判断与防御性编程

> **对应章节**：第4章 选择结构程序设计  
> **对应课件**：《C语言程序设计》第04讲 PPT逐页文稿与教学设计（共20页·双书融合深度优化版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（关系与逻辑运算符优先级、复合逻辑表达式合并法）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（闰年判定逻辑树、三数夺魁“打擂台”算法、智能计算器）
> - 湖南大学《程序设计》课件（逻辑短路“空开断路模型”、就近配对铁律、浮点数零判定防御性编程）  
> **课时设置**：4课时（180分钟）理实一体化课堂  
> **核心指标**：达成**“能组合（写条件）、能避坑（防短路）、能多路（设分支）、能配对（理嵌套）、能测试（测边界）”**的五维能力指标。

---

## 📂 代码资产与目录结构

```
lessons/L04_selection/
├── README.md                                # 本讲教学说明与全景导学指南（本文件）
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与对比）
│   ├── 4.1_leap_year.c                      # 闰年判定双书对比：何版嵌套逻辑树 vs 谭版复合逻辑式 (PPT 第12页)
│   └── 4.2_three_max.c                      # 三数求最大值：嵌套两两比较 vs 何版“打擂台”算法 (PPT 第15页)
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_leap_year_starter.c            # 任务1：公元年份闰年判定模板 (PPT 第12页)
│   ├── task2_three_max_starter.c            # 任务2：三数夺魁“打擂台”算法模板 (PPT 第15页)
│   └── task3_calculator_starter.c          # 任务3：智能计算器与除零防御拦截模板 (PPT 第16页)
├── exercises/                               # 当堂练习与评测
│   ├── exercises_04.md                      # 优先级对决、就近配对推演、极限黑盒破坏性测试单、离堂小测 (PPT 第8, 11, 13, 17, 19页)
│   └── exercise_fix_if_errors.c             # 专升本经典改错：if后误加分号、单等号赋值恒真、及格边界排雷 (PPT 第13~14页)
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── 4.3_smart_calculator.c               # 任务3参考答案：智能计算器与除零拦截 (PPT 第16~17页)
    └── exercises_04_answers.md              # 评测标准答案与专升本深度考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| 1 | [`4.1_leap_year.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L04_selection/lecture-demo/4.1_leap_year.c) | 第12页 | 课上精讲：双书对比 | 嵌套逻辑树 vs 复合逻辑表达式、短路求值（`&&` / `\|\|`）提前截断机制 |
| 2 | [`4.2_three_max.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L04_selection/lecture-demo/4.2_three_max.c) | 第15页 | 机房实战：算法演进 | 嵌套两两比较 vs **“打擂台（Arena）算法”**，$O(N)$ 线性复杂度演进 |
| 3 | [`4.3_smart_calculator.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L04_selection/solutions/4.3_smart_calculator.c) | 第16~17页 | 实践工坊：防御性编程 | `scanf("%f %c %f")` 缓冲区排雷（空格吃回车）、`fabs(num2) < 1e-6` 浮点除零拦截 |
| 4 | [`exercise_fix_if_errors.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L04_selection/exercises/exercise_fix_if_errors.c) | 第13~14页 | 质检排雷：8大翻车地雷 | `if ();` 空语句地雷、`if (x = 5)` 赋值恒真、`score >= 60` 边界等号 |

---

## 🏫 教学实施精细化指引

### 1. 运算符优先级总铁律（PPT 第8页）
$$\text{!(非) 极高} \longrightarrow \text{算术运算符} \longrightarrow \text{关系运算符} \longrightarrow \text{\&\&(与) 和 ||(或)} \longrightarrow \text{赋值运算符 (最低)}$$
- **口诀**：*“非最高，算术高，关系中，逻辑低，赋值吊车尾。”*
- **逻辑短路机制**：
  - `a && b`：左边 `a` 为假(0)，右边 `b` **彻底不执行**；
  - `a || b`：左边 `a` 为真(非0)，右边 `b` **彻底不执行**。

### 2. 就近配对天条与安全花括号（PPT 第11页）
- **C 语言官方铁律**：`else` 总是与它上面**最近的、且未配对的 `if`** 紧紧配对，**无视代码缩进和空格**！
- **工业安全规范**：永远不要省略花括号 `{}`，通过代码块显式划定分支的楚河汉界。

### 3. “打擂台（Arena）”算法思想（PPT 第15页）
```text
  [ 初始状态 ] ──> max = a; (让 a 当初始擂主)
  [ 挑战者 b ] ──> if (b > max) max = b; (若 b 比擂主强，b 成为新擂主)
  [ 挑战者 c ] ──> if (c > max) max = c; (若 c 比擂主强，c 成为新擂主)
```
- **核心价值**：从嵌套的指数复杂度 $2^{N-1}$ 分支灾难，简化为 $O(N)$ 线性结构，是后续数组遍历求最大值/最小值的核心算法基石。

### 4. 防御性编程与缓冲区排雷（PPT 第16页）
- **`%c` 前空格救命草**：`scanf("%f %c %f", &num1, &op, &num2)` 中 `%c` 前的空格用于吃掉缓冲区残留的 `\n` 或空格，彻底终结“运算符被自动跳过”的常见 Bug。
- **浮点数除零拦截**：严禁写 `num2 == 0.0f`（因 IEEE 754 浮点精度误差），应采用 `fabs(num2) < 1e-6` 拦截除数为零，杜绝硬件级中断和闪退。

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | 条件之源与逻辑短路 | PPT 第1~8页：复习导入、关系运算符、数学连写陷阱、短路电路模型、随堂 PK |
| **第2课时** | 45 min | 分流之道与嵌套配对 | PPT 第9~12页：单/双/多分支滑梯模型、就近配对铁律、`4.1_leap_year.c` 闰年双书对比 |
| **第3课时** | 45 min | 质检素养与打擂台实战 | PPT 第13~15页：及格边界值测试、初学者 8 大地雷排查、`4.2_three_max.c` 打擂台实战 |
| **第4课时** | 45 min | 智能计算器工坊与互评 | PPT 第16~20页：编写 `4.3_smart_calculator`、同伴极限黑盒测试、离堂小测、布置作业 |

---

## 📊 代码资产状态

| 资产类别 | 包含文件 | 当前状态 | 备注 |
|:---|:---|:---:|:---|
| **课堂演示代码** | `4.1_leap_year.c`, `4.2_three_max.c` | **已定稿** | 2 份演示源文件全量通过编译测试 |
| **起步模板** | `task1_leap_year_starter.c`, `task2_three_max_starter.c`, `task3_calculator_starter.c` | **已定稿** | 3 份上机任务骨架 |
| **当堂练习** | `exercises_04.md`, `exercise_fix_if_errors.c` | **已定稿** | 1 份测评题单 + 1 份改错实操 |
| **参考答案** | `4.3_smart_calculator.c`, `exercises_04_answers.md` | **已定稿** | 1 份代码答案 + 1 份题目解析 |
