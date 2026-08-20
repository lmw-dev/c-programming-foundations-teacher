# 第07讲 — 探秘C语言的“排队储物柜”：一维数组的定义、内存存储、边界控制与核心算法

> **对应章节**：第6章(上) 一维数组的定义与应用  
> **对应课件**：《C语言程序设计》第07讲 PPT逐页文稿与教学设计（共19页·双书融合极详版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（连续内存物理映像、空间长度解剖、起泡排序趟数与比对推演）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（打擂台算法最值与学号下标同步更新、Fibonacci 数组递推）
> - 湖南大学《程序设计》课件（下标越界幽灵改值排雷、字符串 `'\0'` 终结符底层机制）  
> **课时设置**：4课时（180分钟）理实一体化课堂  
> **核心指标**：达成**“能定义（识结构）、能初始化（晓规则）、能遍历（控边界）、能算法（精实战）”**的四维能力指标。

---

## 📂 代码资产与目录结构

```
lessons/L07_one-dimensional-arrays/
├── README.md                                # 本讲教学说明与全景导学指南（本文件）
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与演示）
│   ├── 7.1_fibonacci.c                      # 斐波那契数列生成器：数组空间换时间、递推公式 f[i]=f[i-1]+f[i-2]、5个一行制表符排版 (PPT 第9页)
│   └── 7.2_grade_master.c                   # 班级成绩大满贯：打擂台最值与学号下标同步更新、升序起泡排序 (PPT 第10~12, 16页)
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_fibonacci_starter.c            # 任务1：斐波那契数列递推模板 (PPT 第9页)
│   ├── task2_grade_master_starter.c         # 任务2：成绩大满贯与打擂台模板 (PPT 第10, 16页)
│   └── task3_bubble_sort_starter.c          # 任务3：起泡排序升序算法模板 (PPT 第11~12页)
├── exercises/                               # 当堂练习与评测
│   ├── exercises_07.md                      # 数组定义与初始化正误判断、内存字节计算、打擂台时序预测、同伴自查单、离堂小测 (PPT 第5, 6, 7, 13, 17, 18页)
│   └── exercise_fix_array_errors.c          # 专升本经典改错：数组越界a[10]访问、求平均丢失小数精度、未赋初值导致垃圾值 (PPT 第15页)
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── 7.3_array_bounds_demo.c              # 任务3/实验3参考答案：数组越界大排雷、栈内存幽灵改值物理实验 (PPT 第6, 15页)
    └── exercises_07_answers.md              # 评测标准答案与专升本深度考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| 1 | [`7.1_fibonacci.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L07_one-dimensional-arrays/lecture-demo/7.1_fibonacci.c) | 第9页 | 课上精讲：连续内存递推 | 数组连续内存寻址、空间换时间 $O(1)$ 随机访问、`(i+1)%5==0` 格式化制表符排版 |
| 2 | [`7.2_grade_master.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L07_one-dimensional-arrays/lecture-demo/7.2_grade_master.c) | 第10~12, 16页 | 实践工坊：综合算法大满贯 | 打擂台算法（最值与学号下标同步更新）、升序起泡排序（外层趟数+内层相邻比对） |
| 3 | [`7.3_array_bounds_demo.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L07_one-dimensional-arrays/solutions/7.3_array_bounds_demo.c) | 第6, 15页 | 实验诊断：越界幽灵改值 | 证明 C 不进行运行期边界检查、越界野蛮读写破坏相邻栈内存（Buffer Overflow 漏洞防范） |
| 4 | [`exercise_fix_array_errors.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L07_one-dimensional-arrays/exercises/exercise_fix_array_errors.c) | 第15页 | 质检排雷：常见错误盘点 | `i <= 10` 越界地雷、求平均整数截断、累加器未初始化垃圾值排查 |

---

## 🏫 教学实施精细化指引

### 1. 一维数组连续内存物理映像（PPT 第4~5页）
```text
 score[0]      score[1]      score[2]      score[3]             score[9]
┌─────────────┬─────────────┬─────────────┬─────────────┬ ⋯ ───┬─────────────┐
│  成绩 (int) │  成绩 (int) │  成绩 (int) │  成绩 (int) │      │  成绩 (int) │
└─────────────┴─────────────┴─────────────┴─────────────┴ ⋯ ───┴─────────────┘
  第1个柜子     第2个柜子     第3个柜子     第4个柜子            第10个柜子
```
- **物理分配**：`int score[10];` 一次性在栈区划分 40 字节连续空间；
- **0 起步规则**：有效下标严格为 `0 ~ 9`，不存在 `score[10]`！

### 2. 部分初始化与自动归零天条（PPT 第7页）
- `int a[10] = {1, 2, 3};` $\rightarrow$ 前 3 格为 1, 2, 3，后 7 格**编译器自动清零**；
- `int a[100] = {0};` $\rightarrow$ 100 个格子全部快速清零的最优工程写法。

### 3. 打擂台算法：最值与下标同步定位（PPT 第10页）
```c
if (score[i] > max_score) {
    max_score = score[i]; // 更新擂主分数
    max_index = i;        // ⚠️ 关键: 同步记录门牌号下标！
}
```

### 4. 起泡排序双重循环物理时序（PPT 第11~12页）
- **外层 $i$ 控制趟数**：$n$ 个元素最多只需 $n-1$ 趟（`i` 从 0 到 $n-2$）；
- **内层 $j$ 控制相邻比对**：比对范围随趟数收缩为 $0 \sim n-1-i$；
- **三步易位交换**：`temp = a[j]; a[j] = a[j+1]; a[j+1] = temp;`。

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | 数组诞生与连续内存映像 | PPT 第1~7页：超市储物柜模型、数组定义三要素、0起步门牌号、部分初始化清零规则 |
| **第2课时** | 45 min | 数组遍历与斐波那契递推 | PPT 第8~9页：循环与数组神仙伴侣、`7.1_fibonacci.c` 演示精讲、每行5个格式排版 |
| **第3课时** | 45 min | 打擂台算法与起泡排序推演 | PPT 第10~14页：最值与下标同步更新、起泡排序物理时序、字符串 `\0` 终结符机制 |
| **第4课时** | 45 min | 越界排雷、同伴互评与小测 | PPT 第15~19页：`7.2_grade_master` 上机、越界幽灵改值实验 `7.3`、互评自查、离堂小测 |

---

## 📊 代码资产状态

| 资产类别 | 包含文件 | 当前状态 | 备注 |
|:---|:---|:---:|:---|
| **课堂演示代码** | `7.1_fibonacci.c`, `7.2_grade_master.c` | **已定稿** | 2 份演示源文件全量通过编译测试 |
| **起步模板** | `task1_fibonacci_starter.c`, `task2_grade_master_starter.c`, `task3_bubble_sort_starter.c` | **已定稿** | 3 份上机任务骨架 |
| **当堂练习** | `exercises_07.md`, `exercise_fix_array_errors.c` | **已定稿** | 1 份测评题单 + 1 份改错实操 |
| **参考答案** | `7.3_array_bounds_demo.c`, `exercises_07_answers.md` | **已定稿** | 1 份代码答案 + 1 份题目解析 |
