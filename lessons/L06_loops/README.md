# 第06讲 — 玩转循环进阶与控制流刹车：for 循环、循环嵌套与 break/continue 精细控制

> **对应章节**：第5章 循环结构程序设计(进阶与综合)  
> **对应课件**：《C语言程序设计》第06讲 PPT逐页文稿与教学设计（共20页·双书融合深度优化版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（for 循环绝对时序拆解、嵌套循环变量生命周期与作用域）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（九九乘法表行列排版、素数过滤器与 $\sqrt{n}$ 算力优化）
> - 湖南大学《程序设计》课件（break/continue 权限边界、多层嵌套越权危机排雷）  
> **课时设置**：4课时（180分钟）理实一体化课堂  
> **核心指标**：达成**“能拆解（识三素）、能控制（握两退）、能嵌套（控双层）、能优化（练双题）”**的四维能力指标。

---

## 📂 代码资产与目录结构

```
lessons/L06_loops/
├── README.md                                # 本讲教学说明与全景导学指南（本文件）
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与演示）
│   ├── 6.1_multiplication_table.c           # 九九乘法表：双重 for 循环、时钟模型、\t 硬件级对齐工程 (PPT 第9~10页)
│   └── 6.2_prime_filter.c                   # 100以内素数过滤器：循环嵌套、break 一票否决制、sqrt(n) 算力拯救 (PPT 第16~17页)
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_multiplication_table_starter.c # 任务1：九九乘法表模板 (PPT 第9~10页)
│   ├── task2_prime_filter_starter.c         # 任务2：素数过滤器与 sqrt 优化模板 (PPT 第16~17页)
│   └── task3_score_skipper_starter.c        # 任务3：及格成绩过滤器与 break/continue 模板 (PPT 第11~15页)
├── exercises/                               # 当堂练习与评测
│   ├── exercises_06.md                      # for时序分析、break vs continue预测、同伴极限黑盒测试单、离堂小测 (PPT 第7, 13, 18, 19页)
│   └── exercise_fix_nested_errors.c         # 专升本经典改错：for后误加分号、while中continue死循环、内外层变量重名排雷 (PPT 第7, 15页)
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── 6.3_score_skipper.c                  # 任务3参考答案：及格成绩过滤器、break 与 continue 深度实战 (PPT 第11~15页)
    └── exercises_06_answers.md              # 评测标准答案与专升本深度考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| 1 | [`6.1_multiplication_table.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L06_loops/lecture-demo/6.1_multiplication_table.c) | 第9~10页 | 课上精讲：双重循环经典 | 双重 for 嵌套、时钟分针秒针模型、`j <= i` 直角三角形约束、`\t` 硬件级对齐 |
| 2 | [`6.2_prime_filter.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L06_loops/lecture-demo/6.2_prime_filter.c) | 第16~17页 | 算法演进：数学级减负 | `break` 一票否决制提前跳出内层、`sqrt(num)`（`<math.h>`）将复杂度由 $O(N)$ 降至 $O(\sqrt{N})$ |
| 3 | [`6.3_score_skipper.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L06_loops/solutions/6.3_score_skipper.c) | 第11~15页 | 实践工坊：控制流刹车 | `break` 哨兵退出 (-1) vs `continue` 异常跳过、深度拦截 while 中 continue 导致的死循环 |
| 4 | [`exercise_fix_nested_errors.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L06_loops/exercises/exercise_fix_nested_errors.c) | 第7, 15页 | 质检排雷：三大夺命地雷 | `for ();` 空循环分号地雷、内外层循环计数器同名打架、换行排版错位 |

---

## 🏫 教学实施精细化指引

### 1. for 循环的绝对执行时序（PPT 第4页）
$$[1. \text{初始化 (仅1次)}] \longrightarrow [2. \text{条件判定 (进门闸)}] \stackrel{\text{真}}{\longrightarrow} [3. \text{循环体}] \longrightarrow [4. \text{步长更新}] \longrightarrow \text{回到 2 判定}$$
- **时序铁律**：步长更新 `表达式3` 是在**循环体执行完毕后立刻执行**，绝非在进入循环体前！

### 2. 双重嵌套时钟模型（PPT 第8页）
- **外层循环** $\rightarrow$ **分针**（动一下，代表新的一行开始）；
- **内层循环** $\rightarrow$ **秒针**（必须完整跑完一整轮，分针才能再动第二下）。
- **总执行次数**：外层 $M$ 次 $\times$ 内层 $N$ 次 $= M \times N$ 次。

### 3. break 与 continue 的物理差异（PPT 第11~14页）
| 指令 | 形象比喻 | 物理动作 | 跳转终点 |
|:---:|:---|:---|:---|
| **`break`** | 直接退赛，队伍解散 | **彻底终结**当前循环 | 包含它的**最直接内层大括号之外** |
| **`continue`** | 本次免谈，下位继续 | **仅跳过本次**剩余语句 | `for` 中跳到 `表达式3` (自增)；`while` 中跳到头部判定 |

### 4. 专升本死循环超级大雷（PPT 第15页）
```c
// ❌ 致命死循环写法：
int i = 1;
while (i <= 5) {
    if (i == 3) continue; // 抄近路跳过了下方的 i++！
    printf("%d", i);
    i++;                  // 永远无法执行，i 冻结在 3，系统死锁！
}
```

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | for 循环时序与空城计 | PPT 第1~7页：复习导入、for 绝对时序、C99 作用域、三类循环选型指南、分号地雷 PK |
| **第2课时** | 45 min | 嵌套循环与九九乘法表 | PPT 第8~10页：时钟分针秒针模型、Trace Table 打表、`6.1_multiplication_table.c` 演示 |
| **第3课时** | 45 min | break与continue精细控制 | PPT 第11~15页：刹车与越档对比、多层嵌套权限、while-continue 死循环排雷、`6.3` 演练 |
| **第4课时** | 45 min | 素数优化实践、互评与小测 | PPT 第16~20页：`6.2_prime_filter.c` 试除优化、同伴黑盒测试、离堂小测、布置作业 |

---

## 📊 代码资产状态

| 资产类别 | 包含文件 | 当前状态 | 备注 |
|:---|:---|:---:|:---|
| **课堂演示代码** | `6.1_multiplication_table.c`, `6.2_prime_filter.c` | **已定稿** | 2 份演示源文件全量通过编译测试 |
| **起步模板** | `task1_multiplication_table_starter.c`, `task2_prime_filter_starter.c`, `task3_score_skipper_starter.c` | **已定稿** | 3 份上机任务骨架 |
| **当堂练习** | `exercises_06.md`, `exercise_fix_nested_errors.c` | **已定稿** | 1 份测评题单 + 1 份改错实操 |
| **参考答案** | `6.3_score_skipper.c`, `exercises_06_answers.md` | **已定稿** | 1 份代码答案 + 1 份题目解析 |
